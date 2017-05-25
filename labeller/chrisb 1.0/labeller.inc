// labeller.inc
// ------------
// Created by Chris Bartlett January 2008 as part of the 'Office Supplies' theme assembled by Ben Chambers
// This include file provides alternative ways to generate a label based upon a design that is held in a separate file.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The scale is 0.001 POV-Ray units = 1mm   (1m = 1 POV-Ray unit)
// Layers of pigment need to lie on the XZ plane. The sample is taken at y=-0.0001.
//
// Render times are typically half a minute to a couple of minutes depending on size.  
//


//**************************//
//       Label Macros       //
//**************************//  


// This macro generates a simple flat label with rounded corners
#macro Labeller_Flat() 
  #declare Labeller_Macro = "Flat"; 

  // Initialise any uninitialised variables, including the label design layers
  Labeller_DefaultSettings()
  #if (file_exists(Labeller_LabelFile)) #include Labeller_LabelFile
  #else Labeller_DefaultDesign()
  #end 
  // Create a cutter to round off the corners of the label to the required radius
  #local Labeller_Cutter = difference {  
    box      {-(Labeller_LabelThickness+Labeller_Delta  )*z,<Labeller_LabelRounding+Labeller_Delta,Labeller_LabelRounding+Labeller_Delta,Labeller_LabelThickness+Labeller_Delta>}
    cylinder {-(Labeller_LabelThickness+Labeller_Delta*2)*z,(Labeller_LabelThickness+2*Labeller_Delta)*z,Labeller_LabelRounding} 
    translate -<Labeller_LabelRounding,Labeller_LabelRounding,0>
  }
  // Add the flat label shape with the appropriate layers of texture  
  difference {
    box {0,<Labeller_LabelWidth,Labeller_LabelThickness,Labeller_LabelHeight>}
    object {Labeller_Cutter rotate x*90       translate <Labeller_LabelWidth,0,Labeller_LabelHeight>} //TR
    object {Labeller_Cutter rotate <90,-90,0> translate <                  0,0,Labeller_LabelHeight>} //TL
    object {Labeller_Cutter rotate <90, 90,0> translate <Labeller_LabelWidth,0,                   0>} //BR
    object {Labeller_Cutter rotate <90,180,0> translate <                  0,0,                   0>} //BL   
    #local LayerI = 0; 
    #while (LayerI<dimension_size(Labeller_LabelLayer,1))
      #local LayerJ = 0; 
      #while (LayerJ<dimension_size(Labeller_LabelLayer,2))   
        #ifdef (Labeller_LabelLayer[LayerI][LayerJ])
          texture {
            pigment {Labeller_LabelLayer[LayerI][LayerJ]} translate y*(Labeller_LabelThickness+Labeller_SampleDepth)
            normal {Labeller_Normal}
            finish {Labeller_Finish}
          } 
        #end
        #local LayerJ = LayerJ + 1;
      #end 
      #local LayerI = LayerI + 1;
    #end  
    // If required, suppress the pigment on the back of the back right surface
    #if (Labeller_PlainBack) 
      Labeller_PlainBackBoxTexture (
        -Labeller_Delta*y,<Labeller_LabelWidth,Labeller_LabelThickness*Labeller_PlainBack,Labeller_LabelHeight>
      )
    #end
  }
#end     



// This macro generates a cylindrical label
#macro Labeller_Cylinder() 
  #declare Labeller_Macro = "Cylinder";  
  
  // Initialise any uninitialised variables, including the label design layers
  Labeller_DefaultSettings()
  #if (file_exists(Labeller_LabelFile)) #include Labeller_LabelFile
  #else Labeller_DefaultDesign() 
  #end
  
  // Create a cutter to round off the corners of the label to the required radius
  // This needs to be thicker on the inside of the curve to take account of the curvature of the label around the object
  // when the rounding is fairly large.
  #local Cutter = difference {  
    box      {-(Labeller_LabelThickness+  Labeller_Delta)*z,<Labeller_LabelRounding+Labeller_Delta,Labeller_LabelRounding+Labeller_Delta,Labeller_LabelThickness+Labeller_ObjectRadius>}
    cylinder {-(Labeller_LabelThickness+2*Labeller_Delta)*z,(Labeller_LabelThickness+Labeller_ObjectRadius)*z,Labeller_LabelRounding} 
    translate -<Labeller_LabelRounding,Labeller_LabelRounding,0>
  }
  
  // Create the label object using CSG and apply the layers of pigment as defined in the external file.
  difference { 
    cylinder { Labeller_LabelBottom*y       , Labeller_LabelTop*y       ,Labeller_ObjectRadius+Labeller_LabelThickness}
    cylinder {(Labeller_LabelBottom-Labeller_Delta)*y,(Labeller_LabelTop+Labeller_Delta)*y,Labeller_ObjectRadius+Labeller_Delta}
    #if (Labeller_LabelArc>0 & Labeller_LabelArc<180)
      plane { x,0 rotate  y*Labeller_LabelArc/2} 
      plane {-x,0 rotate -y*Labeller_LabelArc/2} 
    #end 
    #if (Labeller_LabelArc=180) 
      plane {-z,0} 
    #end
    #if (Labeller_LabelArc>=180 & Labeller_LabelArc<360) 
      intersection {     
        plane { x,0 rotate  y*Labeller_LabelArc/2} 
        plane {-x,0 rotate -y*Labeller_LabelArc/2} 
      }
    #end
    #if (Labeller_LabelArc>0 & Labeller_LabelArc<360) 
      object {Cutter              translate <0,Labeller_LabelTop   ,-Labeller_ObjectRadius> rotate -y*Labeller_LabelArc/2} //TR
      object {Cutter rotate z*90  translate <0,Labeller_LabelTop   ,-Labeller_ObjectRadius> rotate  y*Labeller_LabelArc/2} //TL
      object {Cutter rotate z*270 translate <0,Labeller_LabelBottom,-Labeller_ObjectRadius> rotate -y*Labeller_LabelArc/2} //BR
      object {Cutter rotate z*180 translate <0,Labeller_LabelBottom,-Labeller_ObjectRadius> rotate  y*Labeller_LabelArc/2} //BL
    #end
    // Add layers of pigment and use a cylindrical warp to wrap them around the surface 
    #local LayerI = 0;
    #while (LayerI<dimension_size(Labeller_LabelLayer,1))   
      #local LayerJ = 0; 
      #while (LayerJ<dimension_size(Labeller_LabelLayer,2))   
        #ifdef (Labeller_LabelLayer[LayerI][LayerJ])
          texture {
            pigment {
              Labeller_LabelLayer[LayerI][LayerJ]
              translate y*Labeller_SampleDepth  
              scale <1/Labeller_LabelWidth,1,1>
              warp {
                cylindrical 
                orientation y 
              }
              rotate -y*(90+(360-Labeller_LabelArc)/2)
              translate y*Labeller_LabelBottom
            }
            normal {Labeller_Normal}
            finish {Labeller_Finish} 
          } 
        #end
        #local LayerJ = LayerJ + 1;
      #end 
      #local LayerI = LayerI + 1;
    #end  
    // If required, suppress the pigment on the inner surface of the label
    #if (Labeller_PlainBack) 
      Labeller_PlainBackCylinderTexture (
        (Labeller_LabelBottom+Labeller_Delta)*y, 
        (Labeller_LabelTop   +Labeller_Delta)*y,
        Labeller_ObjectRadius+Labeller_LabelThickness*Labeller_PlainBack
      )
    #end
  }
#end



// This macro generates a rounded box shaped label
#macro Labeller_RoundedBox()
  #declare Labeller_Macro = "RoundedBox"; 
  // Initialise any uninitialised variables, including the label design layers
  Labeller_DefaultSettings()
  #if (file_exists(Labeller_LabelFile)) #include Labeller_LabelFile
  #else Labeller_DefaultDesign()
  #end
    
  #local Labeller_ObjectCornerCircumference = 2*pi* Labeller_ObjectCornerRadius;
  #local Labeller_CornerOuterCircumference  = 2*pi*(Labeller_ObjectCornerRadius+Labeller_LabelThickness);
  #local Labeller_FrontSectionWidth = Labeller_ObjectWidth-2*Labeller_ObjectCornerRadius; 
  #local Labeller_SideSectionWidth  = Labeller_ObjectDepth-2*Labeller_ObjectCornerRadius; 
  
  // Create a cutter suitable for trimming the corner sections to length if the label ends on a corner
  #local Labeller_CornerAngleGrinder = box {
    <-Labeller_ObjectCornerRadius-Labeller_LabelThickness-Labeller_Delta,Labeller_LabelTop   +Labeller_Delta,0>
    < Labeller_ObjectCornerRadius+Labeller_LabelThickness+Labeller_Delta,Labeller_LabelBottom-Labeller_Delta,Labeller_ObjectCornerRadius+Labeller_LabelThickness+Labeller_Delta>
  }

  // The label can't be any wider than the total circumference of the object
  #declare Labeller_LabelWidth=min(Labeller_LabelWidth,2*Labeller_FrontSectionWidth+2*Labeller_SideSectionWidth+Labeller_ObjectCornerCircumference);  

  // Work out which surfaces the label extends onto and how much of each is covered by label
  // Firstly, does the label fit on the front surface?
  #if (Labeller_LabelWidth<Labeller_FrontSectionWidth)
    #local Labeller_Extent = 1; // "Front Surface"
    #local Labeller_FrontWidth = Labeller_LabelWidth;
  #else 
    #local Labeller_FrontWidth = Labeller_FrontSectionWidth;
    // Will it fit on the front surface and the front two corners?
    #if (Labeller_LabelWidth<Labeller_FrontSectionWidth+Labeller_ObjectCornerCircumference/2)
      #local Labeller_Extent = 2; // "Front Corners"  
      #local Labeller_FrontCornerArcAngle = 90*2*(Labeller_LabelWidth-Labeller_FrontSectionWidth)/Labeller_ObjectCornerCircumference;
    #else 
      #local Labeller_FrontCornerArcAngle = 90;
      // Will it fit on the front and sides?
      #if (Labeller_LabelWidth<Labeller_FrontSectionWidth+2*Labeller_SideSectionWidth+Labeller_ObjectCornerCircumference/2)
        #local Labeller_Extent = 3; // "Sides" 
        #local Labeller_SideWidth = (Labeller_LabelWidth-Labeller_FrontSectionWidth-Labeller_ObjectCornerCircumference/2)/2;
      #else 
        #local Labeller_SideWidth = Labeller_SideSectionWidth;
        // Will it fit on the front, sides and two back corners?
        #if (Labeller_LabelWidth<Labeller_FrontSectionWidth+2*Labeller_SideSectionWidth+Labeller_ObjectCornerCircumference)
          #local Labeller_Extent = 4; // "Back Corners"
          #local Labeller_BackCornerArcAngle = 90*2*(Labeller_LabelWidth-Labeller_FrontSectionWidth-2*Labeller_SideSectionWidth-Labeller_ObjectCornerCircumference/2)/Labeller_ObjectCornerCircumference;
        // Otherwise it needs to wrap round onto the back surface?
        #else 
          #local Labeller_Extent = 5; // "All Surfaces"
          #local Labeller_BackCornerArcAngle = 90;       
          #local Labeller_BackWidth = Labeller_LabelWidth-Labeller_FrontSectionWidth-2*Labeller_SideSectionWidth-Labeller_ObjectCornerCircumference;
        #end
      #end
    #end
  #end 
 
 
  // Work out where the centre of the corner radius is for the far right corner 
  #local Labeller_ObjectCornerCentre      = <(Labeller_ObjectWidth/2)-  Labeller_ObjectCornerRadius,0,(Labeller_ObjectDepth/2)-Labeller_ObjectCornerRadius>;
  // Find a point that can be used to trim away the inner part of the hollow cylinder used to create a corner
  #local Labeller_ObjectCornerInnerExtent = <(Labeller_ObjectWidth/2)-2*Labeller_ObjectCornerRadius-Labeller_LabelThickness-Labeller_Delta,0,(Labeller_ObjectDepth/2)-2*Labeller_ObjectCornerRadius-Labeller_LabelThickness-Labeller_Delta>;
  
  // The front surfaces of the label
  #local Labeller_LabelFront = box {
    <-Labeller_FrontWidth/2,Labeller_LabelBottom,-Labeller_LabelThickness-Labeller_ObjectDepth/2>,
    < Labeller_FrontWidth/2,Labeller_LabelTop   ,-Labeller_ObjectDepth/2>  
  }
  // The back surface of the label
  #ifdef (Labeller_BackWidth) 
    #local Labeller_LabelBackLeft = box {
      <-Labeller_ObjectCornerCentre.x                   ,Labeller_LabelBottom,Labeller_LabelThickness+Labeller_ObjectDepth/2>,
      <-Labeller_ObjectCornerCentre.x+Labeller_BackWidth/2,Labeller_LabelTop   ,Labeller_ObjectDepth/2>  
    }
    #local Labeller_LabelBackRight = box {
      < Labeller_ObjectCornerCentre.x-Labeller_BackWidth/2,Labeller_LabelBottom,Labeller_LabelThickness+Labeller_ObjectDepth/2>,
      < Labeller_ObjectCornerCentre.x                   ,Labeller_LabelTop   ,Labeller_ObjectDepth/2>  
    }
  #end

  // The left and right surfaces of the label can be cut from the same shape. 
  #ifdef (Labeller_SideWidth) 
    #local Labeller_LabelRight = box {
      <Labeller_LabelThickness+Labeller_ObjectWidth/2,Labeller_LabelBottom,-Labeller_ObjectCornerCentre.z>,
      <Labeller_ObjectWidth/2                        ,Labeller_LabelTop   ,-Labeller_ObjectCornerCentre.z+Labeller_SideWidth>
    }
  #end

  // The starting shape for all four corners is a quarter of a hollow cylinder
  // If the label finishes in the middle of a corner, any offcuts will be trimmed off during final assembly
  #local Labeller_LabelCorner = difference {
    cylinder {
      y*Labeller_LabelBottom +Labeller_ObjectCornerCentre,
      y*Labeller_LabelTop    +Labeller_ObjectCornerCentre,
      Labeller_ObjectCornerRadius+Labeller_LabelThickness
    }
    cylinder {
      y*(Labeller_LabelBottom-Labeller_Delta) +Labeller_ObjectCornerCentre,
      y*(Labeller_LabelTop   +Labeller_Delta) +Labeller_ObjectCornerCentre,
      Labeller_ObjectCornerRadius
    }
    box {
      y*(Labeller_LabelBottom-Labeller_Delta) +Labeller_ObjectCornerInnerExtent,
      y*(Labeller_LabelTop   +Labeller_Delta) +Labeller_ObjectCornerCentre + z*(Labeller_ObjectCornerRadius+Labeller_LabelThickness+Labeller_Delta)
    }
    box {
      y*(Labeller_LabelBottom-Labeller_Delta) +Labeller_ObjectCornerInnerExtent,
      y*(Labeller_LabelTop   +Labeller_Delta) +Labeller_ObjectCornerCentre + x*(Labeller_ObjectCornerRadius+Labeller_LabelThickness+Labeller_Delta)
    }
  }


  // The flat parts of the texture can be consolidated ahead of the final assembly and reused with appropriate translations
  #local LayerI = 0; 
  #while (LayerI<dimension_size(Labeller_LabelLayer,1))   
    #local LayerJ = 0; 
    #while (LayerJ<dimension_size(Labeller_LabelLayer,2))   
      #ifdef (Labeller_LabelLayer[LayerI][LayerJ])
        #local Labeller_ThisTexture = texture {
          pigment {Labeller_LabelLayer[LayerI][LayerJ]} translate y*(Labeller_LabelThickness+Labeller_SampleDepth)
          normal {Labeller_Normal} 
          finish {Labeller_Finish}
        } 
        // A nasty little work-around for assembling the textures that circumvents the texture syntax limitations
        #ifdef (Labeller_ConsolidatedTexture) 
          #local Labeller_ConsolidatedTexture =
            texture {Labeller_ConsolidatedTexture}
            texture {Labeller_ThisTexture normal {Labeller_Normal} finish {Labeller_Finish}}
        #else  
          #local Labeller_ConsolidatedTexture = texture {Labeller_ThisTexture normal {Labeller_Normal} finish {Labeller_Finish}}
        #end
      #end
      #local LayerJ = LayerJ + 1;
    #end 
    #local LayerI = LayerI + 1;
  #end   
  #ifndef (Labeller_ConsolidatedTexture) #declare Labeller_ConsolidatedTexture = texture {pigment {rgbt 1}} #end
 
  #local Labeller_RightOffset = (Labeller_LabelWidth/2)+(Labeller_FrontWidth/2)+Labeller_CornerOuterCircumference/4;
  #local Labeller_LeftOffset = (Labeller_LabelWidth/2)-(Labeller_FrontWidth/2)-Labeller_CornerOuterCircumference/4;
   
  //**********************************//
  //   RoundedBox - Final Assembly    //
  //**********************************//
  // Create the label object using CSG and apply the layers of pigment as defined in the external file.
  union {                                            
    object {Labeller_LabelFront
      texture {Labeller_ConsolidatedTexture
        rotate -x*90
        translate <-Labeller_FrontWidth/2,Labeller_LabelBottom,-Labeller_LabelThickness-Labeller_ObjectDepth/2>
        translate -x*(Labeller_LabelWidth-Labeller_FrontWidth)/2
      }
      // If required, suppress the pigment on the back of the inside of the front surface
      #if (Labeller_PlainBack) 
        Labeller_PlainBackBoxTexture (
          <-(Labeller_FrontWidth+Labeller_Delta)/2,Labeller_LabelBottom-Labeller_Delta,-Labeller_ObjectDepth/2-Labeller_LabelThickness*Labeller_PlainBack>,
          < (Labeller_FrontWidth+Labeller_Delta)/2,Labeller_LabelTop   +Labeller_Delta,-Labeller_ObjectDepth/2+Labeller_Delta>  
        )
      #end
    }     
    #if (Labeller_Extent>1)                          // "Front Corners" 
      difference { 
        object {Labeller_LabelCorner scale < 1,1,-1>} // Front Right 
        object {Labeller_CornerAngleGrinder rotate  y*(90-Labeller_FrontCornerArcAngle) translate Labeller_ObjectCornerCentre*< 1,0,-1>}
        Labeller_ApplyRoundedCornerTexture((Labeller_LabelWidth/2)+(Labeller_FrontWidth/2), 90, <1,0,-1>*Labeller_ObjectCornerCentre + y*Labeller_LabelBottom)
        // If required, suppress the pigment on the inner surface of the label
        #if (Labeller_PlainBack) 
          Labeller_PlainBackCylinderTexture (
            y*(Labeller_LabelBottom-Labeller_Delta) +Labeller_ObjectCornerCentre*<1,1,-1>,
            y*(Labeller_LabelTop   +Labeller_Delta) +Labeller_ObjectCornerCentre*<1,1,-1>,
            Labeller_ObjectCornerRadius+Labeller_PlainBack*Labeller_LabelThickness
          )
        #end
      }
      difference { 
        object {Labeller_LabelCorner scale <-1,1,-1>} // Front Left
        object {Labeller_CornerAngleGrinder rotate -y*(90-Labeller_FrontCornerArcAngle) translate Labeller_ObjectCornerCentre*<-1,0,-1>}
        Labeller_ApplyRoundedCornerTexture((Labeller_LabelWidth/2)-(Labeller_FrontWidth/2)-(Labeller_CornerOuterCircumference/4), 180, <-1,0,-1>*Labeller_ObjectCornerCentre + y*Labeller_LabelBottom)
        // If required, suppress the pigment on the inner surface of the label
        #if (Labeller_PlainBack) 
          Labeller_PlainBackCylinderTexture (
            y*(Labeller_LabelBottom-Labeller_Delta) +Labeller_ObjectCornerCentre*<-1,1,-1>,
            y*(Labeller_LabelTop   +Labeller_Delta) +Labeller_ObjectCornerCentre*<-1,1,-1>,
            Labeller_ObjectCornerRadius+Labeller_PlainBack*Labeller_LabelThickness
          )
        #end
      }
    #end  
    #if (Labeller_Extent>2)                          // "Sides" 
      object {Labeller_LabelRight
        texture {Labeller_ConsolidatedTexture
          rotate <-90,-90,0>
          translate <Labeller_LabelThickness+Labeller_ObjectWidth/2,Labeller_LabelBottom,-Labeller_ObjectCornerCentre.z>
          translate -z*Labeller_RightOffset
        }
        // If required, suppress the pigment on the inside of the right side surface
        #if (Labeller_PlainBack) 
          Labeller_PlainBackBoxTexture (
            <Labeller_ObjectWidth/2+Labeller_PlainBack*Labeller_LabelThickness,Labeller_LabelBottom-Labeller_Delta,-Labeller_ObjectCornerCentre.z-Labeller_Delta>,
            <Labeller_ObjectWidth/2-Labeller_Delta             ,Labeller_LabelTop   +Labeller_Delta,-Labeller_ObjectCornerCentre.z+Labeller_Delta+Labeller_SideWidth>
          )
        #end
      }
      object {Labeller_LabelRight   scale <-1,1, 1>   // Mirror the Right hand side over to the left   
        texture {Labeller_ConsolidatedTexture
          rotate <-90, 90,0>
          translate <-(Labeller_LabelThickness+Labeller_ObjectWidth/2),Labeller_LabelBottom,-Labeller_ObjectCornerCentre.z>
          translate z*Labeller_LeftOffset
        }
        // If required, suppress the pigment on the inside of the left side surface
        #if (Labeller_PlainBack) 
          Labeller_PlainBackBoxTexture (
            <-Labeller_ObjectWidth/2-Labeller_PlainBack*Labeller_LabelThickness,Labeller_LabelBottom-Labeller_Delta,-Labeller_ObjectCornerCentre.z-Labeller_Delta>,
            <-Labeller_ObjectWidth/2+Labeller_Delta             ,Labeller_LabelTop   +Labeller_Delta,-Labeller_ObjectCornerCentre.z+Labeller_Delta+Labeller_SideWidth>
          )
        #end
      }
    #end  
    #if (Labeller_Extent>3)                           // "Back Corners"         
      difference { 
        object {Labeller_LabelCorner}                 // Back Right  
        object {Labeller_CornerAngleGrinder rotate -y*(Labeller_BackCornerArcAngle) translate Labeller_ObjectCornerCentre}
        Labeller_ApplyRoundedCornerTexture((Labeller_LabelWidth/2)+(Labeller_FrontWidth/2)+(Labeller_SideWidth)+(Labeller_CornerOuterCircumference/4), 0, < 1,0, 1>*Labeller_ObjectCornerCentre + y*Labeller_LabelBottom)
        // If required, suppress the pigment on the inner surface of the label
        #if (Labeller_PlainBack) 
          Labeller_PlainBackCylinderTexture (
            y*(Labeller_LabelBottom-Labeller_Delta) +Labeller_ObjectCornerCentre,
            y*(Labeller_LabelTop   +Labeller_Delta) +Labeller_ObjectCornerCentre,
            Labeller_ObjectCornerRadius+Labeller_PlainBack*Labeller_LabelThickness
          )
        #end
       }
      difference { 
        object {Labeller_LabelCorner scale <-1,1, 1>} // Back Left
        object {Labeller_CornerAngleGrinder rotate  y*(Labeller_BackCornerArcAngle) translate Labeller_ObjectCornerCentre*<-1,0, 1>}
        Labeller_ApplyRoundedCornerTexture((Labeller_LabelWidth/2)-(Labeller_FrontWidth/2)-(Labeller_SideWidth)-(Labeller_CornerOuterCircumference/2), 270, <-1,0, 1>*Labeller_ObjectCornerCentre + y*Labeller_LabelBottom)
        // If required, suppress the pigment on the inner surface of the label
        #if (Labeller_PlainBack) 
          Labeller_PlainBackCylinderTexture (
            y*(Labeller_LabelBottom-Labeller_Delta) +Labeller_ObjectCornerCentre*<-1,1,1>,
            y*(Labeller_LabelTop   +Labeller_Delta) +Labeller_ObjectCornerCentre*<-1,1,1>,
            Labeller_ObjectCornerRadius+Labeller_PlainBack*Labeller_LabelThickness
          )
        #end
      }
    #end                                             
    #if (Labeller_Extent>4)                           // "Back Surface"  
      object {Labeller_LabelBackRight
        texture {Labeller_ConsolidatedTexture
          rotate <-90,180,0>
          translate <Labeller_FrontWidth/2,Labeller_LabelBottom,Labeller_LabelThickness+Labeller_ObjectDepth/2>
          translate x*(Labeller_LabelWidth-Labeller_BackWidth/2)
        } 
        // If required, suppress the pigment on the back of the back right surface
        #if (Labeller_PlainBack) 
          Labeller_PlainBackBoxTexture (
            < Labeller_ObjectCornerCentre.x-Labeller_BackWidth/2-Labeller_Delta,Labeller_LabelBottom-Labeller_Delta,Labeller_ObjectDepth/2+Labeller_PlainBack*Labeller_LabelThickness>,
            < Labeller_ObjectCornerCentre.x                     +Labeller_Delta,Labeller_LabelTop   +Labeller_Delta,Labeller_ObjectDepth/2-Labeller_Delta>  
          )
        #end
      }
      object {Labeller_LabelBackLeft
        texture {Labeller_ConsolidatedTexture
          rotate <-90,180,0>
          translate <-Labeller_FrontWidth/2,Labeller_LabelBottom,Labeller_LabelThickness+Labeller_ObjectDepth/2>
          translate x*Labeller_BackWidth/2
        }
        // If required, suppress the pigment on the back of the back left surface
        #if (Labeller_PlainBack) 
          Labeller_PlainBackBoxTexture (
            <-Labeller_ObjectCornerCentre.x                     -Labeller_Delta,Labeller_LabelBottom-Labeller_Delta,Labeller_ObjectDepth/2+Labeller_PlainBack*Labeller_LabelThickness>,
            <-Labeller_ObjectCornerCentre.x+Labeller_BackWidth/2+Labeller_Delta,Labeller_LabelTop   +Labeller_Delta,Labeller_ObjectDepth/2-Labeller_Delta>  
          )
        #end
      }
    #end 

    pigment {rgbt 1}
  }
#end 




// This macro generates a polygonal shaped label with angled surfaces and both bevelled and rounded edges
#macro Labeller_Polyhedron()
  #declare Labeller_Macro = "Polyhedron";  
  
  // Initialise any uninitialised variables
  Labeller_DefaultSettings()
  // The main calculations are performed in a separate macro so that the same maths can be used from both here
  // and from the design mode version
  Labeller_PolyhedronMaths()  
  // Initialise the label design layers
  #if (file_exists(Labeller_LabelFile)) #include Labeller_LabelFile
  #else Labeller_DefaultDesign()
  #end  
      
  // The surfaces used in the 3D version 
  #local Labeller_BevelFace = box {
    <-Labeller_BevelFaceWidth/2,-Labeller_LabelThickness,0>
    < Labeller_BevelFaceWidth/2,0,Labeller_BevelDepth> 
    translate x*Labeller_BevelFaceWidth/2
  }

  #local Labeller_PolyhedronFace = prism {
    linear_sweep linear_spline -Labeller_LabelThickness,0,5,
    <-Labeller_FaceTopWidth/2,Labeller_LabelDepth>,
    < Labeller_FaceTopWidth/2,Labeller_LabelDepth>,
    < Labeller_FaceBottomWidth/2,0>,
    <-Labeller_FaceBottomWidth/2,0>,
    <-Labeller_FaceTopWidth/2,Labeller_LabelDepth> 
    translate x*max(Labeller_FaceBottomWidth,Labeller_FaceTopWidth)/2
  }

  // The corner shape is a cylinder in the 3D version
  #local Labeller_Corner = difference {
    // Start with a cylinder lying from the origin along +Z
    cylinder {0                ,z* Labeller_BevelDepth                ,Labeller_CornerRadius} 
    // Hollow it out to the thickness required
    cylinder {-z*Labeller_Delta,z*(Labeller_BevelDepth+Labeller_Delta),Labeller_CornerRadius-Labeller_LabelThickness}
    // Slice out the surplus to the left of x=0
    box {
      <-(Labeller_CornerRadius+Labeller_Delta),-(Labeller_CornerRadius+Labeller_Delta),-Labeller_Delta>
      <0,Labeller_CornerRadius+Labeller_Delta,Labeller_BevelDepth+Labeller_Delta>
    }
    // Slice out the surplus around as far as necessary to the right to get the correct angle 
    box {
      <-(Labeller_CornerRadius+Labeller_Delta),-(Labeller_CornerRadius+Labeller_Delta),-Labeller_Delta>
      <0,Labeller_CornerRadius+Labeller_Delta,Labeller_BevelDepth+Labeller_Delta>
      scale <-1,1,1>
      rotate -z*(180-Labeller_CornerAngle)
    } 
  }


  // The base texture is a consolidated texture applied to each individual part of the label 
  #local Labeller_Layer = 0; 
  #while (Labeller_Layer<dimension_size(Labeller_LabelLayer,2))   
    #ifdef (Labeller_LabelLayer[0][Labeller_Layer])
      #local Labeller_ThisTexture = texture {pigment {Labeller_LabelLayer[0][Labeller_Layer]} translate y*(Labeller_LabelThickness+Labeller_SampleDepth)} 
      #ifdef (Labeller_BaseTexture) 
        #local Labeller_BaseTexture =
          texture {Labeller_BaseTexture}
          texture {
            Labeller_ThisTexture
            normal {Labeller_Normal}
            finish {Labeller_Finish}    
          }
      #else
        #local Labeller_BaseTexture = texture {
          Labeller_ThisTexture
          normal {Labeller_Normal}
          finish {Labeller_Finish}
        }
      #end
    #end
    #local Labeller_Layer = Labeller_Layer + 1;
  #end 
  #ifndef (Labeller_BaseTexture) #declare Labeller_BaseTexture = texture {pigment {rgbt 1}} #end

  
  // The individual parts of the texture can be consolidated ahead of the final assembly and reused with appropriate translations 
  #local Labeller_Face = 1;
  #while (Labeller_Face<dimension_size(Labeller_LabelLayer,1))   
    #local Labeller_Layer = 0; 
    #while (Labeller_Layer<dimension_size(Labeller_LabelLayer,2))   
      #ifdef (Labeller_LabelLayer[Labeller_Face][Labeller_Layer])
        #local Labeller_ThisTexture = texture {
          pigment {Labeller_LabelLayer[Labeller_Face][Labeller_Layer]} translate y*(Labeller_LabelThickness+Labeller_SampleDepth)
          normal {Labeller_Normal}
          finish {Labeller_Finish}
        } 
        // A nasty little work-around for assembling the textures that circumvents the texture syntax limitations
        #ifdef (Labeller_ConsolidatedTexture) 
          #local Labeller_ConsolidatedTexture =
            texture {Labeller_ConsolidatedTexture}
            texture {
              Labeller_ThisTexture
              normal {Labeller_Normal}
              finish {Labeller_Finish}
              transform{Labeller_SideTransform[Labeller_Face-1]}
            }
        #else  
          #local Labeller_ConsolidatedTexture = texture {
            Labeller_ThisTexture
            normal {Labeller_Normal}
            finish {Labeller_Finish}
            transform{Labeller_SideTransform[Labeller_Face-1]}
          }
        #end
      #end
      #local Labeller_Layer = Labeller_Layer + 1;
    #end 
    #local Labeller_Face = Labeller_Face +1;
  #end
  #ifndef (Labeller_ConsolidatedTexture) #declare Labeller_ConsolidatedTexture = texture {pigment {rgbt 1}} #end


  //**********************************//
  //   Polyhedron - Final Assembly    //
  //**********************************//
  // Create the label object using CSG and apply the layers of pigment as defined in the external file.
  union {
    #local Labeller_I = 0;
    #while (Labeller_I<Labeller_PolyhedronFaces)
      object {Labeller_PolyhedronFace
        texture {Labeller_BaseTexture}
        texture {Labeller_ConsolidatedTexture transform{Labeller_SideTransform [Labeller_I] inverse}}
        #if ((Labeller_I=Labeller_PolyhedronFaces-1) & Labeller_WrapTexture)
          texture {Labeller_ConsolidatedTexture 
            transform{Labeller_SideTransform [1]}
          }
        #end
        // If required, suppress the pigment on the back of the inside of the front surface
        #if (Labeller_PlainBack) 
          Labeller_PlainBackBoxTexture (
            <-Labeller_Delta                                                    ,-Labeller_LabelThickness-Labeller_Delta,-Labeller_Delta>,
            < Labeller_Delta+max(Labeller_FaceBottomWidth,Labeller_FaceTopWidth),-Labeller_LabelThickness*(1-Labeller_PlainBack)       , Labeller_Delta+Labeller_LabelDepth>  
          )
        #end
        translate -x*max(Labeller_FaceBottomWidth,Labeller_FaceTopWidth)/2
        rotate -x*Labeller_FaceInclination
        translate -z*Labeller_BottomInnerRadius
        rotate -y*Labeller_I*360/Labeller_PolyhedronFaces
      }
      union { 
        object {Labeller_BevelFace      
          texture {Labeller_BaseTexture
            translate <-max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth)/2,0,0>
            translate x*Labeller_BevelFaceWidth/2
            scale <1,1,Labeller_BevelDepth/Labeller_LabelDepth>
          }
          texture {Labeller_ConsolidatedTexture transform{Labeller_BevelTransform [Labeller_I] inverse}}
          #if ((Labeller_I=Labeller_PolyhedronFaces-1) & Labeller_WrapTexture)
            texture {Labeller_ConsolidatedTexture 
              transform{Labeller_SideTransform [1]}
              transform{Labeller_BevelTransform [0] inverse}
            }
          #end
          // If required, suppress the pigment on the back of the inside of the front surface
          #if (Labeller_PlainBack) 
            Labeller_PlainBackBoxTexture (
              <-Labeller_Delta                        ,-Labeller_LabelThickness-Labeller_Delta,-Labeller_Delta>,
              < Labeller_Delta+Labeller_BevelFaceWidth,-Labeller_LabelThickness*(1-Labeller_PlainBack)       , Labeller_Delta+Labeller_BevelDepth>  
            )
          #end
          translate -x*Labeller_BevelFaceWidth/2 
        }
        // There are two flavours of the corner shape, one on either side of the bevel. These are mirrors of each other.
        object {Labeller_Corner
          scale <-1,1,1>
          Labeller_ApplyRoundedPolyhedronCornerTexture(Labeller_Corner1Transform[Labeller_I],90+0.5*360/Labeller_PolyhedronFaces)       
          // If required, suppress the pigment on the inner surface of the label
          #if (Labeller_PlainBack) 
            Labeller_PlainBackCylinderTexture (
              -z*Labeller_Delta,
               z*Labeller_BevelDepth+Labeller_Delta,
              Labeller_CornerRadius-(1-Labeller_PlainBack)*Labeller_LabelThickness
            )
          #end
          translate <-Labeller_BevelFaceWidth/2,-Labeller_CornerRadius,0> 
        }
        object {Labeller_Corner
          Labeller_ApplyRoundedPolyhedronCornerTexture(Labeller_Corner2Transform[Labeller_I],90)       
          // If required, suppress the pigment on the inner surface of the label
          #if (Labeller_PlainBack) 
            Labeller_PlainBackCylinderTexture (
              -z*Labeller_Delta,
               z*Labeller_BevelDepth+Labeller_Delta,
              Labeller_CornerRadius-(1-Labeller_PlainBack)*Labeller_LabelThickness
            )
          #end
          translate <Labeller_BevelFaceWidth/2,-Labeller_CornerRadius,0> 
        } 
        rotate -x*90
        translate y*Labeller_BevelUplift 
        rotate x*90
        rotate -x*Labeller_BevelInclination
        translate -z*Labeller_BottomBevelRadius
        rotate -y*360/(2*Labeller_PolyhedronFaces)
        rotate -y*Labeller_I*360/Labeller_PolyhedronFaces
      }
      #local Labeller_I = Labeller_I+1;
    #end  
    translate y*Labeller_LabelBottom  
  }
#end  
 
// This macro provides a flattened version of the Polyhedral label used for designing the label.
// This macro shows the whole of the label design, whether it fits on the label or not, except for the 
// base layer which is draw on a box that is the size of the label.
#macro Labeller_FlattenedPolyhedron()   
  #declare Labeller_Macro = "Polyhedron"; 
  // Initialise any uninitialised variables
  Labeller_DefaultSettings()
  // The main calculations are performed in a separate macro so that the same maths can be used from both here
  // and from the 3D Polyhedral version
  Labeller_PolyhedronMaths()  
  // Initialise the label design layers
  #if (file_exists(Labeller_LabelFile)) #include Labeller_LabelFile
  #else Labeller_DefaultDesign()
  #end  


  // The surfaces used in the flattened version 
  #local Labeller_BevelFace = box {
    <-Labeller_BevelFaceWidth/2,-Labeller_LabelThickness,0>
    < Labeller_BevelFaceWidth/2,0,Labeller_BevelDepth> 
    translate x*Labeller_BevelFaceWidth/2
  }

  #local Labeller_PolyhedronFace = prism {
    linear_sweep linear_spline -Labeller_LabelThickness,0,5,
    <-Labeller_FaceTopWidth/2,Labeller_LabelDepth>,
    < Labeller_FaceTopWidth/2,Labeller_LabelDepth>,
    < Labeller_FaceBottomWidth/2,0>,
    <-Labeller_FaceBottomWidth/2,0>,
    <-Labeller_FaceTopWidth/2,Labeller_LabelDepth>
    translate x*max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth)/2
  } 

  // The corner shape is a simple box (in this flattened version)
  #local Labeller_Corner = box {
    <-Labeller_CornerWidth/2,-Labeller_LabelThickness,0>
    < Labeller_CornerWidth/2,0,Labeller_BevelDepth>  
    translate x*Labeller_CornerWidth/2
  }  
  #local Labeller_Corner1 = object {Labeller_Corner}
  #local Labeller_Corner2 = object {Labeller_Corner} 
  
  #ifdef(Labeller_BaseTexture)         #undef Labeller_BaseTexture         #end
  #ifdef(Labeller_ConsolidatedTexture) #undef Labeller_ConsolidatedTexture #end


  // The base texture is a consolidated texture applied to each individual part of the label 
  #local Labeller_Layer = 0; 
  #while (Labeller_Layer<dimension_size(Labeller_LabelLayer,2))   
    #ifdef (Labeller_LabelLayer[0][Labeller_Layer])
      #local Labeller_ThisTexture = texture {
        pigment {Labeller_LabelLayer[0][Labeller_Layer]} translate y*(Labeller_LabelThickness+Labeller_SampleDepth)
        normal {Labeller_Normal}
        finish {Labeller_Finish}
      } 
      #ifdef (Labeller_BaseTexture) 
        #local Labeller_BaseTexture =
          texture {Labeller_BaseTexture}
          texture {
            Labeller_ThisTexture
            normal {Labeller_Normal}
            finish {Labeller_Finish}    
          }
      #else
        #local Labeller_BaseTexture = texture {
          Labeller_ThisTexture
          normal {Labeller_Normal}
          finish {Labeller_Finish}
        }
      #end
    #end
    #local Labeller_Layer = Labeller_Layer + 1;  
  #end

  
  // The individual parts of the texture can be consolidated ahead of the final assembly and reused with appropriate translations 
  #local Labeller_Face = 1;
  #while (Labeller_Face<dimension_size(Labeller_LabelLayer,1))   
    #local Labeller_Layer = 0; 
    #while (Labeller_Layer<dimension_size(Labeller_LabelLayer,2))   
      #ifdef (Labeller_LabelLayer[Labeller_Face][Labeller_Layer])
        #local Labeller_ThisTexture = texture {
          pigment {Labeller_LabelLayer[Labeller_Face][Labeller_Layer]} translate y*(Labeller_LabelThickness+Labeller_SampleDepth)
          normal {Labeller_Normal} 
          finish {Labeller_Finish}
        } 
        // A nasty little work-around for assembling the textures that circumvents the texture syntax limitations
        #ifdef (Labeller_ConsolidatedTexture) 
          #local Labeller_ConsolidatedTexture =
            texture {Labeller_ConsolidatedTexture}
            texture {
              Labeller_ThisTexture
              normal {Labeller_Normal}
              finish {Labeller_Finish}
              transform{Labeller_SideTransform[Labeller_Face-1]}
            }
        #else  
          #local Labeller_ConsolidatedTexture = texture {
            Labeller_ThisTexture
            normal {Labeller_Normal}
            finish {Labeller_Finish}
            transform{Labeller_SideTransform[Labeller_Face-1]}
          }
        #end
      #end
      #local Labeller_Layer = Labeller_Layer + 1;
    #end 
    #local Labeller_Face = Labeller_Face +1;
  #end

  //********************************************//
  //   Flattened Polyhedron - Final Assembly    //
  //********************************************//
  // Create the label object using CSG and apply the layers of pigment as defined in the external file.
  union {
    #local Labeller_I = 0;
    #while (Labeller_I<Labeller_PolyhedronFaces)
      object {Labeller_PolyhedronFace 
        texture {Labeller_BaseTexture}
        transform{Labeller_SideTransform   [Labeller_I]}
      } 
      object {Labeller_Corner1
        texture {Labeller_BaseTexture
          translate <-max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth)/2,0,0>
          translate x*Labeller_CornerWidth/2
          scale <1,1,Labeller_BevelDepth/Labeller_LabelDepth>
        }
        transform{Labeller_Corner1Transform[Labeller_I]}
      }
      object {Labeller_BevelFace      
        texture {Labeller_BaseTexture   
          translate <-max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth)/2,0,0>
          translate x*Labeller_BevelFaceWidth/2
          scale <1,1,Labeller_BevelDepth/Labeller_LabelDepth>
        }
        transform{Labeller_BevelTransform  [Labeller_I]}
      }
      object {Labeller_Corner2        
        texture {Labeller_BaseTexture
          translate <-max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth)/2,0,0>
          translate x*Labeller_CornerWidth/2
          scale <1,1,Labeller_BevelDepth/Labeller_LabelDepth>
        }
        transform{Labeller_Corner2Transform[Labeller_I]}
      }
      #local Labeller_I = Labeller_I+1;
    #end    
    // The other layers
    plane {y,Labeller_Delta   
      texture {Labeller_ConsolidatedTexture}
    } 
  }
#end 




// This macro shows the whole of the label design, whether it fits on the label or not, except for the 
// base layer which is draw on a box that is the size of the label.
#macro Labeller_LabelDesign()
  #declare Labeller_Macro = "LabelDesign"; 
  // Initialise any uninitialised variables, including the label design layers
  Labeller_DefaultSettings() 
  #if (file_exists(Labeller_LabelFile)) #include Labeller_LabelFile
  #else Labeller_DefaultDesign() 
  #end 

  // Axes are optional
  #if (Labeller_ShowAxes>0)
    union {
      Labeller_DrawAxes(Labeller_AxesRadius*Labeller_ShowAxes, Labeller_GradationSpacing, Labeller_GradationProtrusion)
  #end

  // The texture is either added to a plane to show all design elements or to a box to clip it to the label size.
  #if (Labeller_LabelDesignClip)
    box {-2*Labeller_SampleDepth*y,<Labeller_LabelWidth,-Labeller_SampleDepth,Labeller_LabelHeight>  
  #else 
    plane {y,-Labeller_SampleDepth 
  #end
    // The layers of pigment
    #local LayerI = 0; 
    #while (LayerI<dimension_size(Labeller_LabelLayer,1))
      #local LayerJ = 0; 
      #while (LayerJ<dimension_size(Labeller_LabelLayer,2))   
        #ifdef (Labeller_LabelLayer[LayerI][LayerJ]) 
          texture {
            pigment {Labeller_LabelLayer[LayerI][LayerJ]} translate y*Labeller_Delta
            normal {Labeller_Normal} 
            finish {Labeller_Finish}
          }  
        #end
        #local LayerJ = LayerJ + 1;
      #end 
      #local LayerI = LayerI + 1;
    #end
  } 
  #if (Labeller_ShowAxes>0)
    }
  #end
#end        


/*****************************/
/*    Utility Macros         */
/*****************************/

// This macro is called by both the Labeller_Polyhedron macro and the Labeller_FlattenedPolyhedron macro to provide consistent 
// calculations to both.
#macro Labeller_PolyhedronMaths()
  #declare Labeller_Height                = Labeller_LabelTop - Labeller_LabelBottom;                    // Vertical Height 
  #declare Labeller_InnerRadiusDifference = abs(Labeller_BottomInnerRadius-Labeller_TopInnerRadius);
  #declare Labeller_LabelDepth            = vlength(<Labeller_InnerRadiusDifference,Labeller_Height,0>); // Depth of band of paper

  #ifndef (sind) #include "math.inc" #end 
  #declare Labeller_TopWidth              = 2*Labeller_TopInnerRadius   *tand(360/(2*Labeller_PolyhedronFaces));
  #declare Labeller_BottomWidth           = 2*Labeller_BottomInnerRadius*tand(360/(2*Labeller_PolyhedronFaces));  
  #declare Labeller_TopOuterRadius        = vlength(<Labeller_TopWidth   /2,Labeller_TopInnerRadius   ,0>);
  #declare Labeller_BottomOuterRadius     = vlength(<Labeller_BottomWidth/2,Labeller_BottomInnerRadius,0>);
  #declare Labeller_OuterRadiusDifference = abs(Labeller_BottomOuterRadius-Labeller_TopOuterRadius);

  #declare Labeller_FaceInclination       = atan2d(Labeller_Height,Labeller_InnerRadiusDifference);
  #if (Labeller_TopInnerRadius>Labeller_BottomInnerRadius)
    #declare Labeller_FaceInclination     = 180-Labeller_FaceInclination;
  #end
  
  #declare Labeller_BevelInclination      = atan2d(Labeller_Height,Labeller_OuterRadiusDifference);
  #if (Labeller_TopOuterRadius>Labeller_BottomOuterRadius)
    #declare Labeller_BevelInclination     = 180-Labeller_BevelInclination;
  #end

  #declare Labeller_BevelDepth            = vlength(<Labeller_LabelDepth,abs(Labeller_BottomWidth-Labeller_TopWidth)/2,0>);

  // Where a bevel and a face come together at a corner, the angle at which they join is quite tricky to 
  // visualise, but can be derived from the inclination of the bevel and the angle which the upper edges
  // of the two surfaces make where they form part of the top rim.
  #declare Labeller_OffStraightAngle = 360/(2*Labeller_PolyhedronFaces);   // (The number of faces plus bevels)
  #declare Labeller_CornerAngle = 180-atan2d(tand(Labeller_OffStraightAngle)*sind(Labeller_BevelInclination),1);
    

  #declare Labeller_BevelDecrement  = 0.5*Labeller_BevelWidth/cosd(360/(2*Labeller_PolyhedronFaces));
  #declare Labeller_CornerDecrement = Labeller_CornerRadius/tand(Labeller_CornerAngle/2);
  #declare Labeller_FaceTopWidth    = Labeller_TopWidth   -2*Labeller_BevelDecrement-2*Labeller_CornerDecrement;
  #declare Labeller_FaceBottomWidth = Labeller_BottomWidth-2*Labeller_BevelDecrement-2*Labeller_CornerDecrement;
  #declare Labeller_BevelFaceWidth  = Labeller_BevelWidth -2*Labeller_CornerDecrement;
  #declare Labeller_CornerOuterCircumference = 2*pi*Labeller_CornerRadius;

  // The bevel and the texture on it need to be lifted up a little to take account of the rounding of the corners 
  #declare Labeller_BevelUplift  = Labeller_CornerDecrement*(Labeller_BottomWidth-Labeller_TopWidth)/Labeller_LabelDepth;
  
  
  #declare Labeller_BottomBevelRadius    = sqrt(pow(vlength(<Labeller_BottomWidth/2-Labeller_BevelDecrement,Labeller_BottomInnerRadius,0>),2)-pow(Labeller_BevelWidth/2,2));// 0.0265;

  #declare Labeller_SideWedgeAngle     = atan2d((Labeller_FaceBottomWidth-Labeller_FaceTopWidth)/2,Labeller_LabelDepth);
  #if (Labeller_FaceTopWidth>Labeller_FaceBottomWidth)
    #declare Labeller_OriginDisplacement = (Labeller_FaceTopWidth-Labeller_FaceBottomWidth)/2;
  #else 
    #declare Labeller_OriginDisplacement = 0;
  #end

  #declare Labeller_CornerWidth      = 2*pi*Labeller_CornerRadius/(2*Labeller_PolyhedronFaces);
  #declare Labeller_SideTransform    = array[Labeller_PolyhedronFaces];
  #declare Labeller_Corner1Transform = array[Labeller_PolyhedronFaces];
  #declare Labeller_BevelTransform   = array[Labeller_PolyhedronFaces];
  #declare Labeller_Corner2Transform = array[Labeller_PolyhedronFaces];


  #declare Labeller_SideTransform   [0] = transform {rotate 0}
  #declare Labeller_Corner1Transform[0] = transform {rotate -y*Labeller_SideWedgeAngle translate x*(Labeller_FaceBottomWidth+Labeller_OriginDisplacement)}
  #declare Labeller_BevelTransform  [0] = transform {translate x*Labeller_CornerWidth    transform {Labeller_Corner1Transform[0]}}
  #declare Labeller_Corner2Transform[0] = transform {translate x*Labeller_BevelFaceWidth transform {Labeller_BevelTransform[0]}}
  
  #local Labeller_I = 1;
  #while (Labeller_I<Labeller_PolyhedronFaces)
    #declare Labeller_SideTransform   [Labeller_I] = transform {translate -x*Labeller_OriginDisplacement rotate -y*Labeller_SideWedgeAngle translate x*Labeller_CornerWidth     transform {Labeller_Corner2Transform[Labeller_I-1]}}
    #declare Labeller_Corner1Transform[Labeller_I] = transform {rotate -y*Labeller_SideWedgeAngle translate x*(Labeller_FaceBottomWidth+Labeller_OriginDisplacement) transform {Labeller_SideTransform[Labeller_I]}}
    #declare Labeller_BevelTransform  [Labeller_I] = transform {translate x*Labeller_CornerWidth    transform {Labeller_Corner1Transform[Labeller_I]}}
    #declare Labeller_Corner2Transform[Labeller_I] = transform {translate x*Labeller_BevelFaceWidth transform {Labeller_BevelTransform[Labeller_I]}}
    #local Labeller_I = Labeller_I+1;                                      
  #end                                                                     
                                   
                                   
#end



// This utility macro is used to apply a flat texture to a rounded corner on a rounded box shaped label and orient it appropriately 
//   XOffset            specifies the amount to move the texture to the left so that it starts in the required position
//                      The line at x=0 on the flat texture will be aligned to the +X direction by the cylindrical warp.
//   YRotation          is the angle required to rotate the start position from +x to wherever it's required 
//   DisplacementVector is the amount by which to displace the texture to align it with the corner position

#macro Labeller_ApplyRoundedCornerTexture (XOffset,YRotation,DisplacementVector) 
  #local LayerI = 0; 
  #while (LayerI<dimension_size(Labeller_LabelLayer,1))   
    #local LayerJ = 0; 
    #while (LayerJ<dimension_size(Labeller_LabelLayer,2))   
      #ifdef (Labeller_LabelLayer[LayerI][LayerJ])
        texture {
          pigment {
            Labeller_LabelLayer[LayerI][LayerJ] 
            translate y*Labeller_SampleDepth
            translate -x*XOffset 
            scale <1/Labeller_CornerOuterCircumference,1,1>
            warp {
              cylindrical 
              orientation y 
            }
            rotate y*YRotation
            translate DisplacementVector
          } 
          normal {Labeller_Normal}
          finish {Labeller_Finish}
        } 
      #end
      #local LayerJ = LayerJ + 1;
    #end
    #local LayerI = LayerI + 1;
  #end
#end


// This utility macro is used to apply a flat texture to a rounded corner and orient it approriately.
// This is similar to the Labeller_ApplyRoundedCornerTexture macro except that it operates on the two dimensional arrays
// used for the Polyhedron shape. 
//   CornerTransformation  specifies a transformation to be applied to the finished texture to move it to the corner position
//   YRotation             is the angle required to rotate the start position from +x to wherever it's required 

#macro Labeller_ApplyRoundedPolyhedronCornerTexture (CornerTransformation, YRotation)  
  #local Labeller_Face = 0;
  #local Labeller_Layer = 0; 
  #while (Labeller_Layer<dimension_size(Labeller_LabelLayer,2))   
    #ifdef (Labeller_LabelLayer[Labeller_Face][Labeller_Layer])
      texture {
        pigment {
          Labeller_LabelLayer[Labeller_Face][Labeller_Layer] 
          translate <-max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth)/2,Labeller_SampleDepth,0>
          translate x*(Labeller_CornerWidth)/2
          scale <1/Labeller_CornerOuterCircumference,1,Labeller_BevelDepth/Labeller_LabelDepth> 
          warp {
            cylindrical 
            orientation y 
          }
          rotate y*YRotation 
          rotate x*90
        } 
        normal {Labeller_Normal}
        finish {Labeller_Finish}
      } 
    #end
    #local Labeller_Layer = Labeller_Layer + 1;
  #end
  #local Labeller_Face = 1;
  #while (Labeller_Face<dimension_size(Labeller_LabelLayer,1))   
    #local Labeller_Layer = 0; 
    #while (Labeller_Layer<dimension_size(Labeller_LabelLayer,2))   
      #ifdef (Labeller_LabelLayer[Labeller_Face][Labeller_Layer])
        texture {
          pigment {
            Labeller_LabelLayer[Labeller_Face][Labeller_Layer] 
            translate y*Labeller_SampleDepth
            transform {Labeller_SideTransform[Labeller_Face-1]}
            transform {CornerTransformation inverse} 
            scale <1/Labeller_CornerOuterCircumference,1,1>
            warp {
              cylindrical 
              orientation y 
            }
            rotate y*YRotation
            rotate x*90
          } 
          normal {Labeller_Normal}
          finish {Labeller_Finish}
        }
        // If required, wrap the texture round from the first segment to the last segment.
        #if ((Labeller_I=Labeller_PolyhedronFaces-1) & Labeller_WrapTexture)  
        #ifdef (Labeller_LabelLayer[1][Labeller_Layer])
            texture {
              pigment{
                Labeller_LabelLayer[1][Labeller_Layer] 
                translate y*Labeller_SampleDepth
                transform {Labeller_SideTransform[Labeller_I]} 
                transform {Labeller_SideTransform[1]} 
                transform {CornerTransformation inverse} 
                scale <1/Labeller_CornerOuterCircumference,1,1>
                warp {
                  cylindrical 
                  orientation y 
                }
                rotate y*YRotation
                rotate x*90
              }
              normal {Labeller_Normal}
              finish {Labeller_Finish}
            } 
          #end
        #end
      #end
      #local Labeller_Layer = Labeller_Layer + 1;
    #end
    #local Labeller_Face = Labeller_Face +1;
  #end
#end



// This utility macro is used to add a pair of axes to a flattened texture in design mode.
//   AxesRadius            specifies the radius in POV-Ray units of the cylinders used to draw the axes.
//   GradationSpacing      specifies the distance between the distance markers      
//   GradationProtrusion   specifies how far out from the axis the distance markers extend
#macro Labeller_DrawAxes(AxesRadius, GradationSpacing, GradationProtrusion)
  cylinder {-z,z,AxesRadius pigment {rgb <5,5,0>}}
  cylinder {-x,x,AxesRadius pigment {rgb <5,0,0>}} 
  #local I = 1;
  #while (I<20)
    cylinder {-GradationProtrusion*z,GradationProtrusion*z,AxesRadius pigment {rgb <5,0,0>} translate x*GradationSpacing*I}
    cylinder {-GradationProtrusion*x,GradationProtrusion*x,AxesRadius pigment {rgb <5,5,0>} translate z*GradationSpacing*I}
    #local I = I + 1;
  #end
#end

 
 
// This utility macro is used to add a flattened label object and a standard orthographic camera and lighting in design mode.
//   SettingsFile            specifies the file ID of the settings file.  
//   LabelFormat             "Rect" (for flat, cylindrical and Rounded Box) or "Poly" (for Polyhedron)
#macro Labeller_DisplayDesign(SettingsFile,LabelFormat) 
  #declare Labeller_LabelDesignMode  = 0; 
  #if (file_exists(SettingsFile))
    // Pick up the label size and other settings
    #include SettingsFile  
    
    // For Flat, Cylindrical and Rounded Box style labels the flattened version is a rectangle. 
    #if (strcmp(LabelFormat,"Rect")=0) 
      // Call the Labeller_LabelDesign macro to generate the flattened version of the label object
      #local TempObject = Labeller_LabelDesign() 
      #local Labeller_CameraCentre = <Labeller_LabelWidth/2,0,Labeller_LabelHeight/2>;
    #end  
    
    // For Polyhedral labels the flattened version is a segmented arc.
    #if (strcmp(LabelFormat,"Poly")=0) 
      #local TempObject = object {
        Labeller_FlattenedPolyhedron()
        #if (Labeller_LabelDesignSegment > 0)
          transform {Labeller_SideTransform[Labeller_LabelDesignSegment-1] inverse}  
        #end   
      } 
      // A setting of '0' for Labeller_LabelDesignSegment indicates that a zoomed-out view of the whole label is required.
      #if (Labeller_LabelDesignSegment=0)
        // Work out where the right most extremity of the flattened label is going to end up  
        Labeller_PolyhedronMaths()
        #include "transforms.inc"
        #local ExtremityVector1 = vtransform(<Labeller_CornerWidth,0,Labeller_BevelDepth>, transform {Labeller_Corner2Transform[Labeller_PolyhedronFaces-1]});      
        #local ExtremityVector2 = vtransform(<Labeller_CornerWidth,0,0                  >, transform {Labeller_Corner2Transform[Labeller_PolyhedronFaces-1]});      
        
        #local LabelMaxExtents = <max(ExtremityVector1.x,ExtremityVector2.x),0,max(Labeller_BevelDepth,ExtremityVector1.z,ExtremityVector2.z)>;
        #local LabelMinExtents = <0,0,min(0,ExtremityVector1.z,ExtremityVector2.z)>;
              
        #local Labeller_CameraCentre = (LabelMinExtents+LabelMaxExtents)/2;

        #local Labeller_CameraSpan  = max(LabelMaxExtents.x-LabelMinExtents.x,(LabelMaxExtents.z-LabelMinExtents.z)*4/3);  
      // If a specific face is being displayed, zoom in on that face.
      #else  
        #local Labeller_CameraCentre = <max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth)/2,0,Labeller_LabelHeight/2>;
        #local Labeller_CameraSpan  = max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth,Labeller_LabelHeight*4/3);
      #end 
      // Axes are optional
      #if (Labeller_ShowAxes>0)
        Labeller_DrawAxes(Labeller_AxesRadius*Labeller_ShowAxes, Labeller_GradationSpacing, Labeller_GradationProtrusion)
      #end
    #end 
    
    // If TempObject is not yet defined and no error was thrown, we assume it's because an invalid LabelFormat was specified
    #ifndef (TempObject)
      #local TempObject = union {
        text {ttf Labeller_FontCheck("arial.ttf") "Invalid LabelFormat Specified:" 1,0 translate y} 
        text {ttf Labeller_FontCheck("arial.ttf") concat("\"",LabelFormat,"\"") 1,0}  
        pigment {rgb <5,0,0>}
        rotate x*90
      }
      #local Labeller_CameraSpan = max_extent(TempObject).x-min_extent(TempObject).x;
      #local Labeller_CameraCentre = <Labeller_CameraSpan/2,0,0>;
      #debug concat("\nInvalid LabelFormat Specified: \"",LabelFormat,"\"\n")
    #end  
    
  // If the Settings File passed to this macro wasn't found, display a message.
  #else
    #local TempObject = union {
      text {ttf Labeller_FontCheck("arial.ttf") "File Not Found:" 1,0 translate y} 
      text {ttf Labeller_FontCheck("arial.ttf") concat("\"",SettingsFile,"\"") 1,0}  
      pigment {rgb <5,0,0>}
      scale 0.005
      rotate x*90
    } 
    #local Labeller_CameraSpan = max_extent(TempObject).x-min_extent(TempObject).x;
    #local Labeller_CameraCentre = <Labeller_CameraSpan/2,0,0>;
    #debug concat("\nFile Not Found: \"",SettingsFile,"\"\n")
  #end

  // Add the object to the scene
  object {TempObject}  

//#debug concat("\nExtremityVector1: \"",vstr(3,ExtremityVector1,",",3,8),"\"\n")
//#debug concat("ExtremityVector2: \"",vstr(3,ExtremityVector2,",",3,8),"\"\n")
//#debug concat("\nLabelMaxExtents:  \"",vstr(3,LabelMaxExtents,",",3,8),"\"\n")
//#debug concat("LabelMinExtents:  \"",vstr(3,LabelMinExtents,",",3,8),"\"\n")
//#debug concat("\nLabeller_CameraCentre: \"",vstr(3,Labeller_CameraCentre,",",3,8),"\"\n")
//#debug concat("\nCamera LocationCentre: \"",vstr(3,Labeller_CameraCentre+y-0.00001*z,",",3,8),"\"\n")
//#debug concat("Labeller_CameraSpan: \"",str(Labeller_CameraSpan,3,8),"\"\n")
//#debug concat("CameraSpanX: \"",vstr(3,1.02*Labeller_CameraSpan.x*x,",",3,8),"\"\n")
//#debug concat("CameraSpanY: \"",vstr(3,1.02*Labeller_CameraSpan.x*y*3/4,",",3,8),"\"\n") 
    
  // Add a light and an orthographic camera
  light_source { <-20,65,30>, rgb 2}
  camera { 
    orthographic
    location Labeller_CameraCentre+y
    look_at  Labeller_CameraCentre
    right 1.02*Labeller_CameraSpan*x 
    up    1.02*Labeller_CameraSpan*y*3/4
  }
#end



// This utility macro checks whether a font file exists and otherwise returns a common one.
//   FontFile            the name of the font file to check.  
#macro Labeller_FontCheck (FontFile) 
  #if (file_exists(FontFile)) 
    FontFile
  #else
    "arial.ttf"
  #end
#end
  


// This macro suppress the pigment on the back of a box section
//   Extent1            specifies one extent of a box to be used as an object pigment.  
//   Extent2            specifies the other extent of a box to be used as an object pigment.  
#macro Labeller_PlainBackBoxTexture (Extent1, Extent2)
  #if (Labeller_PlainBack) 
    texture {
      pigment {
        object {
          box {Extent1,Extent2}
          color <1,1,1,1> 
          color Labeller_PlainBackColor
        }
      }
    }
  #end
#end  

// This macro suppress the pigment on the back of a cylindrical section
//   Extent1            specifies one end of a cylinder to be used as an object pigment.  
//   Extent2            specifies the other end of a cylinder to be used as an object pigment.  
//   Radius             specifies the radius of a cylinder to be used as an object pigment.  
#macro Labeller_PlainBackCylinderTexture (Extent1, Extent2, Radius)
  #if (Labeller_PlainBack) 
    texture {
      pigment {
        object {
          cylinder {Extent1,Extent2,Radius}
          color <1,1,1,1> 
          color Labeller_PlainBackColor
        }
      }
    }
  #end
#end  



// This macro sets the default variable settings for the labeller macros. 
#macro Labeller_DefaultSettings()

  // These values are usually set elsewhere, but having default values is intended to help prevent
  // the macros from breaking when being developed or when called ad-hoc from a scene file.
  // The macro that includes these setting should set a variable to enable macro specific defaults to be set.
  #ifndef (Labeller_Macro) #declare Labeller_Macro = "Polygon"; #end
  
  //**************************//
  //  User Defined Variables  //
  //**************************//
  // If the user defined variables are already set then we don't override those settings.
  #ifndef (Labeller_LabelRounding   ) #declare Labeller_LabelRounding    = 0.002;     #end
  #ifndef (Labeller_LabelThickness  ) #declare Labeller_LabelThickness   = 0.0001;    #end
  #ifndef (Labeller_LabelBottom     ) #declare Labeller_LabelBottom      = 0.004;     #end
  #ifndef (Labeller_LabelTop        ) #declare Labeller_LabelTop         = 0.042;     #end   
  #ifndef (Labeller_LabelDesignMode ) #declare Labeller_LabelDesignMode  = 0;         #end  
  #ifndef (Labeller_WrapTexture     ) #declare Labeller_WrapTexture      = 1;         #end     
                                                                                     
  #ifndef (Labeller_PigmentIntensity) #declare Labeller_PigmentIntensity = 1;         #end
  // By default the pattern on the front shows through on the back of the label.
  #ifndef (Labeller_PlainBack)        #declare Labeller_PlainBack        = 0;         #end
  // If Labeller_PlainBack is > 0 it defines the relative thickness of the backing paper, so we limit it to < 1. 
  #if (Labeller_PlainBack>=1)         #declare Labeller_PlainBack        = 0.99;      #end
  // If a plain back is specified the default color is white.
  #ifndef (Labeller_PlainBackColor)   #declare Labeller_PlainBackColor   = <1,1,1,0>; #end
  
  #ifndef(Labeller_Normal)
    #declare Labeller_Normal = normal {crackle 0}
  #end 
  #ifndef(Labeller_Finish)
    #declare Labeller_Finish = finish {reflection 0}
  #end 
  
  // Polyhedron specific settings
  #ifndef (Labeller_PolyhedronFaces  ) #declare Labeller_PolyhedronFaces    = 8;     #end
  #ifndef (Labeller_TopInnerRadius   ) #declare Labeller_TopInnerRadius     = 0.015; #end
  #ifndef (Labeller_BottomInnerRadius) #declare Labeller_BottomInnerRadius  = 0.025; #end
  #ifndef (Labeller_BevelWidth       ) #declare Labeller_BevelWidth         = 0.004; #end
  #ifndef (Labeller_CornerRadius     ) #declare Labeller_CornerRadius       = 0.002; #end  
  
  
  // Cylinder specific settings.
  #ifndef (Labeller_ObjectRadius   ) #declare Labeller_ObjectRadius    = 0.015;  #end
  #if (strcmp(Labeller_Macro,"Cylinder")=0 | strcmp(Labeller_Macro,"LabelDesign")=0)
    #ifdef (Labeller_LabelWidth)
      #declare Labeller_LabelArc = 360*Labeller_LabelWidth/(2*pi*Labeller_ObjectRadius);
    #else
      #ifndef (Labeller_LabelArc) #declare Labeller_LabelArc = 356;    #end
      #declare Labeller_LabelWidth = 2*pi*Labeller_ObjectRadius*Labeller_LabelArc/360;    
    #end
  #end 
  
  // RoundedBox specific settings.
  #if (strcmp(Labeller_Macro,"RoundedBox")=0 | strcmp(Labeller_Macro,"LabelDesign")=0) 
    #ifndef (Labeller_LabelWidth        ) #declare Labeller_LabelWidth         = 0.0911; #end // 0.0911;
  #end 
  #ifndef (Labeller_ObjectWidth       ) #declare Labeller_ObjectWidth        = 0.03;   #end
  #ifndef (Labeller_ObjectDepth       ) #declare Labeller_ObjectDepth        = 0.02;   #end
  #ifndef (Labeller_ObjectCornerRadius) #declare Labeller_ObjectCornerRadius = 0.005;  #end
  
  // These variables can be used by any of the labeller macros as required.
  #ifndef (Labeller_LabelHeight) #declare Labeller_LabelHeight  = Labeller_LabelTop - Labeller_LabelBottom;   #end      
  #ifndef (Labeller_LabelWidth)  #declare Labeller_LabelWidth   = 0.05;                                       #end      
  #ifndef (Labeller_Delta      ) #declare Labeller_Delta        = 0.0000001;                                  #end
  #ifndef (Labeller_SampleDepth) #declare Labeller_SampleDepth  = 0.0001;                                     #end
  
  // Default camera settings should be set within each 'settings' file.
  #ifndef (Labeller_DefaultCameraLocation) #declare Labeller_DefaultCameraLocation = <0,0.05,-0.1>; #end
  #ifndef (Labeller_DefaultCameraLook_At ) #declare Labeller_DefaultCameraLook_At  = <0,0.03,0>;    #end
  
  
  //**************************//
  //  Label Design File       //
  //**************************//
  // The graphical design of the label (the pigment) is held in an external file to make it easier to change.
  #ifndef (Labeller_LabelFile)  #declare Labeller_LabelFile = "NO_FILE.inc"; #end       
  
  // Default Design Mode Settings
  #ifndef (Labeller_ShowAxes       ) #declare Labeller_ShowAxes        = 0;      #end
  #ifndef (Labeller_LabelDesignClip) #declare Labeller_LabelDesignClip = 1;      #end
  #ifndef (Labeller_CameraSpan)
    #declare Labeller_CameraSpan = max(Labeller_LabelWidth,Labeller_LabelHeight*4/3);
  #end 
  
  #ifndef (Labeller_AxesRadius)
    #declare Labeller_AxesRadius = 0.0016*Labeller_CameraSpan;   
  #end 
  #ifndef (Labeller_GradationSpacing)
    #declare Labeller_GradationSpacing = 0.01;   
  #end 
  #ifndef (Labeller_GradationProtrusion)
    #declare Labeller_GradationProtrusion = Labeller_GradationSpacing/10;   
  #end  
#end


// This macro sets the default design for a labeller macro. 
#macro Labeller_DefaultDesign()

 
  #ifndef (Labeller_PlainBack) #declare Labeller_PlainBack        = 0.99;  #end

  // If this design is being used because the design file was not found, write a warning out to the message stream.
  #if (strcmp(Labeller_LabelFile,"NO_FILE.inc")!=0) 
    #debug "\n Warning: \n"
    #debug   " ******** \n"
    #debug "The Labeller macro within the 'labeller.inc' is using the default\n"
    #debug concat("design because the design file '",Labeller_LabelFile,"' was not found.\n")
    #debug "You should check that this file exists and is either in a directory in the\n"
    #debug "POV-Ray include path or is in the same directory as your scene file.\n"
  #end

  //**************************//
  //     Label Design         //
  //**************************//
  #declare Labeller_LabelLayer = array[Labeller_PolyhedronFaces+1][30];
  
  //**************************//
  //   Layers of pigment      //
  //**************************// 
  
  // The label background 
  #declare Labeller_LabelLayer[0][0] = pigment {rgb <0.85,0.95,0.85>}  
  
  #local Labeller_BandThickness = 0.008;    
  
  // The green band around the middle
  #declare Labeller_LabelLayer[0][1] = pigment {
    object { 
      box {
        <0,-1,Labeller_LabelHeight/2-Labeller_BandThickness/2>,
        <max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth),Labeller_Delta,Labeller_LabelHeight/2+Labeller_BandThickness/2>
      }
      color <1,1,1,1>
      color <0.55,0.65,0.55>*Labeller_PigmentIntensity
    } 
  }

  // This label texture incorporates the POV-Ray logo
  #ifndef(Povray_Logo_Prism) #include "logo.inc" #end     
  
  // A wide version of the POV-Ray logo that will be wider than the polygon faces
  #declare Labeller_LabelLayer[1][1] = pigment {
    object {
      Povray_Logo_Prism
      translate <0,0,0>
      scale <0.025,0.015,8>
      rotate x*90
      translate <max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth),Labeller_Delta,Labeller_LabelDepth>/2
      color <1,1,1,1>
      color <0,0.4,0.4>*Labeller_PigmentIntensity
    } 
  } 

  // A smaller version of the POV-Ray logo that fits on a face
  #declare Labeller_LabelLayer[2][1] = pigment {
    object {
      Povray_Logo_Prism
      translate <0,0,0>
      scale <0.005,0.005,8>
      rotate x*90
      translate <max(Labeller_FaceTopWidth,Labeller_FaceBottomWidth),Labeller_Delta,Labeller_LabelDepth>/2
      color <1,1,1,1>
      color <0.5,0.9,0>*Labeller_PigmentIntensity
    } 
  } 

  // Copy them round to alternating faces
  #declare Labeller_LabelLayer[3][1] = Labeller_LabelLayer[1][1];
  #declare Labeller_LabelLayer[5][1] = Labeller_LabelLayer[1][1];
  #declare Labeller_LabelLayer[7][1] = Labeller_LabelLayer[1][1];

  #declare Labeller_LabelLayer[4][1] = Labeller_LabelLayer[2][1];
  #declare Labeller_LabelLayer[6][1] = Labeller_LabelLayer[2][1];
  #declare Labeller_LabelLayer[8][1] = Labeller_LabelLayer[2][1];

#end


// This macro creates a barcode in a 1 POV-Ray unit box between <0,0,0> and <1,1,1> 
// with the bars and numbers facing towards -Z and running from 0 to +X.
// It is an attempt at European Article Number (EAN) barcodes with a lead digit of '0'
// but the technical accuracy is not in any way guaranteed by the author.
// For a technical description see http://en.wikipedia.org/wiki/European_Article_Number
//
//   PatternDigit      A value between 0 and 9 which identifies the encoding pattern of the barcode. 
//                     An EAN with a leading '0' should produce a barcode compatible with the 
//                     UPC (Universal Product Code) system developed in North America.
//   String            The string of digits that the barcode will represent.
//   ClippingHeight    The height above the x-axis at which the barcode bars should end.
//                     Note. This is relative to a height of 1 POV-Ray unit, so values typically 
//                     range from 0.5 to 1.                                 
#macro Labeller_EANBarCode(PatternDigit, String, ClippingHeight) 
  #local BorderWidth        = 0.05;
  #local CharacterSpacing   = 1/15;
  #local CharacterWidth     = 1/12;
  #local CharacterHeight    = 1/12; 
  #local SeparatorBarSpacer = 2;
  #local BarWidth           = (1-CharacterSpacing-BorderWidth)/(7*(strlen(String)+SeparatorBarSpacer));
  #local BarBottom          = BorderWidth+CharacterHeight;
  #local ExtendedBarBottom  = BarBottom - CharacterHeight/2;
  // The representation of a digit depends on the encoding and the position in the bar code.
  #declare Labeller_BarCodeLDigit = array[10];    #declare Labeller_BarCodeGDigit = array[10];    #declare Labeller_BarCodeRDigit = array[10];   
  #declare Labeller_BarCodeLDigit[0] = "0001101"; #declare Labeller_BarCodeGDigit[0] = "0100111"; #declare Labeller_BarCodeRDigit[0] = "1110010";
  #declare Labeller_BarCodeLDigit[1] = "0011001"; #declare Labeller_BarCodeGDigit[1] = "0110011"; #declare Labeller_BarCodeRDigit[1] = "1100110";
  #declare Labeller_BarCodeLDigit[2] = "0010011"; #declare Labeller_BarCodeGDigit[2] = "0011011"; #declare Labeller_BarCodeRDigit[2] = "1101100";
  #declare Labeller_BarCodeLDigit[3] = "0111101"; #declare Labeller_BarCodeGDigit[3] = "0100001"; #declare Labeller_BarCodeRDigit[3] = "1000010";
  #declare Labeller_BarCodeLDigit[4] = "0100011"; #declare Labeller_BarCodeGDigit[4] = "0011101"; #declare Labeller_BarCodeRDigit[4] = "1011100";
  #declare Labeller_BarCodeLDigit[5] = "0110001"; #declare Labeller_BarCodeGDigit[5] = "0111001"; #declare Labeller_BarCodeRDigit[5] = "1001110";
  #declare Labeller_BarCodeLDigit[6] = "0101111"; #declare Labeller_BarCodeGDigit[6] = "0000101"; #declare Labeller_BarCodeRDigit[6] = "1010000";
  #declare Labeller_BarCodeLDigit[7] = "0111011"; #declare Labeller_BarCodeGDigit[7] = "0010001"; #declare Labeller_BarCodeRDigit[7] = "1000100";
  #declare Labeller_BarCodeLDigit[8] = "0110111"; #declare Labeller_BarCodeGDigit[8] = "0001001"; #declare Labeller_BarCodeRDigit[8] = "1001000";
  #declare Labeller_BarCodeLDigit[9] = "0001011"; #declare Labeller_BarCodeGDigit[9] = "0010111"; #declare Labeller_BarCodeRDigit[9] = "1110100"; 
  // The first digit determines the encoding pattern used for the first 6 digits.
  #declare Labeller_BarCodeFDigit = array[10];   
  #declare Labeller_BarCodeFDigit[0] = "LLLLLL"; 
  #declare Labeller_BarCodeFDigit[1] = "LLGLGG"; 
  #declare Labeller_BarCodeFDigit[2] = "LLGGLG"; 
  #declare Labeller_BarCodeFDigit[3] = "LLGGGL"; 
  #declare Labeller_BarCodeFDigit[4] = "LGLLGG"; 
  #declare Labeller_BarCodeFDigit[5] = "LGGLLG"; 
  #declare Labeller_BarCodeFDigit[6] = "LGGGLL"; 
  #declare Labeller_BarCodeFDigit[7] = "LGLGLG"; 
  #declare Labeller_BarCodeFDigit[8] = "LGLGGL"; 
  #declare Labeller_BarCodeFDigit[9] = "LGGLGL";
  #declare EncodingPattern = Labeller_BarCodeFDigit[PatternDigit]; 
  // Return a union of boxes to represent the bars and the text to represent each numeric digit
  union {
    text {ttf "arial.ttf" str(PatternDigit,0,0) 1,0 scale <CharacterWidth,CharacterWidth,1> translate <BorderWidth,BorderWidth,0>} 
    #local Displacement = BorderWidth+1/15;
    // Start with a double bar separator
    box {<0,ExtendedBarBottom,0>,<BarWidth,ClippingHeight,1> translate x*Displacement} 
    #local Displacement = Displacement + 2*BarWidth;
    box {<0,ExtendedBarBottom,0>,<BarWidth,ClippingHeight,1> translate x*Displacement} 
    #local Displacement = Displacement + BarWidth;
    #local StringIndex = 1;
    #while (StringIndex<=strlen(String))
      #local Character = substr(String,StringIndex,1); 
      text {ttf "arial.ttf" Character 1,0 scale <CharacterWidth,CharacterWidth,1> translate <Displacement+BarWidth,BorderWidth,0>} 
      #local BinaryIndex = 1;
      #if (StringIndex<=6)
        #if (strcmp(substr(EncodingPattern,StringIndex,1),"L")=0)
          #local BinaryString = Labeller_BarCodeLDigit[val(Character)];
        #else
          #local BinaryString = Labeller_BarCodeGDigit[val(Character)];
        #end
      #else
        #local BinaryString = Labeller_BarCodeRDigit[val(Character)];
      #end
      #while (BinaryIndex<=strlen(BinaryString))
        #local Binary = substr(BinaryString,BinaryIndex,1); 
        #if (val(Binary))
          box {<0,BarBottom,0>,<BarWidth,ClippingHeight,1> translate x*Displacement} 
        #end 
        #local Displacement = Displacement + BarWidth;
        #local BinaryIndex = BinaryIndex + 1;
      #end
      #if (StringIndex=6)
        // Add a double bar separator after the first block of 6 digits
        #local Displacement = Displacement + BarWidth;
        box {<0,ExtendedBarBottom,0>,<BarWidth,ClippingHeight,1> translate x*Displacement} 
        #local Displacement = Displacement + 2*BarWidth;
        box {<0,ExtendedBarBottom,0>,<BarWidth,ClippingHeight,1> translate x*Displacement} 
        #local Displacement = Displacement + 2*BarWidth;
      #end
      #local StringIndex = StringIndex + 1;
    #end
    // End with a double bar separator
    box {<0,ExtendedBarBottom,0>,<BarWidth,ClippingHeight,1> translate x*Displacement} 
    #local Displacement = Displacement + 2*BarWidth;
    box {<0,ExtendedBarBottom,0>,<BarWidth,ClippingHeight,1> translate x*Displacement} 
  }
#end  


//**************************//
//       Undef Macro        //
//**************************// 

// This macro undefs all of the global variables used by the Labeller macros
#macro Labeller_Undef() 
  #ifdef(Labeller_ObjectRadius         ) #undef Labeller_ObjectRadius          #end 
  #ifdef(Labeller_ObjectWidth          ) #undef Labeller_ObjectWidth           #end
  #ifdef(Labeller_ObjectDepth          ) #undef Labeller_ObjectDepth           #end
  #ifdef(Labeller_ObjectCornerRadius   ) #undef Labeller_ObjectCornerRadius    #end
  #ifdef(Labeller_PolyhedronFaces      ) #undef Labeller_PolyhedronFaces       #end
  #ifdef(Labeller_TopInnerRadius       ) #undef Labeller_TopInnerRadius        #end
  #ifdef(Labeller_BottomInnerRadius    ) #undef Labeller_BottomInnerRadius     #end
  #ifdef(Labeller_BevelWidth           ) #undef Labeller_BevelWidth            #end
  #ifdef(Labeller_CornerRadius         ) #undef Labeller_CornerRadius          #end
  #ifdef(Labeller_LabelRounding        ) #undef Labeller_LabelRounding         #end
  #ifdef(Labeller_LabelThickness       ) #undef Labeller_LabelThickness        #end
  #ifdef(Labeller_LabelBottom          ) #undef Labeller_LabelBottom           #end
  #ifdef(Labeller_LabelTop             ) #undef Labeller_LabelTop              #end
  #ifdef(Labeller_LabelDesignMode      ) #undef Labeller_LabelDesignMode       #end
  #ifdef(Labeller_LabelWidth           ) #undef Labeller_LabelWidth            #end
  #ifdef(Labeller_LabelArc             ) #undef Labeller_LabelArc              #end
  #ifdef(Labeller_LabelHeight          ) #undef Labeller_LabelHeight           #end
  #ifdef(Labeller_Delta                ) #undef Labeller_Delta                 #end
  #ifdef(Labeller_LabelFile            ) #undef Labeller_LabelFile             #end
  #ifdef(Labeller_WrapTexture          ) #undef Labeller_WrapTexture           #end
//  #ifdef(Labeller_PigmentIntensity     ) #undef Labeller_PigmentIntensity      #end
  #ifdef(Labeller_PlainBack            ) #undef Labeller_PlainBack             #end
  #ifdef(Labeller_PlainBackColor       ) #undef Labeller_PlainBackColor        #end
  #ifdef(Labeller_Normal               ) #undef Labeller_Normal                #end
  #ifdef(Labeller_Finish               ) #undef Labeller_Finish                #end
  #ifdef(Labeller_DefaultCameraLocation) #undef Labeller_DefaultCameraLocation #end
  #ifdef(Labeller_DefaultCameraLook_At ) #undef Labeller_DefaultCameraLook_At  #end
//  #ifdef(       ) #undef         #end
#end


// The Labeller macro is repeatedly redefined to be the default macro for the label being worked on at the time
#ifndef (Labeller) 
  #macro Labeller() 
    Labeller_Polyhedron()
  #end   
#end

