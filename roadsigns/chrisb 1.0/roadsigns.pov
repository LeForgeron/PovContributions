//
// roadsigns.pov
// -------------
// Created by Chris Bartlett March 2008
// This scene file demonstrates the use of the 'roadsigns' include file. 
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The scale is 1 POV-Ray unit = 1 metre
//
// Render Times
// ------------
// Individual road signs typically add less than a second to the render time. 
//
// This example scene contains about 14 road signs.
// Render time is typically about 30 seconds at 640x480 with AA 0.3.
//

#include "roadsigns.inc"

// "Warning" Signs     (using prism objects defined in "roadsigns_uksymbols.inc")
// ---------------
// Aircraft                          LevelCrossingWithBarrier              Roundabout           
// Cattle                            LevelCrossingWithoutBarrier           Sidewinds            
// DoubleBendLeft                    MenAtWork                             StaggeredJunction    
// DoubleBendRight                   OpeningBridge                         TramcarCrossing      
// DualCarriagewayEnds               Quayside                              TwoWayTraffic        
// FallingRocks                      RiskOfGrounding                       TwoWayTrafficCrossing
// FrailPedestrians                  RoadNarrowsBothSides                  WildAnimals          
// HumpBridge                        RoadNarrowsOnLeft                     WildHorses           
// JunctionOnBend                    RoadNarrowsOnRight         


// "Regulatory" Signs  (using prism objects defined in "roadsigns_uksymbols.inc")
// ------------------
// NoCarsOrBikes 
// NoExplosives 
// MaxTruckLength
// MaxTruckWeight


// "Compulsory" Signs  (using prism objects defined in "roadsigns_uksymbols.inc")
// ------------------
// KeepLeft      
// KeepRight     
// TurnLeftAhead 
// TurnRightAhead
// PassEitherSide



// Speed Limit Signs   (using prism objects generated on the fly)
// ----------------- 
// To specify a speed limit, just specify the digits. e.g. Roadsigns_Panel("Regulatory", "40" )


// Add some road signs to the scene and distribute them around a bit
object {Roadsigns_Panel("Warning"   , "RiskOfGrounding"  ) translate  x*0.3}  
object {Roadsigns_Panel("Regulatory", "NoExplosives"   )   translate -x*0.3} 

// Change the size of the sign  
#declare Roadsigns_Diameter = 0.750;                 
object {Roadsigns_Panel("Regulatory", "125"            ) translate <0,0.45,0.15>} 

// Reset the size of the sign, so it goes back to its default size               
#undef Roadsigns_Diameter               
object {Roadsigns_Panel("Regulatory", "5"              ) translate <0,-0.45,0.15>} 

// A selection of "Warning" signs
object {Roadsigns_Panel("Warning"   , "WildAnimals"    ) rotate  y*40 translate < 0.55,0.55,0.15>}
object {Roadsigns_Panel("Warning"   , "TramcarCrossing") rotate -y*40 translate <-0.55,0.55,0.15>}
//object {Roadsigns_Panel("Warning"   , "MenAtWork"      ) rotate  y*40 translate < 0.55,-0.57,0.15>} 
//object {Roadsigns_Panel("Warning"   , "Roundabout"     ) rotate -y*40 translate <-0.55,-0.57,0.15>} 

object {Roadsigns_Panel("Warning"   , "MenAtWork"      ) rotate  y*40 translate < 0.85,0.35,0.15>}
object {Roadsigns_Panel("Warning"   , "Cattle"         ) rotate -y*40 translate <-0.85,0.35,0.15>}
object {Roadsigns_Panel("Warning"   , "Aircraft"       ) rotate  y*40 translate < 0.85,-0.53,0.15>} 
object {Roadsigns_Panel("Warning"   , "FallingRocks"   ) rotate -y*40 translate <-0.85,-0.53,0.15>} 

// A couple of "Compulsory" signs
object {Roadsigns_Panel("Compulsory", "TurnLeftAhead"  ) translate < 1.05,-0.1,0.35>} 
object {Roadsigns_Panel("Compulsory", "TurnRightAhead" ) translate <-1.05,-0.1,0.35>} 

// A couple of "Hazard" signs from the "roadsigns_hazardsymbols.inc" file.
#declare Roadsigns_SymbolFile = "roadsigns_hazardsymbols.inc";
object {Roadsigns_Panel("Hazard"    , "ScullAndCrossBones" ) rotate  y*40 translate < 0.55,-0.57,0.15>} 
object {Roadsigns_Panel("Hazard"    , "Biohazard"          ) rotate -y*40 translate <-0.55,-0.57,0.15>} 


// Lights, Camera, Action
light_source {   <-4,7.5 ,-10   >, rgb 1}
light_source {   < 8,7.5 ,-15   >, rgb 1}
light_source {   < 0,0.1,- 0.2>, rgb 0.4}
camera {location < 0,0,-1.6> look_at <0,0,0>} 
