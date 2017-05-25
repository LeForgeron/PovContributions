// Object Name: Pumpkin 
// Version:     01.10.95 for POV 2.2.   
// Description: A pumpkin for Halloween with eye, nose and mouth holes.
// Scale:       1 unit = 0.5 metre diameter pumpkin.
// Positioning: Sphere centred at the origin.
// Details:     4 copies of a squashed sphere, rotated at different angles
//              around the Y axis to make a segmented pumpkin shape. 
// Keywords:    Pumpkin, Halloween, Vegetables, Market gardening
// Author:      Chris Bartlett.  
// This file is licensed under the terms of the CC-LGPL


#declare Pumpkin_Segments = 19;
#declare Pumpkin_ExternalTexture = texture { 
  pigment {color rgb <1,0.5,0>} 
  normal {average
    normal_map {
      [2 crackle]
      [1 bumps scale 0.05]   
    }
    scale 0.02}
  finish {phong 0.1}
}   

#declare Pumpkin_InternalTexture = texture { 
  pigment {color rgb <1,0.8,0>} 
  normal {bumps scale 0.001}
  finish {phong 0.1}
} 

#declare Pumpkin_StalkTexture = texture {
  pigment {marble turbulence 0.5
    pigment_map { 
      [0   color rgb <0  ,0.08,0  >]  
      [0.5 color rgb <0.1,0.6 ,0.1>]  
      [1   color rgb 0]  
    }
  }
  normal {marble} 
  scale <0.05,0.1,0.05>
}

#declare Pumpkin_Segment = sphere { <0,0,0>,0.4                                                              
  texture {Pumpkin_ExternalTexture}                                                                
  scale <0.6,0.9,0.8> translate -z*0.15}                  
 
#declare Pumpkin_Seed = seed(1);
#declare Pumpkin = difference { 
  union {  
    #local Pumpkin_SegmentCount = 0;
    #while (Pumpkin_SegmentCount<Pumpkin_Segments)
      object {Pumpkin_Segment rotate y*(Pumpkin_SegmentCount*360/Pumpkin_Segments + (rand(Pumpkin_Seed)-0.5)*5)}
      #local Pumpkin_SegmentCount = Pumpkin_SegmentCount+1;
    #end
  }
  union {
    // Now we hollow out the insides and cut eye holes so it can see.
    sphere {<0,0,0>,0.43 scale <1,0.7,1>}
    cylinder{<-0.12,0.15,-0.9><-0.12,0.15,0>0.05}
    cylinder{< 0.12,0.15,-0.9>< 0.12,0.15,0>0.05}
    // We cut out a nose
    difference {
      box {<-0.05,-0.05,-0.91>,<0.05,0.05,0.1> rotate z*45 scale <0.55,1.2,1> }
      plane {y,0}
      rotate z*4
    }
    // And the mouth (leaving 1 tooth).
    difference {
      cylinder {<0,0,-0.9>,<0,0,0>,0.2}
      cylinder {<0,0.25,-0.91>,<0,0.25,0.1>,0.35}
      box {<0.01,-0.14,-0.91>,<0.05,0.1,0.1>}
    } 
    texture {Pumpkin_InternalTexture}
  }
}

#declare Pumpkin_StalkSegment = intersection {
  torus {0.3,0.02 translate z*0.3}  
  box {<0,-0.2,-0.2><0.25,0.2,0.12>}
  rotate z*90
}
#declare Pumpkin_Stalk = union { 
  object {Pumpkin_StalkSegment rotate <-9,50,-2>}
  object {Pumpkin_StalkSegment rotate <-11,52,2>}
  object {Pumpkin_StalkSegment rotate <-7,54,-1>}
  scale <1.2,0.65,1.2>  
  translate y*0.3
  texture {Pumpkin_StalkTexture rotate -z*35}
}                                                       

//  Sample scene of our smiling pumpkin

light_source {<0,-0.2, 0> color rgb <1.5,1.5,1.5> }
light_source {<0, 0.2,-0.1> color rgb<2,2,2> spotlight point_at<0,-0.3,0.2>}
light_source {<2.5, 2.8, -4.8> color rgb <1.2,1.2,1.2> }
camera {location <0.3,0.2,-1.1> look_at  <0,0,0>}


object {Pumpkin}
object {Pumpkin_Stalk}                                    