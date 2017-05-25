// This file is licensed under the terms of the CC-LGPL

// Persistence of Vision Ray Tracer Scene Description File
// File: Pillars.inc
// Vers: 2.0 (for POV 3.6+)
// Desc: columns
// Date: 05/29/97 updated 9/27/2009
// Auth: Tim Attwood
//
// Pillar1 -- a roundish pillar with square cap and squarish base with lathe
// Pillar2 -- a square pillar with fluted cap and squareish base
// Pillar3 -- a smooth roundish pillar with fluted cap and roundish base


#declare Cap1 = difference{
 union {
  box {<-0.3,0,-0.3>,<0.3,0.1,0.3>}
  cylinder { <-0.3,0,-0.3>,<-0.3,0,0.3>, 0.1}
  cylinder { <0.3,0,-0.3>,<0.3,0,0.3>,0.1}
 }
 sphere {<-0.3,0,-0.3>,0.05}
 sphere {<-0.3,0,0.3>,0.05}
 sphere {<0.3,0,-0.3>,0.05}
 sphere {<0.3,0,0.3>,0.05}
};
#declare Base1 = union {
 box { <-0.3,0,-0.3>,<0.3,0.08,0.3>}
 lathe {
  linear_spline // linear_spline | quadratic_spline | cubic_spline
  8, // number of points
  <0, 0>, <0.28, 0>, <0.3,0.02>, <0.3,0.04>, <0.24,0.08>,
  <0.2,0.12>,<0,0.12>,<0,0>
  translate <0,0.08,0>
 }
};
#declare Post1 = difference{
  cylinder { < 0,0,0 >, < 0,1.7,0 >,  0.2 }
  cylinder { < 0,-1,-0.2 >, < 0,2,-0.2 >,  0.05 }
  cylinder { < 0,-1,0.2 >, < 0,2,0.2 >,  0.05 }
  cylinder { < -0.2,-1,0 >, < -0.2,2,0 >,  0.05 }
  cylinder { < 0.2,-1,0 >, < 0.2,2,0 >,  0.05 }
  cylinder { < -0.1414,-1,-0.1414 >, < -0.1414,2,-0.1414 >,  0.05 }
  cylinder { <  0.1414,-1,-0.1414 >, <  0.1414,2,-0.1414 >,  0.05 }
  cylinder { < -0.1414,-1, 0.1414 >, < -0.1414,2, 0.1414 >,  0.05 }
  cylinder { <  0.1414,-1, 0.1414 >, <  0.1414,2, 0.1414 >,  0.05 }
 };
#declare Pillar1 = union {
 object {
  Post1
  translate <0,.2,0>
 }
 object {
  Cap1
  translate <0,1.9,0>
 }
 object {
  Base1
 }
};
#declare Flute = difference {
 sphere {<0,0,0>,0.5
  scale <.5,1,.5>
  }
 sphere {<0,0,0>,0.40
  scale <.5,1.23,.5>
  }
 box {<-1,-1,-1>,<0,1,1>
  rotate <0,-15,0>
  }
 box {<0,-1,-1>,<1,1,1>
  rotate <0,15,0>
  }
 box {<-1,-1,-1>,<1,0,1>
  }
 scale <1,1,1>
 rotate<0,180,0>
 translate <0,0,0.44>
};
#declare Cap2 = union {
 object { Flute rotate <0,0,0> }
 object { Flute rotate <0,45,0> }
 object { Flute rotate <0,90,0> }
 object { Flute rotate <0,135,0> }
 object { Flute rotate <0,180,0> }
 object { Flute rotate <0,225,0> }
 object { Flute rotate <0,270,0> }
 object { Flute rotate <0,315,0> }
 object { Flute rotate <0,22.5,0> translate <0,0.25,0>}
 object { Flute rotate <0,67.5,0> translate <0,0.25,0>}
 object { Flute rotate <0,112.5,0> translate <0,0.25,0>}
 object { Flute rotate <0,157.5,0> translate <0,0.25,0>}
 object { Flute rotate <0,202.5,0> translate <0,0.25,0>}
 object { Flute rotate <0,247.5,0> translate <0,0.25,0>}
 object { Flute rotate <0,292.5,0> translate <0,0.25,0>}
 object { Flute rotate <0,337.5,0> translate <0,0.25,0>}
 superellipsoid {
  <.3,.3>
  scale <.3,.05,.3>
  translate <0,.05,0>
  }
 superellipsoid {
  <.3,.3>
  scale <.3,.05,.3>
  translate <0,.7,0>
  }
 cylinder {
  <0,0.01,0>,<0,.74,0>,0.25
  }
};
#declare Base2 = union {
 superellipsoid {
  <.3,.3>
  scale <.3,.05,.3>
  translate <0,.05,0>
  }
 superellipsoid {
  <.3,.3>
  scale <.3,.05,.3>
  translate <0,.15,0>
  }
 superellipsoid {
  <.3,.3>
  scale <.3,.05,.3>
  translate <0,.25,0>
  }
 };
#declare Post2 = union {
 box {<-0.2,0,-0.2>,<0.2,1,0.2>}
 cylinder{<-0.2,0,-0.2>,<-0.2,1,-0.2>,0.04}
 cylinder{<-0.12,0,-0.2>,<-0.12,1,-0.2>,0.04}
 cylinder{<-0.04,0,-0.2>,<-0.04,1,-0.2>,0.04}
 cylinder{<0.04,0,-0.2>,<0.04,1,-0.2>,0.04}
 cylinder{<0.12,0,-0.2>,<0.12,1,-0.2>,0.04}
 cylinder{<0.2,0,-0.2>,<0.2,1,-0.2>,0.04}

 cylinder{<-0.2,0,0.2>,<-0.2,1,0.2>,0.04}
 cylinder{<-0.12,0,0.2>,<-0.12,1,0.2>,0.04}
 cylinder{<-0.04,0,0.2>,<-0.04,1,0.2>,0.04}
 cylinder{<0.04,0,0.2>,<0.04,1,0.2>,0.04}
 cylinder{<0.12,0,0.2>,<0.12,1,0.2>,0.04}
 cylinder{<0.2,0,0.2>,<0.2,1,0.2>,0.04}

 cylinder{<0.2,0,0.12>,<0.2,1,0.12>,0.04}
 cylinder{<0.2,0,0.04>,<0.2,1,0.04>,0.04}
 cylinder{<0.2,0,-0.04>,<0.2,1,-0.04>,0.04}
 cylinder{<0.2,0,-0.12>,<0.2,1,-0.12>,0.04}

 cylinder{<-0.2,0,0.12>,<-0.2,1,0.12>,0.04}
 cylinder{<-0.2,0,0.04>,<-0.2,1,0.04>,0.04}
 cylinder{<-0.2,0,-0.04>,<-0.2,1,-0.04>,0.04}
 cylinder{<-0.2,0,-0.12>,<-0.2,1,-0.12>,0.04}
};
#declare Pillar2 = union {
 object {
  Cap2
  translate <0,1.25,0>
  }
 object {
  Post2
  translate <0,0.275,0>
  }
 object {
  Base2
  translate <0,0,0>
  }
 };
#declare Cap3 = union {
 object { Flute rotate <0,0,0> }
 object { Flute rotate <0,45,0> }
 object { Flute rotate <0,90,0> }
 object { Flute rotate <0,135,0> }
 object { Flute rotate <0,180,0> }
 object { Flute rotate <0,225,0> }
 object { Flute rotate <0,270,0> }
 object { Flute rotate <0,315,0> }
 object { Flute rotate <0,22.5,0> translate <0,0.25,0>}
 object { Flute rotate <0,67.5,0> translate <0,0.25,0>}
 object { Flute rotate <0,112.5,0> translate <0,0.25,0>}
 object { Flute rotate <0,157.5,0> translate <0,0.25,0>}
 object { Flute rotate <0,202.5,0> translate <0,0.25,0>}
 object { Flute rotate <0,247.5,0> translate <0,0.25,0>}
 object { Flute rotate <0,292.5,0> translate <0,0.25,0>}
 object { Flute rotate <0,337.5,0> translate <0,0.25,0>}
 superellipsoid {
  <0.3,1>
  scale <.3,.05,.3>
  translate <0,.05,0>
  }
 superellipsoid {
  <0.3,1>
  scale <.3,.05,.3>
  translate <0,.7,0>
  }
 cylinder {
  <0,0.01,0>,<0,.74,0>,0.25
  }
};
#declare Post3 = difference {
 sphere {
  <0,0,0>,0.3
  scale <1,3,1>
  translate <0,0.55,0>
 }
 box {<-1,-100,-1>,<1,0,1>}
 box {<-1,1.1,-1>,<1,100,1>}
};
#declare Base3 = union {
 cylinder {<0,0.074,0>,<0,0.2,0>,0.25}
 torus {
  0.25,0.02
  translate <0,0.18,0>
 }
 difference {
  cylinder {<0,0,0>,<0,0.15,0>,0.3}
  torus {
   0.3,0.05
   scale <1,2,1>
   translate <0,.15,0>
   }
 }
};
#declare Pillar3 = union {
 object {
  Cap3
  translate <0,1.25,0>
 }
 object {
  Post3
  translate <0,0.2,0>
 }
 object {
  Base3
  translate <0,0,0>
  }
};
