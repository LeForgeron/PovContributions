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
//  RPPM RadiocomunicadorPortatilPersonalManual
//  El archivo dibuja un radiocomunicador de mano de corto alcance.
//  Posee una macro para modificar las caracteristicas principales, pero 
//  es muy poco flexible. Es compatible con POVRay 3.1.
//
//  La macro principal no tiene parametros.
//  #macro RPPM_Radiocomunicador()
//
//  La siguiente macro permite un mayor control sobre las caracteristicas.
//  #macro RPPM_RadiocomunicadorPortatilPersonalManual(
//              AltoFundamental, FrenteFundamental, GruesoFundamental,
//              FactorEnsanchamiento, FraccionAltoEnsanchamiento,  
//              AltoAntena, DiametroAntena,  
//              ArregloBotones, GIFBotones, FactorBoton,
//              MaterialPrincipal, MaterialBaseCaratula, 
//              MaterialAntena, MaterialPlastico,
//              MaterialPantalla, MaterialTransparente, MaterialBotones ) 
//          AltoFundamental                 : Alto de la radio sin antena. 
//              Valor por defecto 70*L.
//          FrenteFundamental               : Frente en X de la radio sin botones.
//              Valor por defecto 35*L.
//          GruesoFundamental               : Grueso en Z del cuerpo principal inferior.
//              Valor por defecto 21*L.
//          FactorEnsanchamiento            : Factor en que la seccion superior se 
//              ensancha respecto a la inferior.
//              Valor por defecto 1.15.           
//          FactorAltoEnsanchamiento        : Fraccion propia de AltoFundamental que
//              divide la seccion superior e inferior del cuerpo principal.
//              Valor por defecto 0.5.
//          AltoAntena                      : Alto de la antena.
//              Valor por defecto 40*L.
//          DiametroAntena                  : Diametro en la base de la antena.
//              Valor por defecto 11*L. 
//          ArregloBotones                  : Arreglo bidimensional de vectores 2D
//              con el formato array [TotalBotones][4]. Cada renglon definira
//              cuatro esquinas de un cuadrilatero. Las coordenadas deberan estar
//              contenidas en el dominio <-0.5,0>..<0.5,1> que son relativas al espacio
//              de dibujo, aunque el dominio
//              verdadero sera mucho menor pues debe caer en la zona de la placa delantera.
//              Los botones ocuparan el cuadrilatero en su totalidad
//              mas un borde determinado por FactorBotones.
//              Valor por defecto BMME_ArregloBotones.
//          GIFBotones                      : Archivo imagen GIF que se utiza para
//              etiquetar los botones. Utilice "" para ignorar este parametro.
//              El color de indice 0 se utiliza como color transparente.
//              Valor por defecto BMME_GIFBotones.
//          FactorBotones                   : Agrega un borde en exceso a los botones
//              definidos en ArregloBotones. Utiliza coordenadas relativas al espacio
//              disponible. Valor por defecto BMME_FactorBotones.
//          MaterialPrincipal               : Material principal del aparato.
//              Valor por defecto BMME_MaterialPrincipal.
//          MaterialBaseCaratula            : Material para la base de los botones.
//              Valor por defecto BMME_MaterialBaseCaratula.
//          MaterialAntena                  : Material para la antena.
//              Valor por defecto BMME_MaterialAntena.
//          MaterialPlastico                : Material para el borde plastico de la pantalla.
//              Valor por defecto BMME_MaterialPlastico.
//          MaterialPantalla                : Material para el fondo de pantalla.
//              Podria incluir un archivo de imagen para visualizacion.
//              Valor por defecto BMME_MaterialPantalla.
//          MaterialTransparente            : Material del vidrio que cubre la pantalla.
//              Valor por defecto BMME_MaterialTransparente.
//          MaterialBotones                 : Material de los botones.
//              Valor por defecto BMME_MaterialBotones. 
//
//  El radiocomunicador se encuentra contenido entre las siguientes coordenadas:
//      Minimo          = < -22,   0, -12 >*L
//      Maximo          = <  20, 110,  15 >*L
//  El radiocomunicador se dibuja con la pantalla hacia Z-, la antena hacia Y+ y
//  el boton de recepcion hacia X-. Descansa sobre el plano XZ.
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores. 
//  #declare RPPM_GIFBotones                        = "RPPM_IM1.gif"
//      Imagen utilizada por defecto como parametro GIFBotones, para
//      dibujar los botones del radiocomunicador.
//  #declare RPPM_FactorBotones                     = 0.035;                                                               
//      Se utiliza por defecto como parametro FactorBotones, que establece un borde
//      en exceso sobre los cuadrilateros definidos en ArregloBotones.                                                               
//  #declare RPPM_ArregloBotones                    = array [5][4]  
//      Arreglo de vectores 2D que se usa como parametro por defecto 
//      ArregloBotones. Que define cuadrilateros en coordenadas relativas
//      para dibujar los botones.
//  #declare RPPM_DefectoMaterialPrincipal               
//      Material principal del aparato.
//  #declare RPPM_DefectoMaterialBaseCaratula            
//      Material para la base de los botones.
//  #declare RPPM_DefectoMaterialAntena                  
//      Material para la antena.
//  #declare RPPM_DefectoMaterialPlastico                
//      Material para el borde plastico de la pantalla.
//  #declare RPPM_DefectoMaterialPantalla                
//      Material para el fondo de pantalla.
//      Podria incluir el texto aqui de alguna manera.
//  #declare RPPM_DefectoMaterialTransparente            
//      Material del vidrio que cubre la pantalla.
//  #declare RPPM_DefectoMaterialBotones                 
//      Material de los botones.
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es el valor por defecto). 
//  #declare RPPM_MaterialPrincipal                 =
//                  { RPPM_DefectoMaterialPrincipal               }
//      Material principal del aparato.
//  #declare RPPM_MaterialBaseCaratula              =
//                  { RPPM_DefectoMaterialBaseCaratula            }
//      Material para la base de los botones.
//  #declare RPPM_MaterialAntena                    =
//                  { RPPM_DefectoMaterialAntena                  }  
//      Material para la antena.
//  #declare RPPM_MaterialPlastico                  =
//                  { RPPM_DefectoMaterialPlastico                }
//      Material para el borde plastico de la pantalla.
//  #declare RPPM_MaterialPantalla                  =
//                  { RPPM_DefectoMaterialPantalla                }
//      Material para el fondo de pantalla.
//      Podria incluir el texto aqui de alguna manera.
//  #declare RPPM_MaterialTransparente              =
//                  { RPPM_DefectoMaterialTransparente            }
//      Material del vidrio que cubre la pantalla.
//  #declare RPPM_MaterialBotones                   =
//                  { RPPM_DefectoMaterialBotones                 }
//      Material de los botones.
//       
//  Para colocarlo simplemente
//  #include "RPPM.inc" 
//  object { RPPM_Radiocomunicador(  ) }
//                                  
//  Ejemplo con la macro detallada, mismo objeto por defecto
//  #include "RPPM.inc"   
//  object                       {
//    RPPM_RadiocomunicadorPortatilPersonalManual( 0.070, 0.035, 
//                0.021, 1.15, 0.5, 0.040, 0.011,
//                RPPM_ArregloBotones, RPPM_GIFBotones, RPPM_FactorBotones,
//                RPPM_MaterialPrincipal, RPPM_MaterialBaseCaratula,
//                RPPM_MaterialAntena, RPPM_MaterialPlastico,
//                RPPM_MaterialPantalla, RPPM_MaterialTransparente,
//                RPPM_MaterialBotones )
//  }
//        
//  Con modificadores
//  #include "RPPM.inc"
//  #include "textures.inc"
//  #declare RPPM_MaterialPrincipal         = material { texture { PinkAlabaster } } 
//  object        { RPPM_Radiocomunicador(  ) }
//
#include "colors.inc"
#include "textures.inc"

#declare RPPM_L                     = 0.001;
     
#if ( version < 3.2 )
  #ifndef( RPPM_POV3_1 )
    #declare RPPM_POV3_1        = on;
  #end
#else
  #ifndef( RPPM_POV3_1 )
    #declare RPPM_POV3_1        = off;
  #end    
#end
          
#declare RPPM_DefectoMaterialPrincipal              =
  material                                          {
    texture                                         {
      Cork  
      normal                                        {
        onion
        turbulence          0.1
        scale   0.1
      }
    }
    texture                                         {
      pigment                                       {
        color Gray05 transmit 0.025
      }
    }
  }
  

#ifndef ( RPPM_MaterialPrincipal )
  #declare RPPM_MaterialPrincipal                   =
                material  { RPPM_DefectoMaterialPrincipal }
#end  //  #ifndef ( RPPM_MaterialPrincipal )
     
#declare RPPM_DefectoMaterialAntena                 =
  material                                          {
    texture                                         {
      Cork  
      normal                                        {
        onion
        turbulence          0.1
        scale   0.1
      }
    }
    texture                                         {
      pigment                                       {
        color Gray05 transmit 0.01
      }
    }
  }
  

#ifndef ( RPPM_MaterialAntena )
  #declare RPPM_MaterialAntena                   =
                material  { RPPM_DefectoMaterialAntena }
#end  //  #ifndef ( RPPM_MaterialAntena )
     
#declare RPPM_DefectoMaterialBaseCaratula           =
  material                                          {
    texture                                         {
      Cork  
      normal                                        {
        onion
        turbulence          0.1
        scale   0.1
      }
    }
    texture                                         {
      pigment                                       {
        color Gray05 transmit 0.05
      }
      finish                                        {
        phong   0.1
        phong_size  10
        metallic
      }
    }
  }
  

#ifndef ( RPPM_MaterialBaseCaratula )
  #declare RPPM_MaterialBaseCaratula                =
                material  { RPPM_DefectoMaterialBaseCaratula }
#end  //  #ifndef ( RPPM_MaterialBaseCaratula )
                      
#declare RPPM_DefectoMaterialPlastico               =
  material                                          {
    texture                                         {
      pigment                                       {
        color Gray05 
      }
      normal                                        {
        bumps
      }
      finish                                        {
        phong   0.9
        phong_size  100
        metallic
      }
    }
  }
  

#ifndef ( RPPM_MaterialPlastico )
  #declare RPPM_MaterialPlastico                =
                material  { RPPM_DefectoMaterialPlastico }
#end  //  #ifndef ( RPPM_MaterialPlastico )   

#declare RPPM_DefectoMaterialPantalla               =
  material                                          {
    texture                                         {
      pigment                                       {
        color Aquamarine
         
      }
      finish                                        {
        phong   0.9
        phong_size 40
        metallic
      }
    }
  }
  

#ifndef ( RPPM_MaterialPantalla )
  #declare RPPM_MaterialPantalla                =
                material  { RPPM_DefectoMaterialPantalla }
#end  //  #ifndef ( RPPM_MaterialPantalla )  

#declare RPPM_DefectoMaterialTransparente               =    
#if ( RPPM_POV3_1 )   
  material                                          {
    texture         { Glass3 }
    interior {ior 1.5}
  }
#else  //  #else ( RPPM_POV3_1 )
  material                                          {
    M_Glass3
  }  
#end   //  #else ( RPPM_POV3_1 )
  

#ifndef ( RPPM_MaterialTransparente )
  #declare RPPM_MaterialTransparente                =
                material  { RPPM_DefectoMaterialTransparente }
#end  //  #ifndef ( RPPM_MaterialTransparente )     
                     
#declare RPPM_DefectoMaterialBotones                 =
  material                                          {
    texture                                         {
      Cork  
      normal                                        {
        onion
        turbulence          0.1
        scale   0.1
      }
    }
    texture                                         {
      pigment                                       {
        color Gray05 transmit 0.01
      }
    }
  }
 
#ifndef ( RPPM_MaterialBotones )
  #declare RPPM_MaterialBotones                     =
                material  { RPPM_DefectoMaterialBotones }
#end  //  #ifndef ( RPPM_MaterialBotones )     
                     

#declare RPPM_FactorBotones                         = 0.035;                                                               
                                                               
#declare RPPM_ArregloBotones                        = array [5][4]  
    { 
      { <-0.080, 0.430 >, <-0.150, 0.480 >, < 0.150, 0.480 >, < 0.080, 0.430> }, 
      { <-0.250, 0.430 >, <-0.400, 0.530 >, <-0.250, 0.480 >, <-0.150, 0.430> },
      { <-0.150, 0.330 >, <-0.200, 0.380 >, <-0.050, 0.380 >, <-0.050, 0.330> },
      { < 0.150, 0.330 >, < 0.200, 0.380 >, < 0.050, 0.380 >, < 0.050, 0.330> },
      { < 0.250, 0.430 >, < 0.400, 0.530 >, < 0.250, 0.480 >, < 0.150, 0.430> }
    }                       
    
#declare RPPM_GIFBotones                            = "RPPM_IM1.gif"

#macro RPPM_CuadriBoton( U0, U1, U2, U3, FactorR )
  union                                         {     
    #local PU0                                  = < U0.u, U0.v, 0 >;
    #local PU1                                  = < U1.u, U1.v, 0 >;
    #local PU2                                  = < U2.u, U2.v, 0 >;
    #local PU3                                  = < U3.u, U3.v, 0 >;
    prism                                       {
      -FactorR/2, FactorR/2,
      4,
      U0, U1, U2, U3
      rotate            -90*x
    } 
    sphere                                      {
      U0, FactorR/2
    }
    sphere                                      {
      U1, FactorR/2
    }
    sphere                                      {
      U2, FactorR/2
    }
    sphere                                      {
      U3, FactorR/2
    }
    cylinder                                    {
      U0, U1, FactorR/2
    }
    cylinder                                    {
      U1, U2, FactorR/2
    }
    cylinder                                    {
      U2, U3, FactorR/2
    }
    cylinder                                    {
      U3, U0, FactorR/2
    }     
    scale       <1,1,1/FactorR>
  }
#end  // #macro RPPM_CuadriBoton               
                                                                
#macro RPPM_RadiocomunicadorPortatilPersonalManual(
                AltoFundamental, FrenteFundamental, GruesoFundamental,
                FactorEnsanchamiento, FraccionAltoEnsanchamiento,  
                AltoAntena, DiametroAntena,  
                ArregloBotones, GIFBotones, FactorBoton,
                MaterialPrincipal, MaterialBaseCaratula, 
                MaterialAntena, MaterialPlastico,
                MaterialPantalla, MaterialTransparente,
                MaterialBotones )
  union                                 {  
    #local TotalBotones                 = dimension_size( ArregloBotones, 1 );
    //  Caratula Botones
    #local BaseCaratula                 =
      prism                             {
        cubic_spline
        0, 0.5,
        9, 
        <  0.450,  0.750 >,
        <  0.000,  0.950 >,
        < -0.450,  0.750 >,
        < -0.300,  0.200 >,
        <  0.000,  0.050 >,
        <  0.300,  0.200 >,
        <  0.450,  0.750 >,
        <  0.000,  0.950 >,
        < -0.450,  0.750 >
        rotate              -90*x
      }
    
    union                               {
      difference                        {  
        union                           {
          object                          {
            BaseCaratula   
            material                      {
              MaterialBaseCaratula
            }
          }  
          sphere                            {
            0, 1
            scale           < 0.40, 0.225, 0.02 >
            translate       -0.5*z+0.7*y
            material                        {
              MaterialPlastico
            }
          }
        }
        #local MaxFranja                    = 0.325;  
        #local DeltaTotalFranjas            = 0.3;
        #local TotalFranjas                 = 7;
        #local DeltaFranja                  = DeltaTotalFranjas/( 2*TotalFranjas+1 );
        #local C                            = 0;   
        cylinder                            {
          -0.45*z, -0.476*z, 1
          scale         <0.2, 0.6*DeltaTotalFranjas/2 ,1>
          translate         +( MaxFranja-DeltaTotalFranjas/2 )*y      
          material                           {
            MaterialPlastico
          }
        }
        #while ( C < TotalFranjas )
          box                               {
            < -1, 0, -0.475 >,
            < +1, -DeltaFranja, -0.7 >
            translate           ( MaxFranja-( 2*C+1 )*DeltaFranja )*y 
          }
          #local C                          = C+1;
        #end  //  #while ( C < TotalFranjas )
        superellipsoid                      { 
          < 0.7, 0.2 >
          scale         0.5
          material                          {
            MaterialPantalla
          }
          scale           < 0.40, 0.225, 0.1 >
          translate       -0.5*z+0.7*y
        }
        #local C                          = 0; 
        #while ( C < TotalBotones )
          object                          {
            RPPM_CuadriBoton( ArregloBotones[C][0], ArregloBotones[C][1],
                              ArregloBotones[C][2], ArregloBotones[C][3], FactorBoton )  
            scale  <1,1,0.05>                  
            translate             -0.5*z    
          }
          #local C                        = C+1;
        #end  //  #while ( C < TotalBotones )
      }  
      sphere                            {
        0, 0.975
        scale           < 0.40, 0.225, 0.02 >
        translate       -0.5*z+0.7*y
        material                        {
          MaterialTransparente
        }
      }   
      union                                 {
        #local C                          = 0; 
        #while ( C < TotalBotones )
          object                          {
            RPPM_CuadriBoton( ArregloBotones[C][0], ArregloBotones[C][1],
                              ArregloBotones[C][2], ArregloBotones[C][3], 0.8*FactorBoton )  
            scale  <1,1,0.1>                  
            translate             -0.5*z  
          }
          #local C                        = C+1;
        #end  //  #while ( C < TotalBotones )
        material     { MaterialBotones } 
        #if ( strcmp( GIFBotones, "" ) != 0 )
            material            { 
              texture         {
                pigment                         {
                  image_map                     {
                    gif GIFBotones 
                    transmit 0, 1
                  }                
                  translate             -0.5*x
                  scale             <1,0.52,1>              
                  translate         +0.11*y
                }  
                normal              {
                  bumps
                }
              }                    
            }
        #end  //  #if ( strcmp( GIFBotones, "" ) != 0 )
      }  
      scale             < FrenteFundamental, AltoFundamental, GruesoFundamental >
    }  
    //  END Caratula Botones 
    //  Antena
    union                                   {   
      #local FCAntena                       = 0.8;
      #local FBAntena                       = 1.1;  
      union                                 {
        sphere                                {
          0, FCAntena*DiametroAntena/2/FBAntena
          translate           ( AltoAntena-FCAntena*DiametroAntena/2/FBAntena )*y
        }  
        cone                                  {
          0, DiametroAntena/2/FBAntena,
          ( AltoAntena-FCAntena*DiametroAntena/2/FBAntena )*y,
              FCAntena*DiametroAntena/2/FBAntena
        }
        material                            {
          MaterialAntena
          scale          AltoAntena
        }
      }   
      cylinder                              {
        0, -( 1-FraccionAltoEnsanchamiento )*AltoFundamental*y,
        DiametroAntena/2
        matrix              <1,1,0,
                             0,1,0,
                             0,0,1,0,0,0>
      }  
      box                                   {
        < 0, 0, -DiametroAntena/2 >,
        < -FrenteFundamental/2+DiametroAntena/2, 
          -( 1-FraccionAltoEnsanchamiento )*AltoFundamental, +DiametroAntena/2 >
      }
      translate             AltoFundamental*y
                            +( FrenteFundamental/2-DiametroAntena/2 )*x
    }
    //  END Antena
    #local FP                           = 1.3; 
    difference                              {
      union                                 {
        difference                          {
          superellipsoid                      {
            < 0.3, 0.3 > 
          }
          plane                                 {
            -y, 0
          }  
          scale         < FrenteFundamental/2, FraccionAltoEnsanchamiento*AltoFundamental,
                            GruesoFundamental/2 >
          translate         FraccionAltoEnsanchamiento*AltoFundamental*y                  
        }  
        superellipsoid                      {
          < 0.7, 0.3 > 
          scale         < FrenteFundamental/2*FactorEnsanchamiento,
                            FP*( 1-FraccionAltoEnsanchamiento )*AltoFundamental/2,
                            GruesoFundamental/2 >
          translate         ( -FP*( 1-FraccionAltoEnsanchamiento )*AltoFundamental/2
                                    +AltoFundamental )*y                  
        }      
        //  Patillas
        union                      {
          box                           {
            < -0.4*FrenteFundamental, 0, -0.35*GruesoFundamental >,
            < -0.35*FrenteFundamental, 0.1*AltoFundamental, +0.35*GruesoFundamental >
          }
          box                           {
            < +0.4*FrenteFundamental, 0, -0.35*GruesoFundamental >,
            < +0.35*FrenteFundamental, 0.1*AltoFundamental, +0.35*GruesoFundamental >
          }
        }
        //  END Patillas
        //  Decoracion Lateral
        union                           {
          #local MinLateral             = 0.25;
          #local MaxLateral             = 0.85;
          #local TotalLateral           = 7; 
          #local DeltaLateral           = ( MaxLateral-MinLateral )/( 2*TotalLateral+1 );
          #local C                      = 0;
          #while ( C < TotalLateral )
            box                         {
              < -0.5, 0, -0.35>,
              < +0.5, DeltaLateral, +0.35 >
              translate         ( ( 2*C+1 )*DeltaLateral+MinLateral )*y 
            }
            #local C                    = C+1;
          #end 
          material                      {
            MaterialBaseCaratula
          } 
          scale  < FrenteFundamental, FraccionAltoEnsanchamiento*AltoFundamental,
                    GruesoFundamental >          
        }
        //  END Decoracion Lateral   
        //  Boton
        union                           { 
          sphere                        {
            0, 0.6
            scale   <1,0.2,1>
            translate       0.65*y
          }
          cylinder                      {
            0.2*y, 0.65*y, 0.6
          }
          sphere                        {
            0, 0.6
            scale   <1,0.2,1>
            translate       0.2*y
          }  
          #local TotalAros              = 8;
          #local C                      = 0;
          #while ( C < TotalAros )
            torus                       {
              0.6, 0.05 
              scale   <1,0.25,1>
              translate     ( 0.65-( 2*C+1.5 )*0.45/( 2*TotalAros+1 ) )*y
            }
            #local C                    = C+1;
          #end  // #while ( C < TotalAros )  
          material                      {
            MaterialBotones
          }
          scale         <0.5,1,1> 
          translate         -0.95*x*FactorEnsanchamiento/1.15  
          scale     < FrenteFundamental/2, ( 1-FraccionAltoEnsanchamiento )*AltoFundamental,
                            GruesoFundamental/2 >
          translate         FraccionAltoEnsanchamiento*AltoFundamental*y                  
        }
        //  END Boton
      }
      object                            {
        BaseCaratula
        scale             < FrenteFundamental, AltoFundamental, 1.05*GruesoFundamental >
      }  
    }  
    //  Clip
    union                               {
      #local AnguloClipR                = asin( GruesoFundamental/AltoFundamental/4 );
      cylinder                          {
        -0.35*FrenteFundamental*x, 0.35*FrenteFundamental*x, 0.2*GruesoFundamental
      }
      cylinder                          {
        -0.375*FrenteFundamental*x, 0.375*FrenteFundamental*x, 0.1*GruesoFundamental
      }
      cylinder                          {
        -0.325*FrenteFundamental*x, 0.325*FrenteFundamental*x, 0.05*GruesoFundamental
        translate       0.2*GruesoFundamental*y
      }
      cylinder                          {
        -0.325*FrenteFundamental*x, 0.325*FrenteFundamental*x, 0.025*GruesoFundamental
        translate       0.2*GruesoFundamental*z-0.6*AltoFundamental*y
      }
      box                               {
        < -0.35*FrenteFundamental, 0, 0.2*GruesoFundamental >,
        < +0.35*FrenteFundamental, -0.6*AltoFundamental, 0.175*GruesoFundamental >
      }
      rotate          AnguloClipR*x*180/pi
      translate         +0.5*GruesoFundamental*z+0.8*AltoFundamental*y
      material                          {
        MaterialPrincipal
      }
    }                
    //  END Clip      
    material                            {
      MaterialPrincipal    
      scale                 AltoFundamental/2
    }
  } 
#end  //  #macro RPPM_RadiocomunicadorPortatilPersonalManual()

#macro RPPM_Radiocomunicador()
  object                                {
    #local L                            = RPPM_L;
    #local AltoFundamental              = 70*L;
    #local FrenteFundamental            = 35*L;
    #local GruesoFundamental            = 21*L;  
    #local FactorEnsanchamiento         = 1.15;
    #local FraccionAltoEnsanchamiento   = 0.5; 
    #local AltoAntena                   = 40*L;
    #local DiametroAntena               = 11*L;
    RPPM_RadiocomunicadorPortatilPersonalManual(
                AltoFundamental, FrenteFundamental, GruesoFundamental,
                FactorEnsanchamiento, FraccionAltoEnsanchamiento,
                AltoAntena, DiametroAntena, 
                RPPM_ArregloBotones, RPPM_GIFBotones, RPPM_FactorBotones,
                RPPM_MaterialPrincipal, RPPM_MaterialBaseCaratula,
                RPPM_MaterialAntena, RPPM_MaterialPlastico,
                RPPM_MaterialPantalla, RPPM_MaterialTransparente,
                RPPM_MaterialBotones )
  }
#end  //  #macro RPPM_Radiocomunicador()