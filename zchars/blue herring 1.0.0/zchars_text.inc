// Title:        ZChars text macro
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   May 19, 2008
// Last updated: July 15, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
#ifndef(ZChars_Text_Inc)
#declare ZChars_Text_Inc = version;
#version 3.61;

#ifdef(View_POV_Include_Stack)
  #debug "including zchars_text.inc\n"
#end

#include "zchars.inc"

// ZC_Text
// This macro is intended to be used as a wrapper or replacement for the standard text object.
// The primary benefit of this macro is if it cannot find the requested font, it will fall back
// to using the internal object characters (as defined by zchars.inc), instead of failing with an
// error.  If the font is found the macro will created the text object using that font, exactly
// as if it was used directly.
//
// When using the object character set, the objects used are the same as those by ZC_Char_To_Obj and
// ZC_String_To_Obj.  This means that ZC_Text respects any changes made using ZC_Setup_Chars.  The
// character objects are scaled to be consistant with those produced by the text object (avg 
// 4x5x1 -> 0.48x0.6xThickness), and the thickness and offset parameters function the same way.
// The internal set should function just like a built in, fixed-width, font.
//
// Font -
//  Type: String
//  Use:  The name of the font file to use for the text object.  If the font file is available
//        then the macro will create a text obejct using it and the rest of the parameters.  If
//        the font file cannot be found an object string of internal object characters will be
//        creating using the same parameters, and a warning will be issued.  If Font is the 
//        empty string or "*" then the internal characters will be used uncondtionally and no
//        warning will be issued.
//
// String -
//  Type: String
//  Use:  The string of text to create the object from.
//
// Thickness -
//  Type: Float
//  Use:  The size of the resulting object in the z direction.  This corresponds to the 
//        thickness parameter for the text object.
//
// Offset -
//  Type: 3D vector
//  Use:  This is a vector that defines any extra translation between each character. This
//        corresponds to the offset parameter for the text object.
//
#macro ZC_Text(Font, String, Thickness, Offset)

  #ifndef(ZC_Text_No_Warning)
    #local ZC_Text_No_Warning = no;
  #end

  #if(strlen(Font) = 0 | strcmp(Font, "*") = 0)
    #local Internal = yes;
  #else
    #if(! file_exists(Font))
      #if(! ZC_Text_No_Warning)
        #warning concat("ZC_Text: Font file \"", Font, "\" not found, using internal characters.\n")
      #end
      #local Internal = yes;
    #else
      #local Internal = no;
    #end
  #end
  
  #if(Internal)
    #local Length = strlen(String);
    
    #if(Length <= 1)
      #local Result =
        object {
          ZC_Char_To_Obj(String)
          translate x * 2
          scale <0.8/5, 0.8/5, Thickness>
        }
    #else
      #local Off = Offset * <1, 1, 1>;
    
      #local Result =
        union {
          #local Ct = 1;
          #while(Ct <= Length)
            #local C = substr(String, Ct, 1);
            object {
              ZC_Char_To_Obj(C)
              translate x * 2
              //scale <0.8/5, 0.8/5, Thickness>
              scale <0.6/5, 0.6/5, Thickness>
              //translate <0.8 + Off.x, Off.y, Off.z> * (Ct - 1)
              translate <0.6 + Off.x, Off.y, Off.z> * (Ct - 1)
            }
              
            #local Ct = Ct + 1;
          #end
        }
    #end
    
  #else
  
    #local Result = text { ttf Font String Thickness, Offset } 
    
  #end
  
  Result
#end

#version ZChars_Text_Inc;
#end
