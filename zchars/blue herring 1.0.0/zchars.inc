// Title:        ZChars
// Version:      1.0.0
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   March 21, 2008
// Last updated: July 11, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
#ifndef(ZChars_Inc)
#declare ZChars_Inc = version;
#version 3.61;

#ifdef(View_POV_Include_Stack)
  #debug "including zchars.inc\n"
#end

#include "arrays.inc"
#include "chars.inc"
#include "transforms.inc"

// The following are a handful of additional character objects that were not
// included in chars.inc, but are in common usage (at least in English.)

#declare ZC_Comma =
  union {
    cylinder { <0, 0.5, 0>, <0, 0.5, 1>, 0.5 }
    difference {
      cylinder { 0, z, 0.5 scale <1, 2, 1> }
      cylinder { z * -0.0001, z * 1.0001, 0.5 
        scale <1, 2.1, 1> 
        translate x * -0.35
      }
      plane { -y, 0 }
      bounded_by {
        box { <-0.5, -1, 0>, <0.5, 0, 1> }
      }
      translate y * 0.5
    }
  }

#declare ZC_Space =
  box {
    /*<-2, 0, 0>, <2, 5, 1>*/
    -1e-15, 1e-15
    no_image
    no_shadow
    no_reflection
  }
  
#declare ZC_Period =
  cylinder { <0, 0.5, 0>, <0, 0.5, 1>, 0.5 }

#declare ZC_Colon =
  union {
    object { ZC_Period }
    object {
      ZC_Period
      translate y * 3
    }
  }
  
#declare ZC_Semicolon =
  union {
    object { ZC_Comma }
    object {
      ZC_Period
      translate y * 3
    }
  }

#declare ZC_Underline =
  box { <-2, 0, 0>, <2, 1, 1> } 
  
#declare ZC_Equals =
  union {
    box { <-2, 1.25, 0>, <2, 2.25, 1> }
    box { <-2, 2.75, 0>, <2, 3.75, 1> }
  }
  
#declare ZC_Apostrophe =
  object {
    ZC_Comma
    translate y * 4
  }
  
#declare ZC_LCurly =
  union {
    difference {
      cylinder { <1, 1.5, 0>, <1, 1.5, 1>, 1 }
      cylinder { <1, 1.5, -1>, <1, 1.5, 2>, 0.5 }
      plane { y, 1.5 }
      plane { -x, -1 }
      bounded_by {
        box { y * 1.5, <1, 2.5, 1> }
      }
    }
    difference {
      cylinder { <1, -1.5, 0>, <1, -1.5, 1>, 1 }
      cylinder { <1, -1.5, -1>, <1, -1.5, 2>, 0.5 }
      plane { -y, 1.5 }
      plane { -x, -1 }
      bounded_by {
        box { y * -2.5, <1, -1.5, 1> }
      }
    }
    difference {
      cylinder { <-0.5, 0.75, 0>, <-0.5, 0.75, 1>, 1 }
      cylinder { <-0.5, 0.75, -1>, <-0.5, 0.75, 2>, 0.5 }
      plane { -y, -0.75 }
      plane { x, -0.5 }
      bounded_by {
        box { <-0.5, -0.25, 0>, <0.5, 0.75, 1> }
      }
    }
    difference {
      cylinder { <-0.5, -0.75, 0>, <-0.5, -0.75, 1>, 1 }
      cylinder { <-0.5, -0.75, -1>, <-0.5, -0.75, 2>, 0.5 }
      plane { y, -0.75 }
      plane { x, -0.5 }
      bounded_by {
        box { <-0.5, -0.75, 0>, <0.5, 0.25, 1> }
      }
    }
    box { <0, 0.75, 0>, <0.5, 1.5, 1> }
    box { <0, -1.5, 0>, <0.5, -0.75, 1> }
    translate y * 2.5
  }
  
#declare ZC_RCurly =
  object {
    ZC_LCurly
    scale <-1, 1, 1>
  }
  
#declare ZC_Question =
  union {
    difference {
      cylinder { 0, z, 1.5 }
      cylinder { -z, z * 2, 0.5 }
      box { 
        <-3, -3, -1>, z * 2 
        Shear_Trans(x, vrotate(y, z * 45), z)
      }
      bounded_by {
        box { <-1.5, vrotate(y * -1.5, z * 45).y, 0>, <1.5, 1.5, 1> }
      }
    }
    box {
      0, <1, 0.5, 1>
      translate x * -1.5
      rotate z * 135
    }
    difference {
      cylinder { 0, z, 1.5 }
      cylinder { -z, z * 2, 0.5 }
      plane {
        -y, 0
        rotate z * 45
      }
      plane { y, 0 }
      bounded_by {
        box { x * vrotate(x * 0.5, z * 45).x, <1.5, vrotate(x * 1.5, z * 45).y, 1> }
      }
      translate <-2, 0.5, 0>
      rotate z * 135
    }
    box {
      x * 0.5, <1.5, 0.25, 1>
      rotate z * 45
      translate <-2, 0.5, 0>
      rotate z * 135
    }
    cylinder { y * -3, <0, -3, 1>, 0.5 }
    translate y * 3.5
  }

// ZC_Setup_Chars
// Associates a sequence of text characters to a sequence of objects.  This will set
// how characters are converted to objects by the text to object macros below.
//
//  Chars -
//   Type: String
//   Use:  This is a string containing a sequence of text characters to be associated.  Upper
//         and lower case letters are seperate characters, so both should be included if
//         both cases are supported.
//
//  Objects -
//   Type: 1D array of objects
//   Use:  This is an array enumerating the objects to be associated to the characters in
//         Chars.  The array should have the same number of elements as the number of 
//         characters in Chars, and each object will be associated in order to each character.
//         The objects should conform to the sizing and placement of characters in chars.inc:
//         size 4x5x1 with the bottom center of the -z face at the origin.
//
//  Unknown_Obj -
//   Type: Object
//   Use:  This is a fallback object that is used when a requested character is not found in
//         Chars.  It can be one of the objects in Objects, or a different one altogether.
//
// By default the character conversions are setup to support all of the character objects in
// chars.inc plus the additional ones defined above.  The variables ZC_Default_Chars,
// ZC_Default_Objects, and ZC_Default_Unknown and the macro ZC_Reset_Chars provide an example
// usage of ZC_Setup_Chars.
//
#macro ZC_Setup_Chars(Chars, Objects, Unknown_Obj)
  #if(strlen(Chars) != dimension_size(Objects, 1))
    #error "ZC_Setup_Chars: Number of characters does not match number of objects.\n"
  #else
    #declare ZC_Chars = Chars;
    #declare ZC_Objects = Objects;
    #declare ZC_Unknown = Unknown_Obj;
  #end
#end

// ZC_Reset_Chars
// Resets the current character associations to the defaults.  The default set includes all
// the objects in chars.inc (for both upper and lower case) and the additional ones defined
// above.
//
#macro ZC_Reset_Chars()
  ZC_Setup_Chars(ZC_Default_Chars, ZC_Default_Objects, ZC_Default_Unknown)
#end

// ZC_Push_Chars
// Saves the current character associations on an internal stack, and sets the current ones to
// the input values.  The parameters are identical in form and use to those of ZC_Setup_Chars.
//
#macro ZC_Push_Chars(Chars, Objects, Unknown_Obj)
  #local Sz = dimension_size(ZC_Chars_Stack, 1);
  
  #if(ZC_Stack_Counter = Sz)
    Resize_Array(ZC_Chars_Stack, Sz + ZC_Stack_Inc)
    Resize_Array(ZC_Objects_Stack, Sz + ZC_Stack_Inc)
    Resize_Array(ZC_Unknown_Stack, Sz + ZC_Stack_Inc)
  #end
  
  #declare ZC_Chars_Stack[ZC_Stack_Counter] = ZC_Chars;
  #declare ZC_Objects_Stack[ZC_Stack_Counter] = ZC_Objects;
  #declare ZC_Unknown_Stack[ZC_Stack_Counter] = ZC_Unknown;
  
  ZC_Setup_Chars(Chars, Objects, Unknown_Obj)
  
  #declare ZC_Stack_Counter = ZC_Stack_Counter + 1;
#end

// ZC_Push_Reset
// Saves the current character mapping on the internal stack, then resets the current
// mapping to the default values as with ZC_Reset_Chars.
//
#macro ZC_Push_Reset()
  ZC_Push_Chars(ZC_Default_Chars, ZC_Default_Objects, ZC_Default_Unknown)
#end

// ZC_Pop_Chars
// Discards the current character associations, and restores the prior ones from the internal
// stack.  They are restored in the reverse order from how they were saved, ie the most recent
// map saved by ZC_Push_Chars/ZC_Push_Reset will be restored first, then the next most recent, etc.
//
#macro ZC_Pop_Chars()
  #if(ZC_Stack_Counter = 0)
    #error "ZC_Pop_Chars: Character stack is empty, cannot pop.\n"
  #else
    #declare ZC_Stack_Counter = ZC_Stack_Counter - 1;
    #declare ZC_Chars = ZC_Chars_Stack[ZC_Stack_Counter];
    #declare ZC_Objects = ZC_Objects_Stack[ZC_Stack_Counter];
    #declare ZC_Unknown = ZC_Unknown_Stack[ZC_Stack_Counter];
    
    #undef ZC_Chars_Stack[ZC_Stack_Counter]
    #undef ZC_Objects_Stack[ZC_Stack_Counter]
    #undef ZC_Unknown_Stack[ZC_Stack_Counter]
  #end
#end

// ZC_Stack_Size
// Returns the number of mappings that have been pushed onto the internal stack.
//
#macro ZC_Stack_Size()
  ZC_Stack_Counter
#end

// ZC_Stack_Empty
// Returns true if the internal mapping stack is empty, false otherwise.
//
#macro ZC_Stack_Empty()
  (ZC_Stack_Counter = 0)
#end

// ZC_Char_Known
// Returns true or false indicating whether the input character has an object associated to it.
//
//  Char:
//   Type: String
//   Use:  The first character of this string is checked for whether it has a corresponding
//         object in the given set.
//
#macro ZC_Char_Known(Char)
  (ZC_Find_Char(ZC_Chars, Char) > 0)
#end  

// ZC_Char_To_Obj
// Converts a given text character to a character object.  If the input character does not
// have a specific object associated to it, then the current unknown object will be returned.
// The returned object should be approximately 4x5x1, with the bottom of the -z face centered 
// on the origin.  The empty string will also return the unknown object.
//
//  Char -
//   Type: String
//   Use:  The first character of this string will be converted to an object.
//  
#macro ZC_Char_To_Obj(Char)
  #local Ct = ZC_Find_Char(ZC_Chars, Char);

  #if(Ct = 0)
    #local Result = ZC_Unknown;
  #else
    #local Result = ZC_Objects[Ct - 1];
  #end
  
  Result
#end

// ZC_String_To_Obj
// Converts a string to a union of character objects representing the string.  Any unsupported
// characters will be converted to the unknown object.  The resulting object will have its lower
// left-front corner at the origin, and extends in the +x direction.
//
//  String -
//   Type: String
//   Use:  String to convert.
//
//  Spacing -
//   Type: Float
//   Use:  Size of the gap in units between characters.
//
#macro ZC_String_To_Obj(String, Spacing)
  #local Length = strlen(String);
  
  #if(Length <= 1)
    #local Result = 
      object {
        ZC_Char_To_Obj(String)
        translate x * 2
      }
  #else
    #local Result =
      union {
        #local Ct = 1;
        #while(Ct <= Length)
          #local C = substr(String, Ct, 1);
          object {
            ZC_Char_To_Obj(C)
            translate x * ((4 + Spacing) * (Ct - 1) + 2)
          }
          #local Ct = Ct + 1;
        #end
      }
  #end
  
  Result
#end

// ZC_Default_Chars
// The default character sequence string for default character/object mapping.
//
#declare ZC_Default_Chars =
  "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ-+0123456789!@#$%^&*()[], .:;_='{}?";
  
// ZC_Default_Objects
// The default object sequence for the default character/object mapping.  Both
// upper and lower case letters are mapped to the same character from chars.inc.
//
#declare ZC_Default_Objects = 
  array[strlen(ZC_Default_Chars)] {
    char_A, char_A, char_B, char_B, char_C, char_C, char_D, char_D, char_E, char_E,
    char_F, char_F, char_G, char_G, char_H, char_H, char_I, char_I, char_J, char_J,
    char_K, char_K, char_L, char_L, char_M, char_M, char_N, char_N, char_O, char_O,
    char_P, char_P, char_Q, char_Q, char_R, char_R, char_S, char_S, char_T, char_T,
    char_U, char_U, char_V, char_V, char_W, char_W, char_X, char_X, char_Y, char_Y,
    char_Z, char_Z, char_Dash, char_Plus, char_0, char_1, char_2, char_3, char_4,
    char_5, char_6, char_7, char_8, char_9, char_ExclPt, char_AtSign, char_Num,
    char_Dol, char_Perc, char_Hat, char_Amps, char_Astr, char_LPar, char_RPar,
    char_LSqu, char_RSqu, ZC_Comma, ZC_Space, ZC_Period, ZC_Colon, ZC_Semicolon,
    ZC_Underline, ZC_Equals, ZC_Apostrophe, ZC_LCurly, ZC_RCurly, ZC_Question
  };

// ZC_Default_Unknown
// The default unknown object for characters not specifically mapped.
//
#declare ZC_Default_Unknown = ZC_Space;

// Internal macros and structures.  These should not be used directly as they may
// change in future versions.

// ZC_Find_Char
// Internal macro to find a given character in a string and return its position.
//
#macro ZC_Find_Char(String, Char)
  #if(strlen(Char) = 0)
    #local Result = 0;
  #else
    #local Len = strlen(String);
    #local C = substr(Char, 1, 1);
    #local Ct = 1;
    #local Fnd = no;
    #while(Ct <= Len & ! Fnd)
      #if(strcmp(C, substr(String, Ct, 1)) = 0)
        #local Fnd = yes;
      #else
        #local Ct = Ct + 1;
      #end
    #end
    
    #local Result = (Fnd ? Ct : 0);
  #end
  
  Result
#end

// Internal stack data for ZC_Push_Chars and ZC_Pop_Chars.
//
#declare ZC_Stack_Inc     = 10;
#declare ZC_Chars_Stack   = array[ZC_Stack_Inc];
#declare ZC_Objects_Stack = array[ZC_Stack_Inc];
#declare ZC_Unknown_Stack = array[ZC_Stack_Inc];
#declare ZC_Stack_Counter = 0;

// Setup the initial default mapping when file is included.
//
ZC_Reset_Chars()

#version ZChars_Inc;
#end
