// Scroll_array2mesh2.inc
// ----------------------

// Include file for the Scroll_Mesh2FromArray macro takes an array of Positions and generates a mesh2 object.
// Created by Chris Bartlett 07.02.2005
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
// Typical render time 1 second

// Parameters:
// -----------
//     Scroll_Array            - The 2D array of positions 
//     Scroll_Normal           - An optional 2D array of normals
//     Scroll_IDim             - The size of the first dimension
//     Scroll_JDim             - The size of the second dimension  
//     Scroll_JoinEnds         - Whether to join the ends of the mesh together - 1=join them, 0 = leave the mesh open
//
#macro Scroll_Mesh2FromArray(Scroll_Array,Scroll_NormalArray,Scroll_IDim,Scroll_JDim,Scroll_JoinEnds)
  #if ( Scroll_Verbose = 1) #debug concat("Scroll_MeshFromArray Macro Call. \n") #end
  // Rewritten based on an example posted by Scott on the povray.binaries.scene-files newsgroup.
  #if (Scroll_JoinEnds) #local Scroll_JTotal = Scroll_JDim + 1;
  #else            #local Scroll_JTotal = Scroll_JDim;
  #end
  mesh2{
    vertex_vectors{
      Scroll_IDim*Scroll_JTotal
      #local Scroll_I = 0;
      #while(Scroll_I<Scroll_IDim)
        #local Scroll_J=0;
        #while(Scroll_J<Scroll_JTotal) 
          #if ( Scroll_Verbose = 1) #debug concat("I:J = ",str(Scroll_I,3,0),":",str(Scroll_J,3,0),"\n") #end
          #if (Scroll_J<Scroll_JDim) Scroll_Array[Scroll_I][Scroll_J]
          #else            Scroll_Array[Scroll_I][0]
          #end
          #local Scroll_J=Scroll_J+1;
        #end
        #local Scroll_I=Scroll_I+1;
      #end
    }
    normal_vectors{
      Scroll_IDim*Scroll_JTotal
      #local Scroll_I=0;
      #while(Scroll_I<Scroll_IDim)
        #local Scroll_J=0;
        #while(Scroll_J<Scroll_JTotal)
          #ifdef (Scroll_NormalArray[Scroll_I][Scroll_J]) 
            Scroll_NormalArray[Scroll_I][Scroll_J]
          #else
            #local Scroll_Normal  = <0,0,0>;
            #local Scroll_NormalCount = 0; 
            #if (Scroll_JoinEnds)
              #if (Scroll_I>=1 & Scroll_J=Scroll_JDim)
                #local Scroll_Normal = Scroll_Normal + vcross(Scroll_Array[Scroll_I][0]-Scroll_Array[Scroll_I][1],Scroll_Array[Scroll_I][0]-Scroll_Array[Scroll_I-1][0]);
                #local Scroll_NormalCount = Scroll_NormalCount+1;
              #end
              #if (Scroll_I<=Scroll_IDim-2 & Scroll_J=Scroll_JDim)
                #local Scroll_Normal = Scroll_Normal - vcross(Scroll_Array[Scroll_I][0]-Scroll_Array[Scroll_I][1],Scroll_Array[Scroll_I][0]-Scroll_Array[Scroll_I+1][0]);
                #local Scroll_NormalCount = Scroll_NormalCount+1;    
              #end
              #if (Scroll_I>=1 & Scroll_J=Scroll_JDim-1)
                #local Scroll_Normal = Scroll_Normal + vcross(Scroll_Array[Scroll_I][Scroll_J]-Scroll_Array[Scroll_I][0],Scroll_Array[Scroll_I][Scroll_J]-Scroll_Array[Scroll_I-1][Scroll_J]);
                #local Scroll_NormalCount = Scroll_NormalCount+1;
              #end
              #if (Scroll_I<=Scroll_IDim-2 & Scroll_J=Scroll_JDim-1)
                #local Scroll_Normal = Scroll_Normal - vcross(Scroll_Array[Scroll_I][Scroll_J]-Scroll_Array[Scroll_I][0],Scroll_Array[Scroll_I][Scroll_J]-Scroll_Array[Scroll_I+1][Scroll_J]);
                #local Scroll_NormalCount = Scroll_NormalCount+1;    
              #end
              #if (Scroll_I<=Scroll_IDim-2 & Scroll_J=0)
                #local Scroll_Normal = Scroll_Normal + vcross(Scroll_Array[Scroll_I][Scroll_J]-Scroll_Array[Scroll_I][Scroll_JDim-1],Scroll_Array[Scroll_I][Scroll_J]-Scroll_Array[Scroll_I+1][Scroll_J]);
                #local Scroll_NormalCount = Scroll_NormalCount+1;
              #end
              #if (Scroll_I>=1 & Scroll_J=0)
                #local Scroll_Normal = Scroll_Normal - vcross(Scroll_Array[Scroll_I][Scroll_J]-Scroll_Array[Scroll_I][Scroll_JDim-1],Scroll_Array[Scroll_I][Scroll_J]-Scroll_Array[Scroll_I-1][Scroll_J]);
                #local Scroll_NormalCount = Scroll_NormalCount+1;
              #end
            #end
            #if (Scroll_I>=1 & Scroll_J<=Scroll_JDim-2)
              #local Scroll_Normal = Scroll_Normal + vcross(Scroll_Array[Scroll_I][Scroll_J]-Scroll_Array[Scroll_I][Scroll_J+1],Scroll_Array[Scroll_I][Scroll_J]-Scroll_Array[Scroll_I-1][Scroll_J]);
              #local Scroll_NormalCount = Scroll_NormalCount+1;
            #end
            #if (Scroll_I<=Scroll_IDim-2 & Scroll_J<=Scroll_JDim-2)
              #local Scroll_Normal = Scroll_Normal - vcross(Scroll_Array[Scroll_I][Scroll_J]-Scroll_Array[Scroll_I][Scroll_J+1],Scroll_Array[Scroll_I][Scroll_J]-Scroll_Array[Scroll_I+1][Scroll_J]);
              #local Scroll_NormalCount = Scroll_NormalCount+1;    
            #end
            #if (Scroll_I<=Scroll_IDim-2 & Scroll_J>=1 & Scroll_J<Scroll_JDim)
              #local Scroll_Normal = Scroll_Normal + vcross(Scroll_Array[Scroll_I][Scroll_J]-Scroll_Array[Scroll_I][Scroll_J-1],Scroll_Array[Scroll_I][Scroll_J]-Scroll_Array[Scroll_I+1][Scroll_J]);
              #local Scroll_NormalCount = Scroll_NormalCount+1;
            #end
            #if (Scroll_I>=1 & Scroll_J>=1 & Scroll_J<Scroll_JDim)
              #local Scroll_Normal = Scroll_Normal - vcross(Scroll_Array[Scroll_I][Scroll_J]-Scroll_Array[Scroll_I][Scroll_J-1],Scroll_Array[Scroll_I][Scroll_J]-Scroll_Array[Scroll_I-1][Scroll_J]);
              #local Scroll_NormalCount = Scroll_NormalCount+1;
            #end
            #if (vlength(Scroll_Normal/Scroll_NormalCount)=0)
              <-1,0,0>
            #else
              (-Scroll_Normal/Scroll_NormalCount) 
            #end
          #end
          #local Scroll_J=Scroll_J+1;
        #end
        #local Scroll_I=Scroll_I+1;
      #end
    }
    uv_vectors{
      Scroll_IDim*Scroll_JTotal
      #local Scroll_I=0;
      #while(Scroll_I<Scroll_IDim)
        #local Scroll_J=0;
        #while(Scroll_J<Scroll_JTotal)
          <Scroll_I/(Scroll_IDim-1),Scroll_J/(Scroll_JTotal-1)>
          #local Scroll_J=Scroll_J+1;
          #end
        #local Scroll_I=Scroll_I+1;
      #end
    }
    face_indices{
      (Scroll_IDim-1)*(Scroll_JTotal-1)*2
      #local Scroll_I=0;
      #while(Scroll_I<Scroll_IDim-1)
        #local Scroll_J=0;
        #while(Scroll_J<Scroll_JTotal-1)
          <Scroll_J+(Scroll_I+1)*Scroll_JTotal, Scroll_J  + Scroll_I   *Scroll_JTotal, Scroll_J+1+(Scroll_I+1)*Scroll_JTotal  >
          <Scroll_J+1+Scroll_I*Scroll_JTotal    , Scroll_J+1+(Scroll_I+1)*Scroll_JTotal, Scroll_J  + Scroll_I   *Scroll_JTotal>
        #local Scroll_J=Scroll_J+1;
        #end
        #local Scroll_I=Scroll_I+1;
      #end
    }
//    normal_indices{
//      (Scroll_IDim-1)*(Scroll_JTotal-1)*2
//      #local Scroll_I=0;
//      #while(Scroll_I<Scroll_IDim-1)
//        #local Scroll_J=0;
//        #while(Scroll_J<Scroll_JTotal-1)
//          <Scroll_J+(Scroll_I+1)*Scroll_JTotal, Scroll_J  + Scroll_I   *Scroll_JTotal, Scroll_J+1+(Scroll_I+1)*Scroll_JTotal  >
//          <Scroll_J+1+Scroll_I*Scroll_JTotal    , Scroll_J+1+(Scroll_I+1)*Scroll_JTotal, Scroll_J  + Scroll_I   *Scroll_JTotal>
//          #local Scroll_J=Scroll_J+1;
//        #end
//        #local Scroll_I=Scroll_I+1;
//      #end
//    }
//    uv_indices{
//      (Scroll_IDim-1)*(Scroll_JTotal-1)*2
//      #local Scroll_I=0;
//      #while(Scroll_I<Scroll_IDim-1)
//        #local Scroll_J=0;
//        #while(Scroll_J<Scroll_JTotal-1)
//          <Scroll_J+(Scroll_I+1)*Scroll_JTotal, Scroll_J  + Scroll_I   *Scroll_JTotal, Scroll_J+1+(Scroll_I+1)*Scroll_JTotal  >
//          <Scroll_J+1+Scroll_I*Scroll_JTotal    , Scroll_J+1+(Scroll_I+1)*Scroll_JTotal, Scroll_J  + Scroll_I   *Scroll_JTotal>
//          #local Scroll_J=Scroll_J+1;                                                    
//        #end
//        #local Scroll_I=Scroll_I+1;
//      #end
//    }
  }
#end  

