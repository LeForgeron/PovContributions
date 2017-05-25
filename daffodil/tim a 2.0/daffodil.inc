// This file is licensed under the terms of the CC-LGPL
//
// Include file by Tim Attwood April 4, 1997
// updated 9/25/2009
//
// The default daffodil is a Las Vegas -- white and yellow
// Use variables from your source to set options (optional)
//
// Rnd        -- random seed to create differing flowers
// DafLeaves  -- boolean turns on/off (1/0) leaves
// MinLeaves  -- minimum number of leaves
// MaxLeaves  -- maximum number of leaves
// MaxDrot    -- maximum daffodil rotation (varies from MinDrot by this amount)
// MinDrot    -- minimum daffodil rotation (0 is strait ahead along Z axis)
// OrngDaf    -- texture for stamen
// YelDaf     -- texture for center cone
// WhtDaf     -- texture for petals
// GrnDaf     -- texture for stem and leaves

#ifndef (MaxDrot)
 #declare MaxDrot = 240;
#end
#ifndef (MinDrot)
 #declare MinDrot = -120;
#end
#ifndef (MinLeaves)
 #declare MinLeaves = 4;
#end
#ifndef (MaxLeaves)
 #declare MaxLeaves = 6;
#end
#ifndef (DafLeaves)
 #declare DafLeaves = 1;
#end
#ifndef (Rnd)
 #declare Rnd = seed(1);
#end
#ifndef (OrngDaf)
#declare OrngDaf = texture {
  pigment {color rgb <1,0.5,0>}
  normal {bumps}
  finish {
   ambient 0.4
   diffuse 0.3
   reflection 0.2
   phong 0.7
   phong_size 90
  }
  scale 0.1
 };
#end
#ifndef (YelDaf)
#declare YelDaf = texture {
  pigment {color rgb <1,1,0.3>}
  finish {
   ambient 0.4
   diffuse 0.3
   reflection 0.2
   phong 0.7
   phong_size 90
  }
 };
#end
#ifndef (WhtDaf)
#declare WhtDaf = texture {
  pigment {color rgb <1,1,1>}
  finish {
   ambient 0.4
   diffuse 0.3
   reflection 0.2
   phong 0.7
   phong_size 90
  }
 };
#end
#ifndef (GrnDaf)
#declare GrnDaf = texture {
  pigment {rgb <0,0.4,0.1>}
  finish {
   ambient 0.4
   diffuse 0.3
   reflection 0.2
   phong 0.7
   phong_size 90
  }
 };
#end

#declare DafCone = blob {
 threshold 0.5
 #declare Count = 1;
 #while (Count >=0 )
  cylinder {<0,0,0>,<0,1.75,0>,0.5,1
   scale <0.1,1,1>
   rotate <0,10*rand(Rnd)-5,-15>
   translate <0.5,0,0>
   rotate <0,(Count)*360,0>
  }
  cylinder {<0,0,0>,<0,0.25,0>,0.5,1
   scale <0.1,1,1>
   rotate <0,0,-20*rand(Rnd)>
   translate <0,1.75,0>
   rotate <0,0,-15>
   translate <0.5,0,0>
   rotate <0,(Count)*360,0>
  }
  #declare Count = Count - 0.04;
 #end
 cylinder {<0,0,0>,<0,0.1,0>,0.8,2}
 scale 0.5
 texture {
  YelDaf
 }
};
#declare DafCent = union {
 cylinder {<0,0,0>,<0,0.6,0>,0.05 texture {WhtDaf}}
 sphere {<0,0.6,0>,0.07 texture {OrngDaf}}
 cylinder {<0,0,0.1>,<0,0.3,0.1>,0.025 texture {OrngDaf}}
 cylinder {<0,0,0.1>,<0,0.25,0.1>,0.025 rotate <0,120,0> texture {OrngDaf}}
 cylinder {<0,0,0.1>,<0,0.33,0.1>,0.025 rotate <0,240,0> texture {OrngDaf}}
};
#declare DafPetal = blob {
 threshold 0.5
 sphere {<1,0,0>,2,1 scale <1,0.05,0.5>}
 sphere {<1,0.1,0>,2,-0.2 scale <1,0.05,0.5>}
 cylinder{<0.5,0.1,0.1>,<1.5,0.1,0.1>,0.08,-1}
 cylinder{<0.5,0.1,-0.1>,<1.5,0.1,-0.1>,0.08,-1}
 rotate <10*rand(Rnd)-5,20*rand(Rnd)-10,5+10*rand(Rnd)>
 translate <-0.25,0,0>
 texture {WhtDaf}
};
#declare DafTop = union {
 union {
  object { DafPetal rotate <0,0,0> }
  object { DafPetal rotate <0,60,0> }
  object { DafPetal rotate <0,120,0> }
  object { DafPetal rotate <0,180,0> }
  object { DafPetal rotate <0,240,0> }
  object { DafPetal rotate <0,300,0> }
  object { DafCent }
  object { DafCone }
  rotate <0,360*rand(Rnd),0>
 }
 difference {
  sphere {<0,0,0>,0.3 scale <1,2,1>}
  box {<-2,0,-2>,<2,3,2>}
  texture {GrnDaf}
 }
 cylinder {<0,0,0>,<0,-0.5,0>,0.15 texture {GrnDaf}}
 sphere {<0,-0.5,0>,0.15 texture {GrnDaf}}
 translate <0,0.5,0>
};
#declare Daffodil = union {
 #declare DafH = 5+rand(Rnd);
 object{
  DafTop
  rotate <0,0,65+30*rand(Rnd)>
  translate <0,DafH,0>
 }
 cylinder {<0,DafH,0>,<2*rand(Rnd)-1,-0.05,2*rand(Rnd)-1>,0.15 texture {GrnDaf}}
// Leaves
 #if (DafLeaves)
  #declare NLeaf = MinLeaves+(MaxLeaves-MinLeaves)*rand(Rnd);
  #while (NLeaf >0)
   #declare BH = 2.5+1.5*rand(Rnd);
   #declare BR = 1+rand(Rnd);
   #declare BCount = 0;
   blob {
    #while (BCount < 1)
     sphere {<1,BH*BCount,0>,1,1 scale <0.05,1,1> rotate <0,360*BR*BCount,0>}
     #declare BCount = BCount + 0.025;
    #end
    rotate <0,360*rand(Rnd),0>
    rotate <15 -30*rand(Rnd),0,15 -30*rand(Rnd)>
    translate <4*rand(Rnd)-2,0,4*rand(Rnd)-2>
    texture {GrnDaf}
   }
   #declare NLeaf = NLeaf -1;
  #end
 #end
 rotate <0,-90+MinDrot+MaxDrot*rand(Rnd),0>
 scale 0.25
};
