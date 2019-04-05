//  This file is licensed under the terms of the CC-LGPL.
//
//  Autor  : Rafael Angel Campos Vargas
//  Correo : RofoelCompos@hotmail.com  
//  Apdo. 964-1250 Escazu, San Jose, Costa Rica
//  dedicado a Jesus y Maria...
//
//  En este momento estoy creando un programa
//  de animacion LibreN3D para FreeDOS con el compilador FreePascal
//  falta mucho... 19 junio 2018
//                
//  Mis dibujos estan en unidades mL y L (Lisa) segun el contexto.
//  1 L equivale a 0.055063 pulgadas 
//  definido como 0.001 para POVRAY.
//     
//  DUCA DispensadorUniversalCintaAdhesiva
//  El archivo dibuja un dispensador de cinta adhesiva, tipo escolar recargable.
//  La cinta tiene dos posiciones, una enrollada y otra lista en la cuchilla. 
//  Es muy poco flexible. Es compatible con POVRay 3.1.
//
//  La macro principal tiene dos parametros.
//  #macro DUCA_Cinta( FactorRelleno, BanderaCortada )
//          FactorRelleno       : Fraccion de uso. 
//              0.0 indica cinta agotada, y 1.0 cinta nueva.
//              Utilice un valor negativo para no dibujar la cinta del todo.
//          BanderaCortada      : "on" dibuja la cinta puesta en el cortador metalico,
//              "off" dibuja la cinta enrollada sin ubicar en el cortador.
//        
//  La siguiente macro permite un mayor control de las caracteristicas.
//  #macro DUCA_DispensadorUniversalCintaAdhesiva( FactorRelleno, BanderaCortada,
//              DiametroDespachador, AnchoDespachador, DiametroInternoCinta,
//              DiametroAdhesivoMenor, DiametroAdhesivoMayor, AnchoAdhesivo,
//              GruesoPlastico, GruesoFilo, TotalDientes,
//              TexturaPrincipal, TexturaMetalica,
//              TexturaAdhesiva, TexturaSoporteAdhesivo )
//          FactorRelleno       : 0 indica cinta agotada, y 1.0 cinta nueva.
//              Utilice un valor negativo para no dibujar la cinta del todo.
//          BanderaCortada      : "on" dibuja la cinta puesta en el cortador metalico,
//              "off" dibuja la cinta enrollada, sin ubicar en el cortador.
//          DiametroDespachador     : Medida fundamental del despachador. El alto
//              sin las patillas inferiores. 
//              Valor por defecto 54.5*L.
//          AnchoDespachador        : Ancho en Z del despachador.
//              Valor por defecto DiametroDespachador/3.
//          DiametroInternoCinta    : Diametro del carrete de cinta.
//              Valor por defecto DiametroDespachador/3.
//          DiametroAdhesivoMenor   : Diametro menor del material adhesivo.
//              Valor por defecto 26.33*L.
//          DiametroAdhesivoMayor   : Diametro mayor del mayor adhesivo 
//              (con FactorRelleno 1.0).
//              Valor por defecto 36.33*L.
//          AnchoAdhesivo           : Ancho de la cinta.
//              Valor por defecto 13.62*L.
//          GruesoPlastico          : Grueso de las laminas de plastico.
//              Valor por defecto 1*L.
//          GruesoFilo              : Grueso del filo.
//              Valor por defecto GruesoPlastico/5.
//          TotalDientes            : Total de dientes del filo.
//              Valor por defecto 20.
//          TexturaPrincipal        : Textura principal del dispensador.
//              Valor por defecto DUCA_TexturaPrincipal.
//          TexturaMetalica         : Textura de la laminilla cortante.      
//              Valor por defecto DUCA_TexturaMetalica.
//          TexturaAdhesiva         : Textura de la cinta.
//              Valor por defecto DUCA_TexturaAdhesiva.
//          TexturaSoporteAdhesivo  : Textura del carrete que soporta la cinta.
//              Valor por defecto DUCA_TexturaSoporteAdhesivo.
//
//  El dispensador de cinta se encuentra entre las siguientes dimensiones:
//      Minimo      = <  -27,    0,   -9 >*L
//      Maximo      = <  +42,  +56,   +9 >*L
//      Minimo      = < -DiametroDespachador/2, 0, -AnchoDespachador/2 >
//      Maximo      = < +23*DiametroDespachador/50, +DiametroDespachador+GruesoPlastico, 
//                                  +AnchoDespachador/2 >
//  Es casi simetrico con respectro al plano XY. El centro del carrete sobre el eje Y.
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores.  
//  #declare DUCA_DefectoTexturaPrincipal  
//      Textura principal del dispensador.
//  #declare DUCA_DefectoTexturaMetalica
//      Textura de la laminilla cortante.
//  #declare DUCA_DefectoTexturaAdhesiva
//      Textura de la cinta.
//  #declare DUCA_DefectoTexturaSoporteAdhesivo
//      Textura del carrete que soporta la cinta.
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es default)   
//  #declare DUCA_TransformDispensadorZP    = transform { }
//      Permite abrir el dispensador, al desplazar su zona Z+.
//  #declare DUCA_TransformDispensadorZN    = transform { }
//      Permite abrir el dispensador, al desplazar su zona Z-.
//  #declare DUCA_TransformCinta            = transform { }
//      Permite un desplazamiento adicional a la cinta de recarga.
//  #declare DUCA_FactorAbertura            = 1.0;
//      Sirve para cambiar el tamano de la abertura para empujar la cinta con los dedos.
//      Se ha observado que la abertura podria quedar mal ubicada al cambiar los
//      parametros por defecto. Este factor sirve para mitigar el problema.
//  #declare DUCA_TexturaPrincipal          = 
//                  texture  { DUCA_DefectoTexturaPrincipal         }  
//      Textura principal del dispensador.                         
//  #declare DUCA_TexturaMetalica           =
//                  texture  { DUCA_DefectoTexturaMetalica          }
//      Textura de la laminilla cortante.
//  #declare DUCA_TexturaAdhesiva           =
//                  texture  { DUCA_DefectoTexturaAdhesiva          }
//      Textura de la cinta.
//  #declare DUCA_TexturaSoporteAdhesivo    =
//                  texture  { DUCA_DefectoTexturaSoporteAdhesivo   }
//      Textura del carrete que soporta la cinta.
//       
//  Para colocarlo simplemente
//  #include "DUCA.inc" 
//  object { DUCA_Cinta( 1.0, on ) }
//                                  
//  Ejemplo con la macro detallada, mismo objeto default
//  #include "DUCA.inc"   
//  object                       {
//      DUCA_DispensadorUniversalCintaAdhesiva( 1.0, on,
//              0.0545, 0.0545/3, 0.0545/3, 0.02633, 0.03633,
//              0.01362, 0.001, 0.001/5, 20,
//              DUCA_TexturaPrincipal, DUCA_TexturaMetalica,
//              DUCA_TexturaAdhesiva, DUCA_TexturaSoporteAdhesivo )
//  }
//        
//  Con modificadores
//  #include "DUCA.inc"
//  #include "textures.inc"
//  #declare DUCA_TexturaPrincipal   = texture { PinkAlabaster } 
//  object        { DUCA_Cinta( 1.0, on ) }
//
#declare DUCA_L                         = 0.001;

#declare DUCA_TransformDispensadorZP    = transform { }
#declare DUCA_TransformDispensadorZN    = transform { }  
#declare DUCA_TransformCinta            = transform { }  

#declare DUCA_FactorAbertura            = 1.0;

#declare DUCA_DefectoTexturaPrincipal   =
  texture                               {
    pigment                             {    
      color White  transmit 0.75
    }
  }

#ifndef ( DUCA_TexturaPrincipal )
  #declare DUCA_TexturaPrincipal        = DUCA_DefectoTexturaPrincipal
#end  // #ifndef ( DUCA_TexturaPrincipal )

#declare DUCA_DefectoTexturaMetalica   =
  texture                               {
    pigment                             {
      color Silver
    }
  }

#ifndef ( DUCA_TexturaMetalica )
  #declare DUCA_TexturaMetalica         = DUCA_DefectoTexturaMetalica
#end  // #ifndef ( DUCA_TexturaMetalica )

#declare DUCA_DefectoTexturaAdhesiva    =
  texture                               {
    pigment                             {
      color ( Yellow+White )/2  transmit 0.50
    }
  }

#ifndef ( DUCA_TexturaAdhesiva )
  #declare DUCA_TexturaAdhesiva         = DUCA_DefectoTexturaAdhesiva
#end  // #ifndef ( DUCA_TexturaAdhesiva )

#declare DUCA_DefectoTexturaSoporteAdhesivo     =
  texture                               {
    pigment                             {
      color White
    }
  }

#ifndef ( DUCA_TexturaSoporteAdhesivo )
  #declare DUCA_TexturaSoporteAdhesivo  = DUCA_DefectoTexturaSoporteAdhesivo
#end  // #ifndef ( DUCA_TexturaSoporteAdhesivo )

#macro DUCA_DispensadorUniversalCintaAdhesiva( FactorRelleno, BanderaCortada,
          DiametroDespachador, AnchoDespachador, DiametroInternoCinta,
          DiametroAdhesivoMenor, DiametroAdhesivoMayor, AnchoAdhesivo,
          GruesoPlastico, GruesoFilo, TotalDientes,
          TexturaPrincipal, TexturaMetalica,
          TexturaAdhesiva, TexturaSoporteAdhesivo )
  merge                                 {      
    #local C                            = 0;
    // Laterales Despachador
    #while ( C < 2 )
      merge                             {
        // Comun laterales
        difference                      {
          merge                         {
            cylinder                    {
              0, AnchoDespachador/2*z,
              DiametroDespachador/2-AnchoDespachador/5
            }
            difference                  {
              torus                       {
                DiametroDespachador/2-AnchoDespachador/5,
                AnchoDespachador/5
                rotate            90*x
                translate         ( AnchoDespachador/2-AnchoDespachador/5 )*z
              }
              torus                       {
                DiametroDespachador/2-AnchoDespachador/5,
                AnchoDespachador/5-GruesoPlastico
                rotate            90*x
                translate         ( AnchoDespachador/2-AnchoDespachador/5 )*z
              }
              plane                     {
                z, AnchoDespachador/2-AnchoDespachador/5
              }
              plane                     {
                y, 0
              }
            }
            difference                  {
              cylinder                    {
                0, +3*AnchoDespachador/10*z, DiametroDespachador/2
              }
              plane                     {
                y, 0
              }
            }
            box                         {
              < -DiametroDespachador/2+AnchoDespachador/5,
                -DiametroDespachador/6, +AnchoDespachador/2 >,
              < +5*DiametroDespachador/12, 0,
                +AnchoDespachador/2-GruesoPlastico >
            }
            box                         {
              < -DiametroDespachador/6,
                -DiametroDespachador/6, +AnchoDespachador/2 >,
              < +5*DiametroDespachador/12,
                -DiametroDespachador/2+AnchoDespachador/5,
                +AnchoDespachador/2-GruesoPlastico >
            }
            cylinder                                    {
              AnchoDespachador/2*z,
              ( AnchoDespachador/2-GruesoPlastico )*z,
              DiametroDespachador/3-AnchoDespachador/5
              translate  <-1,-1,0>*DiametroDespachador/6
            }
            difference                                  {
              cylinder                                    {
                0, -DiametroDespachador/6*y, AnchoDespachador/5
              }
              cylinder                                    {
                +DiametroDespachador*z, -DiametroDespachador/3*y, AnchoDespachador/5
                -GruesoPlastico
              }
              plane                                     {
                -x, 0
              }
              plane                                     {
                z, 0
              }
              translate +( AnchoDespachador/2-AnchoDespachador/5 )*z
                        -( DiametroDespachador/2-AnchoDespachador/5 )*x
            }
            box                                         {
              < 0, -DiametroDespachador/6, 0 >,
              < +GruesoPlastico, 0, 3*AnchoDespachador/10 >
              translate         -DiametroDespachador/2*x
            }
            difference                                  {
              torus                                     {
                DiametroDespachador/3-AnchoDespachador/5,
                AnchoDespachador/5
                rotate                  90*x
              }
              torus                                     {
                DiametroDespachador/3-AnchoDespachador/5,
                AnchoDespachador/5-GruesoPlastico
                rotate                  90*x
              }
              cylinder                                  {
                -AnchoDespachador*z, AnchoDespachador*z,
                DiametroDespachador/3-AnchoDespachador/5
              }
              plane                                     {
                z, 0
              }
              plane                                     {
                -x, 0
              }
              translate  <-1,-1,0>*DiametroDespachador/6
              translate +( AnchoDespachador/2-AnchoDespachador/5 )*z
            }
            difference                                  {
              cylinder                                  {
                0, +( AnchoDespachador/2-AnchoDespachador/5 )*z,
                DiametroDespachador/3
              }
              cylinder                                  {
                -AnchoDespachador*z, +AnchoDespachador*z,
                DiametroDespachador/3-GruesoPlastico
              }
              plane                                     {
                -y, 0
              }
              plane                                     {
                -x, 0
              }
              translate  <-1,-1,0>*DiametroDespachador/6
            }
            difference                          {
              merge                             {
                difference                      {
                  cylinder                            {
                    -DiametroDespachador/6*x,
                    +5*DiametroDespachador/12*x,
                    AnchoDespachador/5
                  }
                  plane         { z, 0 }
                }
                
                box                             {
                  < -DiametroDespachador/6, 0, 0 >
                  < -DiametroDespachador/6+2*GruesoPlastico,
                  -AnchoDespachador/5, +AnchoDespachador/5 >
                }
                difference                      {
                  merge                         {
                    cylinder                        {
                      -( AnchoDespachador/2-AnchoDespachador/5 )*z,
                      +AnchoDespachador/5*z, GruesoPlastico
                      translate
                            +( -DiametroDespachador/6+GruesoPlastico )*x
                    }
                    cylinder                        {
                      -( AnchoDespachador/2-AnchoDespachador/5 )*z,
                      +AnchoDespachador/5*z, GruesoPlastico
                      translate
                            +( 5*DiametroDespachador/12-GruesoPlastico )*x
                    }
                  }
                  plane                         {
                    -y, 0
                  }
                  translate     -AnchoDespachador/5*y
                }
                box                             {
                  < +5*DiametroDespachador/12, 0, 0 >
                  < +5*DiametroDespachador/12-2*GruesoPlastico,
                  -AnchoDespachador/5, +AnchoDespachador/5 >
                }
              }
              cylinder                            {
                -DiametroDespachador*x,
                +DiametroDespachador*x,
                AnchoDespachador/5-GruesoPlastico
              }
              plane                             {
                -y, 0
              }
              translate ( -DiametroDespachador/2+AnchoDespachador/5 )*y
                        +( AnchoDespachador/2-AnchoDespachador/5 )*z
            }
            box                                 {
              < -DiametroDespachador/6, -DiametroDespachador/2, 0 >,
              < +5*DiametroDespachador/12,
                -DiametroDespachador/2+GruesoPlastico,
                AnchoDespachador/2-AnchoDespachador/5 >
            }
            difference                          {
              cylinder                            {
                AnchoDespachador/2*z,
                ( AnchoDespachador/2-GruesoPlastico )*z,
                7*DiametroDespachador/20-AnchoDespachador/5
              }
              plane                             {
                x, 0
              }
              translate < 5*DiametroDespachador/12,
                        -3*DiametroDespachador/20, 0 >
            }
            difference                          {
              torus                             {
                7*DiametroDespachador/20-AnchoDespachador/5,
                AnchoDespachador/5
                rotate          90*x
              }
              cylinder                          {
                -AnchoDespachador*z, +AnchoDespachador*z
                7*DiametroDespachador/20-AnchoDespachador/5
              }
              torus                             {
                7*DiametroDespachador/20-AnchoDespachador/5,
                AnchoDespachador/5-GruesoPlastico
                rotate          90*x
              }
              plane                             {
                x, 0
              }
              plane                             {
                z, 0
              }
              translate < 5*DiametroDespachador/12,
                        -3*DiametroDespachador/20,
                        +AnchoDespachador/2-AnchoDespachador/5 >
            }
            difference                          {
              cylinder                          {
                0, ( AnchoDespachador/2-AnchoDespachador/5 )*z
                7*DiametroDespachador/20
              }
              cylinder                          {
                -AnchoDespachador/2*z, AnchoDespachador/2*z
                7*DiametroDespachador/20-GruesoPlastico
              }
              plane                             {
                x, 0
              }
              translate < 5*DiametroDespachador/12,
                        -3*DiametroDespachador/20, 0 >
            }
            box                                 {
              < 23*DiametroDespachador/30, +GruesoPlastico, 0 >,
              < DiametroDespachador/2, 0, AnchoDespachador/2 >
              translate         -3*DiametroDespachador/20*y
            }
          }
          cylinder                    {
            -AnchoDespachador/2*z, ( AnchoDespachador/2-GruesoPlastico )*z,
            1.001*( DiametroDespachador/2-AnchoDespachador/5 )
          }
          cylinder                    {
            -AnchoDespachador/2*z, +1.001*3*AnchoDespachador/10*z,
            DiametroDespachador/2-GruesoPlastico
          }
          cylinder                    {
            -AnchoDespachador*z, AnchoDespachador*z,
            DiametroInternoCinta/2
          }
          cylinder                    {
            -AnchoDespachador*z, AnchoDespachador*z,
            DiametroInternoCinta*DUCA_FactorAbertura/2
            translate           DiametroDespachador/2*x
          }
          box                           {
            < 0, -DiametroInternoCinta/2*DUCA_FactorAbertura, -AnchoDespachador >,
            < DiametroDespachador, +DiametroInternoCinta/2*DUCA_FactorAbertura,
              AnchoDespachador >
            rotate              60*z
            translate           DiametroDespachador/2*x
          }
        }
        merge                             {
          torus                           {
            DiametroInternoCinta/2+2*GruesoPlastico
            GruesoPlastico
            rotate                90*x
          }
          intersection                            {
            torus                           {
              DiametroInternoCinta/2
              2*GruesoPlastico
              rotate                90*x
            }
            cylinder                            {
              -GruesoPlastico*z, 3*GruesoPlastico*z,
              DiametroInternoCinta/2
            }
            plane                       {
              -z, 0
            }
            translate           -GruesoPlastico*z
          }
          translate    ( AnchoDespachador/2-GruesoPlastico )*z
        }
        // #END Comun Laterales
        #if ( C = 0 )
          difference                    {
            cylinder                      {
              ( AnchoDespachador/2-2*GruesoPlastico )*z,
              -( AnchoDespachador/2-2*GruesoPlastico )*z,
              DiametroInternoCinta/2-0.05*GruesoPlastico
            }
            cylinder                      {
              -AnchoDespachador*z, AnchoDespachador*z,
              DiametroInternoCinta/2-GruesoPlastico
            }
          }
          transform              DUCA_TransformDispensadorZP

        #else  // #else ( C = 0 )
          difference                    {
            cylinder                      {
              ( AnchoDespachador/2-2*GruesoPlastico )*z,
              -( AnchoDespachador/2-2*GruesoPlastico )*z,
              DiametroInternoCinta/2-1.05*GruesoPlastico
            }
            cylinder                      {
              -AnchoDespachador*z, AnchoDespachador*z,
              DiametroInternoCinta/2-2*GruesoPlastico
            }
          }
          difference                            {
            merge                               {
              box                               {
                < 0, 0, -AnchoDespachador/2+2*GruesoPlastico >,
                < -GruesoPlastico, +9*DiametroDespachador/48,
                  +AnchoDespachador/2-2*GruesoPlastico >
              }
              merge                             {
                box                               {
                  < 0, 0, -AnchoDespachador/2+3*GruesoPlastico >,
                  < -GruesoFilo, +9*DiametroDespachador/48,
                    +AnchoDespachador/2-3*GruesoPlastico >
                    
                }
                #local AnchoDiente              =
                  ( AnchoDespachador-6*GruesoPlastico )/TotalDientes;
                #local D                        = 0;
                #while ( D < TotalDientes )
                  box                             {
                    < 0, AnchoDiente/sqrt( 8 ), AnchoDiente/sqrt( 8 ) >,
                    < -GruesoFilo, -AnchoDiente/sqrt( 8 ),
                      -AnchoDiente/sqrt( 8 ) >
                    rotate                45*x
                    scale  <1,0.01*DiametroDespachador/AnchoDiente,1>
                    translate     9*DiametroDespachador/48*y
                    translate     ( D-( TotalDientes-1 )/2 )*AnchoDiente*z
                  }
                  #local D                      = D+1;
                #end  // #while ( D < TotalDientes )
                texture                         {
                  TexturaMetalica
                }
                translate               -GruesoPlastico*x
              }
            }
            translate                   -3*DiametroDespachador/20*y
                        +23*DiametroDespachador/30*x-GruesoPlastico*x
          }
          scale                       <1,1,-1>
          transform            DUCA_TransformDispensadorZN
        #end   // #else ( C = 0 )
      }
      #local C                          = C+1;
    #end  // #while ( C < 2 )
    // END Laterales Despachador
    // Recarga Adhesiva
    #if ( FactorRelleno >= 0 )
      merge                               {
        #local DiametroMax              = DiametroAdhesivoMenor+
                FactorRelleno*( DiametroAdhesivoMayor-DiametroAdhesivoMenor );
        merge                             {
          difference                      {
            cylinder                        {
              -AnchoAdhesivo/2*z, +AnchoAdhesivo/2*z,
              DiametroInternoCinta/2+GruesoPlastico/2
            }
            cylinder                        {
              -AnchoAdhesivo*z, +AnchoAdhesivo*z,
              DiametroInternoCinta/2
            }
          }
          difference                      {
            cylinder                        {
              -GruesoPlastico*z, +GruesoPlastico*z,
              DiametroAdhesivoMenor/2
            }
            cylinder                        {
              -AnchoAdhesivo*z, +AnchoAdhesivo*z,
              DiametroInternoCinta/2
            }
          }
          difference                      {
            cylinder                        {
              -( AnchoAdhesivo/2+GruesoPlastico )*z,
              +( AnchoAdhesivo/2+GruesoPlastico )*z,
              DiametroAdhesivoMenor/2
            }
            cylinder                        {
              -AnchoAdhesivo*z, +AnchoAdhesivo*z,
              DiametroAdhesivoMenor/2-GruesoPlastico/2
            }
          }        
          texture                         {
            TexturaSoporteAdhesivo
          }
        }
        difference                        {
          cylinder                        {
            -AnchoAdhesivo/2*z, +AnchoAdhesivo/2*z,
            DiametroMax/2
          }
          cylinder                        {
            -AnchoAdhesivo*z, +AnchoAdhesivo*z,
            DiametroAdhesivoMenor/2
          }
        }
        #if ( BanderaCortada )
          #local P1     = < DiametroMax/2, 0 >;
          #local P2     = < 23*DiametroDespachador/30-2*GruesoPlastico,
                                DiametroDespachador/20 >;
          prism                                 {
            bezier_spline
            -AnchoAdhesivo/2, +AnchoAdhesivo/2,
            8,
            P1,
            P1-DiametroDespachador*v/8,
            P2+DiametroDespachador*<-1,-1>/8,
            P2,
            P2,
            P2+DiametroDespachador*<-1,-1.001>/8,
            P1-DiametroDespachador*v/8
            P1
            rotate              -90*x
          }
        #end  // #if ( BanderaCortada )
        texture                           {
          TexturaAdhesiva
        }
        transform                           DUCA_TransformCinta
      }
    #end  // #if ( FactorRelleno >= 0 )
    // END RecargaAdhesiva
    texture                             {
      TexturaPrincipal
    } 
    translate               ( DiametroDespachador/2+GruesoPlastico )*y
  }
#end  // #macro DUCA_DispensadorUniversalCintaAdhesiva

#macro DUCA_Cinta( FactorRelleno, BanderaCortada )
  object                                {
    #local L                            = DUCA_L;
    #local DiametroDespachador          = 54.50*L;
    #local AnchoDespachador             = DiametroDespachador/3;
    #local DiametroInternoCinta         = DiametroDespachador/3;
    #local DiametroAdhesivoMenor        = 26.33*L;
    #local DiametroAdhesivoMayor        = 36.33*L;
    #local AnchoAdhesivo                = 13.62*L;
    #local GruesoPlastico               = 1*L;
    #local GruesoFilo                   = GruesoPlastico/5;
    #local TotalDientes                 = 20;
    DUCA_DispensadorUniversalCintaAdhesiva
      ( FactorRelleno, BanderaCortada,
        DiametroDespachador, AnchoDespachador, DiametroInternoCinta,
        DiametroAdhesivoMenor, DiametroAdhesivoMayor, AnchoAdhesivo,
        GruesoPlastico, GruesoFilo, TotalDientes,
        DUCA_TexturaPrincipal, DUCA_TexturaMetalica,
        DUCA_TexturaAdhesiva, DUCA_TexturaSoporteAdhesivo )
  }
#end   // #macro DUCA_Cinta()
