//
// labeller_peaches.inc
// ---------------------
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
#declare Labeller_DefaultCameraLocation = <0,0.14,-0.15>;
#declare Labeller_DefaultCameraLook_At  = <0,0.05,0>;

// The design of the label is stored in a separate file. 
#declare Labeller_LabelFile = "labeller_peachesdesign.inc"; 
#declare Labeller_LabelBottom   = 0.003;
#declare Labeller_LabelTop      = 0.107;
#declare Labeller_ObjectRadius  = 0.0735/2; 
#declare Labeller_LabelRounding = 0.0001;
#declare Labeller_LabelArc      = 360;

#declare Labeller_PlainBack        = 0;                    
#declare Labeller_PlainBackColor   = <1,1,1>;              
#declare Labeller_Normal           = normal {bumps 0};     
#declare Labeller_Finish           = finish {reflection 0};


// The Labeller macro is set to render the shape for which this label has been designed.
#ifdef (Labeller) #undef Labeller #end
#macro Labeller() 
  #ifndef(Labeller_Cylinder) #include "labeller.inc" #end 
  Labeller_Cylinder() 
#end      


