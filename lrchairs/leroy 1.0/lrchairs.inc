//This file is licensed under the terms of the CC-LGPL

// Cheap Chair with Texture options macro

// CP_Chair macro(Cp_Ftex,Cp_Stex)
// chair faces the -z direction 
// zero point is inbetween back legs
// Vers: 3.6
// Auth: Leroy Whetstone Email llrwii@joplin.com

//Cp_Ftex=frame texure Cp_Stex=Seat texure
#macro Cp_Chair(Cp_Ftex,Cp_Stex)
 #local in=1/12;
 #local Leg=union{cone{0,.05,-y*18*in,.04}sphere{-y*18*in,.04} sphere{0,.05}}
 #local Bac=union{cylinder{0,y*20*in,.05}sphere{y*20*in,.05}}
 union{
  //frame
  object{Leg rotate <-5,0,5> translate<6*in,0,6*in>}
  object{Leg rotate <-5,0,-5> translate<-6*in,0,6*in>}
  object{Leg rotate <6,0,5> translate<6*in,0,-6*in>}
  object{Leg rotate <6,0,-5>translate<-6*in,0,-6*in>}
   cylinder{<6*in,0,5*in><-6*in,0,5*in>,.05}
   cylinder{<-6*in,0,6*in><-6*in,0,-6*in>,.05}
   cylinder{<-6*in,0,-6*in><6*in,0,-6*in>,.05}
   cylinder{<6*in,0,-6*in><6*in,0,6*in>,.05}
  //back frame
  object{Bac rotate <7,0,6> translate<6*in,0,6*in>}
  object{Bac rotate <7,0,-6> translate<-6*in,0,6*in>}
   cylinder{<-5*in,5*in,0><5*in,5*in,0>,.05 rotate x*7
    translate z*6*in}
   cylinder{<-4.2*in,15*in,0><4.2*in,15*in,0>,.05 rotate x*7
    translate z*6*in}
   cylinder{<-4*in,19.9*in,0><4*in,19.9*in,0>,.05 rotate x*7
    translate z*6*in}
   //seat
  union{
   box{<6.5*in,.05,5*in><-6.5*in,1*in+.05,-6.5*in>} 
   cylinder{<6.5*in,.05+.5*in,5*in><6.5*in,.05+.5*in,-6.5*in>,.5*in}
   cylinder{<-6.5*in,.05+.5*in,5*in><-6.5*in,.05+.5*in,-6.5*in>,.5*in}
   cylinder{<-6.5*in,.05+.5*in,-6.5*in><6.5*in,.05+.5*in,-6.5*in>,.5*in}
   cylinder{<-6.5*in,.05+.5*in,5*in><6.5*in,.05+.5*in,5*in>,.5*in}
   sphere{<-6.5*in,.05+.5*in,-6.5*in>,.5*in}
   sphere{<6.5*in,.05+.5*in,-6.5*in>,.5*in}
   sphere{<-6.5*in,.05+.5*in,5*in>,.5*in}
   sphere{<6.5*in,.05+.5*in,5*in>,.5*in}
   texture{Cp_Stex}}
   //back rest
  union{box{<-5.5*in,0,0><0,12*in,-in> rotate -z*5} 
        box{<5.5*in,0,0><0,12*in,-in> rotate z*5}
         cylinder{<5.5*in,-.05,-.5*in><5.5*in,12*in,-.5*in>,.5*in rotate z*5}
         cylinder{<-5.5*in,-.05,-.5*in><-5.5*in,12*in,-.5*in>,.5*in rotate -z*5}
        box{<-4.5*in,11*in,0><4.5*in,12.5*in,-in>}//top
         cylinder{<-4.55*in,12.5*in,-.5*in><4.55*in,12.5*in,-.5*in>,.5*in}
         sphere{<4.4*in,12.5*in,-.5*in>,.5*in}
         sphere{<-4.4*in,12.5*in,-.5*in>,.5*in}
        box{<-5.5*in,0,0><5.5*in,1*in,-in>}//bottom
         cylinder{<-5.5*in,0,-.5*in><5.5*in,0,-.5*in>,.5*in}
         sphere{<-5.5*in,0,-.5*in>,.5*in}
         sphere{<5.5*in,0,-.5*in>,.5*in}
        translate y*5*in rotate x*7 translate z*(6*in-.05)
        texture{Cp_Stex}}  
 texture{Cp_Ftex}
 //adjust zero point
 translate <0,18*in+.02,-7.6*in>
 }
#end

