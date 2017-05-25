//
// BLobCube sample scene by Nekar Xenos 
//
// This file is licensed under the terms of the CC-LGPL  
//
// Persistence of Vision Ray Tracer Scene Description File
// File: ?.pov
// Vers: 3.6
// Desc: Basic Scene Example
// Date: 22/09/2008
// Auth: - Nekar Xenos - 
//
// Warning Clouds render very slow!!

global_settings{
  //assumed_gamma 1
  max_trace_level 100 
  //radiosity{}
}
#default{texture{finish{ambient 0}}}


#include "nxplanets.inc" 




// nxplanet(Size,Terra,Cloud,AtmosphereCol,Gas,GasLines,GasTurb,GasTint,RingCount,RingTint,Vulcanic,Sea,SeaCol,TerraCol,Foilage,FoilageCol,Ice)

#declare Size=1; 
#declare Terra=1;
#declare Cloud=0;
#declare AtmosphereCol=< 0.1, 0.2, 1>;
#declare Gas=0; 
#declare GasLines=10;
#declare GasTurb=.3;  
#declare GasTint=<.3,.5,1>;
#declare RingCount=10;
#declare RingTint=<.1,.2,.3>;
#declare Vulcanic=0;
#declare Sea=1;
#declare SeaCol=<0,.1,.3>;
#declare TerraCol=<.3,.2,.1>;
#declare Foilage=1;
#declare FoilageCol=<.01,.1,.15>;
#declare Ice=1;

nxplanet(Size,Terra,Cloud,AtmosphereCol,Gas,GasLines,GasTurb,GasTint,RingCount,RingTint,Vulcanic,Sea,SeaCol,TerraCol,Foilage,FoilageCol,Ice)


light_source {<2,.1,3>*1000000, color <2.1,2,1.9>*2 media_attenuation on}
sphere {<2,.1,3>*100, 7.5
	texture {
		pigment {color <2.1,2,1.9>/2}
		finish {ambient 10 diffuse 0}
	}
	no_shadow
}   


///////////////////////////////////////////////////////////////
////////////// Camera ////////////////////////////////////////
 
camera{
  location <0,.2,1>//<0,.299,0>//<0,0,.3>//<2,.1,3>/15//<0,0.2989, 0>//<0,.30055,0>//<0,.5,0>    // <.5,0,-1.2> 
  rotate <0,0,-30>
  //up y 
  //sky <0,1,0>
  right x*image_width/image_height
  look_at 0 // 0//<2,.1,3>*1000000//<0,1,0>//<0,-.3,1> //<0,-.4,1> //   

}  