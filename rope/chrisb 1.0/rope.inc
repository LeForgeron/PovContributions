
//
// rope.inc
// --------
// Created by Chris Bartlett May 2009
// This include file contains the 'Rope' macros and some sample rope textures. 
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The scale is 1 POV-Ray unit = 1 metre
//

#include "transforms.inc" 
#include "math.inc"

// These rope macros generate a choice of different types of rope (currently just Left/Right hand twist).
// The rope is formed using spheres to track along a helix following the path of a spline. 
// Two layers of textures are applied, one to give potentially variegated coloration to the 
// individual strands, the other to give a fibrous texture aligned to the length of rope. 



//
// The Rope_StandardStyles macro sets control variables based upon a predefined style. 
// It has one parameter:
//    Rope_Style  is the name of the predefined style required.
//
#macro Rope_StandardStyles(Rope_Style)
  #switch(0)

    #case(strcmp(strlwr(Rope_Style),"brown braided"))
      #declare Rope_Type            = "Braided";
      #declare Rope_OuterColor      = <1,0.55,0.15>;
    #break

    #case(strcmp(strlwr(Rope_Style),"patchwork"))
      #declare Rope_StrandTextureArray     = array[6];
      #declare Rope_StrandTextureArray[0]  = texture {pigment {rgb <1,1,0>}}
      #declare Rope_StrandTextureArray[1]  = texture {pigment {rgb <0,1,1>}}
      #declare Rope_StrandTextureArray[2]  = texture {pigment {rgb <1,0,1>}}
      #declare Rope_StrandTextureArray[3]  = texture {pigment {rgb <1,0,0>}}
      #declare Rope_StrandTextureArray[4]  = texture {pigment {rgb <0,1,0>}}
      #declare Rope_StrandTextureArray[5]  = texture {pigment {rgb <0,0,1>}} 
      #ifndef (Rope_SplineIncrement) #declare Rope_SplineIncrement = 0.001;    #end
      #ifndef (Rope_Radius         ) #declare Rope_Radius          = 0.018;    #end
      #declare Rope_TwistRatio   = 1.8;
      #declare Rope_CordRadius   = Rope_Radius*0.52; 
      #declare Rope_BraidInset   = Rope_CordRadius*1;       // 0.5 to 2
      #declare Rope_Type         = "Braided"; 
    #break
    #case(strcmp(strlwr(Rope_Style),"soft yellow braided"))
      #ifndef (Rope_SplineIncrement) #declare Rope_SplineIncrement = 0.0005;   #end
      #ifndef (Rope_Radius         ) #declare Rope_Radius          = 0.018;    #end
      #declare Rope_TwistRatio   = 1.8;
      #declare Rope_CordRadius   = Rope_Radius*0.52; 
      #declare Rope_BraidInset   = Rope_CordRadius*0.5;       // 0.5 to 2
      #declare Rope_Type         = "Braided"; 
    #break
    #case(strcmp(strlwr(Rope_Style),"gold braided"))
      #declare Rope_FibreColor   = <1.5,1.5,0,0.1>;
      #ifndef (Rope_SplineIncrement) #declare Rope_SplineIncrement = 0.0005;   #end
      #ifndef (Rope_Radius         ) #declare Rope_Radius          = 0.018;    #end
      #declare Rope_TwistRatio   = 1.8;
      #declare Rope_CordRadius   = Rope_Radius*0.3; 
      #declare Rope_BraidInset   = Rope_CordRadius*2;       // 0.5 to 2
      #declare Rope_Randomness   = 4;
      #declare Rope_Type         = "Braided"; 
      #declare Rope_StrandFinish = finish {ambient 0.1 roughness 0.6}
      #declare Rope_FibreFinish  = finish {ambient 0}
    #break
    #case(strcmp(strlwr(Rope_Style),"loose gold braid"))
      #ifndef (Rope_Radius         ) #declare Rope_Radius          = 0.018;   #end
      #declare Rope_TwistRatio   = 3;
      #declare Rope_CordRadius   = Rope_Radius*0.3; 
      #declare Rope_BraidInset   = Rope_CordRadius*1.5;       // 0.5 to 2
      #declare Rope_Randomness   = 1;
      #declare Rope_Type         = "Braided"; 
      #declare Rope_StrandFinish = finish {ambient 0.2 roughness 0.6}
      #declare Rope_FibreFinish  = finish {ambient 0.2}
    #break
    #case(strcmp(strlwr(Rope_Style),"red knobbly"))
      #declare Rope_OuterColor   = <0.4,0,0>;
      #declare Rope_InnerColor   = <0.2,0,0>;
      #declare Rope_FibreColor   = <3,0,0,0.1>;
      #ifndef (Rope_SplineIncrement) #declare Rope_SplineIncrement = 0.0005;  #end
      #ifndef (Rope_Radius         ) #declare Rope_Radius          = 0.018;   #end
      #declare Rope_TwistRatio   = 1.8;
      #declare Rope_CordRadius   = Rope_Radius*0.5; 
      #declare Rope_BraidInset   = Rope_CordRadius*1;       // 0.5 to 2
      #declare Rope_Randomness   = 5;
      #declare Rope_Type         = "Braided"; 
    #break
    #case(strcmp(strlwr(Rope_Style),"white"))
      #ifndef (Rope_Radius         ) #declare Rope_Radius          = 0.018;   #end
      #declare Rope_FibreColor   = <1.5,1.5,1.5,0.1>;
      #declare Rope_Randomness = 1;
      #declare Rope_CordRadius   = Rope_Radius*0.6; 
      #declare Rope_StrandTexture = texture {
        pigment {rgb 1.5} 
        finish {ambient 0.1}
      }
    #break

    #case(strcmp(strlwr(Rope_Style),"cyan"))
      #declare Rope_FibreFrequency  = 30;
      #declare Rope_Randomness      = 0.7;
      #declare Rope_OuterColor      = <0,1,1>;
      #declare Rope_InnerColor      = <0,0.5,1>;
    #break

    #case(strcmp(strlwr(Rope_Style),"cyan braided"))
      #declare Rope_Type = "Braided"; 
      #declare Rope_Randomness      = 0.7;
      #declare Rope_OuterColor      = <0,1,1>;
      #declare Rope_InnerColor      = <0,0.5,1>;
    #break

    #case(strcmp(strlwr(Rope_Style),"soft white"))
      #declare Rope_FibrousTexture = texture {
        pigment { rgb 1}
        normal {radial frequency 20 
          slope_map {
            [0    <0,  1>]   
            [0.5  <0,  0>]  
            [1    <0, -1>]   
          }        
        }
      }
      #declare Rope_Randomness = 2;
    #break

    #case(strcmp(strlwr(Rope_Style),"left helix brown"))
      #declare Rope_Type            = "Left Helix";
      #declare Rope_OuterColor      = <1,0.55,0.15>;
    #break

    #case(strcmp(strlwr(Rope_Style),"brown"))
      #declare Rope_OuterColor      = <1,0.55,0.15>;
    #break

  #end
#end



//
// The Rope_Defaults macro sets default values for any control variables that have not yet been defined. 
// It has no parameters.
//
#macro Rope_Defaults()

  #ifndef (Rope_Type           ) #declare Rope_Type            = "Right Helix";                                      #end
  #ifndef (Rope_Radius         ) #declare Rope_Radius          = 0.018;                                               #end
  #ifndef (Rope_Brightness     ) #declare Rope_Brightness      = 1;                                                   #end
  #ifndef (Rope_OuterColor     ) #declare Rope_OuterColor      = <1,0.95,0.65>*Rope_Brightness;                       #end
  #ifndef (Rope_InnerColor     ) #declare Rope_InnerColor      = 1.2*<1.0,0.6,0.1>*Rope_Brightness;                   #end
  #ifndef (Rope_FibreColor     ) #declare Rope_FibreColor      = (Rope_OuterColor*0.4+<0,0,0,0.1>)*Rope_Brightness;   #end
  #ifndef (Rope_SplineIncrement) #declare Rope_SplineIncrement = 0.001;                                               #end
  #ifndef (Rope_LengthChunks   ) #declare Rope_LengthChunks    = 1000;                                                #end
  #ifndef (Rope_ShowFibres     ) #declare Rope_ShowFibres      = 1;                                                   #end     
  #ifndef (Rope_Randomness     ) #declare Rope_Randomness      = 0;                                                   #end     
  #ifndef (Rope_FibreFrequency ) #declare Rope_FibreFrequency  = 50;                                                  #end     
  #ifndef (Rope_ShowRopeLength ) #declare Rope_ShowRopeLength  = 1;                                                   #end     
                                                                                                                      
  #if (strcmp(strlwr(Rope_Type),"braided")=0)                                                                         
    #ifndef (Rope_CordRadius   ) #declare Rope_CordRadius      = Rope_Radius/3;                                       #end          
    #ifndef (Rope_BraidInset   ) #declare Rope_BraidInset      = Rope_CordRadius;                                     #end
    #ifndef (Rope_TwistRatio   ) #declare Rope_TwistRatio      = 2;                                                   #end
  #else                                                                                                               
    #ifndef (Rope_CordRadius   ) #declare Rope_CordRadius      = Rope_Radius/2;                                       #end          
    #ifndef (Rope_BraidInset   ) #declare Rope_BraidInset      = 0;                                                   #end
    #ifndef (Rope_TwistRatio   ) #declare Rope_TwistRatio      = 3;                                                   #end
  #end

  #if (strcmp(strlwr(Rope_Type),"left helix")=0)                                                       
    #declare Rope_HelixDirection  = -1;
  #else                                                                                             
    #declare Rope_HelixDirection  = 1;
  #end

  #ifndef (Rope_RandomStream) #declare Rope_RandomStream = seed(1);         #end
  #ifndef (Rope_StrandFinish) #declare Rope_StrandFinish = finish {phong 0} #end
  #ifndef (Rope_FibreFinish ) #declare Rope_FibreFinish  = finish {phong 0} #end

  // Add a default texture that's reasonably quick to render
  #ifndef (Rope_StrandTexture)
    #declare Rope_StrandTexture   = texture {
      pigment {gradient z frequency 1
        color_map {
          [0    color Rope_OuterColor]
          [0.05 color Rope_OuterColor]
          [0.1  color Rope_OuterColor*0.8]
          [0.5  color Rope_InnerColor]
          [0.9  color Rope_OuterColor*0.8]
          [0.95 color Rope_OuterColor]
          [1    color Rope_OuterColor]
        }
        scale 2
        translate -z
        scale Rope_CordRadius
      }                 
      finish {Rope_StrandFinish}
    }
  #end
  // Add a default fibrous texture that can optionally be applied to the align with the path of the rope.
  #ifndef (Rope_FibrousTexture)
    #declare Rope_FibrousTexture = texture {
      pigment {radial frequency Rope_FibreFrequency
        color_map {
          [0  , color rgbt 1]
          [0.35, color rgbt 1]
          [0.5  , color rgbt Rope_FibreColor]
          [0.6, color rgbt 1]
          [1  , color rgbt 1]
        }
      }
      normal {agate 1 scale 0.02 translate rand(Rope_RandomStream)}
      finish {Rope_FibreFinish}
    }
  #end
  
  // Declare a default spline
  #ifndef (Rope_CentreSpline) 
    #declare Rope_CentreSpline = spline {
      natural_spline
      0.00, <0,1,0>
      0.25, <0,0.5,0.2>
      0.50, <0,1,0.5>
      0.75, <-0.1,1,-0.1>
      1.00, <0.5,1,-0.1>
    }
  #end
#end  // End of 'Rope_Defaults' macro


//
// The Rope macro generates a rope that follows the spline named 'Rope_CentreSpline'. 
// It has one parameter:
//    Rope_Style  is the name of the predefined style required.
//
#macro Rope(Rope_Style)
  #ifndef (Rope_RandomStream) #declare Rope_RandomStream = seed(1); #end

  // If a style is specified set control variables appropriate to that style.
  #if (strlen(Rope_Style)>0)
    Rope_StandardStyles(Rope_Style) 
    #ifdef(StandardStyles) StandardStyles(Rope_Style) #end
  #end 
 
  // Set default values for any attributes that have not yet been set.
  Rope_Defaults()

  // Find the length of the spline and write that information out into the message stream.
  #declare Rope_Length = 0; 
  #local   Rope_I = 0;
  #local   Rope_LastPos = Rope_CentreSpline(0);
  #declare Rope_LongestIncrement = 0;
  #while (Rope_I<=1)
    #local   Rope_ThisPos          = Rope_CentreSpline(Rope_I);
    #local   Rope_ThisIncrement    = vlength(Rope_ThisPos-Rope_LastPos);
    #declare Rope_LongestIncrement = max(Rope_LongestIncrement,Rope_ThisIncrement);
    #declare Rope_Length           = Rope_Length + Rope_ThisIncrement;
    #local   Rope_LastPos          = Rope_ThisPos;
    #local   Rope_I                = Rope_I+1/Rope_LengthChunks;
  #end
  #if (Rope_ShowRopeLength) #debug concat("Rope Length: ",str(Rope_Length,3,5),"\n") #end
  
  
  // Establish the starting conditions, including the 3D orientation of the beginning of the spline.
  #local Rope_LastPos = Rope_CentreSpline(0);
  #local Rope_ThisPos = Rope_CentreSpline(0.001);
  #local Rope_AheadVector = vnormalize(Rope_ThisPos-Rope_LastPos);
  #if (VAngleD(y, Rope_AheadVector)>5 & VAngleD(y, Rope_AheadVector)<175)
    #local Rope_UpVector = VPerp_To_Plane(y,Rope_AheadVector);
  #else 
    #local Rope_UpVector = VPerp_To_Plane(z,Rope_AheadVector);
  #end

  // Work out how much to twist the rope by with each increment.           
  #local Rope_RotationalIncrement = y*360*Rope_HelixDirection/(2*Rope_Radius*Rope_TwistRatio);
  // Determine how many points along the spline will need to be sampled to be able to get a roughly even increment.
  #local Rope_SplineSteps = max(Rope_LengthChunks,Rope_LengthChunks*Rope_LongestIncrement/Rope_SplineIncrement);
//#debug concat("Rope_LengthChunks: ",str(Rope_LengthChunks,3,3),"\n")
//#debug concat("Rope_LongestIncrement: ",str(Rope_LongestIncrement,3,3),"\n")
//#debug concat("Rope_SplineIncrement: ",str(Rope_SplineIncrement,3,3),"\n")
//#debug concat("Rope_SplineSteps: ",str(Rope_SplineSteps,3,3),"\n")
  #ifndef (Rope_StrandTextureArray ) #declare Rope_StrandTextureArray  = array[6]; #end
  #local Rope_I = 0;
  #while (Rope_I < 6)
    #ifndef (Rope_StrandTextureArray[Rope_I] ) #declare Rope_StrandTextureArray[Rope_I]  = Rope_StrandTexture  #end
    #local Rope_I = Rope_I+1;
  #end
  // The rope object returned from the macro call is a CSG union of spheres.
  union {
    // Step through the spline, keeping tabs on how far along we are, adding a new chunk or rope as required.
    // Note that we keep the macro calls to a minimum within this loop to reduce processing overhead.
    #local Rope_SplinePos = 0;
    #local Rope_SplineDistance = 0;
    #local Rope_ElementCount = 0;
    #if (strcmp(strlwr(Rope_Type),"braided")=0 & Rope_BraidInset>0)
      #local Rope_BraidScale = <1,1,0.5*Rope_BraidInset/Rope_CordRadius>;
    #else 
      #local Rope_BraidScale = 1;
    #end
    #while (Rope_SplinePos <= 1)
      #local Rope_ThisPos        = Rope_CentreSpline(Rope_SplinePos);
      #local Rope_ThisIncrement  = vlength(Rope_ThisPos-Rope_LastPos);
      #local Rope_SplineDistance = Rope_SplineDistance + Rope_ThisIncrement;
      // If the distance since the last chunk is sufficient, add a new one.  
      #if (Rope_SplineDistance>=Rope_ElementCount*Rope_SplineIncrement)
        #local Rope_ElementCount = Rope_ElementCount + 1;
        // The following macro calls have been inlined to improve performance:
        //   #local Rope_UpVector    = VPerp_Adjust(Rope_UpVector,Rope_AheadVector);    
        //   #local Rope_ZRot = VRotationD(<Rope_AheadVector.x,Rope_AheadVector.y,0>,x,z);
        //   #local Rope_YRot = VRotationD(vrotate(Rope_AheadVector,z*Rope_ZRot),x,y);
        //   #local Rope_XRot = VRotationD(vrotate(vrotate(Rope_UpVector,z*Rope_ZRot),y*Rope_YRot),y,x);
        #if (Rope_SplinePos = 1) 
          #local Rope_AheadVector = vnormalize(Rope_CentreSpline(Rope_SplinePos)-Rope_CentreSpline(Rope_SplinePos-0.001)); 
        #else 
          #local Rope_AheadVector = vnormalize(Rope_CentreSpline(Rope_SplinePos+0.001)-Rope_CentreSpline(Rope_SplinePos)); 
        #end
        #local Rope_UpVector    = vnormalize(vcross(vcross(Rope_AheadVector, Rope_UpVector), Rope_AheadVector));
  
        // Calculate the Z rotation required to bring the 'Ahead' vector round onto the XZ-plane.
        #if (Rope_AheadVector.y!=0)
          #local Rope_ZRot = (degrees(acos(min(vdot(vnormalize(<Rope_AheadVector.x,Rope_AheadVector.y,0>),x),1)))
                           * (vdot(z,vcross(<Rope_AheadVector.x,Rope_AheadVector.y,0>,x))<0?-1:1));
        #else #local Rope_ZRot = 0;
        #end      
        // Calculate the Y rotation required to align this intermediary point with the X-axis.
        #local Rope_YRot = (degrees(acos(min(vdot(vnormalize(vrotate(Rope_AheadVector,z*Rope_ZRot)),x),1)))
                         * (vdot(y,vcross(vrotate(Rope_AheadVector,z*Rope_ZRot),x))<0?-1:1));      
        // Calculate the X rotation required to align an intermediary copy of the 'Up' vector with the y-axis.
        #local Rope_XRot = (degrees(acos(min(vdot(vnormalize(vrotate(vrotate(Rope_UpVector,z*Rope_ZRot),y*Rope_YRot)),y),1)))
                         * (vdot(x,vcross(vrotate(vrotate(Rope_UpVector,z*Rope_ZRot),y*Rope_YRot),y))<0?-1:1));      
        #local Rope_ChunkOrientation = -<Rope_XRot,Rope_YRot,Rope_ZRot>;
  
        #local Rope_HelixRotation = mod(Rope_SplineDistance * Rope_RotationalIncrement.y,120);
        // Make the inset follow a sinusoidal path so that two opposite strands are farthest apart 
        // where they cross (at a rotation of 0 and multiples of 120).
        #local Rope_ThisBraidInset = Rope_BraidInset*0.5*(cosd(Rope_HelixRotation*3)+1);
        // Work out how much randomness to apply to each strand (normally 3 strands, 6 if braided)                                      
        #local Rope_StrandRandmomness = array[6] {
          Rope_Randomness*rand(Rope_RandomStream)
          Rope_Randomness*rand(Rope_RandomStream)
          Rope_Randomness*rand(Rope_RandomStream)
          Rope_Randomness*rand(Rope_RandomStream)
          Rope_Randomness*rand(Rope_RandomStream)
          Rope_Randomness*rand(Rope_RandomStream)
        };
        
        // Add a sphere for each of the 3 strands using the rope texture.
        #local Rope_StrandNo = 0;
        union {
          #while (Rope_StrandNo < 3)
            sphere {0, Rope_CordRadius
              // Add the texture to each sphere separately.
              texture {Rope_StrandTextureArray[Rope_StrandNo]}
              // For braided rope take account of the inset value (some rope is only braided on the outside) 
              translate -z*Rope_CordRadius scale Rope_BraidScale translate z*Rope_CordRadius
              // Move the sphere out and rotate to its 'strand' position.
              translate z*(Rope_Radius-Rope_CordRadius-Rope_ThisBraidInset+Rope_StrandRandmomness[Rope_StrandNo]*0.06*Rope_Radius) 
              rotate y*Rope_StrandNo*120 
            }
            #local Rope_StrandNo = Rope_StrandNo + 1;
          #end
          // Rotate around 'y' by the amount required to create a helix.
          rotate Rope_SplineDistance * Rope_RotationalIncrement
          // Orient this chunk so that it points in the direction the rope is going.
          rotate z*90
          rotate Rope_ChunkOrientation
          // Move this chunk into position
          translate Rope_CentreSpline(Rope_SplinePos)
        }
  
        // For braided rope add another 3 helixes turning in the opposite direction.
        #if (strcmp(strlwr(Rope_Type),"braided")=0) 
          #local Rope_StrandNo = 0;
          union {
            #while (Rope_StrandNo < 3)
              sphere {0, Rope_CordRadius
                // Add the texture to each sphere separately.
                texture {Rope_StrandTextureArray[Rope_StrandNo+3]}
                // For braided rope take account of the inset value (some rope is only braided on the outside) 
                translate -z*Rope_CordRadius scale Rope_BraidScale translate z*Rope_CordRadius
                // Move the sphere out and rotate to its 'strand' position. 
                translate z*(Rope_Radius-Rope_CordRadius-Rope_BraidInset+Rope_ThisBraidInset+Rope_StrandRandmomness[Rope_StrandNo+3]*0.001)
                rotate y*Rope_StrandNo*120 
              }
              #local Rope_StrandNo = Rope_StrandNo + 1;
            #end
            // Rotate around 'y' by the amount required to create a helix.
            rotate -Rope_SplineDistance * Rope_RotationalIncrement
            // Orient this chunk so that it points in the direction the rope is going.
            rotate z*90
            rotate Rope_ChunkOrientation
            // Move this chunk into position
            translate Rope_CentreSpline(Rope_SplinePos)
          }
        #end // End of #if "Braided"
  
        // Optionally add a fibrous texture aligned to follow the path of the rope. 
        #if (Rope_ShowFibres)
          // Add 3 slightly larger spheres adding a fibrous texture to the union of these spheres.
          #local Rope_StrandNo = 0;
          union {
            #while (Rope_StrandNo < 3)
              sphere {0, Rope_CordRadius+0.0012
                translate -z*Rope_CordRadius scale Rope_BraidScale translate z*Rope_CordRadius
                translate z*(Rope_Radius-Rope_CordRadius-Rope_ThisBraidInset+Rope_StrandRandmomness[Rope_StrandNo]*0.001)
                rotate y*Rope_StrandNo*120 
              }
              #local Rope_StrandNo = Rope_StrandNo + 1;
            #end
            no_shadow
            rotate Rope_SplineDistance * Rope_RotationalIncrement
            // Add a radial texture after the chunk is twisted to match the helix, so that the texture 
            // aligns on successive chunks.
            texture {Rope_FibrousTexture}
            // Orient and position this chunk.
            rotate z*90
            rotate Rope_ChunkOrientation
            translate Rope_CentreSpline(Rope_SplinePos)
          }
  
          // For braided rope add a fibrous texture to the outside of the rope.
          #if (strcmp(strlwr(Rope_Type),"braided")=0) 
            #local Rope_StrandNo = 0;
            union {
              #while (Rope_StrandNo < 3)
                sphere {0, Rope_CordRadius+0.0012
                  translate -z*Rope_CordRadius scale Rope_BraidScale translate z*Rope_CordRadius
                  translate z*(Rope_Radius-Rope_CordRadius-Rope_BraidInset+Rope_ThisBraidInset+Rope_StrandRandmomness[Rope_StrandNo+3]*0.001)
                  rotate y*Rope_StrandNo*120 
                }
                #local Rope_StrandNo = Rope_StrandNo + 1;
              #end
              no_shadow
              rotate -Rope_SplineDistance * Rope_RotationalIncrement
              // Add a radial texture after the chunk is twisted to match the helix, so that the texture 
              // aligns on successive chunks.
              texture {Rope_FibrousTexture}
              rotate z*90
              rotate Rope_ChunkOrientation
              translate Rope_CentreSpline(Rope_SplinePos)
            }
          #end  // End of #if "Braided"
            
        #end  // End of #if Rope_ShowFibres
          
      #end  // End of the #if statement.
      // Get ready for the next iteration.
      #local Rope_LastPos   = Rope_ThisPos;
      #local Rope_SplinePos = Rope_SplinePos+1/Rope_SplineSteps;    
    #end  // End of the #while loop.
  }
#end  // End of 'Rope' macro


//
// The Rope_Binding macro adds a cylindrical object onto the end of the rope to represent the
// sort of twine binding typically used to stop rope fraying. 
// It has 1 parameter:
//    Rope_WhichEnd      is one of the strings "Start", "End" or "Both" to indicate which end to add this object to.
//
#macro Rope_Binding(Rope_WhichEnd)
  #ifndef (Rope_CentreSpline)
    #error "The Rope macro or the Rope_ArrayToRope macro needs to have been run before running this macro."
  #end
  #ifndef (Rope_BindingLength      ) #declare Rope_BindingLength       = Rope_Radius*1.5;       #end 
  #ifndef (Rope_BindingRadius      ) #declare Rope_BindingRadius       = Rope_Radius*0.95;  #end 
  #ifndef (Rope_BindingThreadRadius) #declare Rope_BindingThreadRadius = Rope_Radius/20;    #end 
  #local Rope_ThreadObjectCount = int(Rope_BindingLength/(2*Rope_BindingThreadRadius)+0.5);
  
  #if (strcmp(strlwr(Rope_Type),"braided")=0)
    #local Rope_ThreadObject = torus {Rope_BindingRadius-Rope_BindingThreadRadius,Rope_BindingThreadRadius
      pigment {color rgb Rope_OuterColor}
    }
    #local Rope_StrandCount = 6;
  #else
    #local Rope_ThreadObject = union {
      torus {Rope_CordRadius-Rope_BindingThreadRadius,Rope_BindingThreadRadius translate z*(Rope_Radius-Rope_CordRadius)}
      torus {Rope_CordRadius-Rope_BindingThreadRadius,Rope_BindingThreadRadius translate z*(Rope_Radius-Rope_CordRadius) rotate y*120}
      torus {Rope_CordRadius-Rope_BindingThreadRadius,Rope_BindingThreadRadius translate z*(Rope_Radius-Rope_CordRadius) rotate y*240}
      cylinder {<-0.5*sqrt(3)*(Rope_Radius-Rope_CordRadius),0,0><0.5*sqrt(3)*(Rope_Radius-Rope_CordRadius),0,0>,Rope_BindingThreadRadius
        translate -z*(0.5*(Rope_Radius-Rope_CordRadius)+Rope_CordRadius)
      }
      cylinder {<-0.5*sqrt(3)*(Rope_Radius-Rope_CordRadius),0,0><0.5*sqrt(3)*(Rope_Radius-Rope_CordRadius),0,0>,Rope_BindingThreadRadius
        translate -z*(0.5*(Rope_Radius-Rope_CordRadius)+Rope_CordRadius) 
        rotate y*120
      }
      cylinder {<-0.5*sqrt(3)*(Rope_Radius-Rope_CordRadius),0,0><0.5*sqrt(3)*(Rope_Radius-Rope_CordRadius),0,0>,Rope_BindingThreadRadius
        translate -z*(0.5*(Rope_Radius-Rope_CordRadius)+Rope_CordRadius) 
        rotate y*240
      }
      pigment {color rgb Rope_OuterColor}
    }
    #local Rope_StrandCount = 3;
  #end
  // Create the object standing upright at the origin.
  #local Rope_BindingObject = union {
    #local Rope_I = 0;
    #while (Rope_I<Rope_ThreadObjectCount)
      object {Rope_ThreadObject translate y*Rope_BindingThreadRadius*2*Rope_I}
      #local Rope_I = Rope_I + 1;
    #end 
    #if (strcmp(strlwr(Rope_Type),"braided")=0)
      cylinder {0,y*Rope_BindingLength,Rope_BindingRadius-Rope_BindingThreadRadius pigment {color rgb Rope_InnerColor}}
    #end
    #local Rope_StrandNo = 0;
    union {
      #while (Rope_StrandNo < Rope_StrandCount)
        difference {
          sphere {0, Rope_CordRadius}
          box {<-Rope_CordRadius,Rope_CordRadius*0.2,-Rope_CordRadius><Rope_CordRadius,Rope_CordRadius+0.0001,Rope_CordRadius>}
          // Add the texture to each sphere separately.
          texture {Rope_StrandTextureArray[Rope_StrandNo]} 
          // For braided rope take account of the inset value (some rope is only braided on the outside) 
          translate -z*Rope_CordRadius translate z*Rope_CordRadius
          // Move the sphere out and rotate to its 'strand' position.
          translate z*(Rope_Radius-Rope_CordRadius) 
          rotate y*Rope_StrandNo*120 
          #if (Rope_StrandNo>=3) rotate y*60 #end
        }
        #local Rope_StrandNo = Rope_StrandNo + 1;
      #end 
      translate y*Rope_BindingLength
    }
    translate y*Rope_CordRadius*0.5
  }                
  #if (strcmp(strlwr(Rope_WhichEnd),"both")=0)
    union {
  #end
  #if (strcmp(strlwr(Rope_WhichEnd),"start")=0 | strcmp(strlwr(Rope_WhichEnd),"both")=0)
    #local Rope_StartPos    = Rope_CentreSpline(0);
    #local Rope_Orientation = Rope_CentreSpline(0)-Rope_CentreSpline(0.001);
    object {Rope_BindingObject Reorient_Trans(y,Rope_Orientation) translate Rope_StartPos}
  #end
  #if (strcmp(strlwr(Rope_WhichEnd),"end"  )=0 | strcmp(strlwr(Rope_WhichEnd),"both")=0)
    #local Rope_StartPos    = Rope_CentreSpline(1);
    #local Rope_Orientation = Rope_CentreSpline(1)-Rope_CentreSpline(0.999);
    object {Rope_BindingObject Reorient_Trans(y,Rope_Orientation) translate Rope_StartPos}
  #end
  #if (strcmp(strlwr(Rope_WhichEnd),"both")=0)
    }
  #end
#end


//
// The Rope_ArrayToSpline macro takes a sequence of coordinates assigned to the Rope_Array array and uses them 
// to generate a spline. 
// It has one parameter:
//    Rope_SplineType  is the type of spline to create. A "natural_spline" works best and is the default.
//
#macro Rope_ArrayToSpline(Rope_SplineType) 
  #ifndef (Rope_Array)
    #declare Rope_Array = array[5] {  
      < 0  ,1  , 0  >,
      < 0  ,0.5, 0.2>,
      < 0  ,1  , 0.5>,
      <-0.1,1  ,-0.1>,
      < 0.5,1  ,-0.1>
    }
  #end
  // If not known, count the number of actual elements used
  #ifndef (Rope_ArrayIndex)
    #local Rope_ArrayIndex = -1;
    #local Rope_I = 0;
    #while (Rope_I<dimension_size(Rope_Array,1))
      #if (defined(Rope_Array[Rope_I]))  
        #local Rope_ArrayIndex = Rope_ArrayIndex+1;
        #local Rope_I = Rope_I+1;
      #else
        #local Rope_I = dimension_size(Rope_Array,1));
      #end
    #end 
  #end
  // Create a spline suitable for use with the Rope macro
  #declare Rope_CentreSpline = spline { 
    #switch (0)
      #case(strcmp(strlwr(Rope_SplineType),"linear_spline"))
        linear_spline
      #break
      #case(strcmp(strlwr(Rope_SplineType),"quadratic_spline"))
        quadratic_spline
      #break
      #case(strcmp(strlwr(Rope_SplineType),"cubic_spline"))
        cubic_spline 
        -0.25, 2*Rope_Array[0]-Rope_Array[1]
      #break
      #else
        natural_spline
    #end
    #local Rope_I = 0;
    #while (Rope_I<=Rope_ArrayIndex)
      Rope_I/Rope_ArrayIndex, Rope_Array[Rope_I]
      #local Rope_I = Rope_I+1;
    #end 
    #switch (0)
      #case(strcmp(strlwr(Rope_SplineType),"cubic_spline"))
        1.25, 2*Rope_Array[Rope_ArrayIndex]-Rope_Array[Rope_ArrayIndex-1]
      #break
    #end
  }
#end 


//
// The Rope_BreakSpline macro adds a marker into the Rope_SplineTypeList array to tell the 
// Rope_ArrayToRope macro where to break a spline into multiple sections each with potentially 
// different spline types.  
// 
// It has one parameter:
//    Rope_SplineType  is the type of spline to create. A "natural_spline" often works best and is the default.
//
#macro Rope_BreakSpline(Rope_SplineType) 
  #if (strcmp(Rope_SplineType,"")=0) #declare Rope_SplineType = "natural_spline"; #end 
  #ifndef(Rope_SplineTypeList)
    Rope_InitializeKnot(0, 0)
  #end
  #if (Rope_ArrayIndex<0)
    #error "Rope_BreakSpline: A point needs to have been added into the Rope_Array macro before calling this macro.\n"
  #end
  #declare Rope_SplineTypeList[Rope_ArrayIndex] = Rope_SplineType;
#end 


//
// The Rope_ArrayToRope macro takes a sequence of coordinates assigned to the Rope_Array array and uses them 
// to generate one or more splines that can be used to construct a single rope object.
// 
// It has 2 parameters:
//    Rope_Style       is the name of the predefined style required.
//
#macro Rope_ArrayToRope(Rope_Style) 
  #local Rope_NotInitialized = 0;
  #if (!defined(Rope_SplineTypeList) | !defined(Rope_ArrayIndex))
    #local Rope_NotInitialized = 1;
  #else
    #if (Rope_ArrayIndex<0) #local Rope_NotInitialized = 1; #end
  #end
  // If something is not initialized, just draw the default rope.
  #if (Rope_NotInitialized) 
    Rope_ArrayToSpline("")
    Rope(Rope_Style)
  #else 
    #if (Rope_ArrayIndex<1)
      #error "Rope_ArrayIndex shows that there are insufficient points in the Rope_Array array (minimum = 2)."
    #end
//#debug concat("Rope_ArrayIndex: ",str(Rope_ArrayIndex,3,3),"\n")
    // Work out how many splines/rope segments are required to generate this rope and their start 
    // and end indices.
    #local Rope_SplineCount = 0;
    #local Rope_SplineStart = array[1000];
    #local Rope_SplineEnd   = array[1000];
    #local Rope_Index = 0;
    // Look for new splines up to but not including the last array index.
    #while (Rope_Index<Rope_ArrayIndex)
      #ifdef(Rope_SplineTypeList[Rope_Index])
        #local Rope_SplineStart[Rope_SplineCount] = Rope_Index;
        #if (Rope_SplineCount>0)
          #local Rope_SplineEnd[Rope_SplineCount-1] = Rope_Index;
        #end
        #local Rope_SplineCount = Rope_SplineCount + 1; 
      #end
      #local Rope_Index = Rope_Index+1;
//#debug concat("Rope_SplineCount: ",str(Rope_SplineCount,3,3),"\n")
    #end
    #local Rope_SplineEnd[Rope_SplineCount-1] = Rope_ArrayIndex; 
    #if (Rope_SplineCount<2)
      Rope_ArrayToSpline("")
      Rope(Rope_Style)
    #else

      union {
        #local Rope_CurrentSpline = 0;
        #while (Rope_CurrentSpline<Rope_SplineCount)
          #declare Rope_SplineType = Rope_SplineTypeList[Rope_SplineStart[Rope_CurrentSpline]];
          // Create a spline suitable for use with the Rope macro
          #declare Rope_CentreSpline = spline { 
            #switch (0)
              #case(strcmp(strlwr(Rope_SplineType),"linear_spline"))
                linear_spline
              #break
              #case(strcmp(strlwr(Rope_SplineType),"quadratic_spline"))
                quadratic_spline
              #break
              #case(strcmp(strlwr(Rope_SplineType),"cubic_spline"))
                cubic_spline 
                -0.25, 2*Rope_Array[0]-Rope_Array[1]
              #break
              #else
                natural_spline
            #end 
            #local Rope_Index = Rope_SplineStart[Rope_CurrentSpline];
            #local Rope_SplineIndex = 0;
            #local Rope_SplineIndexIncrement = 1/(Rope_SplineEnd[Rope_CurrentSpline]-Rope_SplineStart[Rope_CurrentSpline]);
            #while (Rope_Index<=Rope_SplineEnd[Rope_CurrentSpline])
              Rope_SplineIndex, Rope_Array[Rope_Index]  
              #local Rope_SplineIndex = Rope_SplineIndex+Rope_SplineIndexIncrement;
              #local Rope_Index = Rope_Index+1;
            #end 
            #switch (0)
              #case(strcmp(strlwr(Rope_SplineType),"cubic_spline"))
                1.25, 2*Rope_Array[Rope_ArrayIndex]-Rope_Array[Rope_ArrayIndex-1]
              #break
            #end
          }
          Rope(Rope_Style)
          #local Rope_CurrentSpline = Rope_CurrentSpline+1;
        #end   // End of outer while loop
      }      // End of Union

    #end   // End of #if (Rope_SplineCount<2)
  #end   // End of #if initialized
#end   // End of Macro


//
// The Rope_InitializeKnot macro is called by all of the shape/knot macros to 
// make sure that the Rope_Array is initialized, to adjust the orientation vectors
// and, if required, to make sure that the Rope_HalfKnotList is initialized.
//
// It has 2 parameter2:
//    Rope_KnotHalf   shows which part of the knot is being created, or 0 if it's being 
//                    generated in a single pass.
//    Rope_StartArray indicates whether (1) or not (0) this macro should add a first point to
//                    the array if it doesn't contain any points yet.Most of the macros depend 
//                    upon there being a current point from which to add points, the  
//                    Rope_AddPoint macro being the principal exception to this.
//
#macro Rope_InitializeKnot(Rope_KnotHalf, Rope_StartArray)
  #ifndef(Rope_ArraySize) #local Rope_ArraySize = 10000; #end
  #ifndef (Rope_Array) 
    #declare Rope_Array = array[Rope_ArraySize];
    #declare Rope_ArrayIndex = -1;
  #end
  #if (Rope_ArrayIndex < 0 & Rope_StartArray)
    #declare Rope_ArrayIndex = 0;
    #declare Rope_Array[Rope_ArrayIndex] = <0,0,0>;
  #end
  #ifndef (Rope_SplineTypeList) 
    #declare Rope_SplineTypeList = array[Rope_ArraySize];
    #declare Rope_SplineTypeList[0] = "";
  #end
  #if (Rope_ArrayIndex<1)
    #declare Rope_ArrayAheadVector = x;
    #declare Rope_ArrayUpVector = y; 
  #end 
  #declare Rope_ArrayRightVector = -VPerp_To_Plane(Rope_ArrayAheadVector,Rope_ArrayUpVector);
  #ifndef (Rope_KnotHandedness   ) #declare Rope_KnotHandedness    = 1;       #end
  #ifndef (Rope_RandomStream     ) #declare Rope_RandomStream      = seed(1); #end 
  #ifndef (Rope_Radius           ) #declare Rope_Radius            = 0.018;   #end
  #ifndef (Rope_KnotRandomization) #declare Rope_KnotRandomization = 0.3;     #end 
  #ifndef (Rope_ShowPositions) #declare Rope_ShowPositions = 0; #end
  #ifndef (Rope_HalfKnotList)
    #declare Rope_HalfKnotList  = array[1000][3];
    #declare Rope_HalfKnotIndex = -1;
  #end   
  #if (Rope_KnotHalf=2)
    #if (!defined(Rope_HalfKnotList) | Rope_HalfKnotIndex<0)
      #error "You called a Rope shape/knot macro to generate the second part of a multi-part knot before creating the first part.\n"
    #end 
  #end
#end


//
// The Rope_AdjustVectors macro is used to recalculate the Rope_ArrayAheadVector and Rope_ArrayUpVector 
// vectors after one or more coordinates have been added into the Rope_Array array.
// It has no parameters.
//
#macro Rope_AdjustVectors()
  #if (vlength(vcross(Rope_ArrayAheadVector,Rope_ArrayUpVector))=0)
    #declare Rope_ArrayUpVector = VPerp_To_Vector(Rope_ArrayAheadVector);
  #else   
    #declare Rope_ArrayUpVector = VPerp_Adjust(Rope_ArrayUpVector,Rope_ArrayAheadVector);
  #end
  #declare Rope_ArrayRightVector = -VPerp_To_Plane(Rope_ArrayAheadVector,Rope_ArrayUpVector);
#end


//
// The Rope_AddPoint macro adds a coordinate to the Rope_Array array.
//
// It has one parameter:
//    Rope_Coordinate  is the coordinate of the point to add to the array.
//
#macro Rope_AddPoint(Rope_Coordinate)
  Rope_InitializeKnot(0,0)
  #declare Rope_ArrayIndex = Rope_ArrayIndex + 1;
  #declare Rope_Array[Rope_ArrayIndex] = Rope_Coordinate;
  #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  #if (Rope_ArrayIndex>0)
    #declare Rope_ArrayAheadVector = Rope_Array[Rope_ArrayIndex]-Rope_Array[Rope_ArrayIndex-1];
    Rope_AdjustVectors()
  #end
#end


//
// The Rope_SlackSegment macro adds a loose length of rope to the Rope_Array array connecting the current point 
// with a given coordinate. Two points are added to the array. The second point uses the coordinate specified, the 
// first point is somewhere below the straight line between the current point and the specified coordinate, at a height 
// intended to give a drooping length of rope of approximately the required length.             
//
// If it doesn't add the new calculated position where you want it you can use the debug statement at the end of this 
// macro to display the position into the message stream and subsequently use the Rope_AddPoint instead to add a 
// point that is better positioned for your purposes.
//
// It has 2 parameters:
//    Rope_Coordinate    is the coordinate of the end of the segment to add to the array.
//    Rope_SegmentLength is the target length of the segment of rope. This macro will attempt 
//                       to very approximately match this length.
//
#macro Rope_SlackSegment(Rope_Coordinate,Rope_SegmentLength)
  Rope_InitializeKnot(0,1)
  #local Rope_StartPosition = Rope_Array[Rope_ArrayIndex];
  #local Rope_SegmentDisp   = Rope_Coordinate-Rope_StartPosition;
  // Make sure there's at least enough length to connect the two end points.
  #local Rope_SegmentLength = max(vlength(Rope_Coordinate-Rope_StartPosition),Rope_SegmentLength);
  //#local Rope_ShowPositions = 0;  // For debug purposes only
 
  // Add a point between the current position and the specified coordinate to create a curved 
  // section of rope that droops with gravity (ie in the -y direction) which will be approximately
  // the required length.
  #local Rope_HorizontalDist = vlength(Rope_SegmentDisp*<1,0,1>);
  // How much height would we need to achieve the required length in this horizontal distance?
  // This is a very approximate (linear) calculation incorporating a couple of 'frig' factors to limit
  // the consequences of the incumbent inaccuracies.
  #local Rope_VerticalDist   = 1.1*sqrt(max(pow(Rope_SegmentLength,2)-pow(Rope_HorizontalDist,2),0.01));
  // How much of that is below the horizon of the lowest point?  
  #local Rope_YDisp          = -(Rope_VerticalDist-abs(Rope_SegmentDisp.y))/2;
  // Make sure the added control point isn't too close to either end 
  #local Rope_StartDisp      = Rope_SegmentDisp/4; 
  // The new intermediary point is displaced from the lowest end point.
  #if (Rope_StartPosition.y<Rope_Coordinate.y)
    #local Rope_NewPosition = Rope_StartPosition+Rope_StartDisp+y*Rope_YDisp+(<1,0,1>*Rope_SegmentDisp*abs(Rope_YDisp)/Rope_VerticalDist)/2;
  #else
    #local Rope_NewPosition = Rope_Coordinate-Rope_StartDisp+y*Rope_YDisp-(<1,0,1>*Rope_SegmentDisp*abs(Rope_YDisp)/Rope_VerticalDist)/2;
  #end
  #declare Rope_ArrayIndex = Rope_ArrayIndex + 1;
  #declare Rope_Array[Rope_ArrayIndex] = Rope_NewPosition;
  #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end

  // Add the point at the end of the segment
  #declare Rope_ArrayIndex = Rope_ArrayIndex + 1;
  #declare Rope_Array[Rope_ArrayIndex] = Rope_Coordinate;
  #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  #declare Rope_ArrayAheadVector = Rope_Array[Rope_ArrayIndex]-Rope_Array[Rope_ArrayIndex-1];
  Rope_AdjustVectors()
 
//#debug concat("Rope_SegmentLength:  ",str(Rope_SegmentLength,3,3),"\n")
//#debug concat("Rope_HorizontalDist: ",str(Rope_HorizontalDist,3,3),"\n")
//#debug concat("Rope_VerticalDist:   ",str(Rope_VerticalDist,3,3),"\n")
//#debug concat("Rope_YDisp:          ",str(Rope_YDisp,3,3),"\n")
//#debug concat("Rope_NewPosition:    ",vstr(3,Rope_NewPosition,",",3,3),"\n")
#end




//
// The Rope_Catenary macro adds a loose length of rope to the Rope_Array array connecting the current point 
// with a given coordinate. A large number of points are added to the array to attempt to accurately track 
// the catenary path. The catenary follows the path that a chain or cable hanging under its own weight 
// follows. Long lengths of rope typically follow such a path, although for shorter lengths the internal forces
// passed along the rope usually cause the rope to deviate from a catenary shape.              
//
// This macro has one parameter:
//    Rope_Coordinate    is the coordinate of the end of the catenary segment to add to the array.
//
#macro Rope_Catenary(Rope_Coordinate)
  Rope_InitializeKnot(0,1) 
  
  #ifndef (Rope_Catenary_a) #local Rope_Catenary_a = 1; #end
  
  //#local Rope_ShowPositions = 1;  // For debug purposes only
  #local Rope_StartPosition  = Rope_Array[Rope_ArrayIndex];
  // Calculate prereqs for hyperbolic trigonometric calculations.
  #local Rope_SegmentDisp    = Rope_Coordinate-Rope_StartPosition;
  #local Rope_HorizontalDisp = vlength(Rope_SegmentDisp*<1,0,1>);
  #local Rope_VerticalDisp   = abs(Rope_SegmentDisp.y);
  #local Rope_HorizontalDirection = vnormalize(Rope_SegmentDisp*<1,0,1>);
  #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  
  // This algorithm uses trial and error to fit the catenary to the specified start and end points.
  // It uses a derivative of the formula for a catenary with its lowest point at the origin:
  //   y=a*(cosh(x/a)-1)
  // This uses the hyperbolic cosine and the value for 'a', which is a constant for a given
  // catenary, defining the ratio between the horizontal force on the rope and the weight per
  // unit length.
  // We don't know either 'x' or 'y', but, for end points A and B we know 'B.x-A.x' and 'B.y-A.y', so
  // we can say that:
  //   B.y-A.y = a*(cosh(B.x/a)-1) - a*(cosh(A.x/a)-1)  
  // or:
  //   B.y-A.y = a*(cosh(B.x/a) - cosh(A.x/a))
  
  // We start by calculating what the Y displacement would be if the lower of the two end points
  // is positioned at the lowest part of the catenary curve and the higher of the two end points 
  // is on the curve, the required X displacement to the right of that.
  #local Rope_X = 0;
  #local Rope_Y = Rope_Catenary_a*(cosh((Rope_X+Rope_HorizontalDisp)/Rope_Catenary_a)-cosh(Rope_X/Rope_Catenary_a)); 
  // If the Y displacement is too small, move the start point to the right. 
  // If the Y displacement is too large, move the start point to the left.
  #local Rope_Direction =  1; 
  #if (Rope_Y>Rope_VerticalDisp) #local Rope_Direction = -Rope_Direction; #end 
  #local Rope_Accuracy = 0.001;
  // Move quickly at first, but the following #while loop reduces this delta amount as we home-in 
  // on the value we're looking for until we have the accuracy required.
  #local Rope_Delta = Rope_HorizontalDisp/10; 
  #while (abs(Rope_Y-Rope_VerticalDisp)>Rope_Accuracy)
    #local Rope_X = Rope_X+Rope_Delta*Rope_Direction;
    #local Rope_Y = Rope_Catenary_a*(cosh((Rope_X+Rope_HorizontalDisp)/Rope_Catenary_a)-cosh(Rope_X/Rope_Catenary_a)); 
    // If we overshoot, switch directions and reduce the delta to home in more accurately.
    #if ((Rope_Y>Rope_VerticalDisp & Rope_Direction>0)|(Rope_Y<Rope_VerticalDisp & Rope_Direction<0))
      #local Rope_Direction = -Rope_Direction;
      #local Rope_Delta = Rope_Delta/10;
    #end
  #end 

  // Now we've found a line that crosses the catenary with the required horizontal and vertical 
  // displacements to map to our start and end points. We know the X and Y displacements from the 
  // origin of the catenary curve to the lowest of the two ends. Now we can move from one end to the
  // other, adding coordinates into the 'Rope_Array' array.

  // Add 20 points into the Rope_Array array to track along the catenary (using a uniform X displacement)
  // If the start point is higher than the end point we need to start from the other end of the line that 
  // we mapped to the catenary in the last step.
  #if (Rope_StartPosition.y>Rope_Coordinate.y)
    #local Rope_X = -(Rope_HorizontalDisp+Rope_X);
  #end 
  // Reuse Rope_Y to point to the corresponding height of the starting point on the curve.
  #local Rope_Y = Rope_Catenary_a*(cosh(Rope_X/Rope_Catenary_a)-1);
  // Work out how big each horizontal step will be. 
  #local Rope_Delta = Rope_HorizontalDisp/20; 
  #local Rope_XDisp = 0;
  #while (Rope_XDisp < Rope_HorizontalDisp)
    // Get the Y value relative to a catenary with its lowest point at the origin. 
    #local Rope_YVal = Rope_Catenary_a*(cosh((Rope_XDisp+Rope_X)/Rope_Catenary_a)-1); 
    // Work out the Y displacement from the start point for the selected X displacement.                                                                                              
    #local Rope_YDisp = Rope_YVal-Rope_Y;
    // Add this point into the array.
    #declare Rope_ArrayIndex = Rope_ArrayIndex + 1;
    #declare Rope_Array[Rope_ArrayIndex] = Rope_StartPosition + Rope_HorizontalDirection*Rope_XDisp + y*Rope_YDisp;
    #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    // Move along to calculate the next point.
    #local Rope_XDisp = Rope_XDisp + Rope_Delta;
  #end

  // Add the specified end point to the end of the segment
  #declare Rope_ArrayIndex = Rope_ArrayIndex + 1;
  #declare Rope_Array[Rope_ArrayIndex] = Rope_Coordinate;
  #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  #declare Rope_ArrayAheadVector = Rope_Array[Rope_ArrayIndex]-Rope_Array[Rope_ArrayIndex-1];
  Rope_AdjustVectors()
 
//#debug concat("Rope_X:  ",str(Rope_X,3,3),"\n")
//#debug concat("Rope_Y:  ",str(Rope_Y,3,3),"\n")
#end


//
// The Rope_OverhandKnot macro adds 8 points to the Rope_Array array that follow the 
// path of a simple overhand knot tied in the rope.
// It has no parameters.
//
#macro Rope_OverhandKnot()
  Rope_InitializeKnot(0,1)
  
    //#local Rope_ShowPositions = 0;  // For debug purposes only
  #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end

  Rope_ArrayDisplacement( 0.5, 0.5,-0.5 )     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement( 0.8, 0  ,-0.5 )     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement( 0.4,-1.5, 1.0 )     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement(-0.9, 1  , 0.85)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement(-1.2, 1  ,-1.1 )     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement( 0.5,-1  ,-0.85)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement( 0.9,-0.3, 0.8 )     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement( 0.9, 0.3, 0.3 )     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end

  #declare Rope_ArrayAheadVector = Rope_Array[Rope_ArrayIndex]-Rope_Array[Rope_ArrayIndex-1];
  Rope_AdjustVectors()
#end  


//
// The Rope_FigureOfEight macro adds 12 points to the Rope_Array array that follow the 
// path of a figure of eight knot tied in the rope.
// It has no parameters.
//
#macro Rope_FigureOfEight()
  Rope_InitializeKnot(0,1)
   
    //#local Rope_ShowPositions = 0;  // For debug purposes only
  #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end

  Rope_ArrayDisplacement( 1.75, 0.55, 0.5 )     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement( 0.75, 0   , 0.15)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement( 0.75,-0.55, 0.2 )     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement( 1   ,-1   ,-0.85)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement(-1.1 , 0.75,-0.9 )     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement(-0.7 , 0.75, 0.25)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement(-0.3 ,-0.5 , 0.65)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement(-0.75, 0.5 , 1.0 )     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement(-0.95, 0.5 ,-1.0 )     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement( 1.25,-1.15,-0.65)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement( 1.25,-0.65, 0.60)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement( 2.5 , 0.8 , 0.05)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end

  #declare Rope_ArrayAheadVector = Rope_Array[Rope_ArrayIndex]-Rope_Array[Rope_ArrayIndex-1];
  Rope_AdjustVectors()
#end  



//
// The Rope_ReefKnot macro adds 20 points to the Rope_Array array that follow the 
// path of a reef knot tied in the rope (25 if the two halves are joined). This is usually 
// done in two passes, creating one half of the knot (10 points) with the first macro call 
// and completing it with a second macro call.
// This is because a reef knot is usually used to tie two sections of rope together. 
// 
// It has 1 parameter.
//    Rope_KnotHalf  1 to add the first half, 2 to draw the second half or 0 to draw both halves.
//
#macro Rope_ReefKnot(Rope_KnotHalf)
  Rope_InitializeKnot(Rope_KnotHalf,1)
  #ifndef (Rope_HalfKnotList)
    #declare Rope_HalfKnotList  = array[1000][3];
    #declare Rope_HalfKnotIndex = -1;
  #end

    //#local Rope_ShowPositions = 0;  // For debug purposes only
  #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  
  // Because this is a highly symmetrical knot we only really need to define 3 displacements, the rest
  // can be derived by mirroring these points. 
  #local Rope_P1 = <0.2, 0   , 0  >;
  #local Rope_P2 = <0.4,-0.1 ,-0.1>;
  #local Rope_P3 = <0.4,-0.4 , 0.2>;
  #local Rope_P4 = <0.8, 0.75, 0.7>;
  #local Rope_P5 = <0.6, 0.75,-1.25>;

  #if (Rope_KnotHalf=0 | Rope_KnotHalf=1)
    // The first quarter of the knot uses the displacements as defined.
    Rope_ArrayDisplacement( Rope_P1.x, Rope_P1.y, Rope_P1.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( Rope_P2.x, Rope_P2.y, Rope_P2.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( Rope_P3.x, Rope_P3.y, Rope_P3.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( Rope_P4.x, Rope_P4.y, Rope_P4.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( Rope_P5.x, Rope_P5.y, Rope_P5.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    // The second quarter reverses the backward-forward and up-down movements (and the sequence)
    Rope_ArrayDisplacement(-Rope_P5.x,-Rope_P5.y, Rope_P5.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-Rope_P4.x,-Rope_P4.y, Rope_P4.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-Rope_P3.x,-Rope_P3.y, Rope_P3.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-Rope_P2.x,-Rope_P2.y, Rope_P2.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-Rope_P1.x,-Rope_P1.y, Rope_P1.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    // Store away the starting location and orientation required to construct the second half of the knot.
    #declare Rope_HalfKnotIndex = Rope_HalfKnotIndex+1; 
    #declare Rope_HalfKnotList[Rope_HalfKnotIndex][0] =  Rope_Array[Rope_ArrayIndex]
                                                      + 2.2*vnormalize(Rope_ArrayAheadVector)*2*Rope_Radius*Rope_KnotLooseness;
    #declare Rope_HalfKnotList[Rope_HalfKnotIndex][1] = -Rope_ArrayAheadVector; 
    #declare Rope_HalfKnotList[Rope_HalfKnotIndex][2] =  Rope_ArrayUpVector; 
  #end
  #if (Rope_KnotHalf=0)
    // Add a couple of points to join the end of the first half of the knot  
    // to the start of the second half. 
    Rope_ArrayDisplacement(-0.1, 0.3 ,-0.5)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 0.5, 0.3 ,-0.9)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 1.6,-1.2 , 0  )     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 0.5, 0.3 , 0.9)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-0.1, 0.3 , 0.5)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  #end
  #if (Rope_KnotHalf=0 | Rope_KnotHalf=2)
    // Retrieve the starting location and orientation required for the second half of the knot.
    Rope_AddPoint(Rope_HalfKnotList[Rope_HalfKnotIndex][0])
    #declare Rope_ArrayAheadVector = Rope_HalfKnotList[Rope_HalfKnotIndex][1]; 
    #declare Rope_ArrayUpVector    = Rope_HalfKnotList[Rope_HalfKnotIndex][2]; 
    #declare Rope_ArrayRightVector = -VPerp_To_Plane(Rope_ArrayAheadVector,Rope_ArrayUpVector);
    #declare Rope_HalfKnotIndex    = Rope_HalfKnotIndex-1;
    // The third and fourth quarters are the same as the first two quarters, 
    // except that the up-down displacement is reversed.
    Rope_ArrayDisplacement( Rope_P1.x,-Rope_P1.y, Rope_P1.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( Rope_P2.x,-Rope_P2.y, Rope_P2.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( Rope_P3.x,-Rope_P3.y, Rope_P3.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( Rope_P4.x,-Rope_P4.y, Rope_P4.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( Rope_P5.x,-Rope_P5.y, Rope_P5.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-Rope_P5.x, Rope_P5.y, Rope_P5.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-Rope_P4.x, Rope_P4.y, Rope_P4.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-Rope_P3.x, Rope_P3.y, Rope_P3.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-Rope_P2.x, Rope_P2.y, Rope_P2.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-Rope_P1.x, Rope_P1.y, Rope_P1.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  #end
  
  #declare Rope_ArrayAheadVector = Rope_Array[Rope_ArrayIndex]-Rope_Array[Rope_ArrayIndex-1];
  Rope_AdjustVectors()
#end  



//
// The Rope_RoundTurnAndTwoHalfHitches macro adds 14 points to the Rope_Array array that follow the 
// path of a round turn and two half inches tied in the rope (16 if the two halves are joined). This is usually 
// done in two passes, creating the first part of the knot (just a straight line) with the first macro call 
// adding 1 point and completing it with a second macro call that adds the two hitches, using 13 points.
// 
// It has 1 parameter.
//    Rope_KnotHalf  1 to add the first half, 2 to draw the second half or 0 to draw both halves.
//
#macro Rope_RoundTurnAndTwoHalfHitches(Rope_KnotHalf)
  Rope_InitializeKnot(Rope_KnotHalf,1)

    //#local Rope_ShowPositions = 0;  // For debug purposes only
  #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end

  #if (Rope_KnotHalf=0 | Rope_KnotHalf=1)
    // The first part of the knot is a simple straight segment.
    Rope_ArrayDisplacement( 2,0,0)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end

    // Store away the starting location and orientation required to construct the second part of the knot.
    #declare Rope_HalfKnotIndex = Rope_HalfKnotIndex+1; 
    #declare Rope_HalfKnotList[Rope_HalfKnotIndex][0] =  Rope_Array[Rope_ArrayIndex]
                                                      + vnormalize(Rope_ArrayUpVector   )*2*Rope_Radius
                                                      - vnormalize(Rope_ArrayAheadVector)*Rope_Radius
                                                      + vnormalize(Rope_ArrayRightVector)*2*Rope_Radius*Rope_KnotHandedness;
    #declare Rope_HalfKnotList[Rope_HalfKnotIndex][1] = -Rope_ArrayRightVector; 
    #declare Rope_HalfKnotList[Rope_HalfKnotIndex][2] =  Rope_ArrayUpVector; 
  #end
  #if (Rope_KnotHalf=0)
    // Add a couple of points to join the end of the first half of the knot  
    // to the start of the second half. 
    Rope_ArrayDisplacement(2,0,0)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    #declare Rope_ArrayUpVector = -Rope_ArrayRightVector;
    #declare Rope_Coils = 1.55;
    #declare Rope_UpDispPerCoil     = 0;  
    #declare Rope_RightDispPerCoil  = Rope_KnotHandedness;  
    Rope_Spiral()
  #end
  #if (Rope_KnotHalf=0 | Rope_KnotHalf=2)
    // Retrieve the starting location and orientation required for the second half of the knot.
    Rope_AddPoint(Rope_HalfKnotList[Rope_HalfKnotIndex][0])
    #declare Rope_ArrayAheadVector = Rope_HalfKnotList[Rope_HalfKnotIndex][1]; 
    #declare Rope_ArrayUpVector    = Rope_HalfKnotList[Rope_HalfKnotIndex][2]; 
    #declare Rope_ArrayRightVector = -VPerp_To_Plane(Rope_ArrayAheadVector,Rope_ArrayUpVector);
    #declare Rope_HalfKnotIndex    = Rope_HalfKnotIndex-1;
    #declare Rope_PoleRadius       = Rope_Radius;
    // Add a clove hitch that wraps around the first part of the knot.
    Rope_CloveHitch()
  #end
  
  #declare Rope_ArrayAheadVector = Rope_Array[Rope_ArrayIndex]-Rope_Array[Rope_ArrayIndex-1];
  Rope_AdjustVectors()
#end  



//
// The Rope_CloveHitch macro adds 13 points to the Rope_Array array that follow the 
// path of a clove hitch.
// It has no parameters.
//
#macro Rope_CloveHitch()
  Rope_InitializeKnot(0,1)
  
  #ifndef (Rope_Radius        ) #declare Rope_Radius         = 0.018;       #end
  #ifndef (Rope_PoleRadius)     #declare Rope_PoleRadius     = Rope_Radius; #end 

    //#local Rope_ShowPositions = 0;  // For debug purposes only
  #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  
  // The two halves of this knot are mirror images, so we only need to define the points once.
  #local Rope_DispFactor = Rope_PoleRadius/Rope_Radius;    // The ratio between the rope thickness (diameter) and the pole thickness.
  #local Rope_P1 = < (Rope_DispFactor*0.5+0.4),-0.1 , 0  >;
  #local Rope_P2 = < (Rope_DispFactor*0.5+0.5),-(Rope_DispFactor*0.5+0.4), 0.05>;
  #local Rope_P3 = <-(Rope_DispFactor*0.5+0.5),-(Rope_DispFactor*0.5+0.4), 0.44>;
  #local Rope_P4 = <-(Rope_DispFactor*0.5+0.4), (Rope_DispFactor*0.5+0.4), 0.36>;
  #local Rope_P5 = <                      0.3 , (Rope_DispFactor*0.5+0.7),-0.05>;
  #local Rope_P6 = <  Rope_DispFactor*0.3+0.1 , 0.65,-0.88>;
  #local Rope_P7 = <  Rope_DispFactor*0.4-0.1 , 0   ,-0.8>;
                                              
  // The first half of the knot uses the displacements as defined.
  Rope_ArrayDisplacement( Rope_P1.x, Rope_P1.y, Rope_P1.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement( Rope_P2.x, Rope_P2.y, Rope_P2.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement( Rope_P3.x, Rope_P3.y, Rope_P3.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement( Rope_P4.x, Rope_P4.y, Rope_P4.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
//#local Rope_ShowPositions = 1;
  Rope_ArrayDisplacement( Rope_P5.x, Rope_P5.y, Rope_P5.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement( Rope_P6.x, Rope_P6.y, Rope_P6.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  // The line joining the two halves.
  Rope_ArrayDisplacement( Rope_P7.x, Rope_P7.y, Rope_P7.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  // The second half reverses the up-down movements and the sequence.
  Rope_ArrayDisplacement( Rope_P6.x,-Rope_P6.y, Rope_P6.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
//#local Rope_ShowPositions = 0;
  Rope_ArrayDisplacement( Rope_P5.x,-Rope_P5.y, Rope_P5.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement( Rope_P4.x,-Rope_P4.y, Rope_P4.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement( Rope_P3.x,-Rope_P3.y, Rope_P3.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement( Rope_P2.x,-Rope_P2.y, Rope_P2.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  Rope_ArrayDisplacement( Rope_P1.x,-Rope_P1.y, Rope_P1.z)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  
  #declare Rope_ArrayAheadVector = Rope_Array[Rope_ArrayIndex]-Rope_Array[Rope_ArrayIndex-1];
  Rope_AdjustVectors()
#end  

//#debug concat("Rope_LengthChunks: ",str(Rope_LengthChunks,3,3),"\n")
//#debug concat("Rope_ArrayAheadVector  : ",vstr(3,Rope_ArrayAheadVector  ,",",3,3),"\n")


//
// The Rope_Bowline macro adds 16 points to the Rope_Array array that follow the 
// path of a bowline tied in the rope (18 if the two halves are joined). This is 
// usually done in two passes, creating the first part of the knot (just a twist 
// in the rope) with the first macro call adding 7 points and completing it with 
// a second macro call that adds the rest of the knot, using 9 points.
//
// This is similar to Rope_DutchBowline (Dutch Marine Bowline or Cowboy Bowline) 
// except that the final loop is reversed.
// 
// It has 1 parameter.
//    Rope_KnotHalf  1 to add the first half, 2 to draw the second half or 0 to draw both halves.
//
#macro Rope_Bowline(Rope_KnotHalf)
  Rope_InitializeKnot(Rope_KnotHalf,1)

    //#local Rope_ShowPositions = 0;  // For debug purposes only
  #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
//#local Rope_AxisPosition = Rope_Array[Rope_ArrayIndex];

  #if (Rope_KnotHalf=0 | Rope_KnotHalf=1)
  
    // The first part of the knot is a simple twist in the rope.
//#local Rope_ShowPositions = 1;
    Rope_ArrayDisplacement( 1.5  ,-0.5  , 0.587)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 1.5  , 0.7  , 0.134)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
//#local Rope_ShowPositions = 0;
    Rope_ArrayDisplacement( 0.034, 1.0  ,-2.059)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    #local Rope_CrossOverPosition = Rope_Array[Rope_ArrayIndex];
    Rope_ArrayDisplacement(-1.462,-0.900,-0.267)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-0.327, 0.200, 0.966)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 0.020,-0.200, 1.166)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 0.6  , 0.000, 0.9  )     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end

    // Store away the starting location and orientation required to construct the second part of the knot.
    #declare Rope_HalfKnotIndex = Rope_HalfKnotIndex+1; 
    #declare Rope_HalfKnotList[Rope_HalfKnotIndex][0] =  Rope_CrossOverPosition
                                                      + vnormalize(Rope_ArrayAheadVector)*0.5*Rope_Radius
                                                      - vnormalize(Rope_ArrayUpVector   )*2*Rope_Radius
                                                      + vnormalize(Rope_ArrayRightVector)*0*Rope_Radius*Rope_KnotHandedness;
    #declare Rope_HalfKnotList[Rope_HalfKnotIndex][1] = Rope_ArrayAheadVector; 
    #declare Rope_HalfKnotList[Rope_HalfKnotIndex][2] = Rope_ArrayUpVector; 
  #end
  #if (Rope_KnotHalf=0)
    // Add a couple of points to join the end of the first half of the knot  
    // to the start of the second half. 
    Rope_ArrayDisplacement( 5  ,0, 1)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 0.4,0,-4)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  #end
  #if (Rope_KnotHalf=0 | Rope_KnotHalf=2)
    // Retrieve the starting location and orientation required for the second half of the knot.
    Rope_AddPoint(Rope_HalfKnotList[Rope_HalfKnotIndex][0])
    #declare Rope_ArrayAheadVector = Rope_HalfKnotList[Rope_HalfKnotIndex][1]; 
    #declare Rope_ArrayUpVector    = Rope_HalfKnotList[Rope_HalfKnotIndex][2]; 
    #declare Rope_ArrayRightVector = -VPerp_To_Plane(Rope_ArrayAheadVector,Rope_ArrayUpVector);
    #declare Rope_HalfKnotIndex    = Rope_HalfKnotIndex-1;
    // Pass up through the eye, round the start point and back down through the eye.
    Rope_ArrayDisplacement(-1.4  , 0.6  , 0.5  )     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-1.029, 0.000,-0.017)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-0.596,-1.250, 0.233)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-0.254,-0.300, 1.239)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 0.916, 1.550, 0.413)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 0.933, 0.000,-0.616)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 1.466,-1.200,-0.539)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 0.683, 0.000,-0.183)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  #end
  
  #declare Rope_ArrayAheadVector = Rope_Array[Rope_ArrayIndex]-Rope_Array[Rope_ArrayIndex-1];
  Rope_AdjustVectors()
#end  


//
// The Rope_DutchBowline macro adds 16 points to the Rope_Array array that follow the 
// path of a Dutch Marine Bowline or Cowboy Bowline tied in the rope (18 if the two 
// halves are joined). This is usually done in two passes, creating the first part of 
// the knot (just a twist in the rope) with the first macro call adding 7 points and 
// completing it with a second macro call that adds the rest of the knot, using 9 points.
//
// This is similar to Rope_Bowline except that the final loop is reversed.
// 
// It has 1 parameter.
//    Rope_KnotHalf  1 to add the first half, 2 to draw the second half or 0 to draw both halves.
//
#macro Rope_DutchBowline(Rope_KnotHalf)
  Rope_InitializeKnot(Rope_KnotHalf,1)

    //#local Rope_ShowPositions = 0;  // For debug purposes only
  #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
//#local Rope_AxisPosition = Rope_Array[Rope_ArrayIndex];
//#local Rope_ShowPositions = 1;
//#local Rope_ShowPositions = 0;

  #if (Rope_KnotHalf=0 | Rope_KnotHalf=1)
  
    // The first part of the knot is a simple twist in the rope.
    Rope_ArrayDisplacement( 1.593,-0.500,-0.242)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 1.366, 0.700,-0.634)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-1.000, 1.000,-1.800)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    #local Rope_CrossOverPosition = Rope_Array[Rope_ArrayIndex];
    Rope_ArrayDisplacement(-1.400,-0.900, 0.500)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 0.200, 0.200, 1.000)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 0.600,-0.200, 1.000)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 0.970, 0.000, 0.479)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end

    // Store away the starting location and orientation required to construct the second part of the knot.
    #declare Rope_HalfKnotIndex = Rope_HalfKnotIndex+1; 
    #declare Rope_HalfKnotList[Rope_HalfKnotIndex][0] =  Rope_CrossOverPosition
                                                      + vnormalize(Rope_ArrayAheadVector)*2.2*Rope_Radius
                                                      - vnormalize(Rope_ArrayUpVector   )*2*Rope_Radius
                                                      + vnormalize(Rope_ArrayRightVector)*2*Rope_Radius*Rope_KnotHandedness;
    #declare Rope_HalfKnotList[Rope_HalfKnotIndex][1] = Rope_ArrayAheadVector; 
    #declare Rope_HalfKnotList[Rope_HalfKnotIndex][2] = Rope_ArrayUpVector; 
  #end
  #if (Rope_KnotHalf=0)
    // Add a couple of points to join the end of the first half of the knot  
    // to the start of the second half. 
    Rope_ArrayDisplacement( 5  ,0, 2  )     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 0.4,0,-4.5)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  #end
  #if (Rope_KnotHalf=0 | Rope_KnotHalf=2)
    // Retrieve the starting location and orientation required for the second half of the knot.
    Rope_AddPoint(Rope_HalfKnotList[Rope_HalfKnotIndex][0])
    #declare Rope_ArrayAheadVector = Rope_HalfKnotList[Rope_HalfKnotIndex][1]; 
    #declare Rope_ArrayUpVector    = Rope_HalfKnotList[Rope_HalfKnotIndex][2]; 
    #declare Rope_ArrayRightVector = -VPerp_To_Plane(Rope_ArrayAheadVector,Rope_ArrayUpVector);
    #declare Rope_HalfKnotIndex    = Rope_HalfKnotIndex-1;
    // Pass up through the eye, round the start point and back down through the eye.
    Rope_ArrayDisplacement(-1.400, 0.700, 1.4  )     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-0.500, 0.000, 1.000)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-1.000,-1.550, 0.100)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-0.400, 0.300,-1.200)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 0.400, 1.250,-0.500)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 0.900, 0.000,-0.500)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 1.062,-0.600,-0.960)     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 0.4  , 0.000,-0.3  )     #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end

  #end
  
  #declare Rope_ArrayAheadVector = Rope_Array[Rope_ArrayIndex]-Rope_Array[Rope_ArrayIndex-1];
  Rope_AdjustVectors()
#end 


////
//// The Rope_Helix macro adds points to the Rope_Array array, starting at the current position.
//// The new points follow the path of a helix of rope. The number of points is determined by 
//// the product of the Rope_Coils variable (default value = 3) and the Rope_PointsPerCoil 
//// variable (default value = 5.3).
//// The radius of the helix is defined using the Rope_PoleRadius variable (default value = 0.03).
//// 
//// It has no parameters.
////
//#macro Rope_Helix()
//  Rope_InitializeKnot(0,1)
// 
//  #ifndef (Rope_Coils            ) #declare Rope_Coils             = 3;       #end
//  #ifndef (Rope_PointsPerCoil    ) #declare Rope_PointsPerCoil     = 5.3;     #end
//  #ifndef (Rope_PoleRadius       ) #declare Rope_PoleRadius        = 0.03;    #end
//
//  #local Rope_TotalAngle           = 360*Rope_Coils;
//  #local Rope_NewPoints            = int(Rope_PointsPerCoil*Rope_Coils);
//  #local Rope_AngularIncrement     = Rope_TotalAngle/Rope_NewPoints;
//  #local Rope_LinearIncrement      = -Rope_Coils/Rope_NewPoints;  // In terms of Rope Thicknesses
//  #local Rope_CentreUpDisplacement = (Rope_PoleRadius+Rope_Radius)/(2*Rope_Radius);   // In terms of Rope Thicknesses  
//  #local Rope_LastDisplacement     = <0,0,0>;
//  // Loop through adding the required number of points by rotating a fixed 'upward' displacement around the z-axis.
//  // The x,y,z values are used as Forward, Up and Right displacements respectively by the Rope_ArrayDisplacement macro. 
//  #local Rope_I = 1;
//  #while (Rope_I<=Rope_NewPoints)                              
//    #local Rope_Displacement = - y*Rope_CentreUpDisplacement
//                               + vaxis_rotate(y*(Rope_CentreUpDisplacement+0.5*Rope_KnotRandomization*(rand(Rope_RandomStream)-0.5)),-z,Rope_AngularIncrement*Rope_I)
//                               + z*(Rope_I*Rope_LinearIncrement+0.1*Rope_KnotRandomization*(rand(Rope_RandomStream)-0.5));
//    #local Rope_ThisDisplacement = Rope_Displacement - Rope_LastDisplacement;
//    Rope_ArrayDisplacement(Rope_ThisDisplacement.x,Rope_ThisDisplacement.y,Rope_ThisDisplacement.z)
//    #local Rope_LastDisplacement = Rope_Displacement;
//    #local Rope_I = Rope_I+1;
//  #end
//  #declare Rope_ArrayAheadVector = Rope_Array[Rope_ArrayIndex]-Rope_Array[Rope_ArrayIndex-1];
//  Rope_AdjustVectors()
//#end


//
// The Rope_Spiral macro adds points to the Rope_Array array, starting at the current position.
// The new points spiral around an axis and can spiral inwards/outwards left or right based upon
// the specified settings. The number of points is determined by the product of 
// the Rope_Coils variable (default value = 3) and the Rope_PointsPerCoil variable (default 
// value = 5.3).
// 
// It has no parameters.
//
#macro Rope_Spiral()
  Rope_InitializeKnot(0,1)
 
  #ifndef (Rope_Coils            ) #declare Rope_Coils             = 3;    #end
  #ifndef (Rope_PointsPerCoil    ) #declare Rope_PointsPerCoil     = 5.3;  #end
  #ifndef (Rope_UpDispPerCoil    ) #declare Rope_UpDispPerCoil     = 1;    #end       // In terms of Rope Thicknesses
  #ifndef (Rope_RightDispPerCoil ) #declare Rope_RightDispPerCoil  = 0;    #end       // In terms of Rope Thicknesses

  #ifndef (Rope_PoleRadius       ) #local Rope_PoleRadius          = 0.03; #end
  #ifndef (Rope_CentreDisplacement) 
    #declare Rope_CentreDisplacement = 0.5*(Rope_Radius+Rope_PoleRadius)/Rope_Radius; // In terms of Rope Thicknesses
  #end
//#debug concat("Rope_CentreDisplacement: ",str(Rope_CentreDisplacement,3,3),"\n")
//#debug concat("Rope_ArrayAheadVector  : ",vstr(3,Rope_ArrayAheadVector  ,",",3,3),"\n")

  #local Rope_TotalAngle           = 360*Rope_Coils;
  #local Rope_NewPoints            = int(Rope_PointsPerCoil*Rope_Coils);
  #local Rope_AngularIncrement     = Rope_TotalAngle/Rope_NewPoints;
  #local Rope_UpIncrement          = Rope_UpDispPerCoil   *Rope_Coils/Rope_NewPoints;  
  #local Rope_RightIncrement       = Rope_RightDispPerCoil*Rope_Coils/Rope_NewPoints;
  
  #local Rope_LastDisplacement     = <0,0,0>;
  // Loop through adding the required number of points by rotating a fixed 'upward' displacement around the z-axis.
  // The x,y,z values are used as Forward, Up and Right displacements respectively by the Rope_ArrayDisplacement macro. 
  #local Rope_I = 1;
  #while (Rope_I<=Rope_NewPoints)                              
    #local Rope_Displacement = - y*Rope_CentreDisplacement
                               + vaxis_rotate(y*(Rope_CentreDisplacement+Rope_UpIncrement*Rope_I+0.5*Rope_KnotRandomization*(rand(Rope_RandomStream)-0.5)),-z,Rope_AngularIncrement*Rope_I)
                               + z*(Rope_I*Rope_RightIncrement+0.1*Rope_KnotRandomization*(rand(Rope_RandomStream)-0.5));
    #local Rope_ThisDisplacement = Rope_Displacement - Rope_LastDisplacement;
    Rope_ArrayDisplacement(Rope_ThisDisplacement.x,Rope_ThisDisplacement.y,Rope_ThisDisplacement.z)
    #local Rope_LastDisplacement = Rope_Displacement;
    #local Rope_I = Rope_I+1;
  #end
  // The ahead/up vectors at the end are set to be in the same plane as at the start. For accentuated helical 
  // shapes (large values of Rope_RightDispPerCoil) the ahead vector could end up pointing in a significantly 
  // different direction from the 'real' ahead direction of the rope, but this allows several successive coils
  // to be generated in the same plane.
  #declare Rope_ArrayAheadVector = vaxis_rotate(Rope_ArrayAheadVector,Rope_ArrayRightVector,Rope_TotalAngle);
  #declare Rope_ArrayUpVector    = vaxis_rotate(Rope_ArrayUpVector,Rope_ArrayRightVector,Rope_TotalAngle);
  Rope_AdjustVectors()
#end


//
// The Rope_Noose macro adds points to the Rope_Array array that follow the 
// path of a noose tied in the rope. The number of points depends on the number of 
// coils in the rope (14+5*No of coils).
//
// It has 1 parameter.
//    Rope_KnotHalf  1 to add the first half, 2 to draw the second half or 0 to draw both halves.
//
#macro Rope_Noose(Rope_KnotHalf)
  Rope_InitializeKnot(Rope_KnotHalf,1)

  #ifndef (Rope_Coils            ) #declare Rope_Coils             = 9;       #end
  #ifndef (Rope_KnotRandomization) #declare Rope_KnotRandomization = 0.7;     #end 
  #ifndef (Rope_RandomStream     ) #declare Rope_RandomStream      = seed(1); #end  
  
    //#local Rope_ShowPositions = 0;  // For debug purposes only
  #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end

  #if (Rope_KnotHalf=0 | Rope_KnotHalf=1)
    // The first part of the knot is a simple straight segment that passes down through the coils.
    Rope_ArrayDisplacement(  Rope_Coils+1.8, 0  , 0) #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end

    // Store away the starting location and orientation required to construct the second part of the knot.
    #declare Rope_HalfKnotIndex = Rope_HalfKnotIndex+1; 
    #declare Rope_HalfKnotList[Rope_HalfKnotIndex][0] = Rope_Array[Rope_ArrayIndex] - vnormalize(Rope_ArrayUpVector)*1.8*Rope_Radius;
    #declare Rope_HalfKnotList[Rope_HalfKnotIndex][1] = Rope_ArrayAheadVector; 
    #declare Rope_HalfKnotList[Rope_HalfKnotIndex][2] = Rope_ArrayUpVector; 
  #end
  #if (Rope_KnotHalf=0)
    // Add a loop of points to join the end of the first half of the knot to the start of the second part. 
    Rope_ArrayDisplacement( 7  , 2.5, 0) #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 4.9,-3  , 0) #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-4.9,-3  , 0) #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  #end
  #if (Rope_KnotHalf=0 | Rope_KnotHalf=2)
    // Retrieve the starting location and orientation required for the second half of the knot.
    Rope_AddPoint(Rope_HalfKnotList[Rope_HalfKnotIndex][0])
    #declare Rope_ArrayAheadVector = Rope_HalfKnotList[Rope_HalfKnotIndex][1]; 
    #declare Rope_ArrayUpVector    = Rope_HalfKnotList[Rope_HalfKnotIndex][2]; 
    #declare Rope_ArrayRightVector = -VPerp_To_Plane(Rope_ArrayAheadVector,Rope_ArrayUpVector);
    #declare Rope_HalfKnotIndex    = Rope_HalfKnotIndex-1;

    // Go to the top of the coils
    Rope_ArrayDisplacement(1-Rope_Coils, 0  , 0   )         #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    // Add a little loop where the end is tied off
    Rope_ArrayDisplacement(-2.0 , 0  , 0.5 )         #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-0.5 , 0  ,-0.95)         #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 0.5 , 0.2,-0.95)         #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 1.75, 0.5, 0.75)         #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    // Return to the bottom of the coils
    Rope_ArrayDisplacement(Rope_Coils-2,-0.2, 0)   #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    // Wind the coils
    #local Rope_StartAngle       = 145;  
    #local Rope_TotalAngle       = 360*Rope_Coils-Rope_StartAngle;
    #local Rope_AddPoints           = 5*Rope_Coils;
    #local Rope_AngularIncrement = Rope_TotalAngle/Rope_AddPoints;
    #local Rope_LinearIncrement  = Rope_Coils/Rope_AddPoints;
    
    #local Rope_I = 0;
    #local Rope_StaticDisplacement = <0,0,0.5>;             
    #local Rope_InitialOffset      = 0.8;
    #local Rope_LastDisplacement   = -Rope_StaticDisplacement;
    #while (Rope_I<=Rope_AddPoints)
      #local Rope_Displacement = vrotate((1.5+0.5*Rope_KnotRandomization*rand(Rope_RandomStream))*y,-x*(Rope_AngularIncrement*Rope_I+Rope_StartAngle));
      #local Rope_DisplacementVector = Rope_Displacement-Rope_LastDisplacement;
      Rope_ArrayDisplacement(Rope_InitialOffset-Rope_LinearIncrement,Rope_DisplacementVector.y,Rope_DisplacementVector.z)
      #local Rope_InitialOffset      = 0;
      #local Rope_LastDisplacement = Rope_Displacement; 
      #local Rope_I = Rope_I+1;
    #end
    // Add the final Knot at the top
    Rope_ArrayDisplacement(-0.1, -1,-0.9)            #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement( 0.8, -1, 0.4)            #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
    Rope_ArrayDisplacement(-1.0, -1, 0  )            #if (Rope_ShowPositions) Rope_AddPositionMarker(Rope_Array[Rope_ArrayIndex])  #end
  #end

  #declare Rope_ArrayAheadVector = Rope_Array[Rope_ArrayIndex]-Rope_Array[Rope_ArrayIndex-1];
  Rope_AdjustVectors()
#end  


//
// The Rope_ArrayDisplacement macro is used to add a point into the Rope_Array array based upon a 
// 3D displacement where the 3 displacements amounts are aligned to the current orientation 
// of the rope. The displacements are all measured using the thickness of the rope (2*Rope_Radius)
// as one unit.
//
// It has 3 parameters:
//    Rope_AheadDisplacement  is the distance to move in the direction of the Rope_ArrayAheadVector vector.
//    Rope_UpDisplacement     is the distance to move in the direction of the Rope_ArrayUpVector    vector.
//    Rope_RightDisplacement  is the distance to move in the direction of the Rope_ArrayRightVector vector.
//
#macro Rope_ArrayDisplacement(Rope_AheadDisplacement,Rope_UpDisplacement,Rope_RightDisplacement)
  //    Rope_KnotLooseness  is a factor (usually 1) that can be increased to loosen up the knot.
  #ifndef (Rope_KnotLooseness ) #declare Rope_KnotLooseness  = 1;     #end
  #ifndef (Rope_KnotHandedness) #declare Rope_KnotHandedness = 1;     #end
  #ifndef (Rope_Radius        ) #declare Rope_Radius         = 0.018; #end
  #declare Rope_ArrayIndex = Rope_ArrayIndex + 1;
  #declare Rope_Array[Rope_ArrayIndex] = Rope_Array[Rope_ArrayIndex-1]
    +vnormalize(Rope_ArrayAheadVector)*Rope_KnotLooseness*2*Rope_Radius*Rope_AheadDisplacement
    +vnormalize(Rope_ArrayUpVector)   *Rope_KnotLooseness*2*Rope_Radius*Rope_UpDisplacement
    +vnormalize(Rope_ArrayRightVector)*Rope_KnotLooseness*2*Rope_Radius*Rope_RightDisplacement*Rope_KnotHandedness;

  // The following bit of debug code displays the displacements rotated around a given point
  // and can be used when designing knots to recalculate the displacements when it turns out 
  // that the orientation is incorrect relative to the start direction.
  #ifdef(Rope_AxisPosition)
    #ifndef(LastDisp) #declare LastDisp = <0,0,0>; #end
    //#local ThisDisp = vaxis_rotate(Rope_Array[Rope_ArrayIndex]-Rope_AxisPosition,y,30);
    #local ThisDisp = vaxis_rotate(Rope_Array[Rope_ArrayIndex]-Rope_AxisPosition,y,-30);
    #local ThisDelta = 0.5*(ThisDisp - LastDisp)/Rope_Radius;
    #declare LastDisp = ThisDisp;
    #local Delta = <-ThisDelta.x,ThisDelta.y,ThisDelta.z>;
    #debug concat("Displacement: ",str(Rope_KnotHalf,1,0),": ",vstr(3,Delta,",",3,3),"\n")
  #end
#end


//
// The Rope_FindLeadingEdge macro is used to find a point on an object that is inline with the current 
// ahead direction so that the rope can be trailed over that edge.
//
// It has 1 parameter:
//    Rope_TargetObject  is the object in the path of the Rope_ArrayAheadVector vector.
//
#macro Rope_FindEdge(Rope_TargetObject)
  Rope_InitializeKnot(0,1) 
  #ifndef (Rope_TraceIncrement) #local Rope_TraceIncrement = 0.5; #end
  #local Rope_CurrentPosition = Rope_Array[Rope_ArrayIndex];
  #local Rope_HorizontalVector = <Rope_ArrayAheadVector.x,0,Rope_ArrayAheadVector.z>; 
  // If the rope is pointing straight up or down, then try again.
  #if (vlength(Rope_HorizontalVector)=0) #local Rope_HorizontalVector = VPerp_To_Plane(Rope_ArrayRightVector, y); #end 
  #local Rope_HorizontalAngle = VRotationD(x, Rope_HorizontalVector, y);
  #local Rope_TraceInclination = 90;
  #declare Rope_TraceNormal = <0,0,0>;
  #while (vlength(Rope_TraceNormal)=0 & Rope_TraceInclination>-90)
    #local Rope_TraceDirection = vrotate(vrotate(x,z*Rope_TraceInclination),y*Rope_HorizontalAngle);
    #local Rope_Position = trace(Rope_TargetObject,Rope_CurrentPosition,Rope_TraceDirection,Rope_TraceNormal);
    #local Rope_TraceInclination = Rope_TraceInclination-Rope_TraceIncrement;
  #end 
  // If we didn't hit the object in the direction of the ahead vector try aiming for the centre of the object.
  #if (vlength(Rope_TraceNormal)=0)
    #warning "Rope_FindEdge: Was unable to find a point on the object directly in front of the rope. Trying Rope_FindEdgeFromCentre instead. \n"
    #local Rope_Position = Rope_FindEdgeFromCentre(Rope_TargetObject);
  #end 
  // If we didn't hit the object return a point a small distance from the current point and write
  // a warning message into the message stream.
  #if (vlength(Rope_TraceNormal)=0)
    #local Rope_Position = Rope_CurrentPosition + 0.001*vnormalize(Rope_ArrayAheadVector);
    #warning "Rope_FindEdge Was unable to find a suitable point on the object. \n"
  #end 
  (Rope_Position)
#end
                              
                              
//
// The Rope_FindEdgeFromCentre macro is used to find a point on the leading edge of an object 
// that is in the direction of the centre of the object from the current location. 
//
// It has 1 parameter:
//    Rope_TargetObject  is the object to scan.
//
#macro Rope_FindEdgeFromCentre(Rope_TargetObject)
  Rope_InitializeKnot(0,1) 
  #ifndef (Rope_TraceIncrement) #local Rope_TraceIncrement = 0.5; #end
  #local Rope_CurrentPosition = Rope_Array[Rope_ArrayIndex];
  #local Rope_ObjectCentre = (min_extent(Rope_TargetObject)+max_extent(Rope_TargetObject))/2;
  #local Rope_HorizontalVector = <Rope_ObjectCentre.x,0,Rope_ObjectCentre.z>-<Rope_CurrentPosition.x,0,Rope_CurrentPosition.z>; 
  #local Rope_HorizontalAngle = VRotationD(x, Rope_HorizontalVector, y);
  #local Rope_TraceInclination = 90;
  #declare Rope_TraceNormal = <0,0,0>;
  #while (vlength(Rope_TraceNormal)=0 & Rope_TraceInclination>-90)
    #local Rope_TraceDirection = vrotate(vrotate(x,z*Rope_TraceInclination),y*Rope_HorizontalAngle);
    #local Rope_Position = trace(Rope_TargetObject,Rope_CurrentPosition,Rope_TraceDirection,Rope_TraceNormal);
    #local Rope_TraceInclination = Rope_TraceInclination-Rope_TraceIncrement;
  #end 
  // If we didn't hit the object return a point a small distance from the current point and write
  // a warning message into the message stream.
  #if (vlength(Rope_TraceNormal)=0)
    #local Rope_Position = Rope_CurrentPosition + 0.001*vnormalize(Rope_ArrayAheadVector);
    #warning "Rope_FindEdgeFromCentre: Was unable to find a suitable point on the object. \n"
  #end 
  (Rope_Position)
#end


//
// The Rope_TrackOver macro is used to add a series of points to the path of a rope taking it over 
// the top of an object in the direction of the ahead vector.
//
// It has 1 parameter:
//    Rope_TargetObject  is the object to scan.
//
#macro Rope_TrackOver(Rope_TargetObject)
  Rope_InitializeKnot(0,1)
  #local Rope_StartingInex = Rope_ArrayIndex; 
  #ifndef (Rope_TraceIncrement) #local Rope_TraceIncrement = 0.5;   #end
  #ifndef (Rope_Radius        ) #local Rope_Radius         = 0.018; #end
  #local Rope_HorizontalVector = <Rope_ArrayAheadVector.x,0,Rope_ArrayAheadVector.z>; 
  // If the rope is pointing straight up or down, then try again.
  #if (vlength(Rope_HorizontalVector)=0) #local Rope_HorizontalVector = VPerp_To_Plane(Rope_ArrayRightVector, y); #end 
  #local Rope_HorizontalAngle = VRotationD(x, Rope_HorizontalVector, y);
  #declare Rope_TraceNormal = x;
  #while (vlength(Rope_TraceNormal)!=0)
    #local Rope_CurrentPosition = Rope_Array[Rope_ArrayIndex];
    #declare Rope_TraceNormal = <0,0,0>;
    #local Rope_TraceInclination = 90;
    #while (vlength(Rope_TraceNormal)=0 & Rope_TraceInclination>-90)
      #local Rope_TraceDirection = vrotate(vrotate(x,z*Rope_TraceInclination),y*Rope_HorizontalAngle);
      #local Rope_Position = trace(Rope_TargetObject,Rope_CurrentPosition,Rope_TraceDirection,Rope_TraceNormal);
      #local Rope_TraceInclination = Rope_TraceInclination-Rope_TraceIncrement;
    #end 
    #if (vlength(Rope_TraceNormal)!=0)
      Rope_AddPoint(Rope_Position+Rope_Radius*y)
    #end 
  #end
  // If no points have been added, add a message to the degug stream.
  #if (Rope_ArrayIndex = Rope_StartingInex)
    #warning "Rope_TrackOver didn't find any suitable positions on the object.\n"
  #end   
#end


//
// The Rope_AddPositionIndicator macro is a utility macro that can be used during development 
// to place a marker at a specified point. This can, for example, be used to show the current 
// position in the Rope_Array array as it is being populated with new coordinates.
//
// It has one parameter:
//    Rope_Coordinate  is the coordinate of the point at which to draw the marker.
//
#macro Rope_AddPositionMarker (Rope_Coordinate)
  cylinder {Rope_Coordinate,Rope_Coordinate+Rope_ArrayUpVector   *0.3,0.001 pigment {rgb <10,00,10>}} 
  cylinder {Rope_Coordinate,Rope_Coordinate+Rope_ArrayRightVector*0.3,0.001 pigment {rgb <00,10,10>}} 
  cylinder {Rope_Coordinate,Rope_Coordinate+Rope_ArrayAheadVector*0.3,0.001 pigment {rgb <10,10,00>}} 
#end


//
// The Rope_Undef macro can be used to undefine all of the declared variables used to control the various 
// Rope macros. This is only required where 'residual' definitions from one rope definition could interfere
// with the definition of another rope in the same scene file.
//
// It has no parameters.
//
#macro Rope_Undef ()

  #ifdef(Rope_Type               ) #undef Rope_Type                  #end
  #ifdef(Rope_Radius             ) #undef Rope_Radius                #end
  #ifdef(Rope_Brightness         ) #undef Rope_Brightness            #end
  #ifdef(Rope_OuterColor         ) #undef Rope_OuterColor            #end
  #ifdef(Rope_InnerColor         ) #undef Rope_InnerColor            #end
  #ifdef(Rope_SplineIncrement    ) #undef Rope_SplineIncrement       #end
  #ifdef(Rope_LengthChunks       ) #undef Rope_LengthChunks          #end
  #ifdef(Rope_ShowFibres         ) #undef Rope_ShowFibres            #end
  #ifdef(Rope_Randomness         ) #undef Rope_Randomness            #end
  #ifdef(Rope_FibreFrequency     ) #undef Rope_FibreFrequency        #end
  #ifdef(Rope_CordRadius         ) #undef Rope_CordRadius            #end
  #ifdef(Rope_BraidInset         ) #undef Rope_BraidInset            #end
  #ifdef(Rope_HelixDirection     ) #undef Rope_HelixDirection        #end
  #ifdef(Rope_StrandFinish       ) #undef Rope_StrandFinish          #end
  #ifdef(Rope_FibreFinish        ) #undef Rope_FibreFinish           #end
  #ifdef(Rope_StrandTexture      ) #undef Rope_StrandTexture         #end
  #ifdef(Rope_FibrousTexture     ) #undef Rope_FibrousTexture        #end     
  #ifdef(Rope_CentreSpline       ) #undef Rope_CentreSpline          #end
  #ifdef(Rope_RandomStream       ) #undef Rope_RandomStream          #end
  #ifdef(Rope_StrandTextureArray ) #undef Rope_StrandTextureArray    #end 
  #ifdef(Rope_TwistRatio         ) #undef Rope_TwistRatio            #end                                   

  #ifdef(Rope_Array              ) #undef Rope_Array                 #end
  #ifdef(Rope_SplineTypeList     ) #undef Rope_SplineTypeList        #end
  #ifdef(Rope_ArrayIndex         ) #undef Rope_ArrayIndex            #end
  #ifdef(Rope_ArrayUpVector      ) #undef Rope_ArrayUpVector         #end  
  #ifdef(Rope_ArrayRightVector   ) #undef Rope_ArrayRightVector      #end
  #ifdef(Rope_ArrayAheadVector   ) #undef Rope_ArrayAheadVector      #end
  #ifdef(Rope_HalfKnotList       ) #undef Rope_HalfKnotList          #end        
  #ifdef(Rope_HalfKnotIndex      ) #undef Rope_HalfKnotIndex         #end
  #ifdef(Rope_KnotHandedness     ) #undef Rope_KnotHandedness        #end
  #ifdef(Rope_KnotRandomization  ) #undef Rope_KnotRandomization     #end
  #ifdef(Rope_Catenary_a         ) #undef Rope_Catenary_a            #end
  #ifdef(Rope_Coils              ) #undef Rope_Coils                 #end
  #ifdef(Rope_PointsPerCoil      ) #undef Rope_PointsPerCoil         #end
  #ifdef(Rope_PoleRadius         ) #undef Rope_PoleRadius            #end

  #ifdef(Rope_BindingLength      ) #undef Rope_BindingLength         #end
  #ifdef(Rope_BindingRadius      ) #undef Rope_BindingRadius         #end
  #ifdef(Rope_BindingThreadRadius) #undef Rope_BindingThreadRadius   #end
#end 