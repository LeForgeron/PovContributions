//This file is licensed under the terms of the CC-LGPL

#declare Fast = no;
#declare Scene = 2; // 1-3

#include "WRC_RubiksCube.inc"

camera
{ #switch(Scene)
    #case(1)
    #case(2)
      location <8, 9, -10>*2
      look_at 6.6/2-y*.4
      angle 35
    #break
    #case(3)
      location <8, 9, -10>*2
      look_at 6.6/2+y*4
      angle 40
      #if(!Fast)
        focal_point 0 aperture 1.5 blur_samples 50
      #end
    #break
  #end
}

light_source
{ <20, 30, -10>, 1
  fade_distance 30
  fade_power 2
  #if(!Fast)
    area_light x*4, y*4, 16, 16 jitter adaptive 1 circular orient
  #end
}

light_source
{ <-20, 20, -15>, .5
  fade_distance 30
  fade_power 2
  #if(!Fast)
    area_light x*4, y*4, 16, 16 jitter adaptive 1 circular orient
  #end
}

plane
{ y, 0
  #if(Fast)
    pigment { rgb <1, .9, .7> }
  #else
    texture
    { average texture_map
      { #declare S = seed(0);
        #local ReflColor = .8*<1, .9, .7> + .2*<1,1,1>;
        #declare Ind = 0;
        #while(Ind < 20)
          [1 pigment { rgb <1, .9, .7> }
             normal { bumps .1 translate <rand(S),rand(S),rand(S)>*100 scale .001 }
             finish { reflection { ReflColor*.1, ReflColor*.5 } }
          ]
          #declare Ind = Ind+1;
        #end
      }
    }
  #end
}


#if(Scene = 1)
  object { WRC_RubiksRevenge("") }
#end


#if(Scene = 2)
  object
  { WRC_RubiksRevenge("F2 R2fb'fb'L2 f2 ud'ud' F2f2 ud'ud'")
    translate <-8, 0, 3>
  }

  object
  { WRC_RubiksRevenge("F'f' Rrd2R'r' U'u'Rr d2 U ld'l' U' ldl' R'r'Uu Ff")
    translate -6.6/2 rotate y*20 translate 6.6/2+<4, 0, 2>
  }
#end

#if(Scene = 3)
  object
  { WRC_RubiksRevenge("")
    translate -<6.6/2, 0, 6.6/2> rotate y*160 translate <-6, 0, 7>
  }
  object
  { WRC_RubiksRevenge("")
    rotate z*90 translate x*6.6
    rotate z*50 rotate y*-30 translate <3.65, 0, 8>
  }
  object
  { WRC_RubiksRevenge("")
    rotate <-90, 60, 0> translate <12, 0, 9>
  }
  object
  { WRC_RubiksRevenge("uD'")
    rotate y*45 translate <0, 0, 24>
  }
  object
  { WRC_RubiksRevenge("")
    rotate z*180 translate y*6.6
    rotate y*25 translate <-16, 0, 20>
  }
  object
  { WRC_RubiksRevenge("R2l2")
    rotate z*180 translate y*6.6
    rotate -y*25 translate <-18, 0, 15>
  }
  object
  { WRC_RubiksRevenge("")
    translate <-25, 6.62, 18>
  }
  object
  { WRC_RubiksRevenge("")
    rotate <-90, -60, 0>
    translate <-12, 0, 35>
  }
#end
