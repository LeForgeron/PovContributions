
// roadsigns_documentimages.pov
// ----------------------------
// Created by Chris Bartlett January 2008
// This scene file demonstrates the use of the 'roadsigns' include file. 
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The scale is 1 POV-Ray units = 1 metre

// Purpose
// -------
// This scene file is used to re-generate the images used within the documentation contained in roadsigns.html. 
//
// To generate all images use the animation command line options +kfi1 +kff46 which sets ImageNumber to equal the frame_number.
// You can use +fn to generate png files directly. The png files used in the documentation are 160x120, AA 0.3.
// To generate a single image switch off animation and it will use ImageNumber = n, where 'n' is the number of the image you 
// specify here:
#if (frame_number=0) #local ImageNumber = 99;  // Set this to the required image number
#else                #local ImageNumber = frame_number;
#end 

#include "roadsigns.inc"

#local WarningSignNames = array [26];
#local WarningSignNames[ 0]    = "Aircraft"                    ; //  1
#local WarningSignNames[ 1]    = "Cattle"                      ; //  2
#local WarningSignNames[ 2]    = "DoubleBendLeft"              ; //  3
#local WarningSignNames[ 3]    = "DoubleBendRight"             ; //  4
#local WarningSignNames[ 4]    = "DualCarriagewayEnds"         ; //  5
#local WarningSignNames[ 5]    = "FallingRocks"                ; //  6
#local WarningSignNames[ 6]    = "FrailPedestrians"            ; //  7
#local WarningSignNames[ 7]    = "HumpBridge"                  ; //  8
#local WarningSignNames[ 8]    = "JunctionOnBend"              ; //  9
#local WarningSignNames[ 9]    = "LevelCrossingWithBarrier"    ; // 10
#local WarningSignNames[10]    = "LevelCrossingWithoutBarrier" ; // 11
#local WarningSignNames[11]    = "MenAtWork"                   ; // 12
#local WarningSignNames[12]    = "OpeningBridge"               ; // 13
#local WarningSignNames[13]    = "Quayside"                    ; // 14
#local WarningSignNames[14]    = "RiskOfGrounding"             ; // 15
#local WarningSignNames[15]    = "RoadNarrowsBothSides"        ; // 16
#local WarningSignNames[16]    = "RoadNarrowsOnLeft"           ; // 17
#local WarningSignNames[17]    = "RoadNarrowsOnRight"          ; // 18
#local WarningSignNames[18]    = "Roundabout"                  ; // 19
#local WarningSignNames[19]    = "Sidewinds"                   ; // 20
#local WarningSignNames[20]    = "StaggeredJunction"           ; // 21
#local WarningSignNames[21]    = "TramcarCrossing"             ; // 22
#local WarningSignNames[22]    = "TwoWayTraffic"               ; // 23
#local WarningSignNames[23]    = "TwoWayTrafficCrossing"       ; // 24
#local WarningSignNames[24]    = "WildAnimals"                 ; // 25
#local WarningSignNames[25]    = "WildHorses"                  ; // 26

#local RegulatorySignNames = array [4];
#local RegulatorySignNames[ 0] = "NoCarsOrBikes"               ; // 27
#local RegulatorySignNames[ 1] = "NoExplosives"                ; // 28 
#local RegulatorySignNames[ 2] = "MaxTruckLength"              ; // 29 
#local RegulatorySignNames[ 3] = "MaxTruckWeight"              ; // 30 
                                                               
#local CompulsorySignNames = array [5];
#local CompulsorySignNames[ 0] = "KeepLeft"                    ; // 31 
#local CompulsorySignNames[ 1] = "KeepRight"                   ; // 32 
#local CompulsorySignNames[ 2] = "TurnLeftAhead"               ; // 33 
#local CompulsorySignNames[ 3] = "TurnRightAhead"              ; // 34 
#local CompulsorySignNames[ 4] = "PassEitherSide"              ; // 35 

#local SpeedLimitSignNames = array [4];                        
#local SpeedLimitSignNames[ 0] = "20"                          ; // 36
#local SpeedLimitSignNames[ 1] = "60"                          ; // 37
#local SpeedLimitSignNames[ 2] = "!"                           ; // 38
#local SpeedLimitSignNames[ 3] = "?"                           ; // 39      

#local HazardSignNames     = array [7];
#local HazardSignNames[ 0]     = "ScullAndCrossBones"          ; //  40
#local HazardSignNames[ 1]     = "Cross"                       ; //  41
#local HazardSignNames[ 2]     = "Explosion"                   ; //  42
#local HazardSignNames[ 3]     = "Fire"                        ; //  43
#local HazardSignNames[ 4]     = "Oxidation"                   ; //  44
#local HazardSignNames[ 5]     = "Corrosion"                   ; //  45
#local HazardSignNames[ 6]     = "Biohazard"                   ; //  46

                                                         
//**************************//
//     "Warning" Signs      //
//**************************// 
// Images 1 - 26
#if (ImageNumber>=1 & ImageNumber<=26)
  object {Roadsigns_Panel("Warning"   , WarningSignNames[ImageNumber-1])}  
#end

//**************************//
//    "Regulatory" Signs    //
//**************************// 
// Image 27 - 30
#if (ImageNumber>=27 & ImageNumber<=30)
  object {Roadsigns_Panel("Regulatory", RegulatorySignNames[ImageNumber-27])}  
#end

//**************************//
//    "Compulsory" Signs    //
//**************************// 
// Image 31 - 35
#if (ImageNumber>=31 & ImageNumber<=35)
  object {Roadsigns_Panel("Compulsory", CompulsorySignNames[ImageNumber-31])}  
#end

//**************************//
//     Speed Limit Signs    //
//**************************// 
// Image 36 - 37
#if (ImageNumber>=36 & ImageNumber<=37)
  object {Roadsigns_Panel("Regulatory", SpeedLimitSignNames[ImageNumber-36])}  
#end 

//**************************//
//     Caution Signs        //
//**************************// 
// Image 38 - 39
#if (ImageNumber>=38 & ImageNumber<=39)
  object {Roadsigns_Panel("Warning", SpeedLimitSignNames[ImageNumber-36])}  
#end 

//**************************//
//     Hazard Signs         //
//**************************// 
// Image 40 - 46
#if (ImageNumber>=40 & ImageNumber<=46)
  background {<0.1,0.2,0.2>} 
  #declare Roadsigns_SymbolFile = "roadsigns_hazardsymbols.inc"; 
  object {Roadsigns_Panel("Hazard", HazardSignNames[ImageNumber-40])}  
#end 


//**************************//
//     Testing              //
//**************************// 
//  Image 99 - Used for testing
#if (ImageNumber=99)
  background {<0.1,0.2,0.2>} 
  #declare Roadsigns_SymbolFile = "roadsigns_hazardsymbols.inc"; 
  object {Roadsigns_Panel("Hazard", "Cross")}  
#end

// Camera and Lights
camera {location -0.9*z look_at 0}
light_source {   <-4,7.5 ,-10   >, rgb 1}
light_source {   < 8,7.5 ,-15   >, rgb 1}
light_source {   < 0,0.1,- 0.2>, rgb 0.4}  


