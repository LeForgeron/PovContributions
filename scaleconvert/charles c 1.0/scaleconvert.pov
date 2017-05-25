// Example to illustrate the use of the ScaleConvert include file and the ScaleConvert() macro. 
// This file is licensed under the terms of the CC-LGPL 

camera {location <2,-0.6,-10>  look_at <2,-0.6,0>}
light_source {<0,100,-90> color rgb 1}   

#include "scaleconvert.inc"   

#declare MySphere = sphere{0,1 pigment {color rgb <1,0,0>}}

object {MySphere translate -x}        
object {MySphere scale ScaleConvert("m","ft") translate x*ScaleConvert("m","ft")} 

text {ttf "arial.ttf" "Metres > Feet",0.1,0 pigment {color rgb <1,1,0>} scale 1.6 finish {ambient 1} translate <-3.5,-4.8,0>}       
     
// debug output:
ScaleConvert_Debug("m","mm")  
ScaleConvert_Debug("mm","m")  
ScaleConvert_Debug("in","yards")
ScaleConvert_Debug("cm","feet")
ScaleConvert_Debug("millimeters","miles")
ScaleConvert_Debug("feet","kilometers")  


