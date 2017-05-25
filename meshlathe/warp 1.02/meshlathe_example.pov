//This file is licensed under the terms of the CC-LGPL

#include "MeshLathe.inc"

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

object
{ MeshLathe(Spline, 80, 20)
  pigment { rgb 1 } finish { specular .5 }
  translate <3, 0, 0>
}

#declare MeshLatheDebug = 2;
#declare MeshLatheDebugNormalColor = x;
object
{ MeshLathe(Spline, 80, 20)
  pigment { rgb 1 } finish { specular .5 }
}

#declare MeshLatheDebug = 3;
object
{ MeshLathe(Spline, 80, 20)
  pigment { rgb 1 } finish { specular .5 }
  translate <-3, 0, 0>
}
