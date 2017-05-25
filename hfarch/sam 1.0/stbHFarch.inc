/*

stbHFarch.inc
2007 Sam Benge
This file is licensed under the terms of the CC-LGPL

*/

// this macro resets all the include file settings
#macro stbHFarch_reset_values()

 #declare stbHFarch_brick_pattern =
  pigment_map{
   [0.0 rgb 0.0]
   [0.25 rgb .875]
   [0.5 rgb 1.0]
  } 
 
 #declare stbHFarch_brick_pattern_offset=0;
 #declare stbHFarch_brick_pattern_reset=no;
 #ifdef(stbHFarch_pattern_override)
  #undef stbHFarch_pattern_override
 #end
 
 #declare stbHFarch_brick_intersection=0;
 #declare stbHFarch_brick_mirror=no;
 #declare stbHFarch_clipping_mode=1;
 #ifdef(stbHFarch_brick_clipping_depth)
  #undef stbHFarch_brick_clipping_depth
 #end

 #declare stbHFarch_brick_smooth=yes;
 #declare stbHFarch_brick_res=<100,100>;
 
 #declare stbHFarch_brick_texture_offset=<0,0,0>; 
 #ifdef(stbHFarch_brick_texture)
  #undef stbHFarch_brick_texture
 #end
 
 
#end

// initialize default settings
stbHFarch_reset_values()

// declare brick, but don't display it
#macro stbHFarch_brick_declare(brad,brthk,brarch,brdiv,brdepth,pv,tv)
 #local ang=brarch/brdiv;
 #local rd2=brad;
 #local egr=brthk/rd2;
 #local bb=(cos(pi/360*ang)*(1-egr));
 #local bs=(sin(pi/360*ang))/2;

 #local brick_outline=
 difference{
  cylinder{-z,z,1}
  cylinder{-z*1.1,z*1.1,1-egr}
  intersection{
   plane{x,0 rotate z*ang/2 inverse}
   plane{x,0 rotate -z*ang/2 }
   inverse
  }
 }
 
 #local brick_pattern=
  pigment{
   pigment_pattern{ object{ brick_outline 0,1 }}
   pigment_map{
    #if(stbHFarch_clipping_mode!=3)
     [0 rgb 0]
    #end
    [1
     #local brfnc=
     function{
      min(
       abs(
        x*cos(-radians(ang/2))
        -y*sin(-radians(ang/2))
       ),
       abs(
        x*cos(-radians(ang/2))
        +y*sin(-radians(ang/2))
       ),
       -sqrt(x*x+y*y)+1,
       sqrt(x*x+y*y)-(1-egr)
      )*rd2
     }
     
     pigment_pattern{
      function{
       select(brfnc(x,y,z)-1,brfnc(x,y,z),1)
      }
      
      #if(stbHFarch_brick_pattern_reset=no)
       translate -y*(2-brthk/rd2)/2
       
       #else
        rotate z*(ang*pv+ang/2+90)
      #end
      scale rd2/1
     }
  
     #ifdef(stbHFarch_brick_pattern_offset)
      translate z*pv*stbHFarch_brick_pattern_offset
     #end
     pigment_map{stbHFarch_brick_pattern }
     scale 1/rd2
     #if(stbHFarch_brick_pattern_reset=no)
      translate y*(2-brthk/rd2)/2
      
      #else
       rotate -z*(ang*pv+ang/2+90)
       scale -1
     #end
     
    ]
   }
   translate<0,-(1+bb)/2,0>
   scale<0.5/bs,2/(1-bb),1>
   scale .5 translate(x+y)/2
  }
 
 #ifdef(stbHFarch_pattern_override)
  #local brick_pattern=
  pigment{
   
   pigment_pattern{
    pigment_pattern{
     pigment_pattern{
      stbHFarch_pattern_override
      rotate x*90
      scale<-1,1,1>
      #ifdef(stbHFarch_brick_pattern_offset)
      translate y*pv*stbHFarch_brick_pattern_offset
     #end
      
     }
      scale .5 translate (x+z)/2
      scale<radians(ang)/pi/2,1,brthk/rd2>
      translate z*(rd2-brthk)/rd2
      warp{cylindrical }       
      rotate -y*(90-ang/2) 
     
     rotate x*270
     
    }
   }  
   translate<0,-(1+bb)/2,0> scale<0.5/bs,2/(1-bb),1>
   
   scale .5 translate (x+y)/2
   #if(stbHFarch_brick_pattern_offset>0&stbHFarch_brick_pattern_reset=yes)
    translate z*pv*stbHFarch_brick_pattern_offset
   #end
  }
 #end
 
 #declare stbHFarch_brick=
 height_field{
  function stbHFarch_brick_res.x,stbHFarch_brick_res.y{
   pigment{
    brick_pattern
   }
  }
  
  #if(stbHFarch_brick_smooth=yes)
   smooth
  #end
  translate -(x+z)/2
  rotate x*270
  scale<1,-1,1>
  scale<bs*2,0.5*(1-bb),0.25>*4
  translate<0,(1+bb),0>
  scale<0.5,0.5,1>
   
   #if(stbHFarch_clipping_mode=1)
   
    #ifndef(stbHFarch_brick_clipping_depth)
     clipped_by{plane{z,-brdepth/100 }}
     translate z*brdepth/100
     #else
      clipped_by{plane{z,-stbHFarch_brick_clipping_depth/brdepth }}
      translate z*stbHFarch_brick_clipping_depth/brdepth
    #end
    
   #end
   
   #if(stbHFarch_clipping_mode=2|stbHFarch_clipping_mode=3)
    clipped_by{
     object{brick_outline
      translate -y*(1-bb/rd2)
      scale <1,1,1>
      translate y*(1-bb/rd2)
     }
    }
   #end
   
  
  scale<1,1,brdepth>
 }
 #if(stbHFarch_brick_mirror=yes)
  #declare stbHFarch_brick=
  union{ 
   object{stbHFarch_brick}
   object{stbHFarch_brick
    scale<1,1,-1>
   }
   
  }
 #end
 #if(stbHFarch_brick_intersection>0)
  #declare stbHFarch_brick=
  intersection{ 
   object{stbHFarch_brick }
   #if(stbHFarch_brick_mirror=yes)
    object{brick_outline
     translate -y*(2-brthk/rd2)/2
     scale <1-stbHFarch_brick_intersection,1-stbHFarch_brick_intersection,brdepth+.01>
     
     translate y*(2-brthk/rd2)/2
    }
    #else
     object{brick_outline
      translate -z
      translate -y*(2-brthk/rd2)/2
      scale <1-stbHFarch_brick_intersection,1-stbHFarch_brick_intersection,brdepth/2+.01>
      translate y*(2-brthk/rd2)/2
     }
   #end
   
  }
 #end
 
#end

// create single brick instance
#macro stbHFarch_single_brick(brad,brthk,brdiv,brdepth)
 stbHFarch_brick_declare(brad,brthk,360,brdiv,brdepth,0,0)
 #local rd2=brad;
 object{stbHFarch_brick scale<rd2,rd2,1> }
#end

// create brick arch
#macro stbHFarch_brick_arch(brad,brthk,brarch,brdiv,brdepth)
 
 #local ang=brarch/brdiv;
 #local rd2=brad;
 #local egr=brthk/rd2;
 #local bb=(cos(pi/brarch*ang)*(1-egr));
 #local bs=(sin(pi/brarch*ang))/2;
 stbHFarch_brick_declare(brad,brthk,brarch,brdiv,brdepth,0,1)
 
 union{
  #local V=0;
  #local vv=0;
  #while(V<brarch-1)
    #if((stbHFarch_brick_pattern_offset>0|stbHFarch_brick_pattern_reset=yes)&vv>0)
     #ifndef(stbHFarch_pattern_override)
      stbHFarch_brick_declare(brad,brthk,brarch,brdiv,brdepth,vv,1)
     #end
    #end
    
    object{ stbHFarch_brick
     scale<rd2,rd2,1>
     #ifdef(stbHFarch_brick_texture)
      texture{stbHFarch_brick_texture translate<0,brad-(brthk)/2,0>+stbHFarch_brick_texture_offset*vv}
     #end
     rotate z*V
    }
    
   #local V=V+ang;
   #local vv=vv+1;
  #end
  rotate z*(270+ang/2)
 }
#end

// *********************************************
// pillar stuff

#macro stbHFarch_pillar_brick_declare(brad,brthk,brheight,brdepth,pv,dv)

 #declare stbHFarch_pillar_brick=
 height_field{
  
  
   #local pbrick_pattern=
   pigment{
    pigment_pattern{
     #local pfunc=
      function{
       min(
        -abs(x)+brthk,
        -abs(y)+brheight
       )/2
      }
     function{
      select(pfunc(x,y,z)-1,pfunc(x,y,z),1)
     }
     scale .5
    
     #if(stbHFarch_brick_pattern_reset=yes)
      #if(brad>=0)
       translate<(brad-brthk/2),(-dv+.5+pv)*brheight,0>
       #else
        translate<(brad+brthk/2),(-dv+.5+pv)*brheight,0>
      #end
     #end
    
    }
    pigment_map{stbHFarch_brick_pattern}
    
    #if(stbHFarch_brick_pattern_reset=yes)
     #if(brad>=0)
      translate<-(brad-brthk/2),-(-dv+.5+pv)*brheight,0>
      #else
       translate<-(brad+brthk/2),-(-dv+.5+pv)*brheight,0>
     #end
    #end
    
    #if(stbHFarch_brick_pattern_offset>0)
     translate z*pv*stbHFarch_brick_pattern_offset
    #end
    
    scale 2
    scale<1/brthk,1/brheight,1>/2
    scale -1 translate(x+y)/2
    
    
   }
   #ifdef(stbHFarch_pattern_override)
    #local pbrick_pattern=
     pigment{stbHFarch_pattern_override scale -.5 translate(x+y)/2
      #ifdef(stbHFarch_brick_pattern_offset)
       translate z*pv*stbHFarch_brick_pattern_offset
      #end
     }
   #end
  
  
  
  function stbHFarch_brick_res.x,stbHFarch_brick_res.y{
   pigment{
    pbrick_pattern
    
   }
  }
  #if(stbHFarch_brick_smooth=yes)
   smooth
  #end
  rotate x*270
  #if(stbHFarch_clipping_mode=1)
   
    #ifndef(stbHFarch_brick_clipping_depth)
     clipped_by{plane{z,-brdepth/100 }}
     translate z*brdepth/100
     #else
      clipped_by{plane{z,-stbHFarch_brick_clipping_depth/brdepth }}
      translate z*stbHFarch_brick_clipping_depth/brdepth
    #end
    
   #end
  
  translate<-.5,0,0>
  scale<-brthk,brheight,brdepth>
  
  
 }
 
 #if(stbHFarch_brick_mirror=yes)
  #declare stbHFarch_pillar_brick=
  union{ 
   object{stbHFarch_pillar_brick}
   object{stbHFarch_pillar_brick
    scale<1,1,-1>
   }
   
  }
 #end
 
 #if(stbHFarch_brick_intersection>0)
  #declare stbHFarch_pillar_brick=
   intersection{
    object{stbHFarch_pillar_brick}
    
    box{
     <
      -brthk/2+stbHFarch_brick_intersection,
      stbHFarch_brick_intersection,
      -brdepth
     >,
     <brthk/2-stbHFarch_brick_intersection,
      brheight-stbHFarch_brick_intersection,
      brdepth
     >
     
    }
   }
 #end

 
#end

// create single brick instance
#macro stbHFarch_single_pillar_brick(brthk,brheight,brdepth)
 stbHFarch_pillar_brick_declare(0,brthk,brheight,brdepth,0,1)
 
 object{stbHFarch_pillar_brick  }
#end

#macro stbHFarch_pillar(prad, pthk, pht, pdiv, pdpth)
 union{
  #local V=0;
  #local vv=0;
  
  #while(V<pht)
   #if(vv=0)
    stbHFarch_pillar_brick_declare(prad,pthk,pht/pdiv,pdpth,0,pdiv)
    object{stbHFarch_pillar_brick
     #ifdef(stbHFarch_brick_texture)
      texture{stbHFarch_brick_texture translate<0,(pht/pdiv)/2,0>+stbHFarch_brick_texture_offset*vv}
     #end
     translate<prad-pthk/2,V,0>
    }
    #else
    #if((stbHFarch_brick_pattern_offset>0|stbHFarch_brick_pattern_reset=yes)&vv>0)
     #ifndef(stbHFarch_pattern_override)
      stbHFarch_pillar_brick_declare(prad,pthk,pht/pdiv,pdpth,vv,pdiv)
     #end
    #end
    object{stbHFarch_pillar_brick
     #ifdef(stbHFarch_brick_texture)
      texture{stbHFarch_brick_texture translate<0,(pht/pdiv)/2,0>+stbHFarch_brick_texture_offset*vv}
     #end
     translate<prad-pthk/2,V,0>
    }
   #end
   
   #if(vv=0)
    stbHFarch_pillar_brick_declare(-prad,pthk,pht/pdiv,pdpth,0,pdiv)
    object{stbHFarch_pillar_brick
     #ifdef(stbHFarch_brick_texture)
      texture{stbHFarch_brick_texture translate<0,(pht/pdiv)/2,1.5>+stbHFarch_brick_texture_offset*vv}
     #end
     translate<-prad+pthk/2,V,0>
    }
    #else
     #if((stbHFarch_brick_pattern_offset>0|stbHFarch_brick_pattern_reset=yes)&vv>0)
     #ifndef(stbHFarch_pattern_override)
      stbHFarch_pillar_brick_declare(-prad,pthk,pht/pdiv,pdpth,vv,pdiv)
     #end
    #end
    object{stbHFarch_pillar_brick
     #ifdef(stbHFarch_brick_texture)
      texture{stbHFarch_brick_texture translate<0,(pht/pdiv)/2,1.5>+stbHFarch_brick_texture_offset*vv}
     #end
     translate<-prad+pthk/2,V,0>
    }
   #end
   
   #declare V=V+(pht/pdiv);
   #declare vv=vv+1;
  #end
 }
#end
