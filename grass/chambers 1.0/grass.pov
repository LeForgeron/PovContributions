// This file is licensed under the terms of the CC-LGPL. 

#include "functions.inc"
#include "Grass.inc"

camera {
	location <0,5,-10>*3
	look_at -y*2
}

#declare wnd_fun = function {f_bozo((x+clock)/4,0,(z+clock)/3)}

#declare rnd = seed(0);

#declare g = bdc_grass(<-15,0,-15>, <15, 0, 15>, 10, 1/12, 3, 64, -y*2, x+z, wnd_fun, rnd)
object {
	g
	texture {
		pigment {color rgbf <0,1,0,.5>}
		finish {specular 1}
	}
}

light_source {
	<10,10,-20> color rgb 1
}
