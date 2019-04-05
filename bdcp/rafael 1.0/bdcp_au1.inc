// This file is licensed under the terms of the CC-LGPL.

#declare BDCP_BarraLEDCentral           =
  prism                                 {
    -1, 1
    7,
    <  0,  0>,
    <  2, -2>,
    < 18, -2>,
    < 20,  0>,
    < 18,  2>,
    <  2,  2>,
    <  0,  0>
    rotate              -90*x
    scale               1/20
  }

#declare BDCP_BarraLEDLateral           =
  prism                                 {
    -1, 1
    7,
    <  0,  1>,
    <  2,  3>,
    <  2, 17>,
    <  0, 19>,
    < -2, 17>,
    < -2,  3>,
    <  0,  1>
    rotate              -90*x
    scale               1/20
  }

#declare BDCP_BarraLEDTecho             =
  prism                                 {
    -1, 1
    7,
    <  0, 21>,
    <  3, 18>,
    < 17, 18>,
    < 20, 21>,
    < 19, 22>,
    <  1, 22>,
    <  0, 21>
    rotate              -90*x
    scale               1/20
  }

//     --0---
//    /      /
//    3      4
//    /      /
//     --1---
//    /      /
//    5      6
//    /      /
//     --2---
#declare BDCP_ClaveDigitos      = array [10][7]
  { {1,0,1,1,1,1,1},
    {0,0,0,0,1,0,1},
    {1,1,1,0,1,1,0},
    {1,1,1,0,1,0,1},
    {0,1,0,1,1,0,1},
    {1,1,1,1,0,0,1},
    {1,1,1,1,0,1,1},
    {1,0,0,0,1,0,1},
    {1,1,1,1,1,1,1},
    {1,1,1,1,1,0,1} }

#macro BDCP_DisplayDigito( Digito, Cizalla, BanderaUno, BanderaApagado,
              TexturaEncendido, TexturaApagado )
  union                                {
    #local C                           = 0;
    #while ( C < 7 )
      #local BanderaDibujar            = ( !BanderaUno );
      #if ( BanderaUno )
        #if ( C = 4 )
          #local BanderaDibujar        = on;
        #end  // #if ( C = 4 )
        #if ( C = 6 )
          #local BanderaDibujar        = on;
        #end  // #if ( C = 6 )
      #end  // #if ( BanderaUno )
      #if ( BanderaDibujar )
        #switch ( C )
          #case ( 0 )
            #local MyObjeto            =
              object { BDCP_BarraLEDTecho }
          #break  // #case ( 0 )
          #case ( 1 )
            #local MyObjeto            =
              object { BDCP_BarraLEDCentral }
          #break  // #case ( 0 )
          #case ( 2 )
            #local MyObjeto            =
              object { BDCP_BarraLEDTecho scale <1,-1,1> }
          #break  // #case ( 0 )
          #case ( 3 )
            #local MyObjeto            =
              object { BDCP_BarraLEDLateral }
          #break  // #case ( 0 )
          #case ( 4 )
            #local MyObjeto            =
              object { BDCP_BarraLEDLateral scale <-1,1,1>
                       #if ( !BanderaUno ) translate x #end }
          #break  // #case ( 0 )
          #case ( 5 )
            #local MyObjeto            =
              object { BDCP_BarraLEDLateral scale <1,-1,1> }
          #break  // #case ( 0 )
          #case ( 6 )
            #local MyObjeto            =
              object { BDCP_BarraLEDLateral scale <-1,-1,1>
                       #if ( !BanderaUno ) translate x #end }
          #break  // #case ( 0 )
        #end  // #switch ( C )
        #if ( BDCP_ClaveDigitos[Digito][C] = 1 )
          object                           {
            MyObjeto
            texture                        {
              TexturaEncendido
            }
          }
        #else  // #else ( BDCP_ClaveDigitos[Digito][4] = 1 )
          #if ( BanderaApagado )
            object                           {
              MyObjeto
              texture                        {
                TexturaApagado
              }
            }
          #end  // #if ( BanderaApagado )
        #end   // #else ( BDCP_ClaveDigitos[Digito][4] = 1 )
      #end  // #if ( BanderaDibujar )
      #local C                         = C+1;
    #end  // #while ( C < 7 )
    matrix              <1,0,0,
                         Cizalla,1,0,
                         0,0,1,
                         0,0,0>
  }
#end  // #macro BDCP_DisplayDigito

#macro BDCP_DisplayClock( Hora, Minutos,Indicadores, FraccionDisplay,
            BanderaRadial, Frente, ProfundidadDisplay, Radial,
            TexturaLabelLED, TexturaTransparente,
            TexturaLED, TexturaFondoLED )
  union                                 {
    difference                          {
      merge                             {
        box                             {
          <-Frente/2,-Radial,0>,
          <+Frente/2,+Radial,-ProfundidadDisplay>
        }
        #if ( BanderaRadial )
          cylinder                      {
            0.001*ProfundidadDisplay*z,
            -0.999*ProfundidadDisplay*z, Radial
            translate                   -Frente/2*x
          }
          cylinder                      {
            0.001*ProfundidadDisplay*z,
            -0.999*ProfundidadDisplay*z, Radial
            translate                   +Frente/2*x
          }
        #end  // #if ( BanderaRadial )
      }
      box                             {
        <-Frente/2,-Radial,+ProfundidadDisplay/2>*0.90,
        <+Frente/2,+Radial,-ProfundidadDisplay/2>*0.90
        translate                     -ProfundidadDisplay/2*z
      }
      texture                           {
        TexturaTransparente
      }
    }
    difference                          {
      union                             {
        box                             {
          <-Frente/2,-Radial,0>,
          <+Frente/2,+Radial,-ProfundidadDisplay>
        }
        #if ( BanderaRadial )
          cylinder                      {
            0.001*ProfundidadDisplay*z,
            -0.999*ProfundidadDisplay*z, Radial
            translate                   -Frente/2*x
          }
          cylinder                      {
            0.001*ProfundidadDisplay*z,
            -0.999*ProfundidadDisplay*z, Radial
            translate                   +Frente/2*x
          }
        #end  // #if ( BanderaRadial )
        scale           0.99
      }
      #local AltoDisplay                = FraccionDisplay*Radial*2;
      #local FrenteDisplay              = 3.5*AltoDisplay;
      #if ( FrenteDisplay >= Frente )
        #local AltoDisplay              = 0.9*Frente*AltoDisplay/FrenteDisplay;
        #local FrenteDisplay            = 0.9*Frente;
      #end  // #if ( FrenteDisplay >= Frente )
      #local AltoDisplay                = min( AltoDisplay, 0.9*Frente );
      #local DeltaSup                   = ( 2*Radial-AltoDisplay )/3;
      box                               {
        <-FrenteDisplay/2,Radial-DeltaSup,-0.1*ProfundidadDisplay>,
        <+FrenteDisplay/2,Radial-DeltaSup-AltoDisplay,-1.1*ProfundidadDisplay>
        texture                         {
          TexturaFondoLED
        }
      }
      texture                           {
        TexturaLabelLED
      }
    }
    // LED
    #local CizallaDigito                = 3/20;
    union                               {
      #local DecenasHora                = div( Hora, 10 );
      #if ( DecenasHora > 0 )
        object                          {
          BDCP_DisplayDigito( DecenasHora, CizallaDigito, off, off,
            TexturaLED, TexturaLED )
          scale                 0.375*AltoDisplay
          translate             ( Radial-AltoDisplay/2-DeltaSup )*y
          translate             -0.1*ProfundidadDisplay*z
          translate             -1.3*AltoDisplay*x
        }
      #end  // #if ( DecenasHora > 0 )
      #local UnidadesHora               = mod( Hora, 10 );
      object                          {
        BDCP_DisplayDigito( UnidadesHora, CizallaDigito, off, off,
          TexturaLED, TexturaLED )
        scale                 0.375*AltoDisplay
        translate             ( Radial-AltoDisplay/2-DeltaSup )*y
        translate             -0.1*ProfundidadDisplay*z
        translate             -0.6*AltoDisplay*x
      }
      #local DecenasMinutos             = div( Minutos, 10 );
      object                          {
        BDCP_DisplayDigito( DecenasMinutos, CizallaDigito, off, off,
          TexturaLED, TexturaLED )
        scale                 0.375*AltoDisplay
        translate             ( Radial-AltoDisplay/2-DeltaSup )*y
        translate             -0.1*ProfundidadDisplay*z
        translate             +0.4*AltoDisplay*x
      }
      #local UnidadesMinutos            = mod( Minutos, 10 );
      object                          {
        BDCP_DisplayDigito( UnidadesMinutos, 3/20, off, off,
          TexturaLED, TexturaLED )
        scale                 0.375*AltoDisplay
        translate             ( Radial-AltoDisplay/2-DeltaSup )*y
        translate             -0.1*ProfundidadDisplay*z
        translate             +1.1*AltoDisplay*x
      }
      #local UnidadDigito       = 0.375*AltoDisplay;
      #local C                  = 0;
      #while ( C < 2 )
        cylinder                {
          -0.05*UnidadDigito*z, +0.05*UnidadDigito*z,
          0.1*UnidadDigito
          translate             +0.0875*AltoDisplay*x
          translate             -0.1*ProfundidadDisplay*z
          translate             UnidadDigito/2*y
          #if ( C = 1 )
            scale               <1,-1,1>
          #end  // #if ( C = 1 )
          matrix                <1,0,0,
                                 CizallaDigito,1,0,
                                 0,0,1,
                                 0,0,0>
          translate             ( Radial-AltoDisplay/2-DeltaSup )*y
          texture               {
            TexturaLED
          }
        }
        #local C                = C+1;
      #end  // #while ( C < 2 )
      #local Lucesita           = Indicadores;
      #local C                  = 0;
      #while ( C < 5 )
        #if ( mod( Lucesita, 2 ) = 1 )
          cylinder                {
            -0.05*UnidadDigito*z, +0.05*UnidadDigito*z,
            0.1*UnidadDigito
            #switch ( C )
              #case ( 0 )
                translate               UnidadDigito*y
                translate               -1.675*AltoDisplay*x
              #break  // #case ( 0 )
              #case ( 1 )
                translate               1/3*UnidadDigito*y
                translate               -1.675*AltoDisplay*x
              #break  // #case ( 0 )
              #case ( 2 )
                translate               -1/3*UnidadDigito*y
                translate               -1.675*AltoDisplay*x
              #break  // #case ( 0 )
              #case ( 3 )
                translate               1/3*UnidadDigito*y
                translate               +1.550*AltoDisplay*x
              #break  // #case ( 0 )
              #case ( 4 )
                translate               -UnidadDigito*y
                translate               +1.550*AltoDisplay*x
              #break  // #case ( 0 )
            #end  // #switch( C )
            translate             +0.0875*AltoDisplay*x
            translate             -0.1*ProfundidadDisplay*z
            translate             ( Radial-AltoDisplay/2-DeltaSup )*y
            texture               {
              TexturaLED
            }
          }
        #end  // #if ( mod( Lucesita, 2 ) = 1 )
        #local Lucesita         = div( Lucesita, 2 );
        #local C                = C+1;
      #end  // #while ( C < 5 )
    }
  }
#end  // #macro BDCP_DisplayClock
