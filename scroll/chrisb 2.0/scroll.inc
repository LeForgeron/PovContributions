// Scroll.inc
// ----------

// Include file for Macro that generates a mesh2 object in the form of a paper scroll.
// Created by Chris Bartlett 07.02.2005
// Updated by Chris Bartlett 11.08.2008
//    Split out macro into an include file
//    Fixed problem with normals alternating between consecutive triangles
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
// Typical render time 1 minute with text, 1 second without.
// The default size is about 0.5 POV-Ray units high.
// The default position aligns the centre of the bottom scroll with the Z axis centred at '0'.
// The default position for the top scroll is directly above the bottom scroll.

#ifndef (asind)                 #include "math.inc"               #end
#ifndef (Scroll_Mesh2FromArray) #include "scroll_array2mesh2.inc" #end


#macro Scroll()
  #local Scroll_Verbose = 0;   // Option to add messages to debug stream
  // Set default values for all of the key variables exposed to the user
  #ifndef (Scroll_Width                 ) #declare Scroll_Width                   = 0.3;        #end
  #ifndef (Scroll_Length                ) #declare Scroll_Length                  = 0.9;        #end
  #ifndef (Scroll_BottomRollLength      ) #declare Scroll_BottomRollLength        = 0.3;        #end
  #ifndef (Scroll_TopRadius             ) #declare Scroll_TopRadius               = 0.03;       #end
  #ifndef (Scroll_CentreRadius          ) #declare Scroll_CentreRadius            = 0.8;        #end
  #ifndef (Scroll_BottomRadius          ) #declare Scroll_BottomRadius            = 0.03;       #end
  #ifndef (Scroll_TopFactor             ) #declare Scroll_TopFactor               = 1;          #end
  #ifndef (Scroll_BottomFactor          ) #declare Scroll_BottomFactor            = 1;          #end
  #ifndef (Scroll_Increment             ) #declare Scroll_Increment               = 0.01;       #end
  #ifndef (Scroll_Top                   ) #declare Scroll_Top                     = 0.35;       #end
  #ifndef (Scroll_Bottom                ) #declare Scroll_Bottom                  = 0;          #end
  // The coordinates of the mesh2 nodes are written into an array   
  #ifndef (Scroll_Array       ) #local Scroll_Array = array [2][1.1*Scroll_Length/Scroll_Increment]; #end
                                                         
  // Calculate the centre point of the curve of the middle section of the scroll
  // Assume bottom spiral centred on Z axis
  // Use the formulae     y = (r1*r1-r2*r2+2*r0*r1-2*r0*r2+h*h)/2h  and   x = sqrt(pow(r0+r1,2)-y*y)
  // Adjust the result to compensate for displacement of bottom spiral
  #local Scroll_Height = Scroll_Top - Scroll_Bottom;
  #local Scroll_CentrePointY = (pow(Scroll_BottomRadius,2)-pow(Scroll_TopRadius,2)+
    2*Scroll_CentreRadius*Scroll_BottomRadius-2*Scroll_CentreRadius*Scroll_TopRadius+
    pow(Scroll_Height,2))/(2*Scroll_Height);
  #local Scroll_CentrePointX = sqrt(pow(Scroll_CentreRadius+Scroll_BottomRadius,2)-pow(Scroll_CentrePointY,2));  
  #local Scroll_CentrePoint  = <-Scroll_CentrePointX,Scroll_CentrePointY+Scroll_Bottom,0>;
  #if (Scroll_Verbose)  
    #debug concat("Scroll_CentrePointY: ",str(Scroll_CentrePointY,3,8),"\n")
    #debug concat("Scroll_CentrePointX: ",str(Scroll_CentrePointX,3,8),"\n")
  #end
  // Calculate the angles of the joints between the top and bottom spirals and the central section
  #local Scroll_BottomTheta = abs(VAngleD(Scroll_CentrePoint-Scroll_Bottom*y,-x));
  #local Scroll_TopTheta    = abs(VAngleD(Scroll_CentrePoint-Scroll_Top*y,-x)); 
  #local Scroll_CentreTheta = abs(VAngleD(Scroll_Bottom*y-Scroll_CentrePoint,Scroll_Top*y-Scroll_CentrePoint));
  #if (Scroll_Verbose)  
    #debug concat("Scroll_BottomTheta: ",str(Scroll_BottomTheta,3,3),"\n")
    #debug concat("Scroll_TopTheta:    ",str(Scroll_TopTheta,3,3),"\n")
    #debug concat("Scroll_CentreTheta: ",str(Scroll_CentreTheta,3,3),"\n")
  #end
  // Work out where the bottom spiral will need to start to reach the bottom of the 'flat' bit at BottomRollLength.
  #local Scroll_R = Scroll_BottomRadius;
  #local Scroll_Distance = 0;
  #local Scroll_BottomAngle = 0; 
  #while (Scroll_Distance < Scroll_BottomRollLength)
    #local Scroll_BottomAngle = Scroll_BottomAngle + 360*Scroll_Increment/(Scroll_R*2*pi);
    #local Scroll_Distance    = Scroll_Distance + Scroll_Increment;
    #local Scroll_R           = Scroll_R/(1+Scroll_BottomFactor/100);     // Add a percentage to the radius each time 
  #end  
  #local Scroll_BottomAngle = Scroll_BottomAngle-Scroll_BottomTheta; 
    
  // First do a spiral at the bottom end. This will start the mesh at the bottom left which is necessary for uv_mapping.
  #local Scroll_Distance = 0;
  #local Scroll_ArrayIndex = 0;
  #local Scroll_I = 0; 
  #while (Scroll_Distance <= Scroll_BottomRollLength)
    #local Scroll_X = Scroll_R*cosd(Scroll_I);
    #local Scroll_Y = Scroll_R*sind(Scroll_I);
    #local Scroll_Z = 0;
    #local Scroll_Array[0][Scroll_ArrayIndex] = vrotate(<Scroll_X,Scroll_Y,Scroll_Z>,z*(Scroll_BottomAngle+180))+Scroll_Bottom*y+Scroll_Width/2*z;
    #local Scroll_Array[1][Scroll_ArrayIndex] = Scroll_Array[0][Scroll_ArrayIndex]-Scroll_Width*z;
    #local Scroll_R          = Scroll_R*(1+Scroll_BottomFactor/100);     // Add a percentage to the radius each time 
    #local Scroll_Distance   = Scroll_Distance + Scroll_Increment;
    #local Scroll_I          = Scroll_I - 360*Scroll_Increment/(Scroll_R*2*pi);
    #local Scroll_ArrayIndex = Scroll_ArrayIndex + 1;
  #end  
  
  // Work out incremental angle to rotate by to get from bottom to top point respecting Scroll_Increment as closely as possible
  // in an integer number of steps.
  #local Scroll_StepCount = int(0.5+(2*pi*Scroll_CentreRadius * Scroll_CentreTheta/360)/Scroll_Increment);  
  #local Scroll_RotationalIncrement = Scroll_CentreTheta/Scroll_StepCount;  
  #if (Scroll_Verbose)  
    #debug concat("Scroll_StepCount: ",str(Scroll_StepCount,3,3),"\n") 
    #debug concat("Scroll_RotationalIncrement: ",str(Scroll_RotationalIncrement,3,3),"\n") 
  #end
  // Add the more or less straight bit in the middle 
  #local Scroll_J = 1;
  // If the scroll hasn't been started yet, then it could be that the Scroll_BottomRollLength variable is zero or negative.
  #if (Scroll_ArrayIndex>0)
    #local Scroll_BottomPoint = Scroll_Array[0][Scroll_ArrayIndex-1]*<1,1,0>;
  #else
    #local Scroll_BottomPoint = vrotate(-Scroll_BottomRadius*x, -Scroll_BottomTheta*z)+Scroll_Bottom*y;
    #if (Scroll_BottomRollLength<0)
      #local Scroll_J = int(abs(Scroll_BottomRollLength/Scroll_Increment)+0.5);
    #end
  #end
  #while (Scroll_J<=Scroll_StepCount & Scroll_Distance<=Scroll_Length)
    #local Scroll_Array[0][Scroll_ArrayIndex] = vrotate(Scroll_BottomPoint-Scroll_CentrePoint,Scroll_J*Scroll_RotationalIncrement*z)+Scroll_CentrePoint+z*Scroll_Width/2;
    #local Scroll_Array[1][Scroll_ArrayIndex] = Scroll_Array[0][Scroll_ArrayIndex]-z*Scroll_Width;
    #local Scroll_ArrayIndex = Scroll_ArrayIndex + 1;
    #local Scroll_Distance   = Scroll_Distance + Scroll_Increment;
    #local Scroll_J = Scroll_J + 1;
  #end         
  
  // Finally add a spiral at the top end
  #local Scroll_R = Scroll_TopRadius;
  #local Scroll_I = 360*Scroll_Increment/(2*pi*Scroll_R);
  // If the scroll still hasn't been started yet, then it could be that the Scroll_BottomRollLength variable 
  // is a sufficiently large negative number to encroach upon the top spiral.
  #if (Scroll_ArrayIndex<=0)
    #local Scroll_TopPoint = vrotate(Scroll_BottomPoint-Scroll_CentrePoint,z*Scroll_CentreTheta)+Scroll_CentrePoint;
    #local Scroll_CentreSectionDistance = 2*pi*Scroll_CentreRadius * Scroll_CentreTheta/360;
    // If Scroll_BottomRollLength is sufficiently negative to eat into the top spiral
    #if (Scroll_BottomRollLength<0 & Scroll_CentreSectionDistance<abs(Scroll_BottomRollLength))
      #local Scroll_DistanceBeforeStart = abs(Scroll_BottomRollLength)-Scroll_CentreSectionDistance;
      #while (Scroll_DistanceBeforeStart>0)  
        #local Scroll_R = Scroll_R*(1-Scroll_TopFactor/100);     // Remove 1 percent from the radius each time 
        #local Scroll_TopPoint = vrotate(Scroll_R*vnormalize(Scroll_TopPoint-Scroll_Top*y),-z*Scroll_I)+Scroll_Top*y;
        #local Scroll_DistanceBeforeStart = Scroll_DistanceBeforeStart - Scroll_Increment;
      #end
    // If the scroll needs to start precisely at the start of the top spiral
    #end 
    #local Scroll_Array[0][0]=Scroll_TopPoint+Scroll_Width*z/2;
    #local Scroll_Array[1][0]=Scroll_TopPoint-Scroll_Width*z/2;
    #local Scroll_ArrayIndex = Scroll_ArrayIndex + 1;
  #end 
  // Now we can generate the top spiral
  #while (Scroll_Distance<=Scroll_Length)
    #local Scroll_X = Scroll_Array[0][Scroll_ArrayIndex-1].x;
    #local Scroll_Y = Scroll_Array[0][Scroll_ArrayIndex-1].y-Scroll_Top;
    #local Scroll_Z = 0;
    #local Scroll_R = Scroll_R*(1-Scroll_TopFactor/100);     // Remove 1 percent from the radius each time 
    #local Scroll_Array[0][Scroll_ArrayIndex] = vrotate((1-Scroll_TopFactor/100)*<Scroll_X,Scroll_Y,Scroll_Z>,-z*Scroll_I)+Scroll_Top*y+Scroll_Width/2*z;
    #local Scroll_Array[1][Scroll_ArrayIndex] = Scroll_Array[0][Scroll_ArrayIndex]-Scroll_Width*z;
    #local Scroll_Distance   = Scroll_Distance + Scroll_Increment;
    #local Scroll_ArrayIndex = Scroll_ArrayIndex + 1;
  #end 
  
  // Call a function to generate a mesh2 object from the array
  #local Scroll_DummyArray  = array [2][Scroll_ArrayIndex];
  #local Scroll_Verbose = 0;
  
  object {Scroll_Mesh2FromArray(Scroll_Array, Scroll_DummyArray, 2, Scroll_ArrayIndex, 0)}
#end  

// This macro undefines all of the global variables used to control the generation of the scroll object and the text object
// used to display text upon the scroll object.
#macro Scroll_Undef()
  #ifdef (Scroll_Width           ) #undef Scroll_Width            #end
  #ifdef (Scroll_Length          ) #undef Scroll_Length           #end
  #ifdef (Scroll_BottomRollLength) #undef Scroll_BottomRollLength #end
  #ifdef (Scroll_TopRadius       ) #undef Scroll_TopRadius        #end
  #ifdef (Scroll_CentreRadius    ) #undef Scroll_CentreRadius     #end
  #ifdef (Scroll_BottomRadius    ) #undef Scroll_BottomRadius     #end
  #ifdef (Scroll_TopFactor       ) #undef Scroll_TopFactor        #end
  #ifdef (Scroll_BottomFactor    ) #undef Scroll_BottomFactor     #end
  #ifdef (Scroll_Increment       ) #undef Scroll_Increment        #end
  #ifdef (Scroll_Top             ) #undef Scroll_Top              #end
  #ifdef (Scroll_Bottom          ) #undef Scroll_Bottom           #end
  #ifdef (Scroll_Array           ) #undef Scroll_Array            #end

  // If scroll_typeset.inc has been used then call the undef macro from it to undef it's control variables
  #ifdef(Scroll_TypeSet_Undef) Scroll_TypeSet_Undef() #end
#end
