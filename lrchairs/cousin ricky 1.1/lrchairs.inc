// lrchairs.inc version 1.1
// Persistence of Vision Ray Tracer include file
// POV-Ray Object Collection
//
// A cheap chair with texture options macro.
//
// Copyright 2008 Leroy Whetstone Email llrwii@joplin.com  Some rights reserved.
// Copyright 2014 Richard Callwood III.  Some rights reserved.
// This file is licensed under the terms of the CC-LGPL
// See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
//
// Vers  Date        Comments                                       Author
// ----  ----        --------                                       ------
// 1.0   2008-08-21  Initial version.                               L. Whetstone
// 1.0A  2008-08-21  No change.                                     L. Whetstone
// 1.1   2014-12-31  Module is made fully namespace compliant.      R. Callwood
//                   POV-Ray version is set to 3.5.
//                   Scale conversions are added.
#ifndef (lrchairs_Inc_Temp) #declare lrchairs_Inc_Temp = version;
#version 3.5;
#debug "#include \"lrchairs.inc\" // version 1.1\n"

// CP_Chair macro(Cp_Ftex,Cp_Stex)
// chair faces the -z direction
// zero point is in between back legs

//Cp_Ftex=frame texure Cp_Stex=Seat texure
#macro Cp_Chair(Cp_Ftex,Cp_Stex)
 #local Cp_in=1/12;
 #local Cp_Leg=union{cone{0,.05,-y*18*Cp_in,.04}sphere{-y*18*Cp_in,.04} sphere{0,.05}}
 #local Cp_Bac=union{cylinder{0,y*20*Cp_in,.05}sphere{y*20*Cp_in,.05}}
 union{
  //frame
  object{Cp_Leg rotate <-5,0,5> translate<6*Cp_in,0,6*Cp_in>}
  object{Cp_Leg rotate <-5,0,-5> translate<-6*Cp_in,0,6*Cp_in>}
  object{Cp_Leg rotate <6,0,5> translate<6*Cp_in,0,-6*Cp_in>}
  object{Cp_Leg rotate <6,0,-5>translate<-6*Cp_in,0,-6*Cp_in>}
   cylinder{<6*Cp_in,0,5*Cp_in><-6*Cp_in,0,5*Cp_in>,.05}
   cylinder{<-6*Cp_in,0,6*Cp_in><-6*Cp_in,0,-6*Cp_in>,.05}
   cylinder{<-6*Cp_in,0,-6*Cp_in><6*Cp_in,0,-6*Cp_in>,.05}
   cylinder{<6*Cp_in,0,-6*Cp_in><6*Cp_in,0,6*Cp_in>,.05}
  //back frame
  object{Cp_Bac rotate <7,0,6> translate<6*Cp_in,0,6*Cp_in>}
  object{Cp_Bac rotate <7,0,-6> translate<-6*Cp_in,0,6*Cp_in>}
   cylinder{<-5*Cp_in,5*Cp_in,0><5*Cp_in,5*Cp_in,0>,.05 rotate x*7
    translate z*6*Cp_in}
   cylinder{<-4.2*Cp_in,15*Cp_in,0><4.2*Cp_in,15*Cp_in,0>,.05 rotate x*7
    translate z*6*Cp_in}
   cylinder{<-4*Cp_in,19.9*Cp_in,0><4*Cp_in,19.9*Cp_in,0>,.05 rotate x*7
    translate z*6*Cp_in}
   //seat
  union{
   box{<6.5*Cp_in,.05,5*Cp_in><-6.5*Cp_in,1*Cp_in+.05,-6.5*Cp_in>}
   cylinder{<6.5*Cp_in,.05+.5*Cp_in,5*Cp_in><6.5*Cp_in,.05+.5*Cp_in,-6.5*Cp_in>,.5*Cp_in}
   cylinder{<-6.5*Cp_in,.05+.5*Cp_in,5*Cp_in><-6.5*Cp_in,.05+.5*Cp_in,-6.5*Cp_in>,.5*Cp_in}
   cylinder{<-6.5*Cp_in,.05+.5*Cp_in,-6.5*Cp_in><6.5*Cp_in,.05+.5*Cp_in,-6.5*Cp_in>,.5*Cp_in}
   cylinder{<-6.5*Cp_in,.05+.5*Cp_in,5*Cp_in><6.5*Cp_in,.05+.5*Cp_in,5*Cp_in>,.5*Cp_in}
   sphere{<-6.5*Cp_in,.05+.5*Cp_in,-6.5*Cp_in>,.5*Cp_in}
   sphere{<6.5*Cp_in,.05+.5*Cp_in,-6.5*Cp_in>,.5*Cp_in}
   sphere{<-6.5*Cp_in,.05+.5*Cp_in,5*Cp_in>,.5*Cp_in}
   sphere{<6.5*Cp_in,.05+.5*Cp_in,5*Cp_in>,.5*Cp_in}
   texture{Cp_Stex}}
   //back rest
  union{box{<-5.5*Cp_in,0,0><0,12*Cp_in,-Cp_in> rotate -z*5}
        box{<5.5*Cp_in,0,0><0,12*Cp_in,-Cp_in> rotate z*5}
         cylinder{<5.5*Cp_in,-.05,-.5*Cp_in><5.5*Cp_in,12*Cp_in,-.5*Cp_in>,.5*Cp_in rotate z*5}
         cylinder{<-5.5*Cp_in,-.05,-.5*Cp_in><-5.5*Cp_in,12*Cp_in,-.5*Cp_in>,.5*Cp_in rotate -z*5}
        box{<-4.5*Cp_in,11*Cp_in,0><4.5*Cp_in,12.5*Cp_in,-Cp_in>}//top
         cylinder{<-4.55*Cp_in,12.5*Cp_in,-.5*Cp_in><4.55*Cp_in,12.5*Cp_in,-.5*Cp_in>,.5*Cp_in}
         sphere{<4.4*Cp_in,12.5*Cp_in,-.5*Cp_in>,.5*Cp_in}
         sphere{<-4.4*Cp_in,12.5*Cp_in,-.5*Cp_in>,.5*Cp_in}
        box{<-5.5*Cp_in,0,0><5.5*Cp_in,1*Cp_in,-Cp_in>}//bottom
         cylinder{<-5.5*Cp_in,0,-.5*Cp_in><5.5*Cp_in,0,-.5*Cp_in>,.5*Cp_in}
         sphere{<-5.5*Cp_in,0,-.5*Cp_in>,.5*Cp_in}
         sphere{<5.5*Cp_in,0,-.5*Cp_in>,.5*Cp_in}
        translate y*5*Cp_in rotate x*7 translate z*(6*Cp_in-.05)
        texture{Cp_Stex}}
 texture{Cp_Ftex}
 //adjust zero point
 translate <0,18*Cp_in+.02,-7.6*Cp_in>
 }
#end

// Scaling factors:
#declare CP_METER = 0.3048;
#declare CP_METRE = CP_METER;
#declare CP_CM = 30.48;
#declare CP_INCH = 12;
#declare CP_FOOT = 1;
#declare CP_YARD = 1/3;

#version lrchairs_Inc_Temp;
#end
