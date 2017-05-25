// This file is licensed under the terms of the CC-LGPL

// Persistence of Vision Ray Tracer Scene Description Include File
// File: spring.inc
// Vers: 3.7
// Desc: Mesh Spring Macro 
// Date: 9/24/2009 (rewrite of 3.5 macro circa 1999)
// Auth: Tim Attwood

// The spring is created with it's base on the origin, oriented on the +X axis

// U and V are the rectangular width and height of the spring wire

// X_Length is the overall length of the spring

// Radius is the radius of the spring

// Coils is the number of turns the spring makes (fractional numbers are OK)

// Rez is the appoximate number of desired triangles in the mesh.

// U,V, length, radius, coils, rez
#macro Spring (U, V, X_Length, Radius, Coils, Rez)
   #if ((Radius<=0)|(Radius<=V))
      #debug "Radius too small in Spring macro, mesh may be non-manifold.\n"       
   #end
   #if (U<=0)
      #error "Cross section width (U) too small in Spring macro, unable to complete render.\n"       
   #end
   #if (U>=(X_Length/Coils))
      #debug "Cross section width (U) too large in Spring macro, mesh may be non-manifold.\n"
   #end
   #if (V<=0)
      #debug "Cross section height (V) too small in Spring macro, mesh may be non-manifold.\n"   
   #end
   #if (V>=Radius)
      #debug "Cross section height (V) too large in Spring macro, mesh may be non-manifold.\n"   
   #end
   #if (X_Length<=0)
      #error "Length is too small in Spring macro, unable to complete render.\n"
   #end 
   #if (Coils<=0)
      #error "Too few coils in Spring macro, unable to complete render.\n"
   #end       
   #local pntA1 = <0,Radius,0>;
   #local pntB1 = <U,Radius,0>;
   #local pntC1 = <U,Radius-V,0>;
   #local pntD1 = <0,Radius-V,0>;
   #local N1 = <0,1,0>;
   #local step_distance = X_Length-U; 
   #local step_number = int((Rez-4)/8);
   #if (step_number<=2) 
      #debug "Resolution too small in Spring macro, using a resolution of 1004 triangles.\n" 
      #local step_number = 125;
   #end
   #local step = <step_distance/step_number,0,0>;
   #local step_rotate = <(360*Coils)/step_number,0,0>;
   #local pntA2 = vrotate(pntA1,step_rotate)+step;
   #local pntB2 = vrotate(pntB1,step_rotate)+step;
   #local pntC2 = vrotate(pntC1,step_rotate)+step;
   #local pntD2 = vrotate(pntD1,step_rotate)+step;
   #local N2 = vrotate(N1,step_rotate);   
   mesh {
      triangle {pntA1,pntB1,pntC1}
      triangle {pntA1,pntC1,pntD1}
      #local c = 1;
      #while (c <= step_number)       
         smooth_triangle {pntA1,N1,pntB1,N1,pntA2,N2}
         smooth_triangle {pntB1,N1,pntB2,N2,pntA2,N2}        
         triangle {pntB1,pntC1,pntB2} 
         triangle {pntC1,pntC2,pntB2}
         smooth_triangle {pntC1,N1,pntD1,N1,pntC2,N2} 
         smooth_triangle {pntD1,N1,pntD2,N2,pntC2,N2}
         triangle {pntD1,pntA1,pntD2}
         triangle {pntA1,pntA2,pntD2}        
         #local pntA1 = pntA2;
         #local pntB1 = pntB2;
         #local pntC1 = pntC2;
         #local pntD1 = pntD2;
         #local N1 = N2;
         #local pntA2 = vrotate(pntA2,step_rotate)+step;
         #local pntB2 = vrotate(pntB2,step_rotate)+step;
         #local pntC2 = vrotate(pntC2,step_rotate)+step;
         #local pntD2 = vrotate(pntD2,step_rotate)+step;
         #local N2 = vrotate(N1,step_rotate);   
         #local c=c+1; 
      #end
      triangle {pntA1,pntB1,pntC1}
      triangle {pntA1,pntC1,pntD1}
      inside_vector <0,1,0>      
   }
   #debug concat("Spring mesh created with ",str(step_number*8+4,0,0)," triangles.\n")
#end   
   
