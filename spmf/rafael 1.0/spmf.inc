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
//  SPMF SelloProgramacionManualFecha
//  El archivo dibuja un modelo sencillo de sello para tinta con fecha ajustable.
//  Es muy poco flexible. Es compatible con POVRay 3.1.
//
//  La macro no tiene parametros.
//  #macro SPMF_Sello()
//
//  El sello se encuentra contenido entre las siguientes coordenadas:
//      Minimo          = < -17, -32, -10 >*L
//      Maximo          = <  30,  24,   9 >*L
//  El mango se dibuja orientado en el eje hacia Y+, la palanca para tipo de
//  formulario se ubica hacia X-.
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores. 
//  #declare SPMF_DefectoTexturaPrincipal            
//      Textura principal del sello.
//  #declare SPMF_DefectoTexturaPlastica
//      Textura del mango y algunos cilindros de seleccion.              
//  #declare SPMF_DefectoTexturaCorcho            
//      Textura de los rodillos de seleccion.
//  #declare SPMF_DefectoTexturaDecorativa                 
//      Textura decorativa del mango superior.
//  #declare SPMF_DefectoTexturaMensajes              
//      Textura de los mensajes a imprimir.
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es el valor por defecto). 
//  En general los indices comienzan en cero y sera valido utilizar fracciones 
//  impropias en vez de indices enteros para los selectores.   
//  #declare SPMF_AnguloTrianguloGiro               = 40;
//      Gira el selector triangular de formulario.
//  #declare SPMF_ListaMensajesMes                  = array [12]
//      Las etiquetas de mes en tres letras, comenzando en enero.
//      Podria modificarse para traduccion. 
//  #declare SPMF_DeltaMes                          = 8;
//      Permite elegir un numero de mes para impresion. 
//  #declare SPMF_ListaMensajesAno                  = array [12]  
//      Lista para los anos. En el futuro cercano sera necesario modificar esta lista, 
//      pues el modelo original acaba en el 2025 como eleccion 11.
//  #declare SPMF_DeltaAno                          = 4;
//      Permite elegir un ano para impresion. El numero 0 corresponde al 2014.
//  #declare SPMF_ListaMensajesDiaUnidades          = array [12] 
//      Lista de la unidad del dia de mes. El indice 0 corresponde a unidad 0.
//  #declare SPMF_DeltaDiaUnidades                  = 9;
//      Permite elegir las unidades del dia de mes. El indice 0 corresponde a indice 0.
//  #declare SPMF_ListaMensajesDiaDecenas           = array [12]
//      Lista de las decenas para el dia de mes.
//  #declare SPMF_DeltaDiaDecenas                   = 0;
//      Permite elegir las decenas para el dia de mes. El indice 0 corresponde a decena 0.
//  #declare SPMF_ListaMensajesFormulario           = array [12]
//      Contiene las posibles alternativas de formulario. La lista definida concuerda con
//      la imagen GIF suministrada "SPMF_IM1.gif", pero el indice inicia en 0.
//  #declare SPMF_DeltaFormulario                   = 2; 
//      Permite elegir el mensaje.  
//  #declare SPMF_ListaMensajesIndice               = array [12]     
//      Los mensajes de formulario se encuentran numerados aqui. Los numeros rotan en forma
//      simultanea.
//  #declare SPMF_BanderaGIF                        = on;
//      Si "on" se aplica una imagen GIF como indice selector.
//  #declare SPMF_GIFIndice                         = "SPMF_IM1.gif"
//      Nombre de la imagen GIF a aplicar como indice.
//  #declare SPMF_CustomTexturaGIF                  = texture { }
//      Si se declara esta textura se coloca encima de la textura GIF de indice.
//      Esto permite agregar otros efectos al GIF.
//  #declare SPMF_TexturaPrincipal              =
//                      { SPMF_DefectoTexturaPrincipal              }    
//      Textura principal del sello.
//  #declare SPMF_TexturaPlastica               =
//                      { SPMF_DefectoTexturaPlastica               }
//      Textura del mango y algunos cilindros de seleccion.              
//  #declare SPMF_TexturaCorcho                 =
//                      { SPMF_DefectoTexturaCorcho                 }
//      Textura de los rodillos de seleccion.
//  #declare SPMF_TexturaDecorativa             =
//                      { SPMF_DefectoTexturaDecorativa             }         
//      Textura decorativa del mango superior.
//  #declare SPMF_TexturaMensajes               =
//                      { SPMF_DefectoTexturaMensajes               }
//      Textura de los mensajes a imprimir.
//       
//  Para colocarlo simplemente
//  #include "SPMF.inc" 
//  object { SPMF_Sello(  ) }
//                                  
//        
//  Con modificadores
//  #include "SPMF.inc"
//  #include "textures.inc"
//  #declare SPMF_TexturaPrincipal          = PinkAlabaster  
//  #declare SPMF_AnguloTrianguloGiro       = 200;
//  object        { SPMF_Sello(  ) }
//
#include "metals.inc"
#include "textures.inc"

#declare SPMF_L                 = 0.001;      

#declare SPMF_AnguloTrianguloGiro       = 40;

#declare SPMF_DefectoTexturaPrincipal           =
  texture                                       {
    T_Chrome_2A
  }

#ifndef ( SPMF_TexturaPrincipal )
  #declare SPMF_TexturaPrincipal                =
                                SPMF_DefectoTexturaPrincipal
#end  //  #ifndef ( SPMF_TexturaPrincipal )

#declare SPMF_DefectoTexturaPlastica            =
  texture                                       {
    pigment                                     {
      White
    }
  }

#ifndef ( SPMF_TexturaPlastica )
  #declare SPMF_TexturaPlastica                 =
                                SPMF_DefectoTexturaPlastica
#end  //  #ifndef ( SPMF_TexturaPlastica )

#declare SPMF_DefectoTexturaCorcho              =
  texture                                       {
    Cork
  }
  texture                                       {
    pigment                                     { 
      bumps 
      pigment_map {
        [ 0.0 color White transmit 0.25 ]
        [ 0.4 color White transmit 0.25 ]
        [ 1.0 color Blue transmit 0.25 ]
      }                        
    }
    scale   0.02                    
  }

#ifndef ( SPMF_TexturaCorcho )
  #declare SPMF_TexturaCorcho                   =
                                SPMF_DefectoTexturaCorcho
#end  //  #ifndef ( SPMF_TexturaCorcho )

#declare SPMF_DefectoTexturaDecorativa          =
  texture                                       {
    pigment                                     {
      Red
    }
  }

#ifndef ( SPMF_TexturaDecorativa )
  #declare SPMF_TexturaDecorativa                 =
                                SPMF_DefectoTexturaDecorativa
#end  //  #ifndef ( SPMF_TexturaDecorativa )

#declare SPMF_DefectoTexturaMensajes              =  
  texture                                       {
    Cork
  }
  texture                                       {
    pigment                                     { 
      bumps 
      pigment_map {
        [ 0.0 color White transmit 0.25 ]
        [ 0.4 color White transmit 0.25 ]
        [ 1.0 color Blue transmit 0.100 ]
      }                        
    }
    scale   0.01
    rotate      50                    
  }
  
#ifndef ( SPMF_TexturaMensajes )
  #declare SPMF_TexturaMensajes                   =
                                SPMF_DefectoTexturaMensajes
#end  //  #ifndef ( SPMF_TexturaMensajes )
            
#declare SPMF_BanderaGIF                        = on;
            
#declare SPMF_GIFIndice                         = "SPMF_IM1.gif"
            
#declare SPMF_ListaMensajesMes                  = array [12]
  { "ENE", "FEB", "MAR", "ABR", "MAY", "JUN",
    "JUL", "AGO", "SEP", "OCT", "NOV", "DIC" }

#declare SPMF_DeltaMes                          = 8;
 
#declare SPMF_ListaMensajesAno                  = array [12]
  { "2014", "2015", "2016", "2017", "2018", "2019",
    "2020", "2021", "2022", "2023", "2024", "2025" }

#declare SPMF_DeltaAno                          = 4;
     
#declare SPMF_ListaMensajesDiaUnidades          = array [12]
  { "0", "1", "2", "3", "4", "5", 
    "6", "7", "8", "9", "-", "/" }

#declare SPMF_DeltaDiaUnidades                  = 9;
 
#declare SPMF_ListaMensajesDiaDecenas           = array [12]
  { "0", "1", "2", "3", "-", "/",
    "0", "1", "2", "3", "-", "/" }

#declare SPMF_DeltaDiaDecenas                   = 0;
     
#declare SPMF_ListaMensajesFormulario           = array [12]
  { "DESPACHADO", "ABONADO", "ARCHIVADO", "ENTREGADO", "ANOTADO", "REVISADO",
    "RECIBIDO", "CERTIFICADO", "CONTESTADO", "CANCELADO", "CONTADO", "PAGADO" }

#declare SPMF_DeltaFormulario                   = 2;   

#declare SPMF_ListaMensajesIndice               = array [12]
  { "1", "2", "3", "4", "5", "6",
    "7", "8", "9", "10", "11", "12" }

#macro SPMF_UbicarPunto( RelativoSeccion, PuntoBuscado,
        Perimetro, TotalSecciones, RadioGiro,
        GuiaGiro, PosGuiaGiro, BloqueSello,
        PlanaMayor, SitaSelloR )
  #local Seccion                        = Perimetro/TotalSecciones;
  #local DeltaGuia                      = GuiaGiro-BloqueSello/2;
  #local RelativoP                      =
                RelativoSeccion*Seccion-BloqueSello/2;
  #while ( RelativoP < 0 )
    #local RelativoP                    = RelativoP+Perimetro;
  #end  //  #if ( RelativoP < 0 )
  #while ( RelativoP > Perimetro )
    #local RelativoP                    = RelativoP-Perimetro;
  #end  //  #if ( RelativoP < 0 )
  #local BanderaReflejo                 =
                ( 2*RelativoP > Perimetro );
  #if ( BanderaReflejo )
    #local RelativoP                    = Perimetro-RelativoP;
  #end  //  #if ( BanderaReflejo )
  #local PuntoBuscado                   = -y*( PosGuiaGiro+DeltaGuia );
  #if ( RelativoP < ( BloqueSello/2 ) )
    #local PuntoBuscado                 = PuntoBuscado+RelativoP*z;
  #else  //  #else ( RelativoP < ( BloqueSello/2 ) )
    #local PuntoBuscado                 = PuntoBuscado+BloqueSello/2*z;
    #local RelativoP                    = RelativoP-BloqueSello/2;
    #if ( RelativoP < ( DeltaGuia*sqrt( 2 ) ) )
      #local PuntoBuscado               = PuntoBuscado
                +RelativoP*( y+z )/sqrt( 2 );
    #else  //  #else ( RelativoP < ( DeltaGuia*sqrt( 2 ) ) )
      #local PuntoBuscado               = PuntoBuscado+DeltaGuia*( y+z );
      #local RelativoP                  = RelativoP-DeltaGuia*sqrt(2);
      #if ( RelativoP < PlanaMayor )
        #local PuntoBuscado             = PuntoBuscado
                +RelativoP*< 0, sin( SitaSelloR ), cos( SitaSelloR ) >;
      #else  //  #else ( RelativoP < PlanaMayor )
        #local RelativoP                = RelativoP-PlanaMayor;
        #local SitaExtraR               = RelativoP/RadioGiro;
        #local PuntoBuscado             = RadioGiro*
          < 0, -cos( SitaSelloR+SitaExtraR ), sin( SitaSelloR+SitaExtraR ) >;
      #end   //  #else ( RelativoP < PlanaMayor )
    #end   //  #else ( RelativoP < ( DeltaGuia*sqrt( 2 ) ) )
  #end   //  #else ( RelativoP < ( BloqueSello/2 ) )
  #if ( BanderaReflejo )
    #local PuntoBuscado                 =
                < 0, PuntoBuscado.y, -PuntoBuscado.z >;
  #end  //  #if ( BanderaReflejo )
#end  //  #macro SPMF_UbicarPunto( )

#macro SPMF_TiraMensajes( ListaMensajes, Delta, FrenteSello,
          MarcaIzquierda, MarcaDerecha,
          Perimetro, RadioGiro,
          GuiaGiro, PosGuiaGiro, BloqueSello,
          PlanaMayor, SitaSelloR, GruesoCorcho, BanderaContraccion,
          TexturaMensajes )
  union                                 {
    #local PuntoBuscado                 = <0,0,0>;
    #local OtroPunto                    = <0,0,0>;
    #local C                            = 0;             
    #if ( BanderaContraccion )
      #local BoxG                       = -2.1*GruesoCorcho/2;
      #local TxtG                       = -1.1;
    #else
      #local BoxG                       = -3*GruesoCorcho/2;
      #local TxtG                       = -2;
    #end
    #while ( C < 12 )
       SPMF_UbicarPunto( C+Delta, PuntoBuscado,
         Perimetro, 12, RadioGiro,
         GuiaGiro, PosGuiaGiro, BloqueSello,
         PlanaMayor, SitaSelloR )
       SPMF_UbicarPunto( C+Delta+12*BloqueSello/Perimetro, OtroPunto,
         Perimetro, 12, RadioGiro,
         GuiaGiro, PosGuiaGiro, BloqueSello,
         PlanaMayor, SitaSelloR )
      #local OtroPunto                  = OtroPunto-PuntoBuscado;
      #local AnguloBloqueR              = atan2( OtroPunto.y, OtroPunto.z );
      union                             {
        box                             {
          < MarcaIzquierda*FrenteSello, BoxG, 0 >,
          < MarcaDerecha*FrenteSello, +1*GruesoCorcho/2, BloqueSello >
          rotate                          -AnguloBloqueR*180/pi*x
          translate                       PuntoBuscado
        }  
        text                            {
          ttf "crystal.ttf", ListaMensajes[11-C], 1, 0
          translate     TxtG*z
          rotate        -90*x 
          rotate        180*y
          scale    < -1.80*( MarcaDerecha-MarcaIzquierda )*FrenteSello
                    /strlen( ListaMensajes[11-C] ), GruesoCorcho, 0.9*BloqueSello > 
          translate     0.1*BloqueSello*z          
          translate     ( MarcaIzquierda+0.005 )*FrenteSello*x    
          rotate                          -AnguloBloqueR*180/pi*x
          translate                       PuntoBuscado
          texture                             {
            TexturaMensajes
          }
        }
      }
      #local C                          = C+1;
    #end  //  #while ( C < 12 )
    translate                           -0.5*FrenteSello*x
  }
#end  //  #macro SPMF_TiraMensajes

#macro SPMF_SelloProgramacionManualFecha(
                FrenteSello, RadioGiro, GuiaGiro,
                PosGuiaGiro, BloqueSello, GruesoMetal,
                DiametroCilindro, RadioProgramar, GruesoDivision,
                GruesoCorcho, TamanoTriangulo, AltoMango,
                TexturaPrincipal, TexturaPlastica, TexturaCorcho,
                TexturaDecorativa, TexturaMensajes )
  union                                 {
    //  Calculo PERIMETRO
    #local Marca1                       = 0.5;
    #local Marca2                       = 0.57;
    #local Marca3                       = 0.64;
    #local Marca4                       = 0.81;
    #local Marca5                       = 0.97;
    #local AltoMetalico                 = 1.1*RadioProgramar;
    #local SitaL_R                      = atan2( GuiaGiro, PosGuiaGiro );
    #local PivH                         =
                        sqrt( PosGuiaGiro*PosGuiaGiro+GuiaGiro*GuiaGiro );
    #local SitaR_R                      = acos( RadioGiro/PivH );
    #local SitaSelloR                   = SitaR_R+SitaL_R;
    #local PlanaMayor                   = PivH*sin( SitaR_R );
    #local Perimetro                    =
        BloqueSello+( 2*GuiaGiro-BloqueSello )*sqrt( 2 )+2*PlanaMayor
        +2*RadioGiro*( pi-SitaSelloR );
    #local MaxBloques                   = int( Perimetro/BloqueSello );
    #if ( MaxBloques < 12 )
      #error "No hay espacio suficiente para 12 meses\n"
    #end  //  #if ( MaxBloques < 12 )
    //  END Calculo PERIMETRO
    //  Mango
    union                               {
      #local FraccionDecorativo         = 0.85;
      difference                        {
        superellipsoid                  {
          < 0.8, 1 >
          scale     < FrenteSello/6, AltoMango*( 1-FraccionDecorativo ), FrenteSello/6 >
        }
        plane                           {
          y, 0
        }
        texture                         {
          TexturaDecorativa
        }
      }
      difference                        {  
        sphere                          {
          0, 1
          scale      < FrenteSello/6, AltoMango, FrenteSello/6 >
        }
        plane                           {
          -y, 0
        } 
        plane                           {
          y, -FraccionDecorativo*AltoMango
        }
      }                                 
      translate                         FraccionDecorativo*AltoMango*y
      translate                         AltoMetalico*y
      texture                           {
        TexturaPlastica
      }
    }
    //  END Mango
    //  Cilindro Giro
    union                               {    
      //  Triangulo Giro
      difference                             {
        union                           {
          sphere                        {
            -0.05*FrenteSello/2*x, 0.75*DiametroCilindro
          }  
          prism                         {
            -DiametroCilindro/4, DiametroCilindro/4,
            3,
            < -sqrt(3)/2, +1/2 >*TamanoTriangulo,
            < 0, 0 >,
            < -sqrt(3)/2, -1/2 >*TamanoTriangulo
            rotate              90*x
          }
          cylinder                      {
            -TamanoTriangulo/2*y, +TamanoTriangulo/2*y, DiametroCilindro/4
            translate       -sqrt(3)/2*x*TamanoTriangulo
          }      
          cylinder                      {
            0, -TamanoTriangulo/2*y-sqrt(3)/2*x*TamanoTriangulo, DiametroCilindro/4
          }
          cylinder                      {
            0, +TamanoTriangulo/2*y-sqrt(3)/2*x*TamanoTriangulo, DiametroCilindro/4
          }
          sphere                        {
            -TamanoTriangulo/2*y-sqrt(3)/2*x*TamanoTriangulo, DiametroCilindro/4
          }
          sphere                        {
            +TamanoTriangulo/2*y-sqrt(3)/2*x*TamanoTriangulo, DiametroCilindro/4
          }
        }
        plane                           {
          -x, 0.05*FrenteSello/2
        } 
        translate           -FrenteSello/2*x      
        rotate          SPMF_AnguloTrianguloGiro*x
      }
      //  END Triangulo Giro
      cylinder                          {
        -1.05*x*FrenteSello/2,
        +1.05*x*FrenteSello/2,
        DiametroCilindro/2
      }
      cylinder                          {
        -GruesoDivision*x/2, +GruesoDivision*x/2, 0.95*RadioProgramar
        translate               Marca1*FrenteSello*x
        translate               -0.5*FrenteSello*x
      }
      difference                             {
        union                                  {
          cylinder                          {
            -GruesoDivision*x/2, +GruesoDivision*x/2, 0.95*RadioProgramar
            translate               Marca2*FrenteSello*x
            translate               -0.5*FrenteSello*x
          }
          cylinder                          {
            -GruesoDivision*x/2, +GruesoDivision*x/2, 0.95*RadioProgramar
            translate               Marca3*FrenteSello*x
            translate               -0.5*FrenteSello*x
          }
          cylinder                          {
            -GruesoDivision*x/2, +GruesoDivision*x/2, 0.95*RadioProgramar
            translate               Marca4*FrenteSello*x
            translate               -0.5*FrenteSello*x
          }
          cylinder                          {
            -GruesoDivision*x/2, +GruesoDivision*x/2, RadioProgramar
            translate               Marca5*FrenteSello*x
            translate               -0.5*FrenteSello*x
          }
        }
        #local Peq                      = 0.05*RadioProgramar;
        #local C                        = 0;
        #local TotC                     = int( pi/0.05 );
        #while ( C < TotC )
          box                           {
            < -FrenteSello, -Peq, -Peq >,
            < +FrenteSello, +Peq, +Peq >
            rotate                      45*x
            translate                   RadioProgramar*y
            rotate              360*C/TotC*x
          }
          #local C                      = C+1;
        #end
        texture                         {
          TexturaPlastica
        }
      }
      box                               {
        < -FrenteSello/2, -PosGuiaGiro, -BloqueSello/2 >,
        < +FrenteSello/2, -PosGuiaGiro+GruesoMetal, +BloqueSello/2 >
      }
      #local DGuia                      = GuiaGiro-BloqueSello/2;
      box                               {
        < -FrenteSello/2, 0, 0>,
        < +FrenteSello/2, +GruesoMetal, DGuia*sqrt(2) >
        rotate                  -45*x
        translate               -PosGuiaGiro*y+BloqueSello/2*z
      }
      box                               {
        < -FrenteSello/2, 0, 0>,
        < +FrenteSello/2, +GruesoMetal, DGuia*sqrt(2) >
        rotate                  -45*x
        translate               -PosGuiaGiro*y+BloqueSello/2*z
        scale           <1,1,-1>
      }
      box                                       {
        < -FrenteSello/2, 0, -RadioGiro >,
        < +FrenteSello/2, -GruesoMetal/2, +RadioGiro >
        translate               AltoMetalico*y
      }
      #local AnguloCorteR               =
                atan2( RadioGiro-GuiaGiro, PosGuiaGiro+DGuia );
      #local DespTecho                  =
                AltoMetalico*tan( AnguloCorteR )/( 1+tan( AnguloCorteR ) );
      box                               {
        < -FrenteSello/2, 0, 0 >,
        < +FrenteSello/2, -GruesoMetal, DespTecho*sqrt( 2 ) >
        rotate                  45*x
        translate               AltoMetalico*y+RadioGiro*z
      }
      box                               {
        < -FrenteSello/2, 0, 0 >,
        < +FrenteSello/2, -GruesoMetal, DespTecho*sqrt( 2 ) >
        rotate                  45*x
        translate               AltoMetalico*y+RadioGiro*z
        scale           <1,1,-1>
      }
      #local C                          = 0;
      #while ( C < 2 )
        prism                             {
          -GruesoMetal/2, GruesoMetal/2
          6,
          < +RadioGiro, +AltoMetalico >,
          < +RadioGiro+DespTecho, +AltoMetalico-DespTecho >,
          < +GuiaGiro, -PosGuiaGiro-DGuia >,
          < -GuiaGiro, -PosGuiaGiro-DGuia >,
          < -RadioGiro-DespTecho, +AltoMetalico-DespTecho >,
          < -RadioGiro, +AltoMetalico >
          rotate                        90*z
          rotate                       -90*x
          translate                     FrenteSello/2*x
          #if ( C = 1 )
            scale               <-1,1,1>
          #end
        }
        #local C                        = C+1;
      #end
    }
    //  END Cilindro Giro
    //  Corcho
    union                               {
      //  BaseCorcho
      difference                        {
        union                           {
          cylinder                      {
            GruesoMetal*x, Marca5*FrenteSello*x,
            RadioGiro+GruesoCorcho
          }
          prism                         {
            GruesoMetal, Marca5*FrenteSello,
            6,
            ( RadioGiro+GruesoCorcho )*< sin( SitaSelloR ), -cos( SitaSelloR ) >,
            < GuiaGiro+GruesoCorcho, -PosGuiaGiro-( sqrt( 2 )-1 )*GruesoCorcho >,
            < BloqueSello/2+( sqrt( 2 )-1 )*GruesoCorcho,
               -PosGuiaGiro-DGuia-GruesoCorcho >,
            <-BloqueSello/2-( sqrt( 2 )-1 )*GruesoCorcho,
               -PosGuiaGiro-DGuia-GruesoCorcho >,
            <-GuiaGiro-GruesoCorcho, -PosGuiaGiro-( sqrt( 2 )-1 )*GruesoCorcho >,
            (-RadioGiro-GruesoCorcho )*< sin( SitaSelloR ), -cos( SitaSelloR ) >
            rotate                       -90*z
            rotate                       -90*x
          }
        }
        cylinder                        {
          0, FrenteSello*x, RadioGiro
        }
        cylinder                        {
          -GruesoMetal*x, +GruesoMetal*x, PosGuiaGiro+RadioGiro
          translate             Marca1*FrenteSello*x
        }
        cylinder                        {
          -GruesoMetal*x, +GruesoMetal*x, PosGuiaGiro+RadioGiro
          translate             Marca2*FrenteSello*x
        }
        cylinder                        {
          -GruesoMetal*x, +GruesoMetal*x, PosGuiaGiro+RadioGiro
          translate             Marca3*FrenteSello*x
        }
        cylinder                        {
          -GruesoMetal*x, +GruesoMetal*x, PosGuiaGiro+RadioGiro
          translate             Marca4*FrenteSello*x
        }
        prism                         {
          0, FrenteSello,
          6,
          +RadioGiro*< sin( SitaSelloR ), -cos( SitaSelloR ) >,
          < GuiaGiro, -PosGuiaGiro >,
          < BloqueSello/2,
             -PosGuiaGiro-DGuia >,
          <-BloqueSello/2,
             -PosGuiaGiro-DGuia >,
          <-GuiaGiro, -PosGuiaGiro >,
          -RadioGiro*< sin( SitaSelloR ), -cos( SitaSelloR ) >
          rotate                       -90*z
          rotate                       -90*x
        }
        translate                       -0.5*FrenteSello*x
      }
      //  END BaseCorcho
      #local DM                         = GruesoCorcho/FrenteSello;
      //  Mensajes
      object                            {
        SPMF_TiraMensajes( SPMF_ListaMensajesMes, SPMF_DeltaMes+1, FrenteSello,
          Marca3+DM, Marca4-DM,
          Perimetro, RadioGiro,
          GuiaGiro, PosGuiaGiro, BloqueSello,
          PlanaMayor, SitaSelloR, GruesoCorcho, off, TexturaMensajes )
      }
      object                            {
        SPMF_TiraMensajes( SPMF_ListaMensajesAno, SPMF_DeltaAno+1, FrenteSello,
          Marca4+DM, Marca5-DM,
          Perimetro, RadioGiro,
          GuiaGiro, PosGuiaGiro, BloqueSello,
          PlanaMayor, SitaSelloR, GruesoCorcho, off, TexturaMensajes )
      }
      object                            {
        SPMF_TiraMensajes( SPMF_ListaMensajesDiaUnidades, SPMF_DeltaDiaUnidades+1, FrenteSello,
          Marca2+DM, Marca3-DM,
          Perimetro, RadioGiro,
          GuiaGiro, PosGuiaGiro, BloqueSello,
          PlanaMayor, SitaSelloR, GruesoCorcho, off, TexturaMensajes )
      }
      object                            {
        SPMF_TiraMensajes( SPMF_ListaMensajesDiaDecenas, SPMF_DeltaDiaDecenas+1, FrenteSello,
          Marca1+DM, Marca2-DM,
          Perimetro, RadioGiro,
          GuiaGiro, PosGuiaGiro, BloqueSello,
          PlanaMayor, SitaSelloR, GruesoCorcho, off, TexturaMensajes )
      }
      object                            {
        SPMF_TiraMensajes( SPMF_ListaMensajesFormulario, SPMF_DeltaFormulario+1, FrenteSello,
          5*DM, Marca1-DM,
          Perimetro, RadioGiro,
          GuiaGiro, PosGuiaGiro, BloqueSello,
          PlanaMayor, SitaSelloR, GruesoCorcho, off, TexturaMensajes )
      }
      object                            {
        SPMF_TiraMensajes( SPMF_ListaMensajesIndice, SPMF_DeltaFormulario+1, FrenteSello,
          DM, 4*DM,
          Perimetro, RadioGiro,
          GuiaGiro, PosGuiaGiro, BloqueSello,
          PlanaMayor, SitaSelloR, GruesoCorcho, on, TexturaMensajes )
      }
      //  END Mensajes   
      texture                           {
        TexturaCorcho
      }
    }
    //  END Corcho
    //  Placa Indice
    #local PlacaIndice           =     
        difference                          {
          union                               {
            difference                        {
              cylinder                        {
                0, Marca1*FrenteSello*x, AltoMetalico
              }
              cylinder                        {
                -FrenteSello*x, FrenteSello*x, AltoMetalico-GruesoMetal
              }
              plane                           {
                -z, 0
              }
              plane                           {
                y, -AltoMetalico*cos( SitaSelloR )
              }
            }   
            box                               {
              < 0, 0, -AltoMetalico >,
              < Marca1*FrenteSello, -PlanaMayor, -AltoMetalico+GruesoMetal >
              rotate      -( 90-SitaSelloR*180/pi )*x
            }
            translate                 -FrenteSello/2*x
          }  
          box                               {
            < -FrenteSello, -0.5*RadioGiro, -RadioGiro >,
            < Marca1*FrenteSello/5, +0.5*RadioGiro, -2*AltoMetalico >
            translate       -FrenteSello/2*x
          }  
        }  
    //  END PlacaIndice    
    union                               {
      object                            {
        PlacaIndice
      }            
      intersection                      {
        object                          {
          PlacaIndice
        }
        box                             {
          < Marca1*FrenteSello/5, RadioGiro, 0 >,
          < 0.95*Marca1*FrenteSello, -0.95*PlanaMayor*sin( SitaSelloR ), -2*AltoMetalico >
          translate     -FrenteSello/2*x
        } 
        translate           -0.01*RadioGiro*z     
        #if ( SPMF_BanderaGIF )
          texture                         {
            pigment                       {
              image_map                   {    
                gif   SPMF_GIFIndice
              }
              scale  < 0.75*Marca1*FrenteSello,
                       0.95*PlanaMayor*sin( SitaSelloR )+RadioGiro, 1 > 
              translate       -FrenteSello/2*x+Marca1*FrenteSello/5*x+RadioGiro*y         
            }
          } 
        #end  //  #if ( SPMF_BanderaGif )  
        #ifdef ( SPMF_CustomTexturaGIF )
          texture                           {
            SPMF_CustomTexturaGIF
          }
        #end  //  #ifdef 
      }
    }
    texture                             {
      TexturaPrincipal
    }
  }
#end  //  #macro SPMF_SelloProgramacionManualFecha

#macro SPMF_Sello()
  object                                {
    #local L                    = SPMF_L;
    #local FrenteSello          = 45.0*L;
    #local RadioGiro            =  5.4*L;
    #local GuiaGiro             =  2.5*L;
    #local PosGuiaGiro          = 14.3*L;
    #local BloqueSello          =  3.6*L;
    #local GruesoMetal          =  0.6*L;
    #local DiametroCilindro     =  3.6*L;
    #local RadioProgramar       =  8.9*L;
    #local GruesoDivision       =  0.3*L;
    #local GruesoCorcho         =  0.8*L; 
    #local TamanoTriangulo      = 10.0*L; 
    #local AltoMango            = 20.0*L;
    SPMF_SelloProgramacionManualFecha(
                FrenteSello, RadioGiro, GuiaGiro,
                PosGuiaGiro, BloqueSello, GruesoMetal,
                DiametroCilindro, RadioProgramar, GruesoDivision,
                GruesoCorcho, TamanoTriangulo, AltoMango,
                SPMF_TexturaPrincipal, SPMF_TexturaPlastica,
                SPMF_TexturaCorcho, SPMF_TexturaDecorativa,
                SPMF_TexturaMensajes )
  }
#end  //  #macro SPMF_Sello
