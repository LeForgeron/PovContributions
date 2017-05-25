// Netball.inc
// -----------

// Include file containing the NB_Netball Macro for generating a Netball Object
// Created by Chris Bartlett 07.02.2005
// Source http://lib.povray.org/
// Typical render time 1 to 3 minutes, depending on settings etc.
// This file is licensed under the terms of the CC-LGPL.

// Editors notes
// -------------
// When working on the seams of the ball it's easiest to just render one or two segment 
// (for speed and clarity).
//
// If a cut doesn't appear where you expect it to, rendering the cutting tool in a bright 
// colour may help you to see where the mistake is. 
//
// When adding stitches it helps to brightly colour the stitches that you're working on.
// To make them even clearer you can change the sphere definition of the stitch to be 
// centred at <0,BallRadius,0> instead of <0,BallRadius-CutRadius,0> so that they project
// a little above the surface of the ball.


#macro NB_Netball (BallType)  // Stitched or Moulded

  #ifndef (NB_BallRadius    ) #declare NB_BallRadius     = 1; #end
  #ifndef (NB_BallTexture   ) #declare NB_BallTexture    = texture {pigment {color rgb <1,1,1>}     scale NB_BallRadius} #end
  #ifndef (NB_StitchTexture ) #declare NB_StitchTexture  = texture {NB_BallTexture}                                      #end
  #ifndef (NB_IndentTexture ) #declare NB_IndentTexture  = texture {pigment {color rgb <0.1,1,0.2>} scale NB_BallRadius} #end // Only for moulded balls
  #ifndef (NB_BladderTexture) #declare NB_BladderTexture = texture {pigment {color rgb <1,0.8,0>}   scale NB_BallRadius} #end // Only for stitched balls

  #if (strcmp(BallType,"Stitched")=0)
    #local CutRadius = NB_BallRadius*0.02;   // Radius of curvature of the stitched seams 
  #end
  #if (strcmp(BallType,"Moulded")=0)
    #local CutRadius = NB_BallRadius*0.03;   // Radius of curvature of the moulded seams 
  #end 
  // Create a cutting tool that is a flat surface with a torus cut out of it.
  // The outermost extent of the torus is the same radius as the ball.
  // You may like to render just the cutting tool if you're having a problem imagining it.
  #local Cuttingedge = difference {
    box {<-NB_BallRadius*1.1,-NB_BallRadius*1.1,0>,NB_BallRadius*1.1} 
    torus {NB_BallRadius-CutRadius,CutRadius rotate x*90}
    translate -z*CutRadius
  }
  
  // For 'special' cuts we don't want to cut all the way through so create half a cutting 
  // tool as well.
  #local HalfCut = intersection {
    object {Cuttingedge}
    box {1.1*<-NB_BallRadius,-NB_BallRadius,0>,<0,NB_BallRadius,NB_BallRadius>*1.1 translate -z*CutRadius} 
  } 
   
  // Create a selection of lines of stitches to use on different seams.
  // This example uses an arc of small stretched spheres to imitate the distortion of the 
  // leather where the stitches pass through.
  #if (strcmp(BallType,"Stitched")=0)
    #local LongStitchLine = union {
      #local StitchAngle = -53;  
      #while (StitchAngle <= 53)
        sphere {<0,NB_BallRadius-CutRadius,0>,CutRadius scale <0.5,1,1.5> rotate z*StitchAngle}
        #local StitchAngle = StitchAngle + 2;
      #end
      translate -z*CutRadius
      texture {NB_StitchTexture}
    }
    
    #local MediumStitchLine = union {
      #local StitchAngle = -10;  
      #while (StitchAngle <= 10)
        sphere {<0,NB_BallRadius-CutRadius,0>,CutRadius scale <0.5,1,1.5> rotate z*StitchAngle}
        #local StitchAngle = StitchAngle + 2;
      #end
      translate -z*CutRadius
      texture {NB_StitchTexture}
    }
    
    #local ShortStitchLine = union {
      #local StitchAngle = 84;  
      #while (StitchAngle <= 96)
        sphere {<0,NB_BallRadius-CutRadius,0>,CutRadius scale <0.5,1,1.5> rotate z*StitchAngle}
        #local StitchAngle = StitchAngle + 2;
      #end
      translate -z*CutRadius
      texture {NB_StitchTexture}
    }
  #end
  
  // The central strip is cut out of a sphere with lines of stitches added to each edge.
  // The important thing when cutting is that the center of the sphere and the centre of the
  // cutting tool are coincident. Here both stay at the origin which is by far the easiest 
  // place for the centres to be.
  // The rotations for the stitches are the same as for the cutting tool except that the 
  // stitches sometimes need rotating around the z axis. This is because the stitches only 
  // form an arc, whereas the cutting tool forms a complete circle.
  #local StraightSegment = intersection {
    union {
      difference {
        sphere {0,NB_BallRadius}
        object{Cuttingedge rotate -x*80}
        object{Cuttingedge rotate  x*80}
        object{Cuttingedge rotate -y*35}
        object{Cuttingedge rotate  y*35}
      }  
      #if (strcmp(BallType,"Stitched")=0)
        object{LongStitchLine               rotate -x*80}
        object{LongStitchLine  rotate z*180 rotate  x*80}
        object{ShortStitchLine              rotate -y*35}
        object{ShortStitchLine rotate z*180 rotate  y*35}
      #end 
    } 
    box {<-NB_BallRadius,-NB_BallRadius*0.5,-NB_BallRadius*1.01><NB_BallRadius,NB_BallRadius*0.5,-NB_BallRadius*0.5>}
  }
  
  // We will need a nearly triangular piece (one corner trimmed off) to patch into the corners.
  #local TriangleSegment = union {
    difference {
      sphere {0,NB_BallRadius}
      object{Cuttingedge              rotate -y*30 rotate -x*69}
      object{Cuttingedge rotate  y*90 rotate  z*30 rotate -y*69}
      object{Cuttingedge rotate  x*110}
      object{Cuttingedge rotate  y*90 rotate -z*20 rotate -y*53}
    }  
    #if (strcmp(BallType,"Stitched")=0)
      object{MediumStitchLine rotate -z*30              rotate -y*30 rotate -x*69}
      object{MediumStitchLine rotate -z*59 rotate  y*90 rotate  z*30 rotate -y*69}
    #end
  } 
  
  // The segment that lies either side of the central strip is quite a tricky shape.
  // We need to slice odd bits out of a strip then patch in the triangular corner piece.
  // The stitches just follow the seams.
  #local OffsetSegment = intersection {
    union {
      difference {
        sphere {0,NB_BallRadius}
        object{Cuttingedge rotate -x*55}
        object{Cuttingedge rotate  x*100}
        object{Cuttingedge rotate  y*90 rotate -z*20 rotate -y*53}
        object{Cuttingedge rotate -y*90 rotate  z*20 rotate  y*53}
        object{Cuttingedge rotate  y*90 rotate  z*30 rotate -y*69}
        object{Cuttingedge rotate -y*90 rotate -z*30 rotate  y*69}
        object{HalfCut rotate -z*35  rotate  y*20 rotate -x*53}
        object{HalfCut rotate  z*215 rotate -y*20 rotate -x*53}
      }  
      #if (strcmp(BallType,"Stitched")=0)
        object{ShortStitchLine rotate -z*90  rotate -x*55}
        object{LongStitchLine  rotate  z*180 rotate  x*100}
        object{ShortStitchLine rotate -z*103 rotate  y*20 rotate -x*53}
        object{ShortStitchLine rotate -z*77  rotate -y*20 rotate -x*53}
      
        object{ShortStitchLine rotate -z*168 rotate  y*90 rotate -z*20 rotate -y*53}
        object{ShortStitchLine rotate -z*22  rotate -y*90 rotate  z*20 rotate  y*53}
      
      #end
      object {TriangleSegment}
      object {TriangleSegment scale <-1,1,1>}
    } 
    box {<-NB_BallRadius,NB_BallRadius*0.1,-NB_BallRadius*1.01><NB_BallRadius,NB_BallRadius*0.9,-NB_BallRadius*0.45>}
  }
  
  // Assemble three strips to form one sixth of the balls surface
  #local SetOfSegments = union {
    object {OffsetSegment}
    object {StraightSegment}
    object {OffsetSegment rotate z*180}
  }
  
  // The whole ball uses six sets of the three strips (appropriately rotated)
  #local Wholeball = union {
    object {SetOfSegments}
    object {SetOfSegments rotate <90,90,0>}
    object {SetOfSegments rotate <90,0,90>}
    object {SetOfSegments rotate x*180}
    object {SetOfSegments rotate <270,90,0>}
    object {SetOfSegments rotate <90,0,270>}
    #if (strcmp(BallType,"Moulded")=0)
      sphere {0,NB_BallRadius*0.994 texture {NB_IndentTexture}}            // Mouldings
    #else 
      sphere {0,NB_BallRadius*0.990 texture {NB_BladderTexture}}           // Bladder
    #end
  }
  
  // Draw an example of the ball
  object {Wholeball texture {NB_BallTexture}} 

#end  




