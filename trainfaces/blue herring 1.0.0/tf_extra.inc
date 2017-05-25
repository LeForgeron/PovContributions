// Title:        TrainFaces auxilary macros
// Written by:   Matthew Goulet <povray@bherring.cotse.net>
// Created on:   July 17, 2008
// Last updated: July 17, 2008
//
// This file is licensed under the terms of the CC-LGPL
//
#ifndef(Tf_Extra_Inc)
#declare Tf_Extra_Inc = version;
#version 3.61;

#ifdef(View_POV_Include_Stack)
  #debug "including tf_extra.inc\n"
#end

#include "strings.inc"

#macro TF_Iso_Calc_Evaluate(Max_Gradient, Min_Factor, Attenuation)
  #local MG = select(Max_Gradient, 1.1, 1.1, Max_Gradient);
  #local MF = select(Min_Factor, 0.6, 0.6, Min_Factor);
  #local Att = select(Attenuation, 0.7, 0.7, Attenuation);
  
  MG * MF, sqrt(MG / (MG * MF)), Att
#end

#macro TF_Load_Mesh(File, Name)
  #if(strlen(Name) > 0)
    #local Fnd = Parse_String(concat("defined(", Name, ")"));
    #if(! Fnd)
      Parse_String(concat("#declare ", Name, " = #include File"))
    #end
    #local Result = object { Parse_String(Name) };
  #else
    #local Result = #include File
  #end
  
  Result
#end
      

#version Tf_Extra_Inc;
#end
