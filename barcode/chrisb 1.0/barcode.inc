//
// barcode.inc
// -----------
// Created by Chris Bartlett March 2008
// This include file contains a macro to generate an EAN (European Article Number) barcode.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The barcodes fits into a cube from <0,0,0> <1,1,1>.
//
// Render times are typically half a minute to a couple of minutes depending on size.  
//


// This macro creates a barcode in a 1 POV-Ray unit box between <0,0,0> and <1,1,1> 
// with the bars and numbers facing towards -Z and running from 0 to +X.
// It is an attempt at European Article Number (EAN) barcodes with a lead digit of '0'
// but the technical accuracy is not in any way guaranteed by the author.
// For a technical description see http://en.wikipedia.org/wiki/European_Article_Number
//
//   PatternDigit      A value between 0 and 9 which identifies the encoding pattern of the barcode. 
//                     An EAN with a leading '0' should produce a barcode compatible with the 
//                     UPC (Universal Product Code) system developed in North America.
//   String            The string of digits that the barcode will represent.
//   ClippingHeight    The height above the x-axis at which the barcode bars should end.
//                     Note. This is relative to a height of 1 POV-Ray unit, so values typically 
//                     range from 0.5 to 1.                                 
#macro BarCode_EAN(PatternDigit, String, ClippingHeight) 
  #local BorderWidth        = 0.05;
  #local CharacterSpacing   = 1/15;
  #local CharacterWidth     = 1/12;
  #local CharacterHeight    = 1/12; 
  #local SeparatorBarSpacer = 2;
  #local BarWidth           = (1-CharacterSpacing-BorderWidth)/(7*(strlen(String)+SeparatorBarSpacer));
  #local BarBottom          = BorderWidth+CharacterHeight;
  #local ExtendedBarBottom  = BarBottom - CharacterHeight/2;
  // The representation of a digit depends on the encoding and the position in the bar code.
  #declare BarCode_LDigit = array[10];    #declare BarCode_GDigit = array[10];    #declare BarCode_RDigit = array[10];   
  #declare BarCode_LDigit[0] = "0001101"; #declare BarCode_GDigit[0] = "0100111"; #declare BarCode_RDigit[0] = "1110010";
  #declare BarCode_LDigit[1] = "0011001"; #declare BarCode_GDigit[1] = "0110011"; #declare BarCode_RDigit[1] = "1100110";
  #declare BarCode_LDigit[2] = "0010011"; #declare BarCode_GDigit[2] = "0011011"; #declare BarCode_RDigit[2] = "1101100";
  #declare BarCode_LDigit[3] = "0111101"; #declare BarCode_GDigit[3] = "0100001"; #declare BarCode_RDigit[3] = "1000010";
  #declare BarCode_LDigit[4] = "0100011"; #declare BarCode_GDigit[4] = "0011101"; #declare BarCode_RDigit[4] = "1011100";
  #declare BarCode_LDigit[5] = "0110001"; #declare BarCode_GDigit[5] = "0111001"; #declare BarCode_RDigit[5] = "1001110";
  #declare BarCode_LDigit[6] = "0101111"; #declare BarCode_GDigit[6] = "0000101"; #declare BarCode_RDigit[6] = "1010000";
  #declare BarCode_LDigit[7] = "0111011"; #declare BarCode_GDigit[7] = "0010001"; #declare BarCode_RDigit[7] = "1000100";
  #declare BarCode_LDigit[8] = "0110111"; #declare BarCode_GDigit[8] = "0001001"; #declare BarCode_RDigit[8] = "1001000";
  #declare BarCode_LDigit[9] = "0001011"; #declare BarCode_GDigit[9] = "0010111"; #declare BarCode_RDigit[9] = "1110100"; 
  // The first digit determines the encoding pattern used for the first 6 digits.
  #declare BarCode_FDigit = array[10];   
  #declare BarCode_FDigit[0] = "LLLLLL"; 
  #declare BarCode_FDigit[1] = "LLGLGG"; 
  #declare BarCode_FDigit[2] = "LLGGLG"; 
  #declare BarCode_FDigit[3] = "LLGGGL"; 
  #declare BarCode_FDigit[4] = "LGLLGG"; 
  #declare BarCode_FDigit[5] = "LGGLLG"; 
  #declare BarCode_FDigit[6] = "LGGGLL"; 
  #declare BarCode_FDigit[7] = "LGLGLG"; 
  #declare BarCode_FDigit[8] = "LGLGGL"; 
  #declare BarCode_FDigit[9] = "LGGLGL";
  #declare EncodingPattern = BarCode_FDigit[PatternDigit]; 
  // Return a union of boxes to represent the bars and the text to represent each numeric digit
  union {
    text {ttf "arial.ttf" str(PatternDigit,0,0) 1,0 scale <CharacterWidth,CharacterWidth,1> translate <BorderWidth,BorderWidth,0>} 
    #local Displacement = BorderWidth+1/15;
    // Start with a double bar separator
    box {<0,ExtendedBarBottom,0>,<BarWidth,ClippingHeight,1> translate x*Displacement} 
    #local Displacement = Displacement + 2*BarWidth;
    box {<0,ExtendedBarBottom,0>,<BarWidth,ClippingHeight,1> translate x*Displacement} 
    #local Displacement = Displacement + BarWidth;
    #local StringIndex = 1;
    #while (StringIndex<=strlen(String))
      #local Character = substr(String,StringIndex,1); 
      text {ttf "arial.ttf" Character 1,0 scale <CharacterWidth,CharacterWidth,1> translate <Displacement+BarWidth,BorderWidth,0>} 
      #local BinaryIndex = 1;
      #if (StringIndex<=6)
        #if (strcmp(substr(EncodingPattern,StringIndex,1),"L")=0)
          #local BinaryString = BarCode_LDigit[val(Character)];
        #else
          #local BinaryString = BarCode_GDigit[val(Character)];
        #end
      #else
        #local BinaryString = BarCode_RDigit[val(Character)];
      #end
      #while (BinaryIndex<=strlen(BinaryString))
        #local Binary = substr(BinaryString,BinaryIndex,1); 
        #if (val(Binary))
          box {<0,BarBottom,0>,<BarWidth,ClippingHeight,1> translate x*Displacement} 
        #end 
        #local Displacement = Displacement + BarWidth;
        #local BinaryIndex = BinaryIndex + 1;
      #end
      #if (StringIndex=6)
        // Add a double bar separator after the first block of 6 digits
        #local Displacement = Displacement + BarWidth;
        box {<0,ExtendedBarBottom,0>,<BarWidth,ClippingHeight,1> translate x*Displacement} 
        #local Displacement = Displacement + 2*BarWidth;
        box {<0,ExtendedBarBottom,0>,<BarWidth,ClippingHeight,1> translate x*Displacement} 
        #local Displacement = Displacement + 2*BarWidth;
      #end
      #local StringIndex = StringIndex + 1;
    #end
    // End with a double bar separator
    box {<0,ExtendedBarBottom,0>,<BarWidth,ClippingHeight,1> translate x*Displacement} 
    #local Displacement = Displacement + 2*BarWidth;
    box {<0,ExtendedBarBottom,0>,<BarWidth,ClippingHeight,1> translate x*Displacement} 
  }
#end  
