// Persistence of Vision Ray Tracer Scene Description File
// File: scaleconvert.inc
// Vers: 3.6 (POV-Ray syntax version)
// Desc: ScaleConvert() macro to convert any combination of "mm", "cm", "m", "km", "in", "ft", "mi" etc.  Expandable.
// Refer to http://en.wikipedia.org/wiki/Conversion_of_units for more....
// Date: Dec 2006 (originally)  Last Update: Oct 14, 2007
// Auth: Charles Coyle 
// This file is licensed under the terms of the CC-LGPL 


// Purpose:  The macro ScaleConvert() below is intended to make it slightly easier to mix in a single scene
// objects designed for different measurement systems.  Say you want to put a vehical modeled in feet into a 
// scene modeled in kilometers.  How many feet are in a kilometer (or rather, km to a foot)?  You could figure 
// this directly in your object's scale-statement, but the arithmatic might not make it as readable as:  
// scale ScaleConvert("feet", "km")



#local ScaleConvert_Temp_Vers = version; #version 3.6;

//This version of this line is for complete lib.povray.org compliance:
#ifdef(ScaleConvert_View_POV_Include_Stack)  #debug "including scaleconvert.inc\n" #end
//but this line might be more functional if used alongside POV-Ray distro files:
//#ifdef(View_POV_Include_Stack)  #debug "including scaleconvert.inc\n" #end



// Convert a value within one range to a proportionate value within another range:
// Returns "Value" where "Value" is between B_low and B_high 
// what A_posi is between A_low and A_high.
// E.g. freezing and boiling temps: Range_Convert(25,0,100,32,212) returns: 77 (degrees F)
// ((25-0) *(212-32)/(100-0 )) + 32 = 77 //e.g. C to F
//
#macro ScaleConvert_Range_Convert(A_posi, A_low, A_high, B_low, B_high)
      #if(A_high = A_low) #error "\n A_high = A_low.  A null range would result in a divide-by-zero.\n" #end
      (   ( (A_posi-A_low)*(B_high-B_low)/(A_high-A_low) ) + B_low    )    
#end // end macro Range_Convert()


//Takes in a string describing a unit of length, e.g. yd.  Returns a float value in terms of meters.
//One benefit of this use of strings is that it does not polute the namespace with a long list of
//declared floats, e.g. #declare MM = 0.001;
//
#macro ScaleConvert_Unit_Length_Conversion_Table(The_Unit) 
        #switch(1)
          #case (strcmp(The_Unit, "mm") = 0 ) #local Scale_Factor =   0.001;         #break  //millimeter millimetre
          #case (strcmp(The_Unit, "cm") = 0 ) #local Scale_Factor =    0.01;         #break  //centimeter centimetre
          #case (strcmp(The_Unit,  "m") = 0 ) #local Scale_Factor =       1;         #break  //meter metre
          #case (strcmp(The_Unit, "km") = 0 ) #local Scale_Factor =    1000;         #break  //kilometer kilometre
          #case (strcmp(The_Unit, "in") = 0 ) #local Scale_Factor =  0.0254;         #break  //inch
          #case (strcmp(The_Unit, "ft") = 0 ) #local Scale_Factor =  0.0254*12;      #break  //foot feet
          #case (strcmp(The_Unit, "yd") = 0 ) #local Scale_Factor =  0.0254*12*3;    #break  //yard        
          #case (strcmp(The_Unit, "mi") = 0 ) #local Scale_Factor =  0.0254*12*5280; #break  //mile
          //some alternatives:
          #case (strcmp(The_Unit, "millimeter") = 0 ) #local Scale_Factor =   0.001;         #break  //millimeter millimetre
          #case (strcmp(The_Unit, "centimeter") = 0 ) #local Scale_Factor =    0.01;         #break  //centimeter centimetre
          #case (strcmp(The_Unit, "meter") = 0 )      #local Scale_Factor =       1;         #break  //meter metre
          #case (strcmp(The_Unit, "kilometer") = 0 )  #local Scale_Factor =    1000;         #break  //kilometer kilometre
          #case (strcmp(The_Unit, "inch") = 0 )       #local Scale_Factor =  0.0254;         #break  //inch
          #case (strcmp(The_Unit, "foot") = 0 )       #local Scale_Factor =  0.0254*12;      #break  //foot feet
          #case (strcmp(The_Unit, "yard") = 0 )       #local Scale_Factor =  0.0254*12*3;    #break  //yard        
          #case (strcmp(The_Unit, "mile") = 0 )       #local Scale_Factor =  0.0254*12*5280; #break  //mile
          //more alternatives:
          #case (strcmp(The_Unit, "millimetre") = 0 ) #local Scale_Factor =   0.001;         #break  //millimeter millimetre
          #case (strcmp(The_Unit, "centimetre") = 0 ) #local Scale_Factor =    0.01;         #break  //centimeter centimetre
          #case (strcmp(The_Unit, "metre") = 0 )      #local Scale_Factor =       1;         #break  //meter metre
          #case (strcmp(The_Unit, "kilometre") = 0 )  #local Scale_Factor =    1000;         #break  //kilometer kilometre
          //
          //some plural forms:
          #case (strcmp(The_Unit, "millimeters") = 0 ) #local Scale_Factor =   0.001;         #break  //millimeter millimetre
          #case (strcmp(The_Unit, "centimeters") = 0 ) #local Scale_Factor =    0.01;         #break  //centimeter centimetre
          #case (strcmp(The_Unit, "meters") = 0 )      #local Scale_Factor =       1;         #break  //meter metre
          #case (strcmp(The_Unit, "kilometers") = 0 )  #local Scale_Factor =    1000;         #break  //kilometer kilometre
          #case (strcmp(The_Unit, "inches") = 0 )      #local Scale_Factor =  0.0254;         #break  //inch
          #case (strcmp(The_Unit, "feet") = 0 )        #local Scale_Factor =  0.0254*12;      #break  //foot feet
          #case (strcmp(The_Unit, "yards") = 0 )       #local Scale_Factor =  0.0254*12*3;    #break  //yard        
          #case (strcmp(The_Unit, "miles") = 0 )       #local Scale_Factor =  0.0254*12*5280; #break  //mile
          //more plural forms:
          #case (strcmp(The_Unit, "millimetres") = 0 ) #local Scale_Factor =   0.001;         #break  //millimeter millimetre
          #case (strcmp(The_Unit, "centimetres") = 0 ) #local Scale_Factor =    0.01;         #break  //centimeter centimetre
          #case (strcmp(The_Unit, "metres") = 0 )      #local Scale_Factor =       1;         #break  //meter metre
          #case (strcmp(The_Unit, "kilometres") = 0 )  #local Scale_Factor =    1000;         #break  //kilometer kilometre
          //
          //a few other units (singular form):
          #case (strcmp(The_Unit, "fathom") = 0 )      #local Scale_Factor =  0.0254*12*6;         #break  
          #case (strcmp(The_Unit, "league") = 0 )      #local Scale_Factor =  0.0254*12*5280*3;    #break  
          #case (strcmp(The_Unit, "furlong") = 0 )     #local Scale_Factor =  0.0254*12*660;       #break  
          #case (strcmp(The_Unit, "rope") = 0 )        #local Scale_Factor =  0.0254*12*20;        #break  
          #case (strcmp(The_Unit, "palm") = 0 )        #local Scale_Factor =  0.0254*3;            #break  
          #case (strcmp(The_Unit, "hand") = 0 )        #local Scale_Factor =  0.0254*4;            #break  
          #case (strcmp(The_Unit, "span") = 0 )        #local Scale_Factor =  0.0254*6;            #break  
          #case (strcmp(The_Unit, "span(cloth)") = 0 ) #local Scale_Factor =  0.0254*12*9;         #break  
          #case (strcmp(The_Unit, "nail(cloth)") = 0 ) #local Scale_Factor =  0.0254*12*2.25;      #break  
          #case (strcmp(The_Unit, "pace") = 0 )        #local Scale_Factor =  0.0254*12*2.5;       #break  
          #case (strcmp(The_Unit, "rod") = 0 )         #local Scale_Factor =  0.0254*12*16.5;      #break //rod = pole = perch 
          #case (strcmp(The_Unit, "pole") = 0 )        #local Scale_Factor =  0.0254*12*16.5;      #break //rod = pole = perch 
          #case (strcmp(The_Unit, "perch") = 0 )       #local Scale_Factor =  0.0254*12*16.5;      #break //rod = pole = perch 
          #case (strcmp(The_Unit, "stick") = 0 )       #local Scale_Factor =  0.0254*2;            #break 
          #case (strcmp(The_Unit, "telegraph mile") = 0 ) #local Scale_Factor =  0.0254*12*6087;   #break 
          #case (strcmp(The_Unit, "mil") = 0 )         #local Scale_Factor =  0.0254 * 1/1000;     #break  
          //
          //
          //
	#else 
	        #debug concat("\n\n\n\n***** The string parameter \"", The_Unit, 
	                      "\" is not recognized by Unit_Length_Conversion_Table(). *****\n\n\n\n" )
	        #error "ScaleConvert() and ScaleConvert_Unit_Length_Conversion_Table() have recieved one or more invalid string parameters.\n"
	#end //end #switch(1)
	//
        Scale_Factor  //return value
#end  //end #macro ScaleConvert_Unit_Conversion_Table(The_Unit) 





//Converts scale from one unit type to another.
//Takes two string parameters which must be any two of the following:
//"mm", "cm", "m", "km", "in", "ft", "mi"  or any others in 
//ScaleConvert_Unit_Conversion_Table().
//
//Usage, E.g: 
//#object{ MyObject scale Scale_Convert("cm","feet") } 
//is equivalent to: 
//#object{ MyObject scale 0.0328083989501324 }
//or:
//#object{ MyObject scale 1/(2.54*12) }
//
#macro ScaleConvert(From_Unit,To_Unit)
	#local Factor_A = ScaleConvert_Unit_Length_Conversion_Table(From_Unit);
	#local Factor_B = ScaleConvert_Unit_Length_Conversion_Table(To_Unit);
	#local Scaler   = ScaleConvert_Range_Convert(1, 0,Factor_B, 0, Factor_A);  //Convert 1 Unit = From_Unit to To_Unit.	
        //#debug concat("\n*** Converting \"", From_Unit, "\" to \"" To_Unit, "\" requires a factor of ", str(ScaleConvert_Scaler,5,17), ". ***\n" )
        //
        Scaler  //returns this for use in an object{}
#end //end #macro Scale_Convert(From_Unit,To_Unit)


//For easier testing without having to modify ScaleConvert():
#macro ScaleConvert_Debug(From_Unit,To_Unit)
        #debug concat("\n*** Converting \"", From_Unit, "\" to \"" To_Unit, 
               "\" requires a factor of ", str(ScaleConvert(From_Unit,To_Unit),5,17), ". ***\n" )
#end //end #macro Scale_Convert_Debug(From_Unit,To_Unit)



//To test via debug output, un-comment the following, or call ScaleConvert_Debug() from your scene: 
//
//ScaleConvert_Debug("m","mm")  
//ScaleConvert_Debug("mm","m")  
//ScaleConvert_Debug("in","yards")
//ScaleConvert_Debug("cm","feet")
//ScaleConvert_Debug("millimeters","miles")
//ScaleConvert_Debug("feet","kilometers")  

#version ScaleConvert_Temp_Vers;      // Restore previous version
