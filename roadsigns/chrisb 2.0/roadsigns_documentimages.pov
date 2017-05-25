
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
// To generate all of the standard images use the animation command line options +kfi1 +kff86 which sets ImageNumber to equal 
// the frame_number. The oddments (special variants) can be generated using command line options +kfi1001 +kff1017.
// You can use +fn to generate png files directly. The png files used in the documentation are 160x120, AA 0.3.
// To generate a single image switch off animation and it will use ImageNumber = n, where 'n' is the number of the image you 
// specify here:
#if (frame_number=0) #local ImageNumber = 1017;  // Set this to the required image number
#else                #local ImageNumber = frame_number;
#end 

#include "roadsigns.inc"  

//                                Symbol Name                   Image Number
//                                -----------                   ------------
#local WarningSignNames = array [47];
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

// Second Batch of Warning Symbols added April 2008

//                                Symbol Name                   Image Number
//                                -----------                   ------------
#local WarningSignNames[26]    = "Crossroads"                  ; // 47
#local WarningSignNames[27]    = "TJunctionWithPriority"       ; // 48
#local WarningSignNames[28]    = "TrafficMergingFromLeft"      ; // 49
#local WarningSignNames[29]    = "BendToRight"                 ; // 50
#local WarningSignNames[30]    = "BendToLeft"                  ; // 51
#local WarningSignNames[31]    = "UnevenRoad"                  ; // 52
#local WarningSignNames[32]    = "TrafficSignals"              ; // 53
#local WarningSignNames[33]    = "SlipperyRoad"                ; // 54
#local WarningSignNames[34]    = "SteepHillDownwards"          ; // 55
#local WarningSignNames[35]    = "SteepHillUpwards"            ; // 56
#local WarningSignNames[36]    = "TunnelAhead"                 ; // 57
#local WarningSignNames[37]    = "SchoolCrossing"              ; // 58
#local WarningSignNames[38]    = "Pedestrians"                 ; // 59
#local WarningSignNames[39]    = "OverheadElectricCable"       ; // 60
#local WarningSignNames[40]    = "AccompaniedHorses"           ; // 61
#local WarningSignNames[41]    = "CycleRoute"                  ; // 62
#local WarningSignNames[42]    = "RiskOfIce"                   ; // 63
#local WarningSignNames[43]    = "TrafficQueues"               ; // 64
#local WarningSignNames[44]    = "Humps"                       ; // 65
#local WarningSignNames[45]    = "SoftVerges"                  ; // 66
#local WarningSignNames[46]    = "ZebraCrossing"               ; // 67



//                                Symbol Name                   Image Number
//                                -----------                   ------------
#local RegulatorySignNames = array [15];
#local RegulatorySignNames[ 0] = "NoCarsOrBikes"               ; // 27
#local RegulatorySignNames[ 1] = "NoExplosives"                ; // 28 
#local RegulatorySignNames[ 2] = "MaxTruckLength"              ; // 29 
#local RegulatorySignNames[ 3] = "MaxTruckWeight"              ; // 30  

// Second Batch of Regulatory Symbols added April 2008
#local RegulatorySignNames[ 4] = "HeightLimit"                 ; // 68  
#local RegulatorySignNames[ 5] = "WidthLimit"                  ; // 69  
#local RegulatorySignNames[ 6] = "NoBuses"                     ; // 70  
#local RegulatorySignNames[ 7] = "NoCycling"                   ; // 71  
#local RegulatorySignNames[ 8] = "NoLeftTurn"                  ; // 72  
#local RegulatorySignNames[ 9] = "NoOvertaking"                ; // 73  
#local RegulatorySignNames[10] = "NoRightTurn"                 ; // 74  
#local RegulatorySignNames[11] = "NoTowedCaravans"             ; // 75  
#local RegulatorySignNames[12] = "NoUTurns"                    ; // 76  
#local RegulatorySignNames[13] = "NoVehicles"                  ; // 77  
#local RegulatorySignNames[14] = "PriorityToOncomingVehicles"  ; // 78  

                                                               
//                                Symbol Name                   Image Number
//                                -----------                   ------------
#local CompulsorySignNames = array [13];
#local CompulsorySignNames[ 0] = "KeepLeft"                    ; // 31 
#local CompulsorySignNames[ 1] = "KeepRight"                   ; // 32 
#local CompulsorySignNames[ 2] = "TurnLeftAhead"               ; // 33 
#local CompulsorySignNames[ 3] = "TurnRightAhead"              ; // 34 
#local CompulsorySignNames[ 4] = "PassEitherSide"              ; // 35 

// Second Batch of Compulsory Symbols added April 2008
#local CompulsorySignNames[ 5] = "AheadOnly"                   ; // 79 
#local CompulsorySignNames[ 6] = "BusesAndCyclesOnly"          ; // 80 
#local CompulsorySignNames[ 7] = "CyclesOnly"                  ; // 81 
#local CompulsorySignNames[ 8] = "MiniRoundabout"              ; // 82 
#local CompulsorySignNames[ 9] = "SegregatedPedestrian"        ; // 83 
#local CompulsorySignNames[10] = "TramsOnly"                   ; // 84 
#local CompulsorySignNames[11] = "TurnLeft"                    ; // 85 
#local CompulsorySignNames[12] = "TurnRight"                   ; // 86 



//                                Symbol Name                   Image Number
//                                -----------                   ------------
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
// Images 47 - 67
#if (ImageNumber>=47 & ImageNumber<=67)
  object {Roadsigns_Panel("Warning"   , WarningSignNames[ImageNumber-21])}  
#end 

//**************************//
//    "Regulatory" Signs    //
//**************************// 
// Image 27 - 30
#if (ImageNumber>=27 & ImageNumber<=30)
  object {Roadsigns_Panel("Regulatory", RegulatorySignNames[ImageNumber-27])}  
#end
// Images 68 - 78
#if (ImageNumber>=68 & ImageNumber<=78)
  object {Roadsigns_Panel("Regulatory", RegulatorySignNames[ImageNumber-64])}  
#end 


//**************************//
//    "Compulsory" Signs    //
//**************************// 
// Image 31 - 35
#if (ImageNumber>=31 & ImageNumber<=35)
  object {Roadsigns_Panel("Compulsory", CompulsorySignNames[ImageNumber-31])}  
#end
// Images 79 - 86
#if (ImageNumber>=79 & ImageNumber<=86)
  object {Roadsigns_Panel("Compulsory", CompulsorySignNames[ImageNumber-74])}  
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


//**************************//
//     Oddments             //
//**************************// 

#if (ImageNumber=1001)
  #declare Roadsigns_SymbolBackground = <0,164,078>/255;
  object {Roadsigns_Panel("Compulsory", "GO")}  
#end
#if (ImageNumber=1002)
  object {Roadsigns_Panel("Compulsory", "30")}  
#end
#if (ImageNumber=1003)
  #declare Roadsigns_SymbolBackground = <0,117,189>/255;
  object {Roadsigns_Panel("Regulatory", "NoWaiting")}  
#end
#if (ImageNumber=1004)
  #declare Roadsigns_SymbolBackground = <0,117,189>/255;
  object {Roadsigns_Panel("Regulatory", "Clearway")}  
#end
#if (ImageNumber=1005)
  #declare Roadsigns_SymbolText = "30";
  object {Roadsigns_Panel("Compulsory", "EndMinimumSpeed")}  
#end
#if (ImageNumber=1006)
  object {Roadsigns_Panel("Plain_White_Circle", "NationalSpeedLimit")}  
#end
#if (ImageNumber=1007)
  #declare Roadsigns_SymbolBackground = 0.8*<222, 52, 57>/255;
  object {Roadsigns_Panel("Compulsory", "NoEntry")}  
#end
#if (ImageNumber=1008)
  #declare Roadsigns_SymbolBackground = <1,227/255,0>;
  object {Roadsigns_Panel("Regulatory", "SchoolCrossingPatrol")}  
#end
#if (ImageNumber=1009)
  object {Roadsigns_Panel("InvertedWarning", "")}  
#end
#if (ImageNumber=1010)
  object {Roadsigns_Panel("InvertedWarning", "GiveWay")}  
#end
#if (ImageNumber=1011)
  object {Roadsigns_Panel("Octagonal", "STOP")}  
#end
#if (ImageNumber=1012) 
  #declare Roadsigns_FaceWidth = 0.36;
  object {Roadsigns_Panel("RoundedRectangle", "AheadOnly")}    // One Way Traffic
#end
#if (ImageNumber=1013) 
  object {Roadsigns_Panel("RoundedRectangle", "Parking")}  
#end
#if (ImageNumber=1014) 
  #declare Roadsigns_FaceWidth = 0.43;
  #declare Roadsigns_SymbolText = "1 mile";
  object {Roadsigns_Panel("RoundedRectangle", "Parking")}  
#end
#if (ImageNumber=1015)
  #declare Roadsigns_SymbolBackground = 0.8*<222, 52, 57>/255; 
  #declare Roadsigns_FaceWidth = 0.8;
  #declare Roadsigns_TextArray = array [3]{"REDUCE","SPEED","NOW"};
  object {Roadsigns_Panel("RoundedRectangle", "TextArray")}  
#end
#if (ImageNumber=1016)
  background {rgb <0.1,0.3,0.1>}
  #declare Roadsigns_FaceHeight = 0.30;
  #declare Roadsigns_TextArray = array [2]{"GIVE WAY","50 yds"};
  object {Roadsigns_Panel("SupplementaryInformation", "TextArray")}  
#end
#if (ImageNumber=1017)
  background {rgb <0.1,0.3,0.1>}
  #declare Roadsigns_FaceHeight = 0.30;
  #declare Roadsigns_FaceWidth = 0.68;
  #declare Roadsigns_TextArray = array [2]{"No footway","for 400 yds"};
  object {Roadsigns_Panel("SupplementaryInformation", "TextArray")}  
#end

// Camera and Lights
camera {location -0.9*z look_at 0}
light_source {   <-4,7.5 ,-10   >, rgb 1}
light_source {   < 8,7.5 ,-15   >, rgb 1}
light_source {   < 0,0.1,- 0.2>, rgb 0.4}  


