// Persistence of Vision Ray Tracer Scene Description File
// File: swivelstool.inc
// Vers: 3.6 (POV-Ray syntax version)
// Desc: A common style of swivel stool sitting at origin along the positive Y axis. Units are in inches. It lacks bolts.
// Desc: This is a very old file which was originally modeled with R/H z-up coordinates, but the individual components
// Desc: have now been rotated and flipped to L/H y-up coordinates.
// Date: Last Update: Mar 28, 2008
// Auth: Charles Coyle 
// This file is licensed under the terms of the CC-LGPL 

#local SwivelStool_Temp_Vers = version; #version 3.6;

// This version of this line is for complete lib.povray.org compliance:
#ifdef(SwivelStool_View_POV_Include_Stack)  #debug "including swivelstool.inc\n" #end
// but this line might be more functional if used alongside POV-Ray distro files:
// #ifdef(View_POV_Include_Stack)  #debug "including swivelstool.inc\n" #end


// This file can be rendered independently or used as an include.  Declaring a string variable Main_Scene_File containing
// the name of the primary file to render is one way to let "swivelstool.inc" know whether to render a demo scene.
//
// To use this file as intended, uncomment the following line.  It can be left that way.  It is distributed commented-out 
// for complete lib.povray.org compliance.  Either choice will not affect this file's use as an include file if 
// Main_Scene_File or certain common variables (Red) are defined prior to including "swivelstool.inc". 
//
//#ifndef(Main_Scene_File) #declare Main_Scene_File = "swivelstool.inc" #ifdef(Red)#declare Main_Scene_File="\nRed already defined\n"#end  #ifdef(camera)#declare Main_Scene_File="\nCamera already defined\n"#end  #if(!strcmp(Main_Scene_File,"swivelstool.inc")) #local SwivelStool_Render_Demo_Switch=yes;#end   #debug Main_Scene_File #end
//
//
// Uncomment the line above to render this file as a self-rendering demo. 
// Modifying the line below will work too but is not recomended.
#ifndef(SwivelStool_Render_Demo_Switch) #local SwivelStool_Render_Demo_Switch = no; #end //There should be no need to change this to a yes.










// *********************************************************************************************************************
// ***************** A Very Few Settings *******************************************************************************
// Note that many dimensions are hard coded.  (This is a modified, but very old file.)

// If this is no, then default textures won't be created and "metals.inc" won't be needed.
#ifndef(SwivelStool_Make_Default_Textures) #local SwivelStool_Make_Default_Textures = yes; #end

// If this is no, then pure untextured unions will be created whether textures are defined or not.
#ifndef(SwivelStool_Apply_Textures)        #local SwivelStool_Apply_Textures        = yes; #end

// Avoid scaling each instance.  (Inches are default.)
#ifndef(SwivelStool_Scale) #local SwivelStool_Scale = 1; #end 

// You can spin it if you can see the texture well enough. 
#ifndef(SwivelStool_Top_Spin_Angle)  #local SwivelStool_Top_Spin_Angle  = 0; #end


#ifndef(SwivelStool_Dome_Height)     #local SwivelStool_Dome_Height     = 1; #end
#ifndef(SwivelStool_Radius)          #local SwivelStool_Radius          = 7; #end
#ifndef(SwivelStool_Leg_Bend_Radius) #local SwivelStool_Leg_Bend_Radius = 5; #end // High values will cause an error.

#local SwivelStool_Draw_plane_if_self_demo = no; 


// ***************** A Very Few Settings *******************************************************************************
// *********************************************************************************************************************











#if(SwivelStool_Make_Default_Textures) //...then build textures using standard POV-Ray includes.
     #ifndef( T_Chrome_1C ) #include "metals.inc"  #end        
     //
     #ifndef( SwivelStool_Top_Texture )
          #declare SwivelStool_Top_Texture = 
                texture { 
                         pigment{rgb <.1,.1,.1>} 
                         finish{phong .3 ambient 0 specular .3} 
                         normal{agate .1 scale .5*<1,1,2>}   
                } //end texture SwivelStool_Top_Texture
     #end //end #ifndef( SwivelStool_Top_Texture )
    //
    #declare SwivelStool_Metal_Texture = texture{  T_Chrome_1C finish{ambient 0} }
    //
    #declare SwivelStool_Foot_Texture  = texture{ pigment{rgb <.1,.1,.1>} finish{ambient 0} }
#end //end #if(SwivelStool_Make_Default_Textures)





// Since this file was originally written for right-hand, z-up coordinates and left-hand are more common, the following
// transformation is applied to all components:
#local SwivelStool_RH_To_LH_Transform = transform {rotate x * -90 scale <1,1,-1>*SwivelStool_Scale }


//#ifndef(SwivelStool_Dome_Height)    #local SwivelStool_Dome_Height    = 1; #end
//#ifndef(SwivelStool_Radius)         #local SwivelStool_Radius         = 7; #end
#local SwivelStool_B    = atan2(SwivelStool_Radius,SwivelStool_Dome_Height);
#local SwivelStool_Hyp  = sqrt( pow(SwivelStool_Dome_Height,2) + pow(SwivelStool_Radius,2) );
#local SwivelStool_Dist = .5*SwivelStool_Hyp*tan(SwivelStool_B);
#local SwivelStool_Dome_Radius = sqrt( pow(SwivelStool_Dist,2) + pow(SwivelStool_Hyp/2,2)  );

#declare SwivelStool_Top =
union {
       cylinder { <0,0,0>, <0,0,3+(1/2)> SwivelStool_Radius }
       torus { SwivelStool_Radius, (3/32) rotate x*90 }
       torus { SwivelStool_Radius, (3/32) rotate x*90 translate z*(3+(1/2))  }
       sphere {
                <0,0,-SwivelStool_Dome_Radius + SwivelStool_Dome_Height + 3+(1/2)>,   SwivelStool_Dome_Radius
                clipped_by{ plane{ z, 3+(1/2) inverse }  }
                #if(SwivelStool_Apply_Textures) texture{SwivelStool_Top_Texture} #end
              }
       #if(SwivelStool_Apply_Textures) texture {SwivelStool_Top_Texture} #end
       translate z*(25+(3/4)) 
       rotate <0,0,SwivelStool_Top_Spin_Angle>
       transform {SwivelStool_RH_To_LH_Transform}
} //end union SwivelStool_Top



//#ifndef(SwivelStool_Leg_Bend_Radius) #local SwivelStool_Leg_Bend_Radius = 5; #end
#local SwivelStool_Half_Distance_Between_Arc_Centers = sqrt( pow(11+(1/2)-3-(3/4),2) + pow( 7+SwivelStool_Leg_Bend_Radius - (9+(5/8)-SwivelStool_Leg_Bend_Radius),2)   ) /2; 
#local Half_Lenth_Of_Tangent_Piece = sqrt( pow(SwivelStool_Half_Distance_Between_Arc_Centers,2)-pow(SwivelStool_Leg_Bend_Radius,2)  );
#local SwivelStool_Slant_Angle_In_Rad = atan2( 11+(1/2)-3-(3/4), (7+SwivelStool_Leg_Bend_Radius) - (9+(5/8)-SwivelStool_Leg_Bend_Radius)   ) + atan2(SwivelStool_Leg_Bend_Radius,Half_Lenth_Of_Tangent_Piece);
#local SwivelStool_Slant_Angle_In_Deg = SwivelStool_Slant_Angle_In_Rad * 180/pi    -90;


#declare SwivelStool_Foot =  
cone { <9+(5/8),0,0>, 5/8,  <9+(5/8),0,7/8>, 17/32 
       #if(SwivelStool_Apply_Textures) texture {SwivelStool_Foot_Texture}  #end
       transform {SwivelStool_RH_To_LH_Transform}
} //end cone SwivelStool_Foot



#declare SwivelStool_Single_Leg =
union{
              cylinder { <0,0,24+(1/2)>, <4,0,24+(1/2)>, 1/2  } //top horizontal piece
              cylinder { <7,0,21+(1/2)>, <7,0,11+(1/2)>, 1/2  } //upper vertical piece
              cylinder { <9+(5/8),0,3+(3/4)>, <9+(5/8),0,0>, 1/2  } //lower vertical piece
              cylinder { <SwivelStool_Leg_Bend_Radius,0,0>, <SwivelStool_Leg_Bend_Radius,0,Half_Lenth_Of_Tangent_Piece*2>, 1/2 rotate y*(-SwivelStool_Slant_Angle_In_Deg) translate <9+(5/8)-SwivelStool_Leg_Bend_Radius,0,(3+(3/4))>  }
              torus { 3, 1/2  
                      clipped_by { plane{z, 0 inverse}  }
                      clipped_by { plane{x, 0 inverse}  }
                      translate <4,0,21+(1/2)>
                    }//end torus
              torus { SwivelStool_Leg_Bend_Radius, 1/2  
                      clipped_by { plane{z, 0 rotate y*(-SwivelStool_Slant_Angle_In_Deg) }  }
                      clipped_by { plane{z, 0 inverse}  }
                      translate <9+(5/8)-SwivelStool_Leg_Bend_Radius,0,3+(3/4)>
                      //pigment{Green}
                    }//end torus
              torus { SwivelStool_Leg_Bend_Radius, 1/2  
                      clipped_by { plane{z, 0 inverse rotate y*(-SwivelStool_Slant_Angle_In_Deg) }  }
                      clipped_by { plane{z, 0 }  }
                      translate <7+SwivelStool_Leg_Bend_Radius,0,11+(1/2)>
                      //pigment{Green}
                    }//end torus

              #if(SwivelStool_Apply_Textures) texture { SwivelStool_Metal_Texture } #end
              transform {SwivelStool_RH_To_LH_Transform}
} //end union SwivelStool_Single_Leg

#declare SwivelStool_Lower_Rung = 
torus { 8, 1/2 rotate x*90 translate z*(11+(1/2)) 
        #if(SwivelStool_Apply_Textures) texture { SwivelStool_Metal_Texture } #end
        transform {SwivelStool_RH_To_LH_Transform}
} //end torus SwivelStool_Lower_Rung 

#declare SwivelStool_Upper_Rung = 
torus { 6, 1/2 rotate x*90 translate z*(19+(1/2)) 
        #if(SwivelStool_Apply_Textures) texture { SwivelStool_Metal_Texture } #end
        transform {SwivelStool_RH_To_LH_Transform}
} //end torus SwivelStool_Upper_Rung 



// All individual components have been converted to left-hand y-up coordinates, so that's what the following 
// is working in:
#declare SwivelStool = 
union{
       object {SwivelStool_Single_Leg }
       object {SwivelStool_Single_Leg rotate y*90 }
       object {SwivelStool_Single_Leg rotate y*180 }
       object {SwivelStool_Single_Leg rotate y*270 }
       object {SwivelStool_Foot }
       object {SwivelStool_Foot rotate y*90 }
       object {SwivelStool_Foot rotate y*180 }
       object {SwivelStool_Foot rotate y*270 }
       object {SwivelStool_Top}
       object {SwivelStool_Lower_Rung}
       object {SwivelStool_Upper_Rung}       
} //end union SwivelStool





// Note that the following are ONLY parsed if this file is rendered directly, or if this file has been modified.  
// The following therefore cannot contribute to namespace polution and this file should be lib.povray.org compliant.
//
// *********************************************************************************************************************
#if (SwivelStool_Render_Demo_Switch)
// Do the following if "swivelstool.inc" is the main scene file. 
// *********************************************************************************************************************
     //
     light_source { <500, 500, 500>  rgb <1,1,1>   }  
     object{  SwivelStool }
     camera { location  <60,70,102> look_at <0,12,0> direction <0,0,3.2> sky y up y right x*image_width/image_height}
     light_source {     <60,70,102> rgb 1 }   // camera light
     light_source {     <-60,70,-102> rgb 1 } // to pick up some glare from the top of the seat
     //
     #if (SwivelStool_Draw_plane_if_self_demo) 
             plane {y, 0
               texture{
                 pigment{ checker rgb <1,1,1> rgb <.25,0,0> scale 10 }
                 finish{ diffuse .8 ambient 0  reflection 0  }
               } //end texture
             }//end plane
     #else //else make the background color white
             background{rgb 1}
     #end //end #if(SwivelStool_Draw_plane_if_self_demo)
     //
     //
     //Returns a union.  Usage E.g.  #local ClearRefAxis = Define_Reference_Axis(3);  #object{ClearRefAxis scale 5}
     //
     #macro Define_Reference_Axis(Ref_Axis_Textype)
      #switch (Ref_Axis_Textype)
      #case (1) //SOLID:
              #local Xtex = texture{ pigment{rgb x} }
              #local Ytex = texture{ pigment{rgb y} }
              #local Ztex = texture{ pigment{rgb z} }
      #break
      #case (2) //TRANSPARENT:
              #local Xtex = texture{ pigment{rgbt <1,0,0,.7>} finish{ambient 0} }
              #local Ytex = texture{ pigment{rgbt <0,1,0,.7>} finish{ambient 0} }
              #local Ztex = texture{ pigment{rgbt <0,0,1,.7>} finish{ambient 0} }
      #break
      #case (3) //TRANSPARENT 0 diffuse, with ambience:
              #local Xtex = texture{ pigment{rgbt <1,0,0,.7>} finish{diffuse 0 ambient .5} }
              #local Ytex = texture{ pigment{rgbt <0,1,0,.7>} finish{diffuse 0 ambient .5} }
              #local Ztex = texture{ pigment{rgbt <0,0,1,.7>} finish{diffuse 0 ambient .5} }
      #end //end #switch (Ref_Axis_Textype)
      //
      union{
         //sphere{<0,0,0> .09 pigment{Black} }  //origin
         cylinder {<0,0,0>, <.7,0,0> .05 texture{Xtex}  } //x-axis
         cylinder {<0,0,0>, <0,.7,0> .05 texture{Ytex}  } //y-axis
         cylinder {<0,0,0>, <0,0,.7> .05 texture{Ztex}  } //z-axis
         cone{<.7,0,0>, .1, <1,0,0>, 0   texture{Xtex}  } //x-axis
         cone{<0,.7,0>, .1, <0,1,0>, 0   texture{Ytex}  } //y-axis
         cone{<0,0,.7>, .1, <0,0,1>, 0   texture{Ztex}  } //z-axis                   
         #if(file_exists("crystal.ttf"))
            text { ttf "crystal.ttf", "X", .2, 0 scale <.5,.5,.5> texture{Xtex} translate <1.2,-.15,-.05>  }                       //x-axis
            text { ttf "crystal.ttf", "Y", .2, 0 scale <.5,.5,.5> texture{Ytex} translate <1.2,-.15,-.05> rotate z*90 }            //y-axis
            text { ttf "crystal.ttf", "Z", .2, 0 scale <.5,.5,.5> texture{Ztex} translate <1.2,-.15,-.05> rotate z*90 rotate x*90 }//z-axis
         #end //end #if(file_exists("crystal.ttf"))
         no_shadow
      } 
     #end //end #macro Define_Reference_Axis(Ref_Axis_TexType)
     // 
     #local Reference_Axis = Define_Reference_Axis(2); object{Reference_Axis scale 10}
     //
// *********************************************************************************************************************
#end // Do the preceding if "swivelstool.inc" is the main scene file.
// *********************************************************************************************************************



#version SwivelStool_Temp_Vers;      // Restore previous version