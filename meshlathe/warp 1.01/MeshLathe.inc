//This file is licensed under the terms of the CC-LGPL

//=============================================================================
// MeshLathe
// ---------
// Params:
//  * Spline: The spline to make the lathe from
//  * VertSteps: The amount of triangles to create along the spline
//  * HorSteps: The amount of triangles to create around the y-axis
// Debugging identifiers:
// (If these identifiers are defined when calling the macro, they can affect
// how the macro behaves)
//  * MeshLatheDebug: Number from 0 to 3
//     0: No debugging. Create the mesh with smooth triangles. (Default)
//     1: Create a union of cylinders and spheres following the spline
//        (mirroring around y).
//     2: Same as 1, but also creates cylinders showing the normal vectors.
//     3: Create a mesh with flat triangles.
//  * MeshLatheDebugRadius: The radius of the cylinders. (Default: 0.05)
//  * MeshLatheDebugNormalLength: The length of the "normal-vector" cylinders.
//    (Default: 0.2)
//  * MeshLatheDebugNormalColor: The color of the "normal-vector" cylinders.
//    (Default: No color specification)
//=============================================================================
#macro MeshLathe(Spline, VertSteps, HorSteps)
  #ifndef(MeshLatheDebug) #local MeshLatheDebug=0; #end
  #if(MeshLatheDebug=1 | MeshLatheDebug=2)
    #ifndef(MeshLatheDebugRadius) #local MeshLatheDebugRadius=.05; #end
    #ifndef(MeshLatheDebugNormalLength) #local MeshLatheDebugNormalLength=.2; #end
    union
    { #local Ind1 = 0;
      #while(Ind1 < VertSteps)
        #local Time1 = Ind1/(VertSteps-1);

        #local Coord1 = (Spline(Time1));
        #local Tang = (Spline(Time1+1e-5)-Spline(Time1-1e-5));
        #local Normal1 = vnormalize(<Tang.y, -Tang.x, 0>);

        sphere { Coord1, MeshLatheDebugRadius }
        sphere { Coord1*<-1,1,1>, MeshLatheDebugRadius }
        #if(MeshLatheDebug=2)
          cylinder
          { Coord1, Coord1+Normal1*MeshLatheDebugNormalLength,
            MeshLatheDebugRadius*.5
            #ifdef(MeshLatheDebugNormalColor)
              pigment { rgb MeshLatheDebugNormalColor }
            #end
          }
        #end

        #if(Ind1>0)
          cylinder { Coord1, oldCoord1, MeshLatheDebugRadius*.5 }
          cylinder
          { Coord1*<-1,1,1>, oldCoord1*<-1,1,1>, MeshLatheDebugRadius*.5 }
        #end

        #local oldCoord1 = Coord1;
        #local Ind1 = Ind1+1;
      #end
    }
  #else
    mesh
    { #local Ind1 = 0;
      #while(Ind1 < VertSteps-1)
        #local Time1 = Ind1/(VertSteps-1);
        #local Time2 = (Ind1+1)/(VertSteps-1);

        #local Coord1 = (Spline(Time1));
        #local Tang = (Spline(Time1+1e-5)-Spline(Time1-1e-5));
        #local Normal1 = vnormalize(<Tang.y, -Tang.x, 0>);
        #local Coord2 = (Spline(Time2));
        #local Tang = (Spline(Time2+1e-5)-Spline(Time2-1e-5));
        #local Normal2 = vnormalize(<Tang.y, -Tang.x, 0>);

        #local Ind2 = 0;
        #while(Ind2 < HorSteps-1)
          #local Angle1 = 360*Ind2/(HorSteps-1);
          #local Angle2 = 360*(Ind2+1)/(HorSteps-1);
          #local P1 = vrotate(Coord1, y*Angle1);
          #local N1 = vrotate(Normal1, y*Angle1);
          #local P2 = vrotate(Coord2, y*Angle1);
          #local N2 = vrotate(Normal2, y*Angle1);
          #local P3 = vrotate(Coord2, y*Angle2);
          #local N3 = vrotate(Normal2, y*Angle2);
          #local P4 = vrotate(Coord1, y*Angle2);
          #local N4 = vrotate(Normal1, y*Angle2);
          #if(MeshLatheDebug>2)
            triangle { P1, P2, P3 }
            triangle { P3, P4, P1 }
          #else
            smooth_triangle { P1,N1, P2,N2, P3,N3 }
            smooth_triangle { P3,N3, P4,N4, P1,N1 }
          #end
          #local Ind2 = Ind2+1;
        #end

        #local Ind1 = Ind1+1;
      #end
    }
  #end
#end

// Helps creating a spline with evenly distributed time values
// -----------------------------------------------------------
#macro MakeEvenSplinePoints(Points)
  #local Amnt = dimension_size(Points, 1)-1;
  #local Ind = 0;
  #while(Ind <= Amnt)
    Ind/Amnt, Points[Ind]
    #local Ind = Ind+1;
  #end
#end

/*
//----------
// Example:
//----------

#declare Points = array[18]
{ <0,.1>,<1,0>,<1.2,.05>,<1,.1>,<.2,.3>,
  <.25,.4>,<.1,.9>,<.1,2.5>,<.3,2.8>,<.3,3.1>,
  <1,3.25>,<1.25,4>,<1,5>,<.9,5>,<1.1,4.5>,
  <1.15,3.8>,<1,3.4>,<0,3.2>
}

#declare Spline = spline { natural_spline MakeEvenSplinePoints(Points) }

camera { location -z*14 look_at 0 angle 35 translate y*2.5 }
light_source { <100,200,-300>, 1 }
light_source { <-100,20,-30>, <1,.5,0>*.5 }

//#declare MeshLatheDebug = 2;
//#declare MeshLatheDebugNormalColor = x;

object
{ MeshLathe(Spline, 80, 20)
  pigment { rgb 1 } finish { specular .5 }
}
*/
