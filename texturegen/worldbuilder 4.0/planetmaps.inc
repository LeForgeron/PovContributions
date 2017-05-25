// This file is licensed under the terms of the CC-LGPL.
#declare EarthMap=
texture {
  pigment {
  bozo noise_generator 3
  turbulence 2
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

#declare EarthBumpMap=
texture {
  pigment {
  bozo noise_generator 3
  turbulence 2
  octaves 10
  color_map {
  [ 0.0  color red 1 green 1 blue 1]
  [ 0.6  color red 0 green 0 blue 0]
  [ 1.0  color red 0 green 0 blue 0]

}

}

}

#declare EarthSpecMap=
texture {
  pigment {
  bozo noise_generator 3
  turbulence 2
  octaves 10
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
  bozo noise_generator 3
  turbulence 2
  octaves 10
  color_map {
  [ 0  color rgb < 0.8470588,  0.5372549,  0.3882353 >]
  [ 0.5  color rgb < 0.670588235294117647,  0.39607843137254902,  0.305882352941176471 >]
  [ 0.6  color rgb < 0.372549019607843137,  0.313725490196078431,  0.270588235294117647 >]
  [ 0.7  color rgb < 0.20392156862745098,  0.207843137254901961,  0.262745098039215686 >]
  [ 1  color rgb < 0.176470588235294118,  0.184313725490196078,  0.290196078431372549 >]

}

}

}

#declare MarsBumpMap=
texture {
  pigment {
  bozo noise_generator 3
  turbulence 2
  octaves 10
  color_map {
  [ 0  color rgb < 0.8470588,  0.5372549,  0.3882353 >]
  [ 0.5  color rgb < 0.670588235294117647,  0.39607843137254902,  0.305882352941176471 >]
  [ 0.6  color rgb < 0.372549019607843137,  0.313725490196078431,  0.270588235294117647 >]
  [ 0.7  color rgb < 0.20392156862745098,  0.207843137254901961,  0.262745098039215686 >]
  [ 1  color rgb < 0.176470588235294118,  0.184313725490196078,  0.290196078431372549 >]

}

}

}

#declare EarthClouds=
texture {
  pigment {
  bozo noise_generator 3
  turbulence 3
  octaves 10
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
  bozo noise_generator 3
  turbulence 6
  octaves 10
  color_map {
  [ 0.0  color red 1 green 1 blue 1]
  [ 0.1  color red 0 green 0 blue 0]
  [ 1.0  color red 0 green 0 blue 0]

}

}

}
