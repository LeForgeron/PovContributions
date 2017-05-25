// This file is licensed under the terms of the CC-LGPL
//
// Persistence of Vision Ray Tracer Scene Description File
// File: pipemrg.inc
// Vers: 2.0 (for POV 3.6+)
// Desc: create a blended joint between two cylinders
// Date: 2001, updated 9/27/2009
// Auth: Tim Attwood


// the first parameter is the location that the two cylinders intersect
// the second parameter is the radius of the cylinders
// the third parameter is the radius of the saddle curve at the apex
// the forth parameter is the angle between the cylinders
// the fifth parameter is the placement rotation

// the merge object is assumed to lay in the XY plane until rotated by Frot
// and translated by Loc

#macro PipeMrg(Loc, Rad1, Rad2, Ang, Frot) 
 object { 
  #local MRad = (Rad1+Rad2)/sin(radians(Ang/2));
  #local DistX = (Rad1+Rad2)/tan(radians(Ang/2));
  #local A2 = (Ang-(180-2*degrees(atan2(DistX,Rad1))))/2;
  #local DistLim = MRad+Rad2+0.1;
  difference {
   cylinder{<0,-Rad2,0>,<0,Rad2,0>,MRad - Rad2*sin(radians(Ang/2))}
   torus{MRad,Rad2}
   box{<-DistLim,0,-DistLim>,<DistLim,DistLim,DistLim> rotate <0,0,A2>}
   box{<-DistLim,0,-DistLim>,<DistLim,-DistLim,DistLim> rotate <0,0,-A2>}
  }
  scale <1,1,Rad1/(MRad-Rad2)>  
  rotate <0,0,Ang/2>
  rotate Frot 
  translate Loc 
 }
#end

// note: this code could use improvement, it's possible to create a 
// similar CSG joint between cylinders given the other cylinder
// end points, instead of the angle but I gave up trying to get 
// the positioning to work correctly.
