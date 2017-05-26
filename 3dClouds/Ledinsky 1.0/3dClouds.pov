#version 3.7;
global_settings{ assumed_gamma 1.0 }

camera { location <0,2,0>
direction z
up y
right x*image_width/image_height
}

plane{ y,0 texture { checker 
texture { pigment { color srgb 1 }},
texture {pigment { color srgb 0 }}
} }

light_source { <0,2000,0>,1 }

sky_sphere { pigment { color srgb <0.3, 0.6,0.9> }}

#declare clouds_ambient = 2;
#declare clouds_fill = 0.6;
#include "3dclouds.inc"


