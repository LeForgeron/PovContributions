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
#include "colors.inc"

#local OjoAbsoluto            = 256;
#local VecesCentroAbsoluto    = 10;     
#local L                      = 0.001;

camera {
        location  <   0,  0, -( VecesCentroAbsoluto+1 )*OjoAbsoluto >*L
        direction z
        sky       y
        angle     38.74
//        look_at  <   0,  0, -VecesCentroAbsoluto*OjoAbsoluto >*L
}         
light_source    {
         < 500  , 500   , -3000 >*L
         White
}
background      {
         Gray50
}    

#include "SPMF.inc"

#local FactorAcercamiento       = 20.0;    

object                          {
  SPMF_Sello()                      
  translate       -( VecesCentroAbsoluto+1 )*( FactorAcercamiento-1 )
                        /( FactorAcercamiento )*OjoAbsoluto*L*z
}

