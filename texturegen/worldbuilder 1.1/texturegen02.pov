//////////////////////////////////////////////////////////////
// File: texturegen02.pov                                   //
// Vers: 3.6                                                //
// Desc: An upgraded version of my TextureGen map generator.//
// This new version includes a terrestrial color map, as    //
// well as an upgraded version of the bump map included in  //
// the original. This new bump map is 50% darker, as the    //
// oceans are represented with a low, flat surface.         //
// Included in this new release is a specular/ocean mask,   //
// useful in other graphics programs as well as POV-Ray (?).//
// Date: November 6, 2009                                   //
// Auth: worldbuilder                                       //
// This file is licensed under the terms of the CC-LGPL     //
// I don't like having to say that. >:-(                    //
//////////////////////////////////////////////////////////////

#declare MapScale=0.5;
#declare RandomSeed=<0, 0, 0>;
#declare Complexity=1;
#declare Details=8;
#declare ColorMap=
texture {
  pigment {
  wrinkles noise_generator 3
  turbulence Complexity
  octaves Details
  color_map {
  [ 0.0  color red 1 green 1 blue 1]
  [ 0.3  color red 0.8 green 0.6 blue 0.5]
  [ 0.4  color red 0.0 green 0.3 blue 0.0]
  [ 0.4  color red 0.0 green 0.0 blue 0.8]
  [ 1.0  color red 0.0 green 0.0 blue 0.3]

}

}
finish { ambient 1 }
}

#declare BumpMap=
texture {
  pigment {
  wrinkles noise_generator 3
  turbulence Complexity
  octaves Details
  color_map {
  [ 0.0  color red 1 green 1 blue 1]
  [ 0.4  color red 0 green 0 blue 0]
  [ 1.0  color red 0 green 0 blue 0]

}

}
finish { ambient 1 }
}

#declare SpecMap=
texture {
  pigment {
  wrinkles noise_generator 3
  turbulence Complexity
  octaves Details
  color_map {
  [ 0.0  color red 0 green 0 blue 0]
  [ 0.3  color red 0 green 0 blue 0]
  [ 0.4  color red 0 green 0 blue 0]
  [ 0.4  color red 1 green 1 blue 1]
  [ 1.0  color red 1 green 1 blue 1]

}

}
finish { ambient 1 }
}

camera {
  spherical
  location RandomSeed      
  look_at  <0,0,1>     
  angle 360             
        180             
}

sphere {
  RandomSeed
  MapScale       
  texture { ColorMap }
}




