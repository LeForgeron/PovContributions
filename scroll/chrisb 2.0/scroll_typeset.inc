
// scroll_typeset.inc
// ------------------

// Include file for a collection of typesetting Macros.
// Created by Chris Bartlett 12.08.2008
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
// These utility macros work together to take strings of text and build them into a block of text.   
// The text can be wrapped based upon a specified linelength and can be Left, Right, Center or Full justified.
// The text block can be scaled to fit in a unit square, suitable for uv-mapping, respecting specified margins.
// You can subsequently use the formatted text as an object pigment to write on another POV-Ray object


#ifndef (Shear_Trans) #include "transforms.inc" #end

// This macro parses a line of text, splitting the line into multiple lines at word breaks based upon a maximum line length.
// It populates the Scroll_TextArray array with the results. 
// This macro accepts one parameter:
//   Scroll_TextIn - The text that is to be split up.
//
#macro Scroll_WrapText(Scroll_TextIn) 
  #local Scroll_Verbose = 0;   // Option to add messages to debug stream
  // Set some defaults to make the macro as robust as possible.
  #ifndef (Scroll_LineLength)                  #declare Scroll_LineLength  = 12;                 #end
  #ifndef (Scroll_FontFile)                    #declare Scroll_FontFile    = "timrom.ttf";       #end
  #ifndef (Scroll_LineIndex)                   #declare Scroll_LineIndex   = 0;                  #end
  #ifndef (Scroll_TextArray)                   #declare Scroll_TextArray   = array[1000];        #end
  // If the line has something on it already add a space to seperate the old from the new text
  #ifndef (Scroll_TextArray[Scroll_LineIndex])
    #declare Scroll_TextArray[Scroll_LineIndex] = "";
  #else
    #if (strlen(Scroll_TextArray[Scroll_LineIndex])=0)
      #declare Scroll_TextArray[Scroll_LineIndex] = "";
    #else
      #declare Scroll_TextArray[Scroll_LineIndex] = concat(Scroll_TextArray[Scroll_LineIndex]," ");
    #end
  #end 
  // Initialise some working variables
  #local Scroll_CharIndex      = 1;
  #local Scroll_ThisLineLength = 0;  
  #local Scroll_WordCount      = 0;
  #local Scroll_ProcessingWord = 0;
  #local Scroll_Spaces         = "";
  #local Scroll_Word           = "";  
  // Loop through the string one character at a time looking for spaces (word breaks).
  #while (Scroll_CharIndex <= strlen(Scroll_TextIn))
    #local Scroll_ThisChar = substr(Scroll_TextIn,Scroll_CharIndex,1);
    // If we're in the middle of processing a word
    #if (Scroll_ProcessingWord)
      // Encountering a space or reaching the end of the line means we've reached the end of a word 
      #if (strcmp(Scroll_ThisChar," ")=0 | Scroll_CharIndex = strlen(Scroll_TextIn))
        // If non-blank then it's the last character from the string, which needs adding to the end of the word 
        #if (strcmp(Scroll_ThisChar," ")!=0) #local Scroll_Word = concat(Scroll_Word,Scroll_ThisChar); #end
        #local Scroll_WordCount = Scroll_WordCount + 1;
        // Create a text object to test length
        #if (strlen(Scroll_TextArray[Scroll_LineIndex])=0)
          #local Scroll_TempText = concat(Scroll_Spaces,Scroll_Word);
          #local Scroll_JustOneWord = 1;
        #else
          #local Scroll_TempText = concat(Scroll_TextArray[Scroll_LineIndex],Scroll_Spaces,Scroll_Word);
          #local Scroll_JustOneWord = 0;
        #end
        #local Scroll_TempTextObject = text{ttf Scroll_FontFile Scroll_TempText 1, 0}
        // If line is too long, start new one. Otherwise append this word to the current line.
        #if (max_extent(Scroll_TempTextObject).x>Scroll_LineLength & !Scroll_JustOneWord)
          #if (Scroll_Verbose)  
            #debug concat(Scroll_TextArray[Scroll_LineIndex],"\n")          
          #end
          #declare Scroll_LineIndex = Scroll_LineIndex + 1;
          #declare Scroll_TextArray[Scroll_LineIndex] = Scroll_Word;
        // If not too long, record the concatenated string 
        #else
          #declare Scroll_TextArray[Scroll_LineIndex] = Scroll_TempText;
        #end
        #local Scroll_Word = "";
        #local Scroll_ProcessingWord = 0;
        #local Scroll_Spaces = " ";
      // If not a space, append character to word and continue to next character
      #else
        #local Scroll_Word = concat(Scroll_Word,Scroll_ThisChar);
      #end
    // If we're not processing a word at the moment
    #else
      // If it's a space then accumulate spaces 
      #if (strcmp(Scroll_ThisChar," ")=0)
        #local Scroll_Spaces = concat(Scroll_Spaces," ");
      // Reaching a non-blank character means we start a new word
      #else
        #local Scroll_ProcessingWord = 1;
        #local Scroll_Word = Scroll_ThisChar;
      #end
    #end    
    
    // Move on to the next character in the input string
    #local Scroll_CharIndex = Scroll_CharIndex+1; 
  #end
#end  


//
// This macro adds a carriage return/line throw to the text array. 
// It requires one parameter:
//   Scroll_ParagraphSpacing - controls the number of line throws.
//
#macro Scroll_NewParagraph(Scroll_ParagraphSpacing)
  // Set some defaults to make the macro as robust as possible.
  #ifndef (Scroll_LineIndex)                   #declare Scroll_LineIndex        = 0;           #end
  #ifndef (Scroll_TextArray)                   #declare Scroll_TextArray        = array[1000]; #end 
  #local Scroll_NewLineCount = 0;
  #while (Scroll_NewLineCount<Scroll_ParagraphSpacing)
    #declare Scroll_LineIndex = Scroll_LineIndex + 1;
    #declare Scroll_TextArray[Scroll_LineIndex] = ""; 
    #local Scroll_NewLineCount = Scroll_NewLineCount + 1;
  #end
#end


//
// This macro generates a CSG object built of multiple text objects with each line of text being taken from the
// Scroll_TextArray array. 
// This macro accepts one parameter:
//   Scroll_Justification - "Left", "Right" or "Centre" to specify how the text is to be justified.
//
#macro Scroll_MakeTextObject (Scroll_Justification)
  // Check that the required text array is set.
  #ifndef (Scroll_TextArray)
    Scroll_TypeSet("You should assign text to the Scroll_TextArray before calling the Scroll_MakeTextObject macro.")
    Scroll_TypeSet ("You can do this most easily using the Scroll_TypeSet macro (see scroll.html).")
  #end
  // Set some defaults to make the macro as robust as possible.
  #ifndef (Scroll_LineIndex)     #declare Scroll_LineIndex     = dimension_size(Scroll_TextArray,1)-1; #end 
  #ifndef (Scroll_LineLength)    #declare Scroll_LineLength    = 12;                                   #end
  #ifndef (Scroll_FontFile)      #declare Scroll_FontFile      = "timrom.ttf";                         #end
  #ifndef (Scroll_LineSpacing)   #declare Scroll_LineSpacing   = 1;                                    #end
  #ifndef (Scroll_ScaleOverruns) #declare Scroll_ScaleOverruns = 1;                                    #end
  #ifndef (Scroll_TextSlant)     #declare Scroll_TextSlant     = 0;                                    #end
  #ifndef (Scroll_Orientation)   #declare Scroll_Orientation   = "Portrait";                           #end
  
  // Initialise the temporary variable that controls the loop
  #local Scroll_I = 0;
  // Return a single CSG object
  union {
    // Loop through the elements of the Scroll_TextArray array.
    #while (Scroll_I<=Scroll_LineIndex)
      #if (strlen(Scroll_TextArray[Scroll_I])>0)
        // Create a text object and measure the width
        #local Scroll_TempTextObject = text{ttf Scroll_FontFile Scroll_TextArray[Scroll_I] 1, 0}
        #local Scroll_TextWidth = max_extent(Scroll_TempTextObject).x; 
        // Handle any single-word lines that are longer than the linelength
        #if (Scroll_ScaleOverruns & Scroll_TextWidth>Scroll_LineLength)
          #local Scroll_TempTextObject = object {Scroll_TempTextObject scale <Scroll_LineLength/Scroll_TextWidth,1,1>}
        #end
        // Define an aligned text object and add it into the CSG. 
        #switch (0)
          #case (Scroll_CompareStrings(Scroll_Justification,"Left",1))
          #break 
          #case (Scroll_CompareStrings(Scroll_Justification,"Right",1))
            #local Scroll_TempTextObject = object {Scroll_TempTextObject translate x*(Scroll_LineLength-Scroll_TextWidth)}
          #break
          #case (Scroll_CompareStrings(Scroll_Justification,"Center",1))
          #case (Scroll_CompareStrings(Scroll_Justification,"Centre",1))
            #local Scroll_TempTextObject = object {Scroll_TempTextObject translate x*(Scroll_LineLength-Scroll_TextWidth)/2}
          #break
          #case (Scroll_CompareStrings(Scroll_Justification,"Full",1))
            // Full justification is a bit more complicated, so it's handled within a special macro
            #local Scroll_TempTextObject = object {Scroll_FullJustification(Scroll_TextArray[Scroll_I],Scroll_TextWidth,Scroll_LineLength)}
          #break
        #end 
        object {Scroll_TempTextObject 
          Shear_Trans(x,<Scroll_TextSlant,1,0>,z)
          translate -y*Scroll_LineSpacing*Scroll_I
        }
      #end
      #local Scroll_I = Scroll_I + 1;
    #end
    #if (Scroll_CompareStrings(Scroll_Orientation,"Landscape",1)=0) rotate z*90 #end
  }
#end   


// This macro takes a text string and adjusts the spaces between words to fully justify the line to a specified length
// It takes three parameters:
//     
//   Scroll_TextIn     - The text string to be processed
//   Scroll_TextWidth  - The current width of the text
//   Scroll_LineLength - The desired line length
// 
#macro Scroll_FullJustification(Scroll_TextIn,Scroll_TextWidth,Scroll_LineLength) 
  #local Scroll_WordCount  = 0;
  #local Scroll_WhiteSpaceNeeded = Scroll_LineLength - Scroll_TextWidth;
  #if (strcmp(substr(Scroll_TextIn,strlen(Scroll_TextIn),1),".")=0) #local Scroll_WhiteSpaceNeeded = 0; #end
  #if (strcmp(substr(Scroll_TextIn,strlen(Scroll_TextIn),1),":")=0) #local Scroll_WhiteSpaceNeeded = 0; #end
  #if (strcmp(substr(Scroll_TextIn,strlen(Scroll_TextIn),1),"!")=0) #local Scroll_WhiteSpaceNeeded = 0; #end
  #if (strcmp(substr(Scroll_TextIn,strlen(Scroll_TextIn),1),"?")=0) #local Scroll_WhiteSpaceNeeded = 0; #end
  // If the text is already too long or it's the end of a paragraph it'll just stay as-is
  #if (Scroll_WhiteSpaceNeeded>0)
    #local Scroll_CharIndex       = 1; 
    #local Scroll_Word            = "";
    #local Scroll_TotalTextLength = 0;
    #local Scroll_ProcessingWord  = 0;
    #local Scroll_TotalSpaces     = 0;
    #local Scroll_WordObjectArray = array[1000];
    #local Scroll_WordLengthArray = array[1000];
    #local Scroll_WhiteSpaceCount = array[1000];
    #local Scroll_WhiteSpaceCount[Scroll_WordCount] = 0;
    // Loop through the string one character at a time looking for words and spaces.
    // Create an array of text objects, one element for each word and count the number of spaces 
    // at the start of the line and between each word.
    #while (Scroll_CharIndex <= strlen(Scroll_TextIn))
      #local Scroll_ThisChar = substr(Scroll_TextIn,Scroll_CharIndex,1);
      #if (strcmp(Scroll_ThisChar," ")!=0)
        #local Scroll_ProcessingWord = 1;
      #end 
      // If we're in the middle of processing a word
      #if (Scroll_ProcessingWord)
        // Encountering a space or reaching the end of the line means we've reached the end of a word 
        #if (strcmp(Scroll_ThisChar," ")=0 | Scroll_CharIndex = strlen(Scroll_TextIn))
          // If non-blank then it's the last character from the string, which needs adding to the end of the word 
          #if (strcmp(Scroll_ThisChar," ")!=0) #local Scroll_Word = concat(Scroll_Word,Scroll_ThisChar); #end
          // Create a text object from the current word and record its length
          #local Scroll_WordObjectArray[Scroll_WordCount] = text{ttf Scroll_FontFile Scroll_Word 1, 0}
          #local Scroll_WordLengthArray[Scroll_WordCount] = max_extent(Scroll_WordObjectArray[Scroll_WordCount]).x-min_extent(Scroll_WordObjectArray[Scroll_WordCount]).x;
          #local Scroll_TotalTextLength = Scroll_TotalTextLength + Scroll_WordLengthArray[Scroll_WordCount];
          #local Scroll_WordCount = Scroll_WordCount + 1;
          // If the current character is a space, add it into the new space count and the total
          #if (strcmp(Scroll_ThisChar," ")=0) 
            #local Scroll_WhiteSpaceCount[Scroll_WordCount] = 1; 
            #local Scroll_TotalSpaces = Scroll_TotalSpaces + 1;
          // Otherwise just initialise the new space count array element
          #else
            #local Scroll_WhiteSpaceCount[Scroll_WordCount] = 0; 
          #end 
          #local Scroll_ProcessingWord = 0;
          #local Scroll_Word = "";
        // If not a space and it's not the end of the line, append character to word and continue to next character
        #else
          #local Scroll_Word = concat(Scroll_Word,Scroll_ThisChar);
        #end
      // Otherwise it's a duplicate space, so just add it to the spaces count 
      #else
        #local Scroll_WhiteSpaceCount[Scroll_WordCount] = Scroll_WhiteSpaceCount[Scroll_WordCount]+1;
        #local Scroll_TotalSpaces = Scroll_TotalSpaces + 1;
      #end
      // Move on to the next character in the input string
      #local Scroll_CharIndex = Scroll_CharIndex+1; 
    #end
  #end

  #if (Scroll_WordCount<2) #local Scroll_WhiteSpaceNeeded = 0; #end

  // If we need to generate a new text object, loop through the words and build it
  #if (Scroll_WhiteSpaceNeeded>0) 
    #local Scroll_SpaceWidth = (Scroll_LineLength - Scroll_TotalTextLength)/Scroll_TotalSpaces;
    #local Scroll_TempTextObject = union {
      // Add in all the words and spaces to build the new text object    
      #local Scroll_ThisWordIndex=0;
      #local Scroll_CurrentPosition = 0;
      // Build a text object for the line
      #while (Scroll_ThisWordIndex<Scroll_WordCount)
        // Work out the width of the space preceding the current word and adjust the current position accordingly
        #local Scroll_CurrentPosition = Scroll_CurrentPosition + Scroll_SpaceWidth*Scroll_WhiteSpaceCount[Scroll_ThisWordIndex];
        // Add the word object, translating it into position
        object {Scroll_WordObjectArray[Scroll_ThisWordIndex] translate x*Scroll_CurrentPosition}
        // Add the word length to the current position
        #local Scroll_CurrentPosition = Scroll_CurrentPosition + Scroll_WordLengthArray[Scroll_ThisWordIndex];
        #local Scroll_ThisWordIndex = Scroll_ThisWordIndex + 1;
      #end 
    }
  #else
    #local Scroll_TempTextObject = text{ttf Scroll_FontFile Scroll_TextIn 1, 0}
  #end
  object {Scroll_TempTextObject}
#end


// This macro fits a block of text into a unit square, respecting any margins specified
// This macro takes one parameter:
//   Scroll_ObjectIn - is the text object
// 
#macro Scroll_FitToUnitSquare (Scroll_ObjectIn)
  #ifndef (Scroll_TopMargin   )             #declare Scroll_TopMargin     = 0.3;                 #end
  #ifndef (Scroll_BottomMargin)             #declare Scroll_BottomMargin  = 0.32;                #end
  #ifndef (Scroll_LeftMargin  )             #declare Scroll_LeftMargin    = 0.1;                 #end
  #ifndef (Scroll_RightMargin )             #declare Scroll_RightMargin   = 0.1;                 #end
  // Work out the location and size of the object
  #declare Scroll_ObjectMinExtents = min_extent(Scroll_ObjectIn);
  #declare Scroll_ObjectDimensions = max_extent(Scroll_ObjectIn)-min_extent(Scroll_ObjectIn);
  // Move it to the origin, scale it to fit a unit square and translate it to align with the bottom and left margins.
  object {Scroll_ObjectIn
    translate -Scroll_ObjectMinExtents 
    scale <1-Scroll_LeftMargin-Scroll_RightMargin,1-Scroll_TopMargin-Scroll_BottomMargin,1>/<Scroll_ObjectDimensions.x,Scroll_ObjectDimensions.y,Scroll_ObjectDimensions.z>
    translate <Scroll_LeftMargin,Scroll_BottomMargin,-0.5>
  }
#end 
             
             
// This macro compares two strings and returns a '0' if they match or a '1' if they don't.
// The macro capabilities are limited by the desire to be able to embed it within #case 
// clauses of the #switch directive
// It converts both string to upper case for the purposes of the comparison.
// The first string can be an abbreviation of the second string so long as it's length is 
// greater than the minimum length requirements as dictated by the third parameter.
//
// This macro takes three parameters:
//   Scroll_String1       - The first string
//   Scroll_String2       - The second string
//   Scroll_MinimumLength - The minimum string length accepted for the comparison
//    
#macro Scroll_CompareStrings (Scroll_String1, Scroll_String2, Scroll_MinimumLength)
  strcmp(strupr(Scroll_String1),substr(strupr(Scroll_String2),Scroll_MinimumLength,min(strlen(Scroll_String1),strlen(Scroll_String2))))
#end 


// This macro undefines all of the global variables used to control the generation of the text object
// used to display text upon the scroll object.
#macro Scroll_TypeSet_Undef()
  #ifdef (Scroll_LineLength    ) #undef Scroll_LineLength    #end
  #ifdef (Scroll_FontFile      ) #undef Scroll_FontFile      #end
  #ifdef (Scroll_LineIndex     ) #undef Scroll_LineIndex     #end
  #ifdef (Scroll_TextArray     ) #undef Scroll_TextArray     #end
  #ifdef (Scroll_LineSpacing   ) #undef Scroll_LineSpacing   #end
  #ifdef (Scroll_ScaleOverruns ) #undef Scroll_ScaleOverruns #end
  #ifdef (Scroll_TextSlant     ) #undef Scroll_TextSlant     #end
  #ifdef (Scroll_Orientation   ) #undef Scroll_Orientation   #end
  #ifdef (Scroll_TopMargin     ) #undef Scroll_TopMargin     #end
  #ifdef (Scroll_BottomMargin  ) #undef Scroll_BottomMargin  #end
  #ifdef (Scroll_LeftMargin    ) #undef Scroll_LeftMargin    #end
  #ifdef (Scroll_RightMargin   ) #undef Scroll_RightMargin   #end
#end


