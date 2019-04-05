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
//  LHVP (LampadarioHumoVelaParafina)
//  El archivo dibuja un lampadario de Iglesia con alcancia.
//  Incluye una macro para modificar algunas caracteristicas, ademas la macro calcula
//  las posiciones para que el usuario coloque velitas a gusto.
//  Es compatible con POVRay 3.1.
//
//  La macro principal no tiene parametros.
//  #macro LHVP_Lampadario()
//
//  La siguiente macro permite un mayor control sobre las caracteristicas.
//  #macro LHVP_LampadarioHumoVelaParafina(
//              FrenteFundamental, LateralFundamental,
//              AltoFundamental, LateralBandeja,
//              DiametroBarra, LadoCuadradoSoporte,
//              AnguloExposicion, DiametroAlcancia,
//              GruesoLamina, TotalHileras,   
//              VelasPorHilera, DiametroSoporteVela, AltoCruz,
//              MaterialPrincipal, MaterialAlcancia,  
//              MaterialBandeja, MaterialCandelero )
//          FrenteFundamental       : Valor de referencia para el frente del lampadario.
//              Valor por defecto 643*L.
//          LateralFundamental      : Valor de referencia para el ancho lateral Z.
//              valor por defecto 477*L.
//          AltoFundamental         : Alto sin la cruz del lampadario.
//              Valor por defecto 700*L.
//          LateralBandeja          : Valor de referencia para el ancho 
//              lateral Z de la bandeja. Valor por defecto 550*L.
//          DiametroBarra           : Diametro de las barras soporte.
//              Valor por defecto 10*L.
//          LadoCuadradoSoporte     : Lado del cuadrado formado por las barras laterales
//              para soporte de la estructura. Valor por defecto 100*L.
//          AnguloExposicion        : Angulo de inclinacion del plano imaginario para
//              las velitas. Valor por defecto 25.
//          DiametroAlcancia        : Diametro principal de la alcancia.
//              Valor por defecto 50*L.
//          GruesoLamina            : Grueso de algunas laminas de metal de la estructura.
//              Valor por defecto 3*L.
//          TotalHileras            : Total de hileras con velitas. Valor por defecto 6.
//          VelasPorHilera          : Total de velitas en cada hilera. Valor por defecto 10.
//          DiametroSoporteVela     : Diametro de los aros que soportan 
//              los candeleros individuales.
//              Valor por defecto 20*L.
//          AltoCruz                : Alto de la cruz posterior.
//              Valor por defecto 100*L.
//          MaterialPrincipal       : Material de las barras soporte.
//              Valor por defecto LHVP_MaterialPrincipal.
//          MaterialAlcancia        : Material para la alcancia.
//              Valor por defecto LHVP_MaterialAlcancia.
//          MaterialBandeja         : Material para la bandeja.
//              Valor por defecto LHVP_MaterialBandeja.
//          MaterialCandelero       : Material de los candeleros individuales.
//              Valor por defecto LHVP_MaterialCandelero.     
//
//  El lampadario se encuentra contenido entre las siguientes coordenadas:
//      Minimo          = < -330,    0, -305 >*L
//      Maximo          = < +330,  800, +305 >*L
//  La base descansa semicentrada sobre el plano XZ. El frente mira hacia Z-,
//  con la alcancia hacia X+.
//
//  Estas son variables predefinidas o generadas en el
//  interior de las macros que no deberian modificarse directamente.
//  Si quiere cambiarlas, recurra a los modificadores.   
//  #declare LHVP_DefectoMaterialPrincipal       
//      Material de las barras soporte.
//  #declare LHVP_DefectoMaterialAlcancia      
//      Material para la alcancia.
//  #declare LHVP_DefectoMaterialBandeja        
//      Material para la bandeja.
//  #declare LHVP_DefectoMaterialCandelero          
//      Material de los candeleros individuales. 
//  #declare LHVP_ArregloCandelero         = array [ TotalHileras ][ VelasPorHilera ]
//      Un arreglo bidimensional que contiene la posicion de todas las velitas.
//      Las filas se numeran de abajo hacia arriba, y las columnas de izquierda a derecha.
//
//  Los siguientes son los modificadores
//  aplicables y redefinibles por el usuario (si se indica es el valor por defecto). 
//  #declare LHVP_MaterialPrincipal             =
//                      { LHVP_DefectoMaterialPrincipal             }
//      Material de las barras soporte.
//  #declare LHVP_MaterialAlcancia              =
//                      { LHVP_DefectoMaterialAlcancia              }
//      Material para la alcancia.
//  #declare LHVP_MaterialBandeja               =
//                      { LHVP_DefectoMaterialBandeja               }
//      Material para la bandeja.
//  #declare LHVP_MaterialCandelero             =
//                      { LHVP_DefectoMaterialCandelero             }
//      Material de los candeleros individuales. 
//       
//  Para colocarlo simplemente
//  #include "LHVP.inc" 
//  object { LHVP_Lampadario( ) }
//                                  
//  Con la macro detallada
//  #include "LHVP.inc" 
//  object          {
//    LHVP_LampadarioHumoVelaParafina(
//          0.643, 0.477, 0.700, 0.550, 0.010, 0.100,
//          25, 0.050, 0.003, 6, 10, 0.030, 0.100,
//          LHVP_MaterialPrincipal, LHVP_MaterialAlcancia,
//          LHVP_MaterialBandeja, LHVP_MaterialCandelero )
//  }
//      
//  Con modificadores
//  #include "LHVP.inc"
//  #include "textures.inc"
//  #declare LHVP_MaterialPrincipal         = 
//          material { texture { PinkAlabaster } }
//  object        { LHVP_Lampadario( ) }
//
#include "metals.inc"     
     
#declare LHVP_L                                 = 0.001;

#declare LHVP_DefectoMaterialPrincipal          =
  material                                      {  
    texture                                     {
      T_Brass_3C
      normal                                    {
        bumps 
        scale  0.01
      }
    }             
  }
  
#ifndef ( LHVP_MaterialPrincipal )
  #declare LHVP_MaterialPrincipal               = LHVP_DefectoMaterialPrincipal
#end  //  #ifndef ( LHVP_MaterialPrincipal )  
    
#declare LHVP_DefectoMaterialAlcancia           =
  material                                      {  
    texture                                     {
      T_Chrome_1B
      normal                                    {
        bumps 
        scale  0.01
      }
    }             
  }
  
#ifndef ( LHVP_MaterialAlcancia )
  #declare LHVP_MaterialAlcancia                = LHVP_DefectoMaterialAlcancia   
#end  //  #ifndef ( LHVP_MaterialAlcancia )  
    
#declare LHVP_DefectoMaterialBandeja            =
  material                                      {  
    texture                                     {
      T_Brass_1B
      normal                                    {
        bumps 
        scale  0.01
      }
    }             
  }
  
#ifndef ( LHVP_MaterialBandeja )
  #declare LHVP_MaterialBandeja                = LHVP_DefectoMaterialBandeja   
#end  //  #ifndef ( LHVP_MaterialBandeja )  
    
#declare LHVP_DefectoMaterialCandelero         =
  material                                      {  
    texture                                     {
      T_Silver_1B
      normal                                    {
        bumps 
        scale  0.01
      }
    }             
  }
  
#ifndef ( LHVP_MaterialCandelero )
  #declare LHVP_MaterialCandelero                = LHVP_DefectoMaterialCandelero   
#end  //  #ifndef ( LHVP_MaterialCandelero )  
            
#macro LHVP_LampadarioHumoVelaParafina(
          FrenteFundamental, LateralFundamental,
          AltoFundamental, LateralBandeja,
          DiametroBarra, LadoCuadradoSoporte,
          AnguloExposicion, DiametroAlcancia,
          GruesoLamina, TotalHileras,   
          VelasPorHilera, DiametroSoporteVela,  
          AltoCruz,
          MaterialPrincipal, MaterialAlcancia,  
          MaterialBandeja, MaterialCandelero )
  union                                         {  
    #local AnguloExposicionR                    = radians( AnguloExposicion );    
    //  Barras Laterales 
    union                                       {
      #local PBase                              = 
          < 0, DiametroBarra/2, +LateralFundamental/2 >;  
      #local PVerticalA                         =
          < 0, +( LateralFundamental-LadoCuadradoSoporte+DiametroBarra )/2, 
            +LadoCuadradoSoporte/2 >;   
      #local PVerticalB                         = PVerticalA+1.5*LadoCuadradoSoporte*y;  
      #local PAlto                              = <0, AltoFundamental, -LateralFundamental/2>;  
      #local PAltoDelantero                     = 
        <0, AltoFundamental-LateralFundamental*tan( AnguloExposicionR ), +LateralFundamental/2 >;
      #local UnionBajaLateral                   = < 0, 
              ( LateralFundamental-LadoCuadradoSoporte )/4,0 >;  
      #local CorAlcancia                        = 
         ( +DiametroBarra/2+DiametroAlcancia/2 )*<1,1,0>;        
      #local InicioAlcancia                     =
        ( 6*PAltoDelantero-PVerticalB )/5+CorAlcancia;
      #local FinAlcancia                        =
        ( -5*PAltoDelantero+10*PVerticalB )/5+CorAlcancia;                 
      #local C                                  = 0;
      #while ( C < 2 )
        union                                   {
          #local D                              = 0;
          #while ( D < 2 )
            union                               {
              sphere                            {
                PBase, DiametroBarra/2
              }                    
              cylinder                          {
                PBase, PVerticalA, DiametroBarra/2
              } 
              sphere                            {
                PVerticalA, DiametroBarra/2
              } 
              cylinder                          {
                PVerticalA, PVerticalB, DiametroBarra/2
              }   
              sphere                            {
                PVerticalB, DiametroBarra/2
              }   
              cylinder                          {
                UnionBajaLateral, 
                ( 5*PBase+PVerticalA )/6,
                DiametroBarra/2
              }
              #if ( D = 1 )         
                scale                           <1,1,-1>
              #end  //  #if ( D = 1 )
            }
            #local D                            = D+1;
          #end  //  #while ( D < 2 )
          cylinder                              {
            ( 5*PVerticalA+PVerticalB )/6,
            ( 5*PVerticalA+PVerticalB )/6*<1,1,-1>, DiametroBarra/2
          }
          cylinder                              {
            ( PVerticalA+5*PVerticalB )/6,
            ( PVerticalA+5*PVerticalB )/6*<1,1,-1>, DiametroBarra/2
          }  
          cylinder                              {
            PAlto, PVerticalB*<1,1,-1>, DiametroBarra/2
          }  
          cylinder                              {
            PAltoDelantero, PVerticalB, DiametroBarra/2
          }  
          sphere                                {
            PAlto, DiametroBarra/2
          }
          sphere                                {
            PAltoDelantero, DiametroBarra/2
          }
          cylinder                              {
            PAlto, PAltoDelantero, DiametroBarra/2
          }   
          cylinder                              {
            ( PAltoDelantero+PVerticalB )/2, 
            ( 9*PAlto+PVerticalB*<1,1,-1> )/10, DiametroBarra/2
          }     
          sphere                                {
            UnionBajaLateral, DiametroBarra/2
          }
          cylinder                              {
            UnionBajaLateral,
            ( 5*PVerticalA+PVerticalB )/6*<1,1,0>-FrenteFundamental/2*x,
            DiametroBarra/2
          }  
          translate                             FrenteFundamental/2*x
          #if ( C = 1 )
            scale                               <-1,1,1>
          #end  //  #if ( C = 1 )
        }
        #local C                                = C+1;
      #end  //  #while ( C < 2 ) 
      cylinder                                  {
        ( 5*PVerticalA+PVerticalB )/6*<1,1,0>-FrenteFundamental/2*x,
        ( 5*PVerticalA+PVerticalB )/6*<1,1,0>+FrenteFundamental/2*x,
        DiametroBarra/2
      }  
      difference                                {
        cylinder                                { 
          PAlto+( FrenteFundamental/2+DiametroBarra/2+GruesoLamina )*x,
          PAlto-( FrenteFundamental/2+DiametroBarra/2+GruesoLamina )*x,
          2*DiametroAlcancia
        }       
        cylinder                                { 
          PAlto+( FrenteFundamental/2+DiametroBarra/2 )*x,
          PAlto-( FrenteFundamental/2+DiametroBarra/2 )*x,
          3*DiametroAlcancia
        }  
        box                                     {
          < -FrenteFundamental, 0, 1.05*PAlto.z >,
          < +FrenteFundamental, 2*AltoFundamental, -LateralBandeja >
        }     
        box                                     {
          < -FrenteFundamental, 0, -3*DiametroAlcancia >,
          < +FrenteFundamental, 3*DiametroAlcancia,+3*DiametroAlcancia >
          translate             PAlto+DiametroBarra/2*y
        }
        box                                     {
          < -FrenteFundamental, 0, -3*DiametroAlcancia >,
          < +FrenteFundamental, 3*DiametroAlcancia,+3*DiametroAlcancia >   
          rotate                AnguloExposicion*x
          translate             PAlto+DiametroBarra/2*y
        }
        material                                {
          MaterialBandeja
        }  
      }
    }
    //  END Barras Laterales  
    //  Bandeja
    union                                       {     
      difference                                {
        box                                       {
          < -FrenteFundamental/2+DiametroBarra/2, 0, -0.55*LateralBandeja >,
          < +FrenteFundamental/2-DiametroBarra/2, DiametroAlcancia/2, 0.55*LateralBandeja >  
        } 
        box                                     {
          < -FrenteFundamental/2, -DiametroAlcancia, 0 >,
          < -FrenteFundamental/2+DiametroBarra/2+DiametroAlcancia, DiametroAlcancia,
            +LateralBandeja >
        }      
        box                                     {
          < -FrenteFundamental/2+DiametroBarra/2+DiametroAlcancia+GruesoLamina,
            GruesoLamina, -0.55*LateralBandeja+GruesoLamina >,
          < +FrenteFundamental/2-DiametroBarra/2-GruesoLamina,
            DiametroAlcancia, +0.55*LateralBandeja-GruesoLamina >
        }
         box                                     {
          < -FrenteFundamental/2+DiametroBarra/2+GruesoLamina,
            GruesoLamina, -0.55*LateralBandeja+GruesoLamina >,
          < +FrenteFundamental/2-DiametroBarra/2-GruesoLamina,
            DiametroAlcancia, -GruesoLamina >
        }
       translate           ( PAltoDelantero.y+PVerticalB.y )/2*y
      }          
      material                                  {
        MaterialBandeja
      }
    }
    //  END Bandeja 
    // Velitas 
    union                                       {
      //  Barras soporte  
        #declare LHVP_ArregloCandelero         = array [ TotalHileras ][ VelasPorHilera ]
        #local C                                = 0;
        #while ( C < TotalHileras )            
          union                                 {
            cylinder                              {
              -FrenteFundamental/2*x, FrenteFundamental/2*x, DiametroBarra/2
            }  
            #local D                              = 0;
            #while ( D < VelasPorHilera ) 
              #local BanderaCandelero             = 
                  ( !( ( ( C = 1 ) | ( C = 0 ) ) & ( D = 0 ) ) );
              #if ( BanderaCandelero )            
                union                               {
                  torus                               {
                    DiametroSoporteVela/2+DiametroBarra/2, DiametroBarra/2
                  }
                  difference                        {
                    union                           {
                      cylinder                        {
                        -( DiametroBarra/2+GruesoLamina )*y,
                        +DiametroBarra/2*y, DiametroSoporteVela/2
                      }
                      cylinder                        {
                        +( DiametroBarra/2+GruesoLamina )*y,
                        +DiametroBarra/2*y, DiametroSoporteVela/2+DiametroBarra
                      }
                    } 
                    cylinder                        {
                      -DiametroBarra/2*y, DiametroBarra*y,
                      DiametroSoporteVela/2-GruesoLamina/2
                    }
                    material                        {
                      MaterialCandelero
                    }
                  }   
                  translate           -FrenteFundamental/2*x
                  translate           +DiametroSoporteVela/2*z+DiametroBarra*z
                  translate           ( D+1 )*FrenteFundamental/( VelasPorHilera+1 )*x 
                }
              #end  //  #if ( BanderaCandelero )
              #declare LHVP_ArregloCandelero[C][VelasPorHilera-D-1] =   
                 ( ( C*PAlto+( TotalHileras-C-1 )*PAltoDelantero )/( TotalHileras-1 )
                  -FrenteFundamental/2*x
                  +DiametroSoporteVela/2*z+DiametroBarra*z
                  +( D+1 )*FrenteFundamental/( VelasPorHilera+1 )*x
                  -DiametroBarra/2*y )*<-1,1,-1>;
             #local D                            = D+1;
            #end  // #while ( D < VelasPorHilera ) 
            translate           ( C*PAlto+( TotalHileras-C-1 )*PAltoDelantero )/( TotalHileras-1 )
          } 
          #local  C                             = C+1;
        #end  
      //  END Barras soporte
    }       
    
    // END Velitas
    // Accesorios
    union                                       {
      //  Alcancia 
      difference                                {
        union                                     {
          cylinder                                {
            InicioAlcancia, FinAlcancia, DiametroAlcancia/2
          }           
          cylinder                                {
            InicioAlcancia, ( 23*InicioAlcancia+FinAlcancia )/24, 1.1*DiametroAlcancia/2
          }
        }
        box                                         {
          #local DeltaAlcancia                      =
                vnormalize( InicioAlcancia-FinAlcancia );    
          <-0.1*DiametroAlcancia, -0.1*DiametroAlcancia, -DiametroAlcancia >,
          <+0.1*DiametroAlcancia, +0.1*DiametroAlcancia, +DiametroAlcancia >                 
          matrix            <1,0,0,
                             0,DeltaAlcancia.z,DeltaAlcancia.y,
                             0,-DeltaAlcancia.y,DeltaAlcancia.z,
                             InicioAlcancia.x, InicioAlcancia.y, InicioAlcancia.z >      
        }           
        translate               -FrenteFundamental/2*x  
        material                                {
          MaterialAlcancia
        }
      }
      //  END Alcancia 
      //  Cruz
      union                                     {
        cylinder                                {
          0, AltoCruz*y, DiametroBarra/2
        }
        cylinder                                {
          -0.333*AltoCruz*x, +0.333*AltoCruz*x, DiametroBarra/2  
          translate     0.75*AltoCruz*y
        }
        translate           AltoFundamental*y-LateralFundamental/2*z
      }
      //  END Cruz
    }
    //  END Accesorios 
    rotate                          180*y
    material                                    {
      MaterialPrincipal
    }
  }
#end  //  #macro LHVP_LampadarioHumoVelaParafina()

#macro LHVP_Lampadario()
  object                                        {
    #local L                        = LHVP_L;
    #local FrenteFundamental        = 643*L;   
    #local LateralFundamental       = 477*L; 
    #local AltoFundamental          = 700*L;
    #local LateralBandeja           = 550*L;  
    #local DiametroBarra            =  10*L;
    #local LadoCuadradoSoporte      = 100*L; 
    #local AnguloExposicion         =  25;   
    #local DiametroAlcancia         =  50*L;    
    #local GruesoLamina             =   3*L;  
    #local TotalHileras             =   6;  
    #local VelasPorHilera           =  10;
    #local DiametroSoporteVela      =  30*L;
    #local AltoCruz                 = 100*L;
    LHVP_LampadarioHumoVelaParafina(
        FrenteFundamental, LateralFundamental,
        AltoFundamental, LateralBandeja,
        DiametroBarra, LadoCuadradoSoporte, 
        AnguloExposicion, DiametroAlcancia,
        GruesoLamina, TotalHileras, 
        VelasPorHilera, DiametroSoporteVela, 
        AltoCruz,
        LHVP_MaterialPrincipal, LHVP_MaterialAlcancia,
        LHVP_MaterialBandeja, LHVP_MaterialCandelero )
  }
#end  //  #macro LHVP_Lampadario()

