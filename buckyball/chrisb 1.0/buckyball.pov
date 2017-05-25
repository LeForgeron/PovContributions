// Object Name: Buckyball II   
// Version:     01.10.95 written for POV 2.2.   
// Description: A C60 molecule.
// Scale:       1.5 units = about 1 molecule radius.
// Positioning: Sphere centred at the origin.
// Keywords:    Buckyball
// Author:      Chris Bartlett.  
// This file is licensed under the terms of the CC-LGPL.


                                          
light_source   {<-3, 8, -30> color rgb <1,1,1> }                         
light_source   {<-3, 8, -30> color rgb <1,1,1> }                         
camera {location <2, 3, -5> look_at  <0, 0, 0> }                         
background {color rgb <0,1,1>}                                           
                                                                         
#declare Buckyball_Separation = 1;       // The distance between the atoms          
#declare Buckyball_AtomRadius = 0.15;    // The size of the atoms                   
#declare Buckyball_BarRadius = 0.02;     // The thickness of the bars between atoms 
                                                                         
#declare Buckyball_Atom = union {                                                  
  sphere {             
    <0,0,Buckyball_Separation * 0.850651>,Buckyball_AtomRadius          
    texture {                                       
      pigment {color rgb <0,0,0>}                   
      finish {phong 0.9 phong_size 60}              
      }                                             
    }                                               
  cylinder {<0,0,0><0,0,Buckyball_Separation/2>,Buckyball_BarRadius     
    rotate <31.7175,0,0>                            
    translate <0,0,Buckyball_Separation * 0.850651>           
    pigment {color rgb <1,0,0>}                     
    }                                               
  cylinder {<0,0,0><0,0,-Buckyball_Separation>,Buckyball_BarRadius      
    rotate <0,54,0>                                 
    translate <0,0,Buckyball_Separation * 0.850651>           
    pigment {color rgb <1,0,0>}                     
    }                                               
  }                                                 
                 
#declare Buckyball_Sidelength = Buckyball_Separation * 2.09017;       
#declare Buckyball_MoleculeRadius = Buckyball_Sidelength * 1.309021;  
                                                 
#declare Buckyball_Pentagon = union {                      
  object {Buckyball_Atom rotate <0,36,0>}                  
  object {Buckyball_Atom rotate <0,-36,0> }                
  object {Buckyball_Atom rotate <0,108,0> }                
  object {Buckyball_Atom rotate <0,-108,0> }               
  object {Buckyball_Atom rotate <0,180,0> }                
  }                                              
                                                 
#declare Buckyball_DualPentagon = union {                  
  object{ Buckyball_Pentagon                               
    translate <0,0,Buckyball_Sidelength * 0.688191>        
    rotate <31.7175,0,0>                         
    }                                            
  object{Buckyball_Pentagon                                
    translate <0,0,Buckyball_Sidelength * 0.688191>  
    rotate <31.7175,180,0>                                                
    }                                                                     
  translate <0,Buckyball_MoleculeRadius,0>                                          
  }                                                                       

#declare Buckyball = union {                                                                          
  object {Buckyball_DualPentagon}                                                     
  object {Buckyball_DualPentagon rotate<180,0,0>}                                     
  object {Buckyball_DualPentagon rotate<90,0,90>}                                     
  object {Buckyball_DualPentagon rotate<270,0,90>}                                    
  object {Buckyball_DualPentagon rotate<0,90,90>}                                     
  object {Buckyball_DualPentagon rotate<0,90,270>}                                    
  sphere {<0,0,0> Buckyball_MoleculeRadius*0.89 
    pigment{color rgbf <0.7,.7,.7,0.7>}
  //  finish {reflection 0.7}
    }  
  }
                   
object {Buckyball rotate <clock,0,0>}
                                                       
//            End of Buckyball                                                                                                                                       