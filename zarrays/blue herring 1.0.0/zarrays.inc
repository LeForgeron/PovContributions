// Title:        ZArrays
// Version:      1.0.0
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   February 21, 2008
// Last Updated: February 22, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
#ifndef(ZArrays_Inc)
#declare ZArrays_Inc = version;
#version 3.61;

#ifdef(View_POV_Include_Stack)
  #debug "including zarrays.inc\n"
#end

// ZA_Append_Arrays
// Concatenates two one-dimensional arrays.
//  Array_1, Array_2 - Arrays to concatenate.  They need not be the same length.
//  Appended         - This will return the combined array.  The new array will be as long as the
//                     combined lengths of the input arrays.
// Example:
//   #declare A1 = array[3] {1, 2, 3};
//   #declare A2 = array[2] {4, 5};
//   #declare A  = array[1];
//   ZA_Append_Arrays(A1, A2, A)
//   // A will be equal to {1, 2, 3, 4, 5}
//
#macro ZA_Append_Arrays(Array_1, Array_2, Appended)
  
  #if(dimensions(Array_1) != 1 | dimensions(Array_2) != 1)
    #error "ZA_Append_Arrays will only work with 1 dimensional arrays."
  #else
  
    #local Count_1   = dimension_size(Array_1, 1);
    #local Count_2   = dimension_size(Array_2, 1);
    #local Index     = 0;
    #local New_Index = 0;
    #local Tmp_Array = array[Count_1 + Count_2]
  
    #while(Index < Count_1)
      #local Tmp_Array[New_Index] = Array_1[Index];
      #local Index     = Index + 1;
      #local New_Index = New_Index + 1;
    #end
  
    #local Index = 0;
    #while(Index < Count_2)
      #local Tmp_Array[New_Index] = Array_2[Index];
      #local Index     = Index + 1;
      #local New_Index = New_Index + 1;
    #end
  
    #declare Appended = Tmp_Array;
  #end
 
#end

// ZA_Fill_Array
// Sets all the elements of an array to a value.
//  Array - Array to be filled in.  Can be 1 - 5 dimensions in size.
//  Value - The value to set all the elements of Array to.
//
// Example:
//   #declare A = array[3];
//   ZA_Fill_Array(A, 1)
//   // Array A will be equal to {1, 1, 1}
//
#macro ZA_Fill_Array(Array, Value)
  #macro ZA__Process_Item(Item, Subs, Stop)
    #declare Item = Value;
  #end
  
  ZA__Process_Array(Array, yes, yes)
  
  #undef ZA__Process_Item
#end

// ZA_Rand_Fill_Array
// Sets all the elements of an array to a random value, picked from a specific set of values.
//  Array  - Array to be filled in.  Can be 1 - 5 dimensions in size.
//  Values - A 1-dimensional array of one or more elements.  A value will be picked at random
//           from this array for each element that is set.
//  Stream - A random stream.
//
// Example:
//   #declare R = seed(13);
//   #declare A = array[5];
//   #declare Vals = array[3] { 10, 20, 30 };
//   ZA_Rand_Fill_Array(A, Vals, R)
//   // Array A will be equal to { 20, 30, 30, 10, 10 };
//
#macro ZA_Rand_Fill_Array(Array, Values, Stream)
  #macro ZA__Process_Item(Item, Subs, Stop)
    #declare Item = ZA_Rand_Item(Values, Stream);
  #end
  
  ZA__Process_Array(Array, yes, yes)

  #undef ZA__Process_Item
#end

// ZA_New_Array
// Creates a new array, and initializes all its elements to a given value.
//  Dims  - The number of dimensions of the new array.  Can be 1 - 5.
//  Sizes - The sizes of each dimension of the new array.  Can be a float or a vector.
//          If it is a float, all dimensions will be of the same size.
//          If it is a vector, the first dimension of the new array will be the size of the first
//          vector element, the second the size of the second vector element, etc.  If the vector
//          has more elements than the dimensions specified, the extra are ignored.
// Examples:
//   #declare A1 = ZA_New_Array(1, 3, 50);
//   // Equivalent to:
//   // #declare A1 = array[3] {50, 50, 50};
//
//   #declare A2 = ZA_New_Array(2, 2, 5);
//   // Equivalent to:
//   // #declare A2 = 
//   //   array[2][2] {
//   //     {5, 5},
//   //     {5, 5}
//   //   }
//
//   #declare A3 = ZA_New_Array(3, <2, 3, 4>, 42);
//   // Eqivalent to:
//   // #declare A3 =
//   //   array[2][3][4] {
//   //     { {42, 42, 42, 42},
//   //       {42, 42, 42, 42},
//   //       {42, 42, 42, 42}},
//   //     { {42, 42, 42, 42},
//   //       {42, 42, 42, 42},
//   //       {42, 42, 42, 42}}
//   //   }
//   //     
#macro ZA_New_Array(Dims, Sizes, Value)
  #local Array = ZA__New_Array(Dims, Sizes);
  ZA_Fill_Array(Array, Value)
  Array
#end

// ZA_New_Rand_Array
// Creates a new array and initializes it with random values drawn from a specific list.
//  Dims    - The number of dimensions of the new array.  Can be 1 - 5.
//  Sizes   - Sizes of each dimension of the new array. Same as for ZA_New_Array.
//  Values  - A one-dimensional list of values to select from.  Same as for ZA_Rand_Fill_Array.
//  Stream  - A random stream.
//
// Example:
//   #declare R = seed(13);
//   #declare Vals = array[3] { 10, 20, 30 };
//   #declare A = ZA_New_Rand_Array(1, 5, Vals, R)
//   // Array A will be equal to { 20, 30, 30, 10, 10 };
//
#macro ZA_New_Rand_Array(Dims, Sizes, Values, Stream)
  #local Array = ZA__New_Array(Dims, Sizes);
  ZA_Rand_Fill_Array(Array, Values, Stream)
  Array
#end

// ZA_Merge_Arrays
// Combines two one-dimensional arrays by interleaving thier values.
//  First, Second - The arrays to combine.  They should contain the same types of values.
//  Merged        - The resultant merged array.  The length of the new array will be twice that
//                  of the smaller of the two input arrays.  The new array is created by
//                  alternating elements from the inputs.  If one of the inputs is longer than
//                  the other, the extra elements at the end of the longer one are not included.
// Examples:
//   #declare A1 = array[3] { 1, 2, 3 };
//   #declare A2 = array[3] { 4, 5, 6 };
//   #declare A  = array[6];
//   ZA_Merge_Arrays(A1, A2, A)
//   // A will be equal to { 1, 4, 2, 5, 3, 6 }
//
//   #declare B1 = array[3] { 10, 20, 30 };
//   #declare B2 = array[5] { 40, 50, 60, 70, 80 };
//   #declare B  = array[6];
//   ZA_Merge_Arrays(B1, B2, B)
//   // B will be equal to { 10, 40, 20, 50, 30, 60 }
//
#macro ZA_Merge_Arrays(First, Second, Merged)
  
  #local Count_1   = dimension_size(First, 1);
  #local Count_2   = dimension_size(Second, 1);
  #local Min_Count = min(Count_1, Count_2);
  #local New_Count = Min_Count * 2;
  #local New_Array = array[New_Count]
  #local Index     = 0;
  #local New_Index = 0;
  
  #while(Index < Min_Count)
    #declare New_Array[New_Index]     = First[Index];
    #declare New_Array[New_Index + 1] = Second[Index];
    #local Index     = Index + 1;
    #local New_Index = New_Index + 2;
  #end
  
  #declare Merged = New_Array;
  
#end  

// ZA_Opp_Array
// Fills a one-dimensional array with alternating positive/negative values.
//  Array - Array to fill.
//  First - Flor or vector value of first element.  This value will be inverted and applied to the 
//        - remaining elements of the array in succession.
//
// Examples:
//   #declare A = array[4];
//   ZA_Opp_Array(A, 1)
//   // A will be equal to {1, -1, 1, -1}
//
//   #declare B = array[5];
//   ZA_Opp_Array(B, -2)
//   // B will be equal to {-2, 2, -2, 2, -2}
//
//   #declare C = array[3];
//   ZA_Opp_Array(C, <-1, 2, -3>)
//   // C will be equal to { <-1, 2, -3>, <1, -2, 3>, <-1, 2, -3> }
//
#macro ZA_Opp_Array(Array, First)

  #local Count = dimension_size(Array, 1);
  #local Index = 0;
  #local Value = First;
  
  #while(Index < Count)
    #declare Array[Index] = Value;
    #local Index = Index + 1;
    #local Value = -Value;
  #end
  
#end

// ZA_Rand_Item
// Returns a random item from the input array.  This is a slightly modified version of 
// the standard Rand_Array_Item macro found in "rand.inc".  It avoids certain missing
// semicolon errors that can occur in the standard version.
//  Array  - One-dimensional array of values.  The macro will return a random value from this array.
//  Stream - A random stream.
//
#macro ZA_Rand_Item(Array, Stream)
  #if(dimensions(Array)=1)
    #local Result = Array[floor(rand(Stream)*0.9999999*dimension_size(Array,1))];
  #else
    #error "The ZA_Rand_Item() macro only works for 1D arrays."
  #end
  Result
#end

// ZA_Process_Array
// Applies a custom macro to every element of an array in succession.
//  Array - The input array to process. It can be from 1 to 5 dimensions in size.
//
// Before calling ZA_Process_Array, the user must define a macro called ZA_Process_Item, which will be
// applied to each element of the input array.  This macro can do anything the author wishes,
// including modifying the array values.  The ZA_Process_Item macro must have the following
// specification:
//   #macro ZA_Process_Item(Item, Subs, Stop)
//     ...
//   #end
//
// Item - The value of the element being processed by this call.  It can be set by using #declare as
//        normally done to change macro parameters, and the modified value will be stored back to the
//        original array.
// Subs - This a one-dimensional array containing the subscripts of the array element currently 
//        being processed.  For example if the current element is A[3][6][1], the array passed in
//        would be { 3, 6, 1 }.  Changing this parameter has no effect.
// Stop - This parameter will always have a false boolean value.  Setting it to true within
//        ZA_Process_Item will cause the ZA_Process_Array macro to terminate early, not processing any
//        more array elements.
//
// Examples:
//   // It is often a good idea to encapsulate ZA_Process_Array in a custom macro, to avoid name
//   // collisions or unexpected side effects.
//   //
//   // Simple macro to list a float array.
//   #macro Print_Values(Array)
//     #macro ZA_Process_Item(Item, Subs, Stop)
//       #debug concat(str(Item,0,0),"\n")
//     #end
//     
//     ZA_Process_Array(Array)
//
//     #undef ZA_Process_Item // Prevent unexpected effects later
//   #end
//
//   #declare A = array[5] { 1, 2, 3, 4, 5 };
//   Print_Values(A)
//
//   // Macro to double the values of an array.
//   #macro Double_Array(Array)
//     #macro ZA_Process_Item(Item, Subs, Stop)
//       #declare Item = Item * 2;
//     #end
//
//     ZA_Process_Array(Array)
//
//     #undef ZA_Process_Item
//   #end
//
//   #declare B = array[5] { 1, 2, 3, 4, 5 };
//   Double_Array(B)
//   // B is equal to { 2, 4, 6, 8, 10 }
//
//   // Prints first array item greater than a value.
//   #macro Find_Greater(Array, Val)
//     #macro ZA_Process_Item(Item, Subs, Stop)
//       #if(Item > Val)
//         #debug concat("Found: ",str(Item, 0, 0),"\n")
//         #declare Stop = yes;
//       #end
//     #end
//     
//     ZA_Process_Array(Array)
//
//     #undef ZA_Process_Item
//   #end
//
//   #declare C = array[5] { 1, 2, 3, 4, 5 };
//   Find_Greater(C, 2)
//   // Prints "Found: 3"
//
// See also ZA_Print_Array macro below for example of using Subs.
//
#macro ZA_Process_Array(Array)
  ZA__Process_Array(Array, no, no)
#end

// ZA_Print_Array
// Prints a float array of 1-5 dimensions to the debug stream.
//  Array - Array to print.
//  Name  - String.  Name of array to use in the output.
//
#macro ZA_Print_Array(Array, Name)
  #macro ZA__Process_Item(Item, Subs, Stop)
    #local Dims = dimension_size(Subs, 1);
    #local Ct = 0;
    #local DStr = "";
    #while(Ct<Dims)
      #local DStr = concat(DStr,"[",str(Subs[Ct],0,0),"]");
      #local Ct = Ct + 1;
    #end
    #debug concat(Name,DStr," = ", str(Item,0,-1),"\n")
  #end
  
  ZA__Process_Array(Array, yes, no)
  
  #undef ZA__Process_Item
#end
    

// Internal macros.  These should not be used directly as they may change in the future.

#macro ZA__New_Array(Dims, Sizes)
  #switch(Dims)
    #case(1)
      #local Result = array[Sizes.x]
    #break
    #case(2)
      #local Result = array[Sizes.x][Sizes.y]
    #break
    #case(3)
      #local Result = array[Sizes.x][Sizes.y][Sizes.z]
    #break
    #case(4)
      #local Result = array[Sizes.x][Sizes.y][Sizes.z][Sizes.filter]
    #break
    #case(5)
      #local Result = array[Sizes.x][Sizes.y][Sizes.z][Sizes.filter][Sizes.transmit]
    #break
  #end
  Result
#end

#macro ZA__Process_Array(Array, Internal, Tmp_Set)

  #local Ok = yes;

  #if(Internal)
    #ifndef(ZA__Process_Item)
      #error "Internal ZA__Process_Item macro not defined for ZA__Process_Array\n"
    #end
  #else
    #ifndef(ZA_Process_Item)
      #warning "ZA_Process_Item macro should be redefined when using ZA_Process_Array\n"
      #local Ok = no;
    #end
  #end

  #if(Ok)
      
    #local Dims   = dimensions(Array);
    #local Count  = array[Dims];
    #local Ct     = array[Dims];
    #local Done   = no;
    #local Do_Inc = no;
    #local Tmp    = "";
    
    #local Level = 0;
       
    #while(Level < Dims)
      #local Count[Level] = dimension_size(Array, Level+1);
      #local Ct[Level] = 0;
      #local Level = Level + 1;
    #end
  
    #while(!Done)
      #if(Internal)
        #switch(Dims)
          #case(1)
            #local Subs = array[1] { Ct[0] };
            #if(Tmp_Set)
              ZA__Process_Item(Tmp, Subs, Done)
              #declare Array[Ct[0]] = Tmp;
            #else
              ZA__Process_Item(Array[Ct[0]], Subs, Done)
            #end
          #break
          #case(2)
            #local Subs = array[2] { Ct[0], Ct[1] };
            #if(Tmp_Set)
              ZA__Process_Item(Tmp, Subs, Done)
              #declare Array[Ct[0]][Ct[1]] = Tmp;
            #else
              ZA__Process_Item(Array[Ct[0]][Ct[1]], Subs, Done)
            #end
          #break
          #case(3)
            #local Subs = array[3] { Ct[0], Ct[1], Ct[2] };
            #if(Tmp_Set)
              ZA__Process_Item(Tmp, Subs, Done)
              #declare Array[Ct[0]][Ct[1]][Ct[2]] = Tmp;
            #else
              ZA__Process_Item(Array[Ct[0]][Ct[1]][Ct[2]], Subs, Done)
            #end
          #break
          #case(4)
            #local Subs = array[4] { Ct[0], Ct[1], Ct[2], Ct[3] };
            #if(Tmp_Set)
              ZA__Process_Item(Tmp, Subs, Done)
              #declare Array[Ct[0]][Ct[1]][Ct[2]][Ct[3]] = Tmp;
            #else
              ZA__Process_Item(Array[Ct[0]][Ct[1]][Ct[2]][Ct[3]], Subs, Done)
            #end
          #break
          #case(5)
            #local Subs = array[5] { Ct[0], Ct[1], Ct[2], Ct[3], Ct[4] };
            #if(Tmp_Set)
              ZA__Process_Item(Tmp, Subs, Done)
              #declare Array[Ct[0]][Ct[1]][Ct[2]][Ct[3]][Ct[4]] = Tmp;
            #else
              ZA__Process_Item(Array[Ct[0]][Ct[1]][Ct[2]][Ct[3]][Ct[4]], Subs, Done)
            #end
          #break
        #end
      #else
        #switch(Dims)
          #case(1)
            #local Subs = array[1] { Ct[0] };
            ZA_Process_Item(Array[Ct[0]], Subs, Done)
          #break
          #case(2)
            #local Subs = array[2] { Ct[0], Ct[1] };
            ZA_Process_Item(Array[Ct[0]][Ct[1]], Subs, Done)
          #break
          #case(3)
            #local Subs = array[3] { Ct[0], Ct[1], Ct[2] };
            ZA_Process_Item(Array[Ct[0]][Ct[1]][Ct[2]], Subs, Done)
          #break
          #case(4)
            #local Subs = array[4] { Ct[0], Ct[1], Ct[2], Ct[3] };
            ZA_Process_Item(Array[Ct[0]][Ct[1]][Ct[2]][Ct[3]], Subs, Done)
          #break
          #case(5)
            #local Subs = array[5] { Ct[0], Ct[1], Ct[2], Ct[3], Ct[4] };
            ZA_Process_Item(Array[Ct[0]][Ct[1]][Ct[2]][Ct[3]][Ct[4]], Subs, Done)
          #break
        #end
      #end
        
      #local Level = Dims - 1;
      #local Do_Inc = yes;
    
      #while(Do_Inc & !Done)
        #local Ct[Level] = Ct[Level] + 1;
        #if(Ct[Level] >= Count[Level])
          #local Ct[Level] = 0;
          #local Level = Level - 1;
        #else
          #local Do_Inc = no;
        #end
        #if(Level < 0)
          #local Done = yes;
        #end
      #end
    #end
  #end
#end


#version ZArrays_Inc;
#end
