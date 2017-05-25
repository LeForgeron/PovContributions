// Persistence of Vision Ray Tracer Include File
// File: BlobCube.inc
// Vers: 3.6
// Desc: BlobCube macro. 
//       BlobCube(Size) // BlobCube Macro
// Date: 22/09/2008
// Auth: - Nekar Xenos -  
//
//This file is licensed under the terms of the CC-LGPL
//                 


#macro BlobCube(Size)


  cylinder { -x*2, +x*2, 1, 1 scale  <1/4,1,1> scale Size}  
  cylinder { -y*2, +y*2, 1, 1 scale <1,1/4,1> scale Size}
  cylinder { -z*2, +z*2, 1, 1 scale <1,1,1/4> scale Size} 
  


#end
