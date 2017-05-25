//This file is licensed under the terms of the CC-LGPL

#include "gardenchair.inc"

camera { location <-5, 5, -10> look_at y*1.8 angle 35 }
light_source
{ <10, 50, -25>, 1
  area_light x*4,z*4, 12, 12 adaptive 2
  fade_distance 50 fade_power 2
}
light_source
{ <-40, 30, 0>, <.8,.5,.2>*.7
  area_light x*4,z*4, 12, 12 adaptive 1
  fade_distance 50 fade_power 2
}
plane { y, 0 pigment { rgb <.5, 1, .5> } }

GardenChair
