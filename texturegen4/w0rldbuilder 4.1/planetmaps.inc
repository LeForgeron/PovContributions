// Planet maps include file for TextureGen. 
// This file is licensed under the terms of the CC-LGPL.

// Global controls for turbulence and detail are now in this file.

#declare Complexity= 2; 
#declare EarthCloudsComplexity= 3;
#declare MarsCloudsComplexity= 6;
#declare Detail= 15;
#declare NoiseGenerator= 3;
#declare NoiseType=  pigment { wrinkles }

#declare EarthMap=
texture {
  pigment {
  NoiseType noise_generator NoiseGenerator
  turbulence Complexity
  octaves 10
  color_map {
  [ 0  color red 1 green 1 blue 1]
  [ 0.3  color red 0.8 green 0.6 blue 0.5]
  [ 0.6  color red 0.0 green 0.3 blue 0.0]
  [ 0.6  color red 0.0 green 0.0 blue 0.8]
  [ 1  color red 0.0 green 0.0 blue 0.3]

}

}

}

#declare EarthBump=
texture {
  pigment {
  NoiseType noise_generator NoiseGenerator
  turbulence Complexity
  octaves Detail
  color_map {
  [ 0.0  color red 1 green 1 blue 1]
  [ 0.6  color red 0 green 0 blue 0]
  [ 1.0  color red 0 green 0 blue 0]

}

}

}

#declare EarthSpec=
texture {
  pigment {
  NoiseType noise_generator NoiseGenerator
  turbulence Complexity
  octaves Detail
  color_map {
  [ 0.0  color red 0 green 0 blue 0]
  [ 0.6  color red 0 green 0 blue 0]
  [ 0.6  color red 1 green 1 blue 1]
  [ 1.0  color red 1 green 1 blue 1]

}

}

}

#declare MarsMap=
texture {
  pigment {
  NoiseType noise_generator NoiseGenerator
  turbulence Complexity
  octaves Detail
  color_map {
  [ 0  color rgb < 0.8470588,  0.5372549,  0.3882353 >]
  [ 0.5  color rgb < 0.670588235294117647,  0.39607843137254902,  0.305882352941176471 >]
  [ 0.6  color rgb < 0.372549019607843137,  0.313725490196078431,  0.270588235294117647 >]
  [ 0.7  color rgb < 0.20392156862745098,  0.207843137254901961,  0.262745098039215686 >]
  [ 1  color rgb < 0.176470588235294118,  0.184313725490196078,  0.290196078431372549 >]

}

}

}

#declare MarsBump=
texture {
  pigment {
  NoiseType noise_generator NoiseGenerator
  turbulence Complexity
  octaves Detail
  color_map {
  [ 0  color rgb < 0,  0,  0 >]
  [ 0.3  color rgb < 0.3,  0.3,  0.3 >]
  [ 0.5  color rgb < 0.4,  0.4,  0.4 >]
  [ 0.7  color rgb < 0.5,  0.5,  0.5 >]
  [ 1  color rgb < 1, 1, 1 >]

}

}

}

#declare EarthClouds=
texture {
  pigment {
  NoiseType noise_generator NoiseGenerator
  turbulence EarthCloudsComplexity
  octaves Detail
  color_map {
  [ 0.0  color red 1 green 1 blue 1]
  [ 0.7  color red 0 green 0 blue 0]
  [ 1.0  color red 0 green 0 blue 0]

}

}

}

#declare MarsClouds=
texture {
  pigment {
  NoiseType noise_generator NoiseGenerator
  turbulence MarsCloudsComplexity
  octaves Detail
  color_map {
  [ 0.0  color red 1 green 1 blue 1]
  [ 0.1  color red 0 green 0 blue 0]
  [ 1.0  color red 0 green 0 blue 0]

}

}

}

#declare Raw=
texture {
  pigment {
  NoiseType noise_generator NoiseGenerator
  turbulence Complexity
  octaves Detail
  color_map {
  [ 0.0  color red 0 green 0 blue 0]
  [ 1.0  color red 1 green 1 blue 1]

}

}

}
