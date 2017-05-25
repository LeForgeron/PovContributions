//
// periodictable.pov
// -----------------
// Created by Chris Bartlett July 2009
// This scene file displays the periodic table. 
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The scale is 1 POV-Ray unit = 1 element in the table
//
// The periodic table can be rendered using an orthographic camera using 
// global ambient lighting and no light source, or using a perspective 
// camera with a light source. Uncomment the camera you want to use.
//

// Orthographic View
//camera {orthographic location <9, 15.2,-6.2> look_at <9,0,-6.2> sky z}
//global_settings { ambient_light 8}

// Perspective View
camera {location <0, 7,-18> look_at <6,0,-9.5>}
light_source {<2,20,-4> color rgb 2}

// Define a macro to add an element
#macro PT_AddElement(PT_Number, PT_Symbol, PT_Group, PT_Period, PT_Origin)
  difference {
    box {<-0.45,-1,-0.45>,<0.45,-0.1,0.45> pigment {rgb PT_BoxColor}}
    #local PT_NumberText = text {ttf "arial.ttf" PT_Number 1,0 pigment {rgb PT_TextColor} scale 0.3 rotate x*90}
    #local PT_SymbolText = text {ttf "arial.ttf" PT_Symbol 1,0 pigment {rgb PT_TextColor} scale 0.3 rotate x*90}
    object {PT_NumberText translate z*0.2-(min_extent(PT_NumberText)+max_extent(PT_NumberText))/2}
    object {PT_SymbolText translate -z*0.2-(min_extent(PT_SymbolText)+max_extent(PT_SymbolText))/2}
    translate <PT_Group,0,-PT_Period>
    #if (PT_Period>7) translate -z*0.5 #end
  }
  // Add a border to the box
  #if(strcmp(PT_Origin,"None")!=0) 
    difference {
      box {<-0.475,-1.001,-0.475>,<0.475,-0.1001,0.475>
        #switch(0)
          #case(strcmp(PT_Origin,"Primordial")) 
            pigment {rgb PT_BorderColor}
          #break
          #case(strcmp(PT_Origin,"From Decay")) 
            pigment {checker color rgb PT_BorderColor, color rgb 0 scale 0.1}
          #break
          #case(strcmp(PT_Origin,"Synthetic")) 
            pigment {checker color rgb PT_BorderColor, color rgb 0 scale 0.05}
          #break
          #else
            pigment {rgb 0.5}
        #end 
      }
      box {<-0.45,-1,-0.45>,<0.45,-0.1,0.45> pigment {rgb 1}}
      translate <PT_Group,0,-PT_Period>
      #if (PT_Period>7) translate -z*0.5 #end
    }
  #end
#end                  

// Define a macro to add an item to the key at the bottom
#macro PT_AddKey(PT_Column, PT_Row, PT_Title, PT_Border)
  difference {
    box {<-0.3,-1,-0.15>,<3.2,-0.1,0.35> pigment {rgb PT_BoxColor}}
    text {ttf "arial.ttf" PT_Title 1,0 pigment {rgb PT_TextColor} scale 0.3 rotate x*90}
    translate <1+4*(PT_Column-1),0,-10.5-PT_Row*0.6>
  }
  // Add a border to the box
  difference {
    box {<-0.325,-1.001,-0.175>,<3.225,-0.1001,0.375> 
      #switch(0)
        #case(strcmp(PT_Border,"Primordial")) 
          pigment {rgb PT_BorderColor}
        #break
        #case(strcmp(PT_Border,"From Decay")) 
          pigment {checker color rgb PT_BorderColor, color rgb 0 scale 0.1}
        #break
        #case(strcmp(PT_Border,"Synthetic")) 
          pigment {checker color rgb PT_BorderColor, color rgb 0 scale 0.05}
        #break
        #else
          pigment {rgb 0.5}
      #end 
    }
    box {<-0.3,-1,-0.15>,<3.2,-0.1,0.35> pigment {rgb PT_BoxColor}}
    translate <1+4*(PT_Column-1),0,-10.5-PT_Row*0.6>
  }
#end                  


// Repeatedly call the macros to add the elements and the key items
#declare PT_TextColor = <0.2,0,0>;
#declare PT_BorderColor = 2;
#declare PT_BoxColor = <0.5,1,0.5>;
PT_AddElement(  "1","H" ,  1,1, "Primordial") 

#declare PT_BoxColor = <1,0.3,0.3>;
PT_AddKey(1, 1, "Alkali Metals", "Primordial")
PT_AddElement(  "3","Li",  1,2, "Primordial") 
PT_AddElement( "11","Na",  1,3, "Primordial") 
PT_AddElement( "19","K" ,  1,4, "Primordial") 
PT_AddElement( "37","Rb",  1,5, "Primordial") 
PT_AddElement( "55","Cs",  1,6, "Primordial") 
PT_AddElement( "87","Fr",  1,7, "From Decay") 

#declare PT_BoxColor = <1,0.9,0.8>;
PT_AddKey(1, 2, "Alkali Earth Metals", "Primordial")
PT_AddElement(  "4","Be",  2,2, "Primordial") 
PT_AddElement( "12","Mg",  2,3, "Primordial") 
PT_AddElement( "20","Ca",  2,4, "Primordial") 
PT_AddElement( "38","Sr",  2,5, "Primordial") 
PT_AddElement( "56","Ba",  2,6, "Primordial") 
PT_AddElement( "88","Ra",  2,7, "From Decay") 

#declare PT_BoxColor = <1,0.7,0.7>;
PT_AddKey(2, 2, "Transition Elements", "Primordial")
PT_AddElement( "21","Sc",  3,4, "Primordial") 
PT_AddElement( "39","Y" ,  3,5, "Primordial") 
                              
PT_AddElement( "22","Ti",  4,4, "Primordial") 
PT_AddElement( "40","Zr",  4,5, "Primordial") 
PT_AddElement( "72","Hf",  4,6, "Primordial") 
PT_AddElement("104","Rf",  4,7, "Synthetic") 

PT_AddElement( "23","V" ,  5,4, "Primordial") 
PT_AddElement( "41","Nb",  5,5, "Primordial") 
PT_AddElement( "73","Ta",  5,6, "Primordial") 
PT_AddElement("105","Db",  5,7, "Synthetic") 

PT_AddElement( "24","Cr",  6,4, "Primordial") 
PT_AddElement( "42","Mo",  6,5, "Primordial") 
PT_AddElement( "74","W" ,  6,6, "Primordial") 
PT_AddElement("106","Sg",  6,7, "Synthetic") 

PT_AddElement( "25","Mn",  7,4, "Primordial") 
PT_AddElement( "43","Tc",  7,5, "From Decay") 
PT_AddElement( "75","Re",  7,6, "Primordial") 
PT_AddElement("107","Bh",  7,7, "Synthetic") 

PT_AddElement( "26","Fe",  8,4, "Primordial") 
PT_AddElement( "44","Ru",  8,5, "Primordial") 
PT_AddElement( "76","Os",  8,6, "Primordial") 
PT_AddElement("108","Hs",  8,7, "Synthetic") 

PT_AddElement( "27","Co",  9,4, "Primordial") 
PT_AddElement( "45","Rh",  9,5, "Primordial") 
PT_AddElement( "77","Ir",  9,6, "Primordial") 
                              
PT_AddElement( "28","Ni", 10,4, "Primordial") 
PT_AddElement( "46","Pd", 10,5, "Primordial") 
PT_AddElement( "78","Pt", 10,6, "Primordial") 

PT_AddElement( "29","Cu", 11,4, "Primordial") 
PT_AddElement( "47","Ag", 11,5, "Primordial") 
PT_AddElement( "79","Au", 11,6, "Primordial") 

PT_AddElement( "30","Zn", 12,4, "Primordial") 
PT_AddElement( "48","Cd", 12,5, "Primordial") 
PT_AddElement( "80","Hg", 12,6, "Primordial") 
PT_AddElement("112","Uub",12,7, "Synthetic") 

#declare PT_BoxColor = <1,0.95,0.95>;
PT_AddElement("109","Mt",  9,7, "Synthetic") 
PT_AddElement("110","Ds", 10,7, "Synthetic") 
PT_AddElement("111","Rg", 11,7, "Synthetic") 

#declare PT_BoxColor = <0.5,0.75,0.5>;
PT_AddKey(3, 1, "Metalloids", "Primordial")
PT_AddElement(  "5","B" , 13,2, "Primordial") 
PT_AddElement( "14","Si", 14,3, "Primordial") 
PT_AddElement( "32","Ge", 14,4, "Primordial") 
PT_AddElement( "33","As", 15,4, "Primordial") 
PT_AddElement( "51","Sb", 15,5, "Primordial") 
PT_AddElement( "52","Te", 16,5, "Primordial") 
PT_AddElement( "84","Po", 16,6, "From Decay") 

#declare PT_BoxColor = <0.5,1,0.5>;
PT_AddKey(4, 3, "Other Non-Metals", "Primordial")
PT_AddElement(  "6","C" , 14,2, "Primordial") 
PT_AddElement(  "7","N" , 15,2, "Primordial") 
PT_AddElement(  "8","O" , 16,2, "Primordial") 
PT_AddElement( "15","P" , 15,3, "Primordial") 
PT_AddElement( "16","S" , 16,3, "Primordial") 
PT_AddElement( "34","Se", 16,4, "Primordial") 

#declare PT_BoxColor = <0.7,0.7,0.7>;
PT_AddKey(2, 3, "Other Metals", "Primordial")
PT_AddElement( "13","Al", 13,3, "Primordial") 
PT_AddElement( "31","Ga", 13,4, "Primordial") 
PT_AddElement( "49","In", 13,5, "Primordial") 
PT_AddElement( "81","Tl", 13,6, "Primordial") 
PT_AddElement( "50","Sn", 14,5, "Primordial") 
PT_AddElement( "82","Pb", 14,6, "Primordial") 
PT_AddElement( "83","Bi", 15,6, "Primordial") 

#declare PT_BoxColor = <1,1,1>;
PT_AddKey(3, 2, "Unknown", "Primordial")
PT_AddElement("113","Uut",13,7, "Synthetic") 
PT_AddElement("114","Uuq",14,7, "Synthetic") 
PT_AddElement("115","Uup",15,7, "Synthetic") 
PT_AddElement("116","Uuh",16,7, "Synthetic") 
PT_AddElement("(117)","(Uus)",17,7, "") 
PT_AddElement("118","Uuo",18,7, "Synthetic") 

#declare PT_BoxColor = <1,1,0.5>;
PT_AddKey(4, 1, "Halogens", "Primordial")
PT_AddElement(  "9","F" , 17,2, "Primordial") 
PT_AddElement( "17","Cl", 17,3, "Primordial") 
PT_AddElement( "35","Br", 17,4, "Primordial") 
PT_AddElement( "53","I" , 17,5, "Primordial") 
PT_AddElement( "85","At", 17,6, "From Decay") 

#declare PT_BoxColor = <0.5,1,1  >;
PT_AddKey(4, 2, "Noble Gases", "Primordial")
PT_AddElement(  "2","He", 18,1, "Primordial") 
PT_AddElement( "10","Ne", 18,2, "Primordial") 
PT_AddElement( "18","Ar", 18,3, "Primordial") 
PT_AddElement( "36","Kr", 18,4, "Primordial") 
PT_AddElement( "54","Xe", 18,5, "Primordial") 
PT_AddElement( "86","Rn", 18,6, "From Decay") 


// Lanthanoids
#declare PT_BoxColor = <1,0.7,1>;
PT_AddKey(1, 3, "Lanthanoids", "Primordial")
PT_AddElement( " " ,"*" , 3,6, "") 
PT_AddElement( "57","La", 3,8, "Primordial") 
PT_AddElement( "58","Ce", 4,8, "Primordial") 
PT_AddElement( "59","Pr", 5,8, "Primordial") 
PT_AddElement( "60","Nd", 6,8, "Primordial") 
PT_AddElement( "61","Pm", 7,8, "From Decay") 
PT_AddElement( "62","Sm", 8,8, "Primordial") 
PT_AddElement( "63","Eu", 9,8, "Primordial") 
PT_AddElement( "64","Gd",10,8, "Primordial") 
PT_AddElement( "65","Tb",11,8, "Primordial") 
PT_AddElement( "66","Dy",12,8, "Primordial") 
PT_AddElement( "67","Ho",13,8, "Primordial") 
PT_AddElement( "68","Er",14,8, "Primordial") 
PT_AddElement( "69","Tm",15,8, "Primordial") 
PT_AddElement( "70","Yb",16,8, "Primordial") 
PT_AddElement( "71","Lu",17,8, "Primordial") 

// Actinoids
#declare PT_BoxColor = <1,0.3,1>;
PT_AddKey(2, 1, "Actinoids", "Primordial")
PT_AddElement( " " ,"**", 3,7, "") 
PT_AddElement( "89","Ac", 3,9, "From Decay") 
PT_AddElement( "90","Th", 4,9, "Primordial") 
PT_AddElement( "91","Pa", 5,9, "From Decay") 
PT_AddElement( "92","U" , 6,9, "Primordial") 
PT_AddElement( "93","Np", 7,9, "From Decay") 
PT_AddElement( "94","Pu", 8,9, "Synthetic") 
PT_AddElement( "95","Am", 9,9, "Synthetic") 
PT_AddElement( "96","Cm",10,9, "Synthetic") 
PT_AddElement( "97","Bk",11,9, "Synthetic") 
PT_AddElement( "98","Cf",12,9, "Synthetic") 
PT_AddElement( "99","Es",13,9, "Synthetic") 
PT_AddElement("100","Fm",14,9, "Synthetic") 
PT_AddElement("101","Md",15,9, "Synthetic") 
PT_AddElement("102","No",16,9, "Synthetic") 
PT_AddElement("103","Lr",17,9, "Synthetic") 


// Labels
// Main Title 
#declare PT_BoxColor = 0;
#declare PT_TextColor = <2,2,0>;
difference {
  box {<-0.1,-1,-0.22>,<9.5,-0.001,1> pigment {rgb PT_BoxColor}}
  text {ttf "arial.ttf" "Periodic Table of the Elements" 0.1,0 pigment {rgb PT_TextColor} scale 0.7 rotate x*90}
  box {<0,-0.1,-0.20>,<9.4,0,-0.16> pigment {rgb PT_TextColor}}
  translate <4,0,0.5>
}
// Groups and Periods 
#local PT_I = 1;
#while (PT_I<=18)
  PT_AddElement("", str(PT_I,2,0), PT_I,0, "None") 
#local PT_I = PT_I + 1;
#end
#local PT_I = 1;
#while (PT_I<=7)
  PT_AddElement("", str(PT_I,2,0), 0,PT_I, "None") 
#local PT_I = PT_I + 1;
#end
// Lanthanoid and Actinoid Titles
#declare PT_TextColor = <2,0,0>;
#declare PT_BoxColor = 0;
difference {
  box {<-0.1,-1,-0.2>,<2.5,-0.1,0.6> pigment {rgb PT_BoxColor}}
  text {ttf "arial.ttf" "     * Lanthanoids" 1,0 pigment {rgb PT_TextColor} scale 0.3 rotate x*90 }
  translate -z*8.75
}
difference {
  box {<-0.1,-1,-0.2>,<2.5,-0.1,0.6> pigment {rgb PT_BoxColor}}
  text {ttf "arial.ttf" "    ** Actinoids"   1,0 pigment {rgb PT_TextColor} scale 0.3 rotate x*90 }
  translate -z*9.75
} 
   
   
// Key to origins of Element
#declare PT_TextColor = 0;
#declare PT_BoxColor = 1;
PT_AddKey(1,4.5, "Primordial"    , "Primordial")
PT_AddKey(2,4.5, "From Decay"    , "From Decay")
PT_AddKey(3,4.5, "Synthetic"     , "Synthetic" )
PT_AddKey(4,4.5, "(Undiscovered)", "Primordial")
