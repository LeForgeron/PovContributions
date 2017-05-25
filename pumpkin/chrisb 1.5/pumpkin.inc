// Object Name: Pumpkin 
// Version:     01.10.95 for POV 2.2.
// Updated:     17.10.07 To use macros in an include file   
// Description: A pumpkin for Halloween with eye, nose and mouth holes.
// Scale:       1 unit = 0.5 metre diameter pumpkin (All sizes are approximate).
// Positioning: Sphere centred at the origin.
// Details:     A configurable number of copies of a squashed sphere, rotated at different 
//              angles around the Y axis to make a segmented pumpkin shape. 
//              Alternatively a Blob-based pumpkin is slower to render, but more bumpy.
// Keywords:    Pumpkin, Halloween, Vegetables, Market gardening
// Author:      Chris Bartlett.  
// This file is licensed under the terms of the CC-LGPL

// This Macro builds a pumpkin out of a series of segments.
#macro Pumpkin () 
  // Initialise any control variables that haven't been explicitly set in the scene file
  #ifndef(Pumpkin_Seed)                #declare Pumpkin_Seed = seed(1);          #end // Randomisation seed makes successive pumpkins differ
  #ifndef(Pumpkin_Segments)            #declare Pumpkin_Segments = 19;           #end // Minimum about 12, Maximum about 24
  #ifndef(Pumpkin_SegmentType)         #declare Pumpkin_SegmentType = "Blob";    #end // "Blob"=More realistic or "Sphere"=Quick to render
  #ifndef(Pumpkin_SegmentPerturbation) #declare Pumpkin_SegmentPerturbation = 1; #end // 0=Not very perturbed, 1=Very perturbed
  #ifndef(Pumpkin_StalkOn)             #declare Pumpkin_StalkOn             = 1; #end // Default is to add a stalk
  #ifndef(Pumpkin_FaceHolesOn)         #declare Pumpkin_FaceHolesOn         = 1; #end // Default is to cut eyes, nose and mouth holes
  #ifndef(Pumpkin_LightsOn)            #declare Pumpkin_LightsOn            = 1; #end // Add interior lights
  
  // The texture used for the exterior surface of the Pumpkin
  #ifndef(Pumpkin_ExternalTexture)
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
  #end  
  
  // The texture used for the interior of the Pumpkin and the various holes
  #ifndef(Pumpkin_InternalTexture)
    #declare Pumpkin_InternalTexture = texture { 
      pigment {color rgb <1,0.8,0>} 
      normal {bumps scale 0.001}
      finish {phong 0.1}
    }
  #end 
  
  // If not already set, define a default set of holes for the face
  #ifndef(Pumpkin_FaceHoles)
    #declare Pumpkin_FaceHoles = union {
      // Now we hollow out the insides and cut eye holes so it can see.
      sphere {<0,0,0>,0.43 scale <1,0.7,1>}
      cylinder{<-0.12,0.15,-0.9><-0.12,0.15,0>0.05 scale <0.95,1,1>}
      cylinder{< 0.12,0.15,-0.9>< 0.12,0.15,0>0.05 scale <1,0.97,1>}
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
      texture {Pumpkin_InternalTexture translate 100*Pumpkin_Seed}
    }
  #end

  // Build our pumpkin
  difference { 
    union {  
      #local Pumpkin_SegmentCount = 0;
      #while (Pumpkin_SegmentCount<Pumpkin_Segments)
        object {Pumpkin_Segment(Pumpkin_SegmentType)
          rotate y*(Pumpkin_SegmentCount*360/Pumpkin_Segments + (rand(Pumpkin_Seed)-0.5)*5)
        }
        #local Pumpkin_SegmentCount = Pumpkin_SegmentCount+1;
      #end
    }
    #if (Pumpkin_FaceHolesOn) object {Pumpkin_FaceHoles} #end
  }
  #if (Pumpkin_StalkOn) Pumpkin_Stalk() #end
  // Add some internal light sources 
  #if (Pumpkin_LightsOn)
    light_source {<0,-0.2, 0> color rgb <1.8,1.8,1.8> }
    light_source {<0, 0.2,-0.1> color rgb<2,2,2> spotlight point_at<0,-0.3,0.2>} 
  #end
#end

// This macro builds individual pumpkin segments. It can use the Sphere shape for speed or the Blob shape for realism.
#macro Pumpkin_Segment (Type)  
  #if (strcmp(Type,"Blob")=0) 
    blob { 
      sphere {<0,0,0>,0.8,2}                                                              
      sphere {<0,0,-0.4>,0.8,-0.08 scale <0.25,0.4,1.2>}
      #local Increment = 1-Pumpkin_SegmentPerturbation;
      #while (Increment<1)
        sphere {<0,0,-0.4>,0.3*rand(Pumpkin_Seed)*Pumpkin_SegmentPerturbation+0.1,-0.03
          rotate <(rand(Pumpkin_Seed)-0.5)*180,2*(rand(Pumpkin_Seed)-0.5)*360/Pumpkin_Segments,0>
          pigment {color rgb <1,0,0>}
        }
        #local Increment = Increment + 0.3*rand(Pumpkin_Seed);
      #end
                                                                    
      texture {Pumpkin_ExternalTexture translate 100*Pumpkin_Seed}                                                                
      scale <0.5,0.9,0.8> translate -z*0.15
    }
  // If not using blobs, default to using a squashed sphere
  #else
    sphere { <0,0,0>,0.4                                                              
      texture {Pumpkin_ExternalTexture translate 100*Pumpkin_Seed}                                                                
      scale <0.6,0.9,0.8> translate -z*0.15
    }
  #end
#end
 
// This macro creates a stalk from 3 stalk segments.
#macro Pumpkin_Stalk() 
  // If a texture for the stalk has not been defined, create a default texture
  #ifndef(Pumpkin_StalkTexture)
    #declare Pumpkin_StalkTexture = texture {
      pigment {marble turbulence 0.5
        pigment_map { 
          [0   color rgb <0  ,0.08,0  >]  
          [0.5 color rgb <0.1,0.6 ,0.1>]  
          [1   color rgb 0]  
        }
      }
      normal {marble} 
      scale <0.03,0.1,0.03>
      translate y*100*rand(Pumpkin_Seed)
    }
  #end
  
  // Build the stalk 
  union { 
    object {Pumpkin_StalkSegment() rotate <-7-6*rand(Pumpkin_Seed),50+6*rand(Pumpkin_Seed),-2+6*rand(Pumpkin_Seed)>}
    object {Pumpkin_StalkSegment() rotate <-7-6*rand(Pumpkin_Seed),50+6*rand(Pumpkin_Seed),-2+6*rand(Pumpkin_Seed)>}
    object {Pumpkin_StalkSegment() rotate <-7-6*rand(Pumpkin_Seed),50+6*rand(Pumpkin_Seed),-2+6*rand(Pumpkin_Seed)>}
    scale <1.2,0.65,1.2>  
    translate y*0.3
    rotate y*360*rand(Pumpkin_Seed)
  }
#end                                                       
                 
// This macro creates a single segment of pumpkin stalk.
#macro Pumpkin_StalkSegment ()
  intersection {
    torus {0.3,0.02 translate z*0.3}  
    box {<0,-0.2,-0.2><0.25,0.2,0.12>}
    rotate z*90 
    texture {Pumpkin_StalkTexture rotate x*45 translate 100*rand(Pumpkin_Seed)}
  } 
#end 
 
