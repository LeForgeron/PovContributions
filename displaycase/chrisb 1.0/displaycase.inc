//
// displaycase.inc
// ---------------
// Created by Chris Bartlett Aug 2009 
//
// This include file contains the 'DisplayCase' macros which can construct a number of 
// differently shaped display cases. 
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The scale is 1 POV-Ray unit = 1 metre
// A display case will typically add about 10 seconds to the render time.
//

// See displaycase.html for a full list of settings and for illustrations of the 
// examples contained in displaycase.pov.

#ifndef (DisplayCase_RandomStream   ) #declare DisplayCase_RandomStream    = seed(1); #end
#ifndef (DisplayCase_Brightness     ) #declare DisplayCase_Brightness      = 1;       #end
#ifndef (DisplayCase_SimpleMaterials) #declare DisplayCase_SimpleMaterials = true;    #end // 1=true=yes 0=false=no

// This macro adds a display case to your scene. In fact this is really just a sort of switch-board
// that works out which macro to call to create the desired display case configuration.
#macro DisplayCase (DisplayCase_Type, DisplayCase_Mount)
  #switch (0)
    #case(strcmp(strlwr(DisplayCase_Mount),"pedestal"))
      DisplayCase_Pedestal(DisplayCase_Type)
    #break
    #case(strcmp(strlwr(DisplayCase_Mount),"tree"))
      DisplayCase_Tree()
    #break
    #case(strcmp(strlwr(DisplayCase_Mount),"wallmount"))
      DisplayCase_WallMount(DisplayCase_Type)
    #break
    #case(strcmp(strlwr(DisplayCase_Mount),"roundpillar"))
      DisplayCase_RoundPillar(DisplayCase_Type)
    #break
    #case(strcmp(strlwr(DisplayCase_Mount),"rectangularpillar"))
      DisplayCase_RectangularPillar(DisplayCase_Type)
    #break
    #case(strcmp(strlwr(DisplayCase_Mount) ,"barrierpost"))
      DisplayCase_BarrierPost()
    #break
    #case(strcmp(strlwr(DisplayCase_Mount) ,"ropehook"))
      DisplayCase_RopeHook()
    #break
    #case(strcmp(strlwr(DisplayCase_Mount) ,""))
      DisplayCase_MakeCase(DisplayCase_Type)
    #break
    #else 
      #error "DisplayCase macro: Unknown parameters specified."
  #end
#end


// This macro interprets the display case type and calls the appropriate macro to generate the case type specified.
// The default display case is "spherical".
#macro DisplayCase_MakeCase(DisplayCase_Type)
   #switch (0)
     #case (strcmp(strlwr(DisplayCase_Type),"spherical"))
       DisplayCase_Spherical ()
     #break
     #case (strcmp(strlwr(DisplayCase_Type),"oblong"))
       DisplayCase_Oblong ()
     #break
     #case (strcmp(strlwr(DisplayCase_Type),"cylindrical"))
       DisplayCase_Cylindrical ()
     #break
     #case (strcmp(strlwr(DisplayCase_Type),"box"))
       DisplayCase_Box ()
     #break
     #else
       #debug "DisplayCase_MakeCase macro: Unknown display case type specified, 'spherical' will be used."
       DisplayCase_Spherical()
   #end
#end


// A wood material that can be used to override the default gold material used to construct the display cases
#macro DisplayCase_WoodMaterial ()                 
  #declare DisplayCase_DefaultMaterial = material {
    texture {
      pigment {wood turbulence 0.05 scale 0.01 rotate -x*90} 
      normal {wood turbulence 0.05 scale 0.01 rotate -x*90} 
      finish {phong 0.5 reflection 0 ambient 0.05*DisplayCase_Brightness} 
      translate y*10*rand(DisplayCase_RandomStream)
    }
  }
#end 


// A marble material that can be used to override the default gold material used to construct the display cases
#macro DisplayCase_MarbleMaterial (DisplayCase_MarbleColor)
  #switch (0)
    #case (strcmp(strlwr(DisplayCase_MarbleColor),"white"))
      #local DisplayCase_MarbleColor1 = 1.5*<1,1,1,0>;
      #local DisplayCase_MarbleColor2 = <-1,-1,-1,0>;
    #break
    #case (strcmp(strlwr(DisplayCase_MarbleColor),"red"))
      #local DisplayCase_MarbleColor1 = <0,0,0,0>;
      #local DisplayCase_MarbleColor2 = <2.5,0,0,0>;
    #break
    #case (strcmp(strlwr(DisplayCase_MarbleColor),"green"))
      #local DisplayCase_MarbleColor1 = <0,0,0,0>;
      #local DisplayCase_MarbleColor2 = <0,1.4,0,0>;
    #break
    #case (strcmp(strlwr(DisplayCase_MarbleColor),"blue"))
      #local DisplayCase_MarbleColor1 = <0,0,0,0>;
      #local DisplayCase_MarbleColor2 = <0,0,5,0>;
    #break
    #case (strcmp(strlwr(DisplayCase_MarbleColor),"yellow"))
      #local DisplayCase_MarbleColor1 = <0,0,0,0>;
      #local DisplayCase_MarbleColor2 = <2,2,0,0>;
    #break
    #else
      #local DisplayCase_MarbleColor1 = <0,0,0,0>;
      #local DisplayCase_MarbleColor2 = <1,1,1,0>;    
  #end
                 
  #declare DisplayCase_DefaultMaterial = material {
    texture {
      pigment {marble 
        color_map {
          [0     color rgbt DisplayCase_MarbleColor1]
          [0.65  color rgbt DisplayCase_MarbleColor1]
          [0.99  color rgbt 0.1*DisplayCase_MarbleColor2+0.9*DisplayCase_MarbleColor1]
          [0.995 color rgbt DisplayCase_MarbleColor2]
          [1.0   color rgbt DisplayCase_MarbleColor2]
        }
        omega 0.8
        lambda 1.5
        turbulence 1
        scale 0.2
      } 
      normal {marble turbulence 0.05 scale 0.01} 
      finish {phong 0.5 reflection 0.1 ambient 0.4*DisplayCase_Brightness}
    }
    translate y*10*rand(DisplayCase_RandomStream)
  }
#end 


// Default settings for the materials used to construct the display cases
#macro DisplayCase_DefaultMaterials ()                 

  // The glass material
  #ifndef (DisplayCase_GlassMaterial)
    #declare DisplayCase_GlassMaterial = material {
      texture {
        pigment {color <1,1,1> filter 0.95}
        finish {
          phong 0.5
          ambient 0
          diffuse 0 
          #if (!DisplayCase_SimpleMaterials)
            reflection 0.1
          #end
        }
      }
      #if (!DisplayCase_SimpleMaterials)
        interior {
          ior 1.005
        } 
      #end
    }
  #end  
    
  #ifndef (DisplayCase_DefaultMaterial)
    #declare DisplayCase_DefaultMaterial = material {
      texture {
        pigment {color <0.3,0.2,0.1>*DisplayCase_Brightness} 
        finish {phong 1 reflection 0.98 ambient 0.05*DisplayCase_Brightness}
      }
    }
  #end  

  // The material around the edge of the top of the base upon which the rim of the glass display case sits.
  #ifndef (DisplayCase_JointMaterial       ) #declare DisplayCase_JointMaterial     = material{texture{pigment{rgb 0}}} #end
  // The material beneath the base on a floor standing display case.
  #ifndef (DisplayCase_KickPlateMaterial   ) #declare DisplayCase_KickPlateMaterial = material{texture{pigment{rgb 0}}} #end

  // The fabric material to line the base of the display case
  #ifndef (DisplayCase_FabricMaterial)
    #declare DisplayCase_FabricMaterial = material {
      texture {
        pigment {color <0.40,0.06,1>*DisplayCase_Brightness}
        normal {bozo 1 scale <0.05,0.75,0.05>}
        finish {diffuse 0.4 phong 0.05 ambient 0.3*DisplayCase_Brightness}
      }
    }  
  #end

  // Default material settings
  #ifndef (DisplayCase_PoleMaterial          ) #declare DisplayCase_PoleMaterial           = material {DisplayCase_DefaultMaterial    } #end
  #ifndef (DisplayCase_ExhibitSupportMaterial) #declare DisplayCase_ExhibitSupportMaterial = material {DisplayCase_DefaultMaterial    } #end
  #ifndef (DisplayCase_BaseMaterial          ) #declare DisplayCase_BaseMaterial           = material {DisplayCase_DefaultMaterial    } #end
  #ifndef (DisplayCase_LabelHolderMaterial   ) #declare DisplayCase_LabelHolderMaterial    = material {DisplayCase_DefaultMaterial    } #end
  #ifndef (DisplayCase_LabelSupportMaterial  ) #declare DisplayCase_LabelSupportMaterial   = material {DisplayCase_LabelHolderMaterial} #end
  #ifndef (DisplayCase_FloorStandMaterial    ) #declare DisplayCase_FloorStandMaterial     = material {DisplayCase_DefaultMaterial    } #end
  #ifndef (DisplayCase_RopeHookMaterial      ) #declare DisplayCase_RopeHookMaterial       = material {DisplayCase_DefaultMaterial    } #end
  #ifndef (DisplayCase_WallPlateMaterial     ) #declare DisplayCase_WallPlateMaterial      = material {DisplayCase_DefaultMaterial    } #end
  #ifndef (DisplayCase_PillarMaterial        ) #declare DisplayCase_PillarMaterial         = material {DisplayCase_DefaultMaterial    } #end
#end 


// This macro adds an information message into the message stream if an array is found to have an innapropriate number of elements.
#macro DisplayCase_ArrayMessage (DisplayCase_OffendingArray, DisplayCase_OffendingArraySize)
  #debug "Warning From DisplayCase_Tree macro:\n" 
  #debug concat("The ",DisplayCase_OffendingArray," array has an array size of ",str(DisplayCase_OffendingArraySize,1,0),", which is inconsistent either with the size of\n")
  #debug "another array or with the quantity of display cases requested via the 'DisplayCase_Quantity' setting.\n"
  #debug concat("Only ",str(DisplayCase_Quantity,1,0)" display cases will be added into this tree of display cases.\n")
#end


// Floor-standing tree of display cases.
// This macro can generate quite a range of different display case configurations, controlled using a set of arrays. 
// By default it generates a single central oblong display case surrounded by 3 spherical display cases. 
// The first half of this macro is just about making sure that configuration variables are set and consistent.
// The second half returns a single object comprised of all of the components of the various display cases and the
// supporting stand.
#macro DisplayCase_Tree()
  DisplayCase_DefaultMaterials() 
  
  #ifndef (DisplayCase_SupportArmReach  ) #declare DisplayCase_SupportArmReach   = 0.45;                           #end
  #ifndef (DisplayCase_SupportRadius    ) #declare DisplayCase_SupportRadius     = 0.04;                           #end

  // The number of cases can be controlled either directly, using the DisplayCase_Quantity variable, or indirectly by 
  // specifying one or more control arrays of the required size.
  // If the number of display cases is not specified, work out a sensible default value.
  #ifndef (DisplayCase_Quantity)
    // If any of the arrays is set, use the smallest array size as the number of display cases.
    #local DisplayCase_Quantity = 1000   ;
    #ifdef (DisplayCase_Types            ) #local DisplayCase_Quantity = min(dimension_size(DisplayCase_Types            ,1),DisplayCase_Quantity); #end
    #ifdef (DisplayCase_JointHeights ) #local DisplayCase_Quantity = min(dimension_size(DisplayCase_JointHeights ,1),DisplayCase_Quantity); #end
    #ifdef (DisplayCase_YRotations       ) #local DisplayCase_Quantity = min(dimension_size(DisplayCase_YRotations       ,1),DisplayCase_Quantity); #end
    #ifdef (DisplayCase_LabelPigments    ) #local DisplayCase_Quantity = min(dimension_size(DisplayCase_LabelPigments    ,1),DisplayCase_Quantity); #end 
    #ifdef (DisplayCase_Exhibits         ) #local DisplayCase_Quantity = min(dimension_size(DisplayCase_Exhibits         ,1),DisplayCase_Quantity); #end 
    #ifdef (DisplayCase_SupportRodHeights) #local DisplayCase_Quantity = min(dimension_size(DisplayCase_SupportRodHeights,1),DisplayCase_Quantity); #end 
    // If none of the arrays was set, generate 4 display cases.
    #if (DisplayCase_Quantity = 1000     ) #local DisplayCase_Quantity = 4; #end
  #end 
    
  // Make sure that all of the required arrays exist.
  #ifndef (DisplayCase_Types            ) #declare DisplayCase_Types             = array[DisplayCase_Quantity];    #end
  #ifndef (DisplayCase_JointHeights ) #declare DisplayCase_JointHeights  = array[DisplayCase_Quantity];    #end
  #ifndef (DisplayCase_YRotations       ) #declare DisplayCase_YRotations        = array[DisplayCase_Quantity];    #end
  #ifndef (DisplayCase_LabelPigments    ) #declare DisplayCase_LabelPigments     = array[DisplayCase_Quantity];    #end
  #ifndef (DisplayCase_Exhibits         ) #declare DisplayCase_Exhibits          = array[DisplayCase_Quantity];    #end
  #ifndef (DisplayCase_SupportRodHeights) #declare DisplayCase_SupportRodHeights = array[DisplayCase_Quantity];    #end
  
  // Issue a warning if there are differently sized arrays about. 
  #if (dimension_size(DisplayCase_Types            ,1) != DisplayCase_Quantity) DisplayCase_ArrayMessage("DisplayCase_Types"            ,dimension_size(DisplayCase_Types            ,1)) #end
  #if (dimension_size(DisplayCase_JointHeights ,1) != DisplayCase_Quantity) DisplayCase_ArrayMessage("DisplayCase_JointHeights" ,dimension_size(DisplayCase_JointHeights ,1)) #end
  #if (dimension_size(DisplayCase_YRotations       ,1) != DisplayCase_Quantity) DisplayCase_ArrayMessage("DisplayCase_YRotations"       ,dimension_size(DisplayCase_YRotations       ,1)) #end
  #if (dimension_size(DisplayCase_LabelPigments    ,1) != DisplayCase_Quantity) DisplayCase_ArrayMessage("DisplayCase_LabelPigments"    ,dimension_size(DisplayCase_LabelPigments    ,1)) #end
  #if (dimension_size(DisplayCase_Exhibits         ,1) != DisplayCase_Quantity) DisplayCase_ArrayMessage("DisplayCase_Exhibits"         ,dimension_size(DisplayCase_Exhibits         ,1)) #end
  #if (dimension_size(DisplayCase_SupportRodHeights,1) != DisplayCase_Quantity) DisplayCase_ArrayMessage("DisplayCase_SupportRodHeights",dimension_size(DisplayCase_SupportRodHeights,1)) #end

  // Set default values as required for the central display case
  #ifndef (DisplayCase_Types[0]           ) #declare DisplayCase_Types      [0]      = "Oblong";                       #end
  #ifndef (DisplayCase_JointHeights[0]) #declare DisplayCase_JointHeights[0] = 1.4;                            #end
  #ifndef (DisplayCase_YRotations[0]      ) #declare DisplayCase_YRotations [0]      = 0;                              #end
  #ifndef (DisplayCase_LabelPigments[0]   )
    #declare DisplayCase_LabelPigments[0]  = pigment {image_map {gif "displaycase_defaultlabel.gif"}}; 
  #end
  
  // Set default values as required for the other display cases
  #local DisplayCase_I = 1;
  #while (DisplayCase_I<DisplayCase_Quantity)
    #ifndef (DisplayCase_Types           [DisplayCase_I]) #declare DisplayCase_Types           [DisplayCase_I] = "Spherical";                                #end
    #ifndef (DisplayCase_JointHeights[DisplayCase_I]) #declare DisplayCase_JointHeights[DisplayCase_I] = DisplayCase_JointHeights[0]-0.4;             #end
    #ifndef (DisplayCase_YRotations      [DisplayCase_I]) #declare DisplayCase_YRotations      [DisplayCase_I] = DisplayCase_I*360/(DisplayCase_Quantity-1); #end
    #ifndef (DisplayCase_LabelPigments   [DisplayCase_I])
      #declare DisplayCase_LabelPigments [DisplayCase_I] = pigment {image_map {gif "displaycase_defaultlabel.gif"}}; 
    #end
  
    #local DisplayCase_I = DisplayCase_I + 1;
  #end

  // Make sure there's not an exhibit left over from any previous macro call.  
  #ifdef (DisplayCase_Exhibit) #undef DisplayCase_Exhibit #end
  
  // Return a union of all of the components of this display case
  union {
    // Build the required number of display cases, the is central, the others encircle it.
    #local DisplayCase_I = 0;
    #while (DisplayCase_I<DisplayCase_Quantity)
      // Pick up the label definition and the contents to be incorporated into this display case
      #declare DisplayCase_LabelPigment = DisplayCase_LabelPigments[DisplayCase_I];
      #ifdef (DisplayCase_Exhibits[DisplayCase_I])
        #local DisplayCase_Exhibit = DisplayCase_Exhibits[DisplayCase_I];
      #end 
      #ifdef(DisplayCase_SupportRodHeights[DisplayCase_I])
         #local DisplayCase_SupportRodHeight = DisplayCase_SupportRodHeights[DisplayCase_I];
      #end 
      // First build the central cylindrical display case
      #if (DisplayCase_I=0) 
        object {
          DisplayCase_Oblong()
          translate y*DisplayCase_JointHeights[DisplayCase_I]
          rotate y*DisplayCase_YRotations[DisplayCase_I]
        } 
      // The other three display cases are spherical
      #else 
        object {
          DisplayCase_Spherical()
          translate <0,DisplayCase_JointHeights[DisplayCase_I],-DisplayCase_SupportArmReach>
          rotate y*DisplayCase_YRotations[DisplayCase_I]
        }
        // The spherical display cases each need a support arm
        object {DisplayCase_SupportArm()
          translate  y*DisplayCase_JointHeights[DisplayCase_I]
          rotate y*DisplayCase_YRotations[DisplayCase_I]
        } 
      #end 
      // Make sure that settings intended for one display case aren't also carried over into the next
      #ifdef (DisplayCase_Exhibit         ) #undef DisplayCase_Exhibit          #end
      #ifdef (DisplayCase_SupportRodHeight) #undef DisplayCase_SupportRodHeight #end
      #local DisplayCase_I = DisplayCase_I+1;
    #end
    
    // The central support
    cylinder {<0,0,0>,<0,DisplayCase_JointHeights[0]+0.01,0>,DisplayCase_SupportRadius material {DisplayCase_PoleMaterial}}
    object {DisplayCase_FloorStand ()}
  }
#end  


// Floor-standing pedestal with a display case on top.
#macro DisplayCase_Pedestal(DisplayCase_Type)
  DisplayCase_DefaultMaterials()
  
  #ifndef (DisplayCase_PostHeight      ) #local DisplayCase_PostHeight       = 1;                            #end
  #ifndef (DisplayCase_PostRadius      ) #local DisplayCase_PostRadius       = 0.03;                         #end
  #ifndef (DisplayCase_BaseHeight      ) #local DisplayCase_BaseHeight       = 1.5*0.08;                     #end
  #ifndef (DisplayCase_BaseRadius      ) #local DisplayCase_BaseRadius       = 1.5*0.12;                     #end
  #ifndef (DisplayCase_BaseInset       ) #local DisplayCase_BaseInset        = 1.5*0.06;                     #end

  // Return a union of all of the components of this display case
  union {
    // The post
    cylinder {<0,0,0>,<0,DisplayCase_PostHeight,0>,DisplayCase_PostRadius material {DisplayCase_PoleMaterial}}
    // The base
    object {DisplayCase_FloorStand ()}
    // The display case
    object {
      DisplayCase_MakeCase(DisplayCase_Type)
      translate y*DisplayCase_PostHeight
    }
  }
#end  


// Floor-standing round pillar with a display case on top.
#macro DisplayCase_RoundPillar(DisplayCase_Type)
  DisplayCase_DefaultMaterials()
  
  #ifndef (DisplayCase_PillarHeight          ) #local DisplayCase_PillarHeight           = 0.9;                          #end
  #ifndef (DisplayCase_PillarKickPlateHeight ) #local DisplayCase_PillarKickPlateHeight  = 0.12;                         #end
  #ifndef (DisplayCase_PillarKickPlateInset  ) #local DisplayCase_PillarKickPlateInset   = 0.01;                         #end
  // Try to establish a sensible default for the radius of the pillar
  #ifndef (DisplayCase_PillarRadius) 
    #ifdef(DisplayCase_Radius) #local DisplayCase_PillarRadius = DisplayCase_Radius; #end 
  #else
    #ifdef(DisplayCase_Width) 
      #ifdef(DisplayCase_Depth)
        #local DisplayCase_PillarRadius = min(DisplayCase_Width,DisplayCase_Depth); 
      #end 
    #end 
  #end
  #ifndef (DisplayCase_PillarRadius          ) #local DisplayCase_PillarRadius           = 0.25;                          #end

  // Return a union of all of the components of this display case
  union {
    // The post
    cylinder {<0,DisplayCase_PillarKickPlateHeight,0>,<0,DisplayCase_PillarHeight,0>,DisplayCase_PillarRadius material {DisplayCase_PillarMaterial}}
    // The kick-plate at the base of the pillar
    #if (DisplayCase_PillarKickPlateHeight>0)
      cylinder {<0,0,0><0,DisplayCase_PillarKickPlateHeight,0> DisplayCase_PillarRadius-DisplayCase_PillarKickPlateInset
        material {DisplayCase_KickPlateMaterial}
      }
    #end
    // The display case
    object {
      DisplayCase_MakeCase(DisplayCase_Type)
      translate y*DisplayCase_PillarHeight
    }
  }
#end  


// Floor-standing rectangular pillar with a display case on top.
#macro DisplayCase_RectangularPillar(DisplayCase_Type)
  DisplayCase_DefaultMaterials()
  
  #ifndef (DisplayCase_PillarHeight          ) #local DisplayCase_PillarHeight           = 0.9;                          #end
  #ifndef (DisplayCase_PillarKickPlateHeight ) #local DisplayCase_PillarKickPlateHeight  = 0.12;                         #end
  #ifndef (DisplayCase_PillarKickPlateInset  ) #local DisplayCase_PillarKickPlateInset   = 0.01;                         #end
  // Try to establish a sensible default for the width and depth of the pillar
  #ifndef (DisplayCase_PillarWidth) #ifdef(DisplayCase_Width ) #local DisplayCase_PillarWidth = DisplayCase_Width ; #end #end
  #ifndef (DisplayCase_PillarWidth) #ifdef(DisplayCase_Radius) #local DisplayCase_PillarWidth = DisplayCase_Radius; #end #end
  #ifndef (DisplayCase_PillarWidth) #local DisplayCase_PillarWidth = 0.3; #end
  #ifndef (DisplayCase_PillarDepth) #ifdef(DisplayCase_Depth ) #local DisplayCase_PillarDepth = DisplayCase_Depth ; #end #end
  #ifndef (DisplayCase_PillarDepth) #ifdef(DisplayCase_Radius) #local DisplayCase_PillarDepth = DisplayCase_Radius; #end #end
  #ifndef (DisplayCase_PillarDepth) #local DisplayCase_PillarDepth = 0.3; #end

  // Return a union of all of the components of this display case
  union {
    // The post
    box {
      <-DisplayCase_PillarWidth/2,DisplayCase_PillarKickPlateHeight,-DisplayCase_PillarDepth/2>
      < DisplayCase_PillarWidth/2,DisplayCase_PillarHeight         , DisplayCase_PillarDepth/2> 
      material {DisplayCase_PillarMaterial}
    }
    // The kick-plate at the base of the pillar
    #if (DisplayCase_PillarKickPlateHeight>0)
    box {
      <-DisplayCase_PillarWidth/2+DisplayCase_PillarKickPlateInset,                                0,-DisplayCase_PillarDepth/2+DisplayCase_PillarKickPlateInset>
      < DisplayCase_PillarWidth/2-DisplayCase_PillarKickPlateInset,DisplayCase_PillarKickPlateHeight, DisplayCase_PillarDepth/2-DisplayCase_PillarKickPlateInset> 
        material {DisplayCase_KickPlateMaterial}
      }
    #end
    // The display case
    object {
      DisplayCase_MakeCase(DisplayCase_Type)
      translate y*DisplayCase_PillarHeight
    }
  }
#end  


// Wall-Mounted display case.
#macro DisplayCase_WallMount(DisplayCase_Type)
  DisplayCase_DefaultMaterials()
  
  #ifndef (DisplayCase_CaseHeight      ) #local DisplayCase_CaseHeight       = 0.2;                          #end
  #ifndef (DisplayCase_ArmLength       ) #local DisplayCase_ArmLength        = 0.35;                         #end
  #ifndef (DisplayCase_BracketHeight   ) #local DisplayCase_BracketHeight    = 0;                            #end

  // Return a union of all of the components of this display case.
  union {
    // The wall plate
    #ifndef (DisplayCase_WallPlateThickness) #local DisplayCase_WallPlateThickness = 0.025;  #end
    object {DisplayCase_WallPlate () translate y*DisplayCase_BracketHeight}
    // The arm connecting the bottom of the display case to the wall bracket.
    #ifndef (DisplayCase_SupportArmRadius) #local DisplayCase_SupportArmRadius = 0.03;   #end
    #ifndef (DisplayCase_ElbowRadius     ) #local DisplayCase_ElbowRadius      = 0.1;    #end
    #local DisplayCase_SupportArmReach  = DisplayCase_ArmLength;
    #local DisplayCase_SupportArmDepth = DisplayCase_CaseHeight-DisplayCase_BracketHeight+DisplayCase_SupportArmRadius;
    object {DisplayCase_SupportArm()
      translate <0,DisplayCase_CaseHeight,0>
    }
    // Add a rounded joint between the support arm and the wall plate 
    difference {
      cylinder{-y*DisplayCase_SupportArmRadius,0,2*DisplayCase_SupportArmRadius}
      torus {2*DisplayCase_SupportArmRadius,DisplayCase_SupportArmRadius}
      rotate -x*90
      translate <0,DisplayCase_BracketHeight,-(DisplayCase_WallPlateThickness+DisplayCase_SupportArmRadius)> 
      material {DisplayCase_PoleMaterial}
    }
    // The display case
    object {
      DisplayCase_MakeCase(DisplayCase_Type)
      translate <0,DisplayCase_CaseHeight,-DisplayCase_ArmLength>
    }
  }
#end      


// A simple post for use as part of a rope barrier.
#macro DisplayCase_BarrierPost()
  DisplayCase_DefaultMaterials()
  
  #ifndef (DisplayCase_PostHeight      ) #local DisplayCase_PostHeight       = 1;                            #end
  #ifndef (DisplayCase_PostRadius      ) #local DisplayCase_PostRadius       = 0.03;                         #end
  #ifndef (DisplayCase_BaseHeight      ) #local DisplayCase_BaseHeight       = 0.08;                         #end
  #ifndef (DisplayCase_BaseRadius      ) #local DisplayCase_BaseRadius       = 0.12;                         #end
  #ifndef (DisplayCase_BaseInset       ) #local DisplayCase_BaseInset        = 0.06;                         #end

  // Return a union of all of the components of this display case
  union {
    // The post
    cylinder {<0,0,0>,<0,DisplayCase_PostHeight,0>,DisplayCase_PostRadius}
    // The base
    object {DisplayCase_FloorStand ()}
    torus {DisplayCase_PostRadius*2/3,DisplayCase_PostRadius/8
      translate <0,DisplayCase_PostHeight-2*DisplayCase_PostRadius, DisplayCase_PostRadius*(1+2/3)>
    } 
    torus {DisplayCase_PostRadius*2/3,DisplayCase_PostRadius/8
      translate <0,DisplayCase_PostHeight-2*DisplayCase_PostRadius,-DisplayCase_PostRadius*(1+2/3)>
    } 
    material {DisplayCase_PoleMaterial}
  }
#end  


// This macro returns a spherical display case
#macro DisplayCase_Spherical () 
  DisplayCase_DefaultMaterials()

  #ifndef (DisplayCase_Radius          ) #local DisplayCase_Radius           = 0.3;                           #end
  #ifndef (DisplayCase_GlassThickness  ) #local DisplayCase_GlassThickness   = 0.008;                         #end
  #ifndef (DisplayCase_JointHeight ) #local DisplayCase_JointHeight  = DisplayCase_Radius*0.43;       #end
  #ifndef (DisplayCase_FabricHeight    ) #local DisplayCase_FabricHeight     = 0.016;                         #end
  #ifndef (DisplayCase_SupportRodRadius) #local DisplayCase_SupportRodRadius = 0.02;                          #end
  #ifndef (DisplayCase_SupportRodHeight) #local DisplayCase_SupportRodHeight = DisplayCase_Radius-DisplayCase_JointHeight;  #end

  // Return a union of all of the components of this display case
  union {
    // The spherical glass case
    difference {
      sphere {<0,0,0> DisplayCase_Radius}
      sphere {<0,0,0> DisplayCase_Radius-DisplayCase_GlassThickness}
      box {
        <-(DisplayCase_Radius+0.001),-(DisplayCase_Radius+0.001)                          ,-(DisplayCase_Radius+0.001)>
        <  DisplayCase_Radius+0.001 ,DisplayCase_JointHeight+0.0001-DisplayCase_Radius,  DisplayCase_Radius+0.001 >
      }
      material {DisplayCase_GlassMaterial}
    }
    // The base of the display case
    intersection {
      sphere {<0,0,0> DisplayCase_Radius+0.0001}
      box {
        <-(DisplayCase_Radius+0.001),-(DisplayCase_Radius+0.001)                   ,-(DisplayCase_Radius+0.001)>
        <  DisplayCase_Radius+0.001 ,DisplayCase_JointHeight-DisplayCase_Radius,  DisplayCase_Radius+0.001 >
        material {DisplayCase_JointMaterial}
      }
      material {DisplayCase_BaseMaterial}
    }
    // The fabric covering the bottom of the inside of the display case
    intersection {
      torus {0.75*DisplayCase_FabricHeight,DisplayCase_FabricHeight 
        translate -y*DisplayCase_FabricHeight
        scale <10,2.5,10> 
        translate (DisplayCase_JointHeight-DisplayCase_Radius+DisplayCase_FabricHeight)*y
      }
      cylinder {
        <0,DisplayCase_JointHeight-DisplayCase_Radius,0>,
        <0,DisplayCase_JointHeight-DisplayCase_Radius+DisplayCase_FabricHeight,0>, 
        sqrt(pow(DisplayCase_Radius-DisplayCase_GlassThickness-0.0001,2)-pow(DisplayCase_JointHeight-DisplayCase_Radius,2))
      }
      material {DisplayCase_FabricMaterial} 
    }
    // The rod supporting the exhibit within the case 
    #if (DisplayCase_SupportRodHeight>0)
      cylinder {
        <0,DisplayCase_JointHeight-DisplayCase_Radius                             ,0>,
        <0,DisplayCase_JointHeight-DisplayCase_Radius+DisplayCase_SupportRodHeight,0>,
        DisplayCase_SupportRodRadius 
        material {DisplayCase_ExhibitSupportMaterial}
      }
    #end 
    // The exhibit (if one is defined)
    #ifdef(DisplayCase_Exhibit) 
      object {DisplayCase_Exhibit translate y*(DisplayCase_JointHeight-DisplayCase_Radius+DisplayCase_SupportRodHeight)}
    #end 
    // Call a macro to generate a label for the exhibit
    object {DisplayCase_Label() translate <0,DisplayCase_JointHeight-DisplayCase_Radius,-0.6*DisplayCase_Radius>}  
    // Move the case so the base is sitting on the origin
    translate y*DisplayCase_Radius
  }
  
#end 


// This macro returns an oblong cylindrical display case
#macro DisplayCase_Oblong () 
  DisplayCase_DefaultMaterials()

  #ifndef (DisplayCase_Height          ) #local DisplayCase_Height           = 1.1;                           #end
  #ifndef (DisplayCase_Radius          ) #local DisplayCase_Radius           = 0.25;                          #end
  #ifndef (DisplayCase_GlassThickness  ) #local DisplayCase_GlassThickness   = 0.008;                         #end
//  #ifndef (DisplayCase_JointHeight ) #local DisplayCase_JointHeight  = DisplayCase_Radius*0.43;       #end
  #ifndef (DisplayCase_FabricHeight    ) #local DisplayCase_FabricHeight     = 0.016;                         #end
  #ifndef (DisplayCase_SupportRodRadius) #local DisplayCase_SupportRodRadius = 0.02;                          #end
  #ifndef (DisplayCase_SupportRodHeight)
    #local DisplayCase_SupportRodHeight = DisplayCase_Height-2.7*DisplayCase_Radius;
  #end

  #local DisplayCase_CylinderHeight = DisplayCase_Height-2*DisplayCase_Radius;

  // Return a union of all of the components of this display case
  union {
    // The oblong glass cover
    difference {
      merge { 
        sphere {<0,DisplayCase_CylinderHeight,0>,DisplayCase_Radius}
        cylinder {<0,0,0><0,DisplayCase_CylinderHeight,0>,DisplayCase_Radius}
      }
      sphere {<0,DisplayCase_CylinderHeight,0>,DisplayCase_Radius-DisplayCase_GlassThickness}
      cylinder {<0,-0.001,0><0,DisplayCase_CylinderHeight,0>,DisplayCase_Radius-DisplayCase_GlassThickness}
      material {DisplayCase_GlassMaterial}
    }

    // The base of the display case
    intersection {
      sphere {<0,0,0> DisplayCase_Radius}
      box {
        <-(DisplayCase_Radius+0.001),-(DisplayCase_Radius+0.001),-(DisplayCase_Radius+0.001)>
        <  DisplayCase_Radius+0.001 , 0                         ,  DisplayCase_Radius+0.001 >
        material {DisplayCase_JointMaterial}
      }
      material {DisplayCase_BaseMaterial}
    }
    // The fabric covering the bottom of the inside of the display case
    intersection {
      torus {0.75*DisplayCase_FabricHeight,DisplayCase_FabricHeight 
        translate -y*DisplayCase_FabricHeight
        scale <10,2.5,10> 
        translate (DisplayCase_FabricHeight)*y
      }
      cylinder {
        <0,0,0>,
        <0,DisplayCase_FabricHeight,0>, 
        DisplayCase_Radius-DisplayCase_GlassThickness
      }
      material {DisplayCase_FabricMaterial} 
    }
    // The rod supporting the exhibit within the case 
    #if (DisplayCase_SupportRodHeight>0)
      cylinder {<0,0,0>,<0,DisplayCase_SupportRodHeight,0>,DisplayCase_SupportRodRadius 
        material {DisplayCase_ExhibitSupportMaterial}
      }
    #end
    // The exhibit (if one is defined)
    #ifdef(DisplayCase_Exhibit) 
      object {DisplayCase_Exhibit translate DisplayCase_SupportRodHeight*y}
    #end
    // Call a macro to generate a label for the exhibit
    object {DisplayCase_Label() translate -z*0.66*DisplayCase_Radius}
    // Move the case so the base is sitting on the origin
    translate y*DisplayCase_Radius
  }
#end


// This macro returns a cylindrical display case
#macro DisplayCase_Cylindrical () 
  DisplayCase_DefaultMaterials()

  #ifndef (DisplayCase_Height          ) #local DisplayCase_Height           = 1;                             #end
  #ifndef (DisplayCase_Radius          ) #local DisplayCase_Radius           = 0.25;                          #end
  #ifndef (DisplayCase_GlassThickness  ) #local DisplayCase_GlassThickness   = 0.008;                         #end
  #ifndef (DisplayCase_JointHeight ) #local DisplayCase_JointHeight  = DisplayCase_Height/6;          #end
  #ifndef (DisplayCase_KickPlateHeight ) #local DisplayCase_KickPlateHeight  = 0;                             #end
  #ifndef (DisplayCase_KickPlateInset  ) #local DisplayCase_KickPlateInset   = 0.01;                          #end
  #ifndef (DisplayCase_CaseLights      ) #local DisplayCase_CaseLights       = 1;                             #end
  #ifndef (DisplayCase_TopRimHeight    ) #local DisplayCase_TopRimHeight     = DisplayCase_Height/12;         #end
  #ifndef (DisplayCase_TopCapHeight    ) #local DisplayCase_TopCapHeight     = DisplayCase_Height/24;         #end
  #ifndef (DisplayCase_RimThickness    ) #local DisplayCase_RimThickness     = 0.0001;                        #end
  #ifndef (DisplayCase_FabricHeight    ) #local DisplayCase_FabricHeight     = 0.016;                         #end
  #ifndef (DisplayCase_SupportRodRadius) #local DisplayCase_SupportRodRadius = 0.02;                          #end

  #local DisplayCase_CylinderHeight = DisplayCase_Height-DisplayCase_JointHeight-DisplayCase_KickPlateHeight;

  #ifndef (DisplayCase_SupportRodHeight)
    #local DisplayCase_SupportRodHeight = DisplayCase_CylinderHeight/2;
  #end


  // Return a union of all of the components of this display case
  union {
    // The oblong glass cover
    difference {
      cylinder {<0,0,0><0,DisplayCase_CylinderHeight,0>,DisplayCase_Radius}
      cylinder {<0,-0.001,0><0,DisplayCase_CylinderHeight-DisplayCase_GlassThickness,0>,DisplayCase_Radius-DisplayCase_GlassThickness}
      material {DisplayCase_GlassMaterial}
    }
    // The base of the display case
    #if (DisplayCase_JointHeight>0)
      cylinder {<0,-DisplayCase_JointHeight,0><0,0,0> DisplayCase_Radius
        material {DisplayCase_BaseMaterial}
      }
    #end
    // The kickplate beneath the base of the display case
    #if (DisplayCase_KickPlateHeight>0)
      cylinder {<0,-DisplayCase_JointHeight-DisplayCase_KickPlateHeight,0><0,-DisplayCase_JointHeight,0> DisplayCase_Radius-DisplayCase_KickPlateInset
        material {DisplayCase_KickPlateMaterial}
      }
    #end
    // The rim around the top of the display case
    #if (DisplayCase_TopRimHeight>0)
      difference {
        cylinder {
          <0,DisplayCase_CylinderHeight-DisplayCase_TopRimHeight,0>
          <0,DisplayCase_CylinderHeight,0> 
          DisplayCase_Radius+DisplayCase_RimThickness
        }
        cylinder {
          <0,DisplayCase_CylinderHeight-DisplayCase_TopRimHeight-0.0001,0>
          <0,DisplayCase_CylinderHeight+0.0001,0> 
          DisplayCase_Radius
        }
        material {DisplayCase_BaseMaterial}
      }
    #end
    // The cap covering the top of the display case
    #if (DisplayCase_TopCapHeight>0)
      intersection {
        cylinder {
          <0,DisplayCase_CylinderHeight,0>
          <0,DisplayCase_CylinderHeight+DisplayCase_TopCapHeight,0> 
          DisplayCase_Radius+DisplayCase_RimThickness
        }
        #local DisplayCase_CapRadius = (pow(DisplayCase_Radius+DisplayCase_RimThickness,2)+pow(DisplayCase_TopCapHeight,2))/
                                       (2*DisplayCase_TopCapHeight);
        sphere {
          <0,DisplayCase_CylinderHeight+DisplayCase_TopCapHeight-DisplayCase_CapRadius,0>
          DisplayCase_CapRadius
        }
        material {DisplayCase_BaseMaterial}
      }
    #end
    // The fabric covering the bottom of the inside of the display case
    intersection {
      torus {0.75*DisplayCase_FabricHeight,DisplayCase_FabricHeight 
        translate -y*DisplayCase_FabricHeight
        scale <10,2.5,10> 
        translate (DisplayCase_FabricHeight)*y
      }
      cylinder {
        <0,0,0>,
        <0,DisplayCase_FabricHeight,0>, 
        DisplayCase_Radius-DisplayCase_GlassThickness
      }
      material {DisplayCase_FabricMaterial} 
    }
    // The rod supporting the exhibit within the case 
    #if (DisplayCase_SupportRodHeight>0)
      cylinder {<0,0,0>,<0,DisplayCase_SupportRodHeight,0>,DisplayCase_SupportRodRadius 
        material {DisplayCase_ExhibitSupportMaterial}
      }
    #end
    // The exhibit (if one is defined)
    #ifdef(DisplayCase_Exhibit) 
      object {DisplayCase_Exhibit translate DisplayCase_SupportRodHeight*y}
    #end
    // Optionally add a small light inside the case
    #if (DisplayCase_CaseLights)
      light_source { <0,DisplayCase_CylinderHeight-DisplayCase_TopRimHeight-0.001,-0.9*DisplayCase_Radius>
        color rgb DisplayCase_CaseLights*<1,1,0.5>
        spotlight radius  5 falloff 12 tightness 0 point_at <0,0.7*DisplayCase_SupportRodHeight,-0.1*DisplayCase_Radius> 
        fade_distance DisplayCase_CylinderHeight fade_power 5
      }
    #end
    // Call a macro to generate a label for the exhibit
    object {DisplayCase_Label() translate -z*0.66*DisplayCase_Radius}
    // Move the case so the base is sitting on the origin
    translate y*(DisplayCase_JointHeight+DisplayCase_KickPlateHeight)
  }
  
#end


// This macro returns a box shaped display case
#macro DisplayCase_Box () 
  DisplayCase_DefaultMaterials()

  #ifndef (DisplayCase_Height          ) #local DisplayCase_Height           = 1;                             #end
  #ifndef (DisplayCase_Width           ) #local DisplayCase_Width            = 0.5;                           #end
  #ifndef (DisplayCase_Depth           ) #local DisplayCase_Depth            = 0.5;                           #end
  #ifndef (DisplayCase_GlassThickness  ) #local DisplayCase_GlassThickness   = 0.008;                         #end
  #ifndef (DisplayCase_JointHeight ) #local DisplayCase_JointHeight  = DisplayCase_Height/6;          #end
  #ifndef (DisplayCase_TopRimHeight    ) #local DisplayCase_TopRimHeight     = DisplayCase_Height/12;         #end
  #ifndef (DisplayCase_TopCapHeight    ) #local DisplayCase_TopCapHeight     = DisplayCase_Height/24;         #end
  #ifndef (DisplayCase_RimThickness    ) #local DisplayCase_RimThickness     = 0.0001;                        #end
  #ifndef (DisplayCase_FabricHeight    ) #local DisplayCase_FabricHeight     = 0.016;                         #end
  #ifndef (DisplayCase_SupportRodRadius) #local DisplayCase_SupportRodRadius = 0.02;                          #end
  #ifndef (DisplayCase_KickPlateHeight ) #local DisplayCase_KickPlateHeight  = 0;                             #end
  #ifndef (DisplayCase_KickPlateInset  ) #local DisplayCase_KickPlateInset   = 0.01;                          #end
  #ifndef (DisplayCase_CaseLights      ) #local DisplayCase_CaseLights       = 1;                             #end

  #local DisplayCase_GlassHeight = DisplayCase_Height-DisplayCase_JointHeight-DisplayCase_KickPlateHeight;
  #ifndef (DisplayCase_SupportRodHeight)
    #local DisplayCase_SupportRodHeight = DisplayCase_GlassHeight/2;
  #end
  #ifndef (DisplayCase_FabricShape     ) #local DisplayCase_FabricShape      = "Rectangular";                 #end

  // Return a union of all of the components of this display case
  union {
    // The box-shaped glass cover
    difference {
      box {
        <-DisplayCase_Width/2,                      0,-DisplayCase_Depth/2>
        < DisplayCase_Width/2,DisplayCase_GlassHeight, DisplayCase_Depth/2>
      }
      box {
        <-(DisplayCase_Width/2)+DisplayCase_GlassThickness,                                           -0.0001,-(DisplayCase_Depth/2)+DisplayCase_GlassThickness>
        < (DisplayCase_Width/2)-DisplayCase_GlassThickness,DisplayCase_GlassHeight-DisplayCase_GlassThickness, (DisplayCase_Depth/2)-DisplayCase_GlassThickness>
      }
      material {DisplayCase_GlassMaterial}
    }
    // The base of the display case
    #if (DisplayCase_JointHeight>0)
      // Top surface, used to create a black joint
      box {
        <-DisplayCase_Width/2,       0,-DisplayCase_Depth/2>
        < DisplayCase_Width/2, 0.00001, DisplayCase_Depth/2>
        material {DisplayCase_JointMaterial}
      }
      box {
        <-DisplayCase_Width/2,-DisplayCase_JointHeight,-DisplayCase_Depth/2>
        < DisplayCase_Width/2,                      0, DisplayCase_Depth/2>
        material {DisplayCase_BaseMaterial}
      }
    #end
    // The kickplate beneath the base of the display case
    #if (DisplayCase_KickPlateHeight>0)
      box {
        <-DisplayCase_Width/2+DisplayCase_KickPlateInset,-DisplayCase_JointHeight                            ,-DisplayCase_Depth/2+DisplayCase_KickPlateInset>
        < DisplayCase_Width/2-DisplayCase_KickPlateInset,-DisplayCase_JointHeight-DisplayCase_KickPlateHeight, DisplayCase_Depth/2-DisplayCase_KickPlateInset>
        material {DisplayCase_KickPlateMaterial}
      }
    #end
    // The rim around the top of the display case
    #if (DisplayCase_TopRimHeight>0)
      difference {
        box {
          <-(DisplayCase_Width/2)-DisplayCase_RimThickness,DisplayCase_GlassHeight-DisplayCase_TopRimHeight,-(DisplayCase_Depth/2)-DisplayCase_RimThickness>
          < (DisplayCase_Width/2)+DisplayCase_RimThickness,DisplayCase_GlassHeight                         , (DisplayCase_Depth/2)+DisplayCase_RimThickness>
        }
        box {
          <-DisplayCase_Width/2,DisplayCase_GlassHeight-0.0001,-DisplayCase_Depth/2>
          < DisplayCase_Width/2,DisplayCase_Height     +0.0001, DisplayCase_Depth/2>
        }
        material {DisplayCase_BaseMaterial}
      }
    #end
    // The cap covering the top of the display case
    #if (DisplayCase_TopCapHeight>0)
      intersection {
        box {
          <-DisplayCase_Width/2,DisplayCase_GlassHeight                         ,-DisplayCase_Depth/2>
          < DisplayCase_Width/2,DisplayCase_GlassHeight+DisplayCase_TopCapHeight, DisplayCase_Depth/2>
        }
        #local DisplayCase_CapRadius = (pow(DisplayCase_Width+DisplayCase_RimThickness,2)+pow(DisplayCase_Depth+DisplayCase_RimThickness,2)+pow(DisplayCase_TopCapHeight,2))/
                                       (2*DisplayCase_TopCapHeight);
        sphere {
          <0,DisplayCase_GlassHeight+DisplayCase_TopCapHeight-DisplayCase_CapRadius,0>
          DisplayCase_CapRadius
        }
        material {DisplayCase_BaseMaterial}
      }
    #end
    // The fabric covering the bottom of the inside of the display case
    intersection {
      torus {0.75*DisplayCase_FabricHeight,DisplayCase_FabricHeight 
        translate -y*DisplayCase_FabricHeight
        scale <30*DisplayCase_Width,2.5,30*DisplayCase_Depth> 
        translate (DisplayCase_FabricHeight)*y
      }
      #if (strcmp(DisplayCase_FabricShape,"Eliptical")=0)
        cylinder {
          <0,0,0>,
          <0,DisplayCase_FabricHeight,0>, 
          DisplayCase_Width/2-DisplayCase_GlassThickness
        }
      #else 
        box {
          <-DisplayCase_Width/2+DisplayCase_GlassThickness,                       0,-DisplayCase_Depth/2+DisplayCase_GlassThickness>
          < DisplayCase_Width/2-DisplayCase_GlassThickness,DisplayCase_FabricHeight, DisplayCase_Depth/2-DisplayCase_GlassThickness>
        }
      #end
      scale <1,1,DisplayCase_Depth/DisplayCase_Width>
      material {DisplayCase_FabricMaterial} 
    } 
    // The rod supporting the exhibit within the case 
    #if (DisplayCase_SupportRodHeight>0)
      cylinder {<0,0,0>,<0,DisplayCase_SupportRodHeight,0>,DisplayCase_SupportRodRadius 
        material {DisplayCase_ExhibitSupportMaterial}
      }
    #end
    // The exhibit (if one is defined)
    #ifdef(DisplayCase_Exhibit) 
      object {DisplayCase_Exhibit translate DisplayCase_SupportRodHeight*y}
    #end
    // Call a macro to generate a label for the exhibit
    object {DisplayCase_Label() translate -z*0.66*DisplayCase_Depth/2}
    // Optionally add small lights inside the case
    #if (DisplayCase_CaseLights)
      #local DisplayCase_LocalLight = light_source { <0,DisplayCase_GlassHeight-DisplayCase_TopRimHeight-0.001,0>
        color rgb DisplayCase_CaseLights*<1,1,0.5>
        spotlight radius  5 falloff 25 tightness 0 point_at <0,DisplayCase_SupportRodHeight,0.5*DisplayCase_Depth> 
        fade_distance DisplayCase_GlassHeight fade_power 5
      }
      light_source {DisplayCase_LocalLight}
      #local DisplayCase_I = 0.1;
      #while (DisplayCase_I<(DisplayCase_Width/2))
        light_source {DisplayCase_LocalLight rotate 40*y*10*DisplayCase_I*(rand(DisplayCase_RandomStream)-0.5) translate <-DisplayCase_I,0,-0.45*DisplayCase_Depth>}
        light_source {DisplayCase_LocalLight rotate 40*y*10*DisplayCase_I*(rand(DisplayCase_RandomStream)-0.5) translate < DisplayCase_I,0,-0.45*DisplayCase_Depth>}
        #local DisplayCase_I = DisplayCase_I+0.1;
      #end
    #end
    // Move the case so the base is sitting on the origin
    translate y*(DisplayCase_JointHeight+DisplayCase_KickPlateHeight)
  }
#end


// This macro returns a label describing an exhibit
#macro DisplayCase_Label() 
  DisplayCase_DefaultMaterials()
  #ifndef (DisplayCase_LabelAngle      ) #local DisplayCase_LabelAngle       = 45;                            #end
  #ifndef (DisplayCase_LabelWidth      ) #local DisplayCase_LabelWidth       = 0.084;                         #end
  #ifndef (DisplayCase_LabelHeight     ) #local DisplayCase_LabelHeight      = 0.054;                         #end
  #ifndef (DisplayCase_LabelRimWidth   ) #local DisplayCase_LabelRimWidth    = 0.008;                         #end
  #ifndef (DisplayCase_LabelRimDepth   ) #local DisplayCase_LabelRimDepth    = 0.005;                         #end
  #ifndef (DisplayCase_LabelPanelHeight) #local DisplayCase_LabelPanelHeight = 0.08;                          #end
  #ifndef (DisplayCase_LabelSuppRadius ) #local DisplayCase_LabelSuppRadius  = 0.003;                         #end
  
  #ifndef (DisplayCase_LabelPigment)
    #local DisplayCase_LabelPigment = pigment {image_map {gif "displaycase_defaultlabel.gif"}}
  #end

  union {
    difference {
      box {
        <-(DisplayCase_LabelRimWidth+DisplayCase_LabelWidth/2),-(DisplayCase_LabelRimWidth+DisplayCase_LabelHeight/2),-DisplayCase_LabelRimDepth>,
        < (DisplayCase_LabelRimWidth+DisplayCase_LabelWidth/2), (DisplayCase_LabelRimWidth+DisplayCase_LabelHeight/2),0>
      }
      box {
        <-DisplayCase_LabelWidth/2,-DisplayCase_LabelHeight/2,-DisplayCase_LabelRimDepth-0.0001>,
        <DisplayCase_LabelWidth/2,DisplayCase_LabelHeight/2,-DisplayCase_LabelRimDepth/2>
      }
      rotate x*DisplayCase_LabelAngle translate <0,DisplayCase_LabelPanelHeight,0>
    }
    // The little rod supporting the label panel
    cylinder {<0,0,0>,<0,DisplayCase_LabelPanelHeight,0>,DisplayCase_LabelSuppRadius}
    // The paper label
    box {
      <-DisplayCase_LabelWidth/2,-DisplayCase_LabelHeight/2,-2*DisplayCase_LabelRimDepth/3>,
      < DisplayCase_LabelWidth/2, DisplayCase_LabelHeight/2,-DisplayCase_LabelRimDepth/2>
      pigment {DisplayCase_LabelPigment
        translate <-0.5,-0.5,-DisplayCase_LabelRimDepth>
        scale <DisplayCase_LabelWidth,DisplayCase_LabelHeight,1>
      }
      finish {ambient 0.4*DisplayCase_Brightness}
      rotate x*DisplayCase_LabelAngle translate <0,DisplayCase_LabelPanelHeight,0>
    }
    material {DisplayCase_LabelHolderMaterial}
  }
#end  


// This macro returns a horizontal support arm to hold a display case. This arm turns up at the end to 
// join onto the base of the display case. 
#macro DisplayCase_SupportArm ()
  DisplayCase_DefaultMaterials()
  #ifndef (DisplayCase_SupportArmTop   ) #local DisplayCase_SupportArmTop    = 0;      #end
  #ifndef (DisplayCase_SupportArmReach ) #local DisplayCase_SupportArmReach  = 0.45;   #end
  #ifndef (DisplayCase_SupportArmRadius) #local DisplayCase_SupportArmRadius = 0.04;   #end
  #ifndef (DisplayCase_SupportArmDepth ) #local DisplayCase_SupportArmDepth  = 0.19;   #end
  #ifndef (DisplayCase_ElbowRadius     ) #local DisplayCase_ElbowRadius      = 0.1;    #end

  #local DisplayCase_ElbowTop = DisplayCase_SupportArmTop-DisplayCase_SupportArmDepth+DisplayCase_SupportArmRadius+DisplayCase_ElbowRadius;
  union { 
    // Join the bottom of the case to the elbow of the support arm.
    cylinder {
      <0,DisplayCase_SupportArmTop+0.04,0>,
      <0,DisplayCase_ElbowTop,0>,
      DisplayCase_SupportArmRadius
      material {DisplayCase_PoleMaterial}
    } 
    // Join the elbow to the anchor point on the wall, column or central support.
    cylinder {
      <0,0,DisplayCase_ElbowRadius>,
      <0,0,DisplayCase_SupportArmReach>,
      DisplayCase_SupportArmRadius 
      material {DisplayCase_PoleMaterial rotate x*90}
      translate y*(DisplayCase_ElbowTop-DisplayCase_ElbowRadius)
    }
    // Add the elbow
    intersection {
      torus {DisplayCase_ElbowRadius,DisplayCase_SupportArmRadius}
      box {
        <0,-DisplayCase_SupportArmRadius-0.0001,0>
        <DisplayCase_ElbowRadius+DisplayCase_SupportArmRadius,DisplayCase_SupportArmRadius+0.0001,-DisplayCase_ElbowRadius-DisplayCase_SupportArmRadius>
      }
      material {DisplayCase_PoleMaterial rotate <90,45,0>}
      translate <0,0,DisplayCase_ElbowRadius>
      rotate -z*90 
      translate y*(DisplayCase_ElbowTop)
    }
    material {DisplayCase_PoleMaterial}
    translate -DisplayCase_SupportArmReach*z
  }
#end


// This macro returns an object intended to represent a floor-standing base to support a free-stand display case.
#macro DisplayCase_FloorStand ()   
  DisplayCase_DefaultMaterials()

  #ifndef (DisplayCase_BaseHeight      ) #local DisplayCase_BaseHeight       = 0.24;   #end
  #ifndef (DisplayCase_BaseRadius      ) #local DisplayCase_BaseRadius       = 0.30;   #end
  #ifndef (DisplayCase_BaseInset       ) #local DisplayCase_BaseInset        = 0.18;   #end

  difference {                                                                                     
    cylinder {<0,0,0>,<0,DisplayCase_BaseHeight,0>,DisplayCase_BaseRadius}
    torus {DisplayCase_BaseRadius,DisplayCase_BaseInset translate y*DisplayCase_BaseHeight}
    material {DisplayCase_FloorStandMaterial}
  }
#end


// This macro returns a connecting cup to connect the end of a rope to a barrier post.
#macro DisplayCase_RopeHook ()   
  DisplayCase_DefaultMaterials()

  #ifndef (DisplayCase_CupRadius      ) #local DisplayCase_CupRadius        = 0.03;                        #end
  #ifndef (DisplayCase_CupLength      ) #local DisplayCase_CupLength        = 2*DisplayCase_CupRadius;     #end
  #ifndef (DisplayCase_EdgeRadius     ) #local DisplayCase_EdgeRadius       = 0.75*DisplayCase_CupRadius;  #end
  #ifndef (DisplayCase_RingThickness  ) #local DisplayCase_RingThickness    = DisplayCase_CupRadius*0.15;  #end
  #ifndef (DisplayCase_RingRadius     ) #local DisplayCase_RingRadius       = DisplayCase_CupRadius-2*DisplayCase_RingThickness;  #end

  union {
    difference {                                                                                     
      cylinder {<0, 0    ,0>,<0,DisplayCase_CupLength-DisplayCase_EdgeRadius,0>,DisplayCase_CupRadius}
      cylinder {<0,-0.001,0>,<0,DisplayCase_CupLength-DisplayCase_EdgeRadius,0>,DisplayCase_CupRadius*0.95}
    }
    // Add a rounded edge to the end of the cup.
    torus {DisplayCase_CupRadius-DisplayCase_EdgeRadius,DisplayCase_EdgeRadius translate y*(DisplayCase_CupLength-DisplayCase_EdgeRadius)}
    // Fill the recess left by the torus.
    cylinder {<0,DisplayCase_CupLength-DisplayCase_EdgeRadius,0>,<0,DisplayCase_CupLength,0>,DisplayCase_CupRadius-DisplayCase_EdgeRadius}
    // Add a connecting ring
    torus {DisplayCase_RingRadius,DisplayCase_RingThickness rotate z*90 translate y*(DisplayCase_CupLength+DisplayCase_CupRadius*0.7)}
    material {DisplayCase_RopeHookMaterial}
  }
#end


// This macro returns an object intended to represent a fixing plate for bolting a supporting arm to the wall.
#macro DisplayCase_WallPlate ()   
  DisplayCase_DefaultMaterials()

  #ifndef (DisplayCase_WallPlateThickness) #local DisplayCase_WallPlateThickness = 0.025;  #end
  #ifndef (DisplayCase_WallPlateRadius   ) #local DisplayCase_WallPlateRadius    = 0.12;   #end
  #ifndef (DisplayCase_WallPlateInset    ) #local DisplayCase_WallPlateInset     = 0.04;   #end
  
  // The Wall Plate
  difference {                                                                                     
    cylinder {<0,0,-DisplayCase_WallPlateThickness>,<0,0,0>,DisplayCase_WallPlateRadius}
    torus {DisplayCase_WallPlateRadius,DisplayCase_WallPlateInset scale <1,0.5,1> rotate -x*90 translate -z*DisplayCase_WallPlateThickness}
    material {DisplayCase_WallPlateMaterial}
  }
#end


// This macro returns a simple wood panel texture used in some of the examples to represent a wooden floor.
#macro DisplayCase_SampleFloorTexture()
  texture {
    pigment {
      wood
      turbulence 0.025
      color_map {
        [0.222         color rgb <0.808 , 0.671 , 0.251>]
        [0.222, 0.342  color rgb <0.808 , 0.671 , 0.251>
                       color rgb <0.600 , 0.349 , 0.043>]
        [0.342, 0.393  color rgb <0.600 , 0.349 , 0.043>
                       color rgb <0.808 , 0.671 , 0.251>]
        [0.709, 0.821  color rgb <0.808 , 0.671 , 0.251>
                       color rgb <0.533 , 0.298 , 0.027>]
        [0.821, 1      color rgb <0.533 , 0.298 , 0.027>
                       color rgb <0.808 , 0.671 , 0.251>]
      } 
      scale 0.1
      translate <10, 0, 0>
    }
    finish { phong 0.5 ambient 0.05}
  }
  
  // Yellow_Pine layer 2
  texture {
    pigment {
      wood
      turbulence 0.015
      color_map {
        [0.000, 0.120   color rgbf <1.000 , 1.000 , 1.000 , 1.000>
                        color rgbf <0.702 , 0.412 , 0.118 , 0.608>]
        [0.120, 0.231   color rgbf <0.702 , 0.412 , 0.118 , 0.608>
                        color rgbf <0.702 , 0.467 , 0.118 , 0.608>]
        [0.231, 0.496   color rgbf <0.702 , 0.467 , 0.118 , 0.608>
                        color rgbf <1.000 , 1.000 , 1.000 , 1.000>]
        [0.701, 0.829   color rgbf <1.000 , 1.000 , 1.000 , 1.000>
                        color rgbf <0.702 , 0.467 , 0.118 , 0.608>]
        [0.829, 1       color rgbf <0.702 , 0.467 , 0.118 , 0.608>
                        color rgbf <1.000 , 1.000 , 1.000 , 1.000>]
      }
      scale 0.5 
      translate <10, 0, 0>
    }
    finish { phong 0.5 ambient 0 }
  }
  texture {     
    pigment { gradient x
      color_map {
        [0.025 color rgb  <0  ,0   ,0       >]
        [0.025 color rgbf <0.9,0.85,0.85,1  >]
        [0.03  color rgbf <0.5,0.4 ,0.2 ,0.6>]
        [0.1   color rgbf <1  ,1,1 ,1       >]
        [0.9   color rgbf <1  ,1   ,1   ,1  >]
        [0.03  color rgbf <0.5,0.4 ,0.2 ,0.6>]
        [0.975 color rgbf <0.9,0.85,0.85,1  >]
        [0.975 color rgb  <0  ,0   ,0>]
      }
      turbulence 0
      scale <0.163,1,1>
    }
    finish { phong 0.5 ambient 0 }
  }
#end  

// A sample object that can be used as an exhibit for testing and demo purposes.
#macro DisplayCase_SampleExhibit (DisplayCase_ExhibitName)
  #switch (0)
    #case (strcmp(strlwr(DisplayCase_ExhibitName),"white"))
      #local DisplayCase_MarbleColor1 = 0;
      #local DisplayCase_MarbleColor2 = <2,2,2,0>;
    #break
    #case (strcmp(strlwr(DisplayCase_ExhibitName),"flame"))
      #local DisplayCase_MarbleColor1 = 0;
      #local DisplayCase_MarbleColor2 = <2.5,1,0,0>;
    #break
    #case (strcmp(strlwr(DisplayCase_ExhibitName),"red"))
      #local DisplayCase_MarbleColor1 = 0;
      #local DisplayCase_MarbleColor2 = <2.5,0,0,0>;
    #break
    #case (strcmp(strlwr(DisplayCase_ExhibitName),"green"))
      #local DisplayCase_MarbleColor1 = 0;
      #local DisplayCase_MarbleColor2 = <0,1.4,0,0>;
    #break
    #case (strcmp(strlwr(DisplayCase_ExhibitName),"blue"))
      #local DisplayCase_MarbleColor1 = <-1,-1,-1,0>;
      #local DisplayCase_MarbleColor2 = <0,1,2,0>;
    #break
    #case (strcmp(strlwr(DisplayCase_ExhibitName),"yellow"))
      #local DisplayCase_MarbleColor1 = 0;
      #local DisplayCase_MarbleColor2 = <2,2,0,0>;
    #break
    #case (strcmp(strlwr(DisplayCase_ExhibitName),"violet"))
      #local DisplayCase_MarbleColor1 = 0;
      #local DisplayCase_MarbleColor2 = <1,0,2,0>;
    #break
    #else
      #local DisplayCase_MarbleColor1 = 1;
      #local DisplayCase_MarbleColor2 = <1,1,1,0>;    
  #end
                 
  sphere {0,0.1
    texture { 
      pigment {marble 
        color_map {
          [0     color rgbt 1]
          [0.1   color rgbt DisplayCase_MarbleColor1]
          [0.7   color rgbt DisplayCase_MarbleColor1]
          [0.8   color rgbt 0.1*DisplayCase_MarbleColor2+0.9*DisplayCase_MarbleColor1]
          [0.9   color rgbt DisplayCase_MarbleColor2]
          [1.0   color rgbt DisplayCase_MarbleColor2]
        }
        omega 0.8
        lambda 1.5
        turbulence 1
        scale 0.2
      } 
      normal {marble turbulence 0.05 scale 0.01} 
      finish {phong 0.5 reflection 0.1 ambient 0.4*DisplayCase_Brightness}
      translate y*10*rand(DisplayCase_RandomStream)
    }
  }
#end 


// This macro undefines variables that could have been defined by the 
// DisplayCase macros or by the user to control them.
#macro DisplayCase_Undef () 

  #ifdef (DisplayCase_ArmLength                ) #undef DisplayCase_ArmLength                  #end
  #ifdef (DisplayCase_BaseHeight               ) #undef DisplayCase_BaseHeight                 #end
  #ifdef (DisplayCase_JointHeights         ) #undef DisplayCase_JointHeights           #end
  #ifdef (DisplayCase_BaseInset                ) #undef DisplayCase_BaseInset                  #end
  #ifdef (DisplayCase_JointHeight          ) #undef DisplayCase_JointHeight            #end
  #ifdef (DisplayCase_BaseMaterial             ) #undef DisplayCase_BaseMaterial               #end
  #ifdef (DisplayCase_BaseRadius               ) #undef DisplayCase_BaseRadius                 #end
  #ifdef (DisplayCase_BracketHeight            ) #undef DisplayCase_BracketHeight              #end
  #ifdef (DisplayCase_CaseHeight               ) #undef DisplayCase_CaseHeight                 #end
  #ifdef (DisplayCase_CaseLights               ) #undef DisplayCase_CaseLights                 #end
  #ifdef (DisplayCase_CupLength                ) #undef DisplayCase_CupLength                  #end
  #ifdef (DisplayCase_CupRadius                ) #undef DisplayCase_CupRadius                  #end
  #ifdef (DisplayCase_DefaultMaterial          ) #undef DisplayCase_DefaultMaterial            #end
  #ifdef (DisplayCase_Depth                    ) #undef DisplayCase_Depth                      #end
  #ifdef (DisplayCase_EdgeRadius               ) #undef DisplayCase_EdgeRadius                 #end
  #ifdef (DisplayCase_ElbowRadius              ) #undef DisplayCase_ElbowRadius                #end
  #ifdef (DisplayCase_ExhibitSupportMaterial   ) #undef DisplayCase_ExhibitSupportMaterial     #end
  #ifdef (DisplayCase_Exhibit                  ) #undef DisplayCase_Exhibit                    #end
  #ifdef (DisplayCase_Exhibits                 ) #undef DisplayCase_Exhibits                   #end
  #ifdef (DisplayCase_FabricHeight             ) #undef DisplayCase_FabricHeight               #end
  #ifdef (DisplayCase_FabricMaterial           ) #undef DisplayCase_FabricMaterial             #end
  #ifdef (DisplayCase_FabricShape              ) #undef DisplayCase_FabricShape                #end
  #ifdef (DisplayCase_FloorStandMaterial       ) #undef DisplayCase_FloorStandMaterial         #end
  #ifdef (DisplayCase_GlassMaterial            ) #undef DisplayCase_GlassMaterial              #end
  #ifdef (DisplayCase_GlassThickness           ) #undef DisplayCase_GlassThickness             #end
  #ifdef (DisplayCase_Height                   ) #undef DisplayCase_Height                     #end
  #ifdef (DisplayCase_JointMaterial            ) #undef DisplayCase_JointMaterial              #end
  #ifdef (DisplayCase_KickPlateHeight          ) #undef DisplayCase_KickPlateHeight            #end
  #ifdef (DisplayCase_KickPlateInset           ) #undef DisplayCase_KickPlateInset             #end
  #ifdef (DisplayCase_KickPlateMaterial        ) #undef DisplayCase_KickPlateMaterial          #end
  #ifdef (DisplayCase_LabelAngle               ) #undef DisplayCase_LabelAngle                 #end
  #ifdef (DisplayCase_LabelHeight              ) #undef DisplayCase_LabelHeight                #end
  #ifdef (DisplayCase_LabelHolderMaterial      ) #undef DisplayCase_LabelHolderMaterial        #end
  #ifdef (DisplayCase_LabelPanelHeight         ) #undef DisplayCase_LabelPanelHeight           #end
  #ifdef (DisplayCase_LabelPigment             ) #undef DisplayCase_LabelPigment               #end
  #ifdef (DisplayCase_LabelPigments            ) #undef DisplayCase_LabelPigments              #end
  #ifdef (DisplayCase_LabelRimDepth            ) #undef DisplayCase_LabelRimDepth              #end
  #ifdef (DisplayCase_LabelRimWidth            ) #undef DisplayCase_LabelRimWidth              #end
  #ifdef (DisplayCase_LabelSuppRadius          ) #undef DisplayCase_LabelSuppRadius            #end
  #ifdef (DisplayCase_LabelSupportMaterial     ) #undef DisplayCase_LabelSupportMaterial       #end
  #ifdef (DisplayCase_LabelWidth               ) #undef DisplayCase_LabelWidth                 #end
  #ifdef (DisplayCase_PillarDepth              ) #undef DisplayCase_PillarDepth                #end
  #ifdef (DisplayCase_PillarHeight             ) #undef DisplayCase_PillarHeight               #end
  #ifdef (DisplayCase_PillarKickPlateHeight    ) #undef DisplayCase_PillarKickPlateHeight      #end
  #ifdef (DisplayCase_PillarKickPlateInset     ) #undef DisplayCase_PillarKickPlateInset       #end
  #ifdef (DisplayCase_PillarMaterial           ) #undef DisplayCase_PillarMaterial             #end
  #ifdef (DisplayCase_PillarRadius             ) #undef DisplayCase_PillarRadius               #end
  #ifdef (DisplayCase_PillarWidth              ) #undef DisplayCase_PillarWidth                #end
  #ifdef (DisplayCase_PoleMaterial             ) #undef DisplayCase_PoleMaterial               #end
  #ifdef (DisplayCase_PostHeight               ) #undef DisplayCase_PostHeight                 #end
  #ifdef (DisplayCase_PostRadius               ) #undef DisplayCase_PostRadius                 #end
  #ifdef (DisplayCase_Quantity                 ) #undef DisplayCase_Quantity                   #end
  #ifdef (DisplayCase_Radius                   ) #undef DisplayCase_Radius                     #end
  #ifdef (DisplayCase_RimThickness             ) #undef DisplayCase_RimThickness               #end
  #ifdef (DisplayCase_RingRadius               ) #undef DisplayCase_RingRadius                 #end
  #ifdef (DisplayCase_RingThickness            ) #undef DisplayCase_RingThickness              #end
  #ifdef (DisplayCase_RopeHookMaterial         ) #undef DisplayCase_RopeHookMaterial           #end
  #ifdef (DisplayCase_SupportArmDepth          ) #undef DisplayCase_SupportArmDepth            #end
  #ifdef (DisplayCase_SupportArmRadius         ) #undef DisplayCase_SupportArmRadius           #end
  #ifdef (DisplayCase_SupportArmReach          ) #undef DisplayCase_SupportArmReach            #end
  #ifdef (DisplayCase_SupportArmTop            ) #undef DisplayCase_SupportArmTop              #end
  #ifdef (DisplayCase_SupportRadius            ) #undef DisplayCase_SupportRadius              #end
  #ifdef (DisplayCase_SupportRodHeight         ) #undef DisplayCase_SupportRodHeight           #end
  #ifdef (DisplayCase_SupportRodHeights        ) #undef DisplayCase_SupportRodHeights          #end
  #ifdef (DisplayCase_SupportRodRadius         ) #undef DisplayCase_SupportRodRadius           #end
  #ifdef (DisplayCase_TopCapHeight             ) #undef DisplayCase_TopCapHeight               #end
  #ifdef (DisplayCase_TopRimHeight             ) #undef DisplayCase_TopRimHeight               #end
  #ifdef (DisplayCase_Types                    ) #undef DisplayCase_Types                      #end
  #ifdef (DisplayCase_WallPlateInset           ) #undef DisplayCase_WallPlateInset             #end
  #ifdef (DisplayCase_WallPlateMaterial        ) #undef DisplayCase_WallPlateMaterial          #end
  #ifdef (DisplayCase_WallPlateRadius          ) #undef DisplayCase_WallPlateRadius            #end
  #ifdef (DisplayCase_WallPlateThickness       ) #undef DisplayCase_WallPlateThickness         #end
  #ifdef (DisplayCase_Width                    ) #undef DisplayCase_Width                      #end
  #ifdef (DisplayCase_YRotations               ) #undef DisplayCase_YRotations                 #end





#end     