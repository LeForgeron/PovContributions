//
// labeller_bottledphotons.inc
// ---------------------------
// Created by Chris Bartlett February 2008
// This include file contains the settings necessary to generate a particular type of label.
// Having included this file in a scene you can call the Labeller macro to generate the corresponding label object.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/

// The scale is 0.001 POV-Ray units = 1mm   (1m = 1 POV-Ray unit)

// Clear down any settings there may be from earlier calls to a Labeller macro
#ifdef (Labeller_Undef) Labeller_Undef() #end

// These camera settings can be used from your scene file to frame the label in it's default location
#declare Labeller_DefaultCameraLocation = <0,0.10,-0.125>; 
#declare Labeller_DefaultCameraLook_At  = <0,0.06,0>;

// The design of the label is stored in a separate file. 
#declare Labeller_LabelFile = "labeller_bottledphotonsdesign.inc";  
#declare Labeller_PolyhedronFaces    = 8;      
#declare Labeller_TopInnerRadius     = 0.03;  
#declare Labeller_BottomInnerRadius  = 0.03;  
#declare Labeller_BevelWidth         = 0.001;
#declare Labeller_CornerRadius       = 0.002; 
#declare Labeller_LabelBottom        = 0.008; 
#declare Labeller_LabelTop           = 0.080; 
#declare Labeller_LabelThickness     = 0.0002;

#declare Labeller_PlainBack        = 0;                     
#declare Labeller_PlainBackColor   = <1,1,1>;               
#declare Labeller_Normal           = normal {bumps 0};      
#declare Labeller_Finish           = finish {reflection 0}; 


// The Labeller macro is set to render the shape for which this label has been designed.
#ifdef (Labeller) #undef Labeller #end
#macro Labeller() 
  #ifndef(Labeller_Polyhedron) #include "labeller.inc" #end 
  Labeller_Polyhedron() 
#end    

// Note. This label contains transparency requiring the max_trace_level to be increased to avoid black-spots.
 global_settings { max_trace_level 8}
