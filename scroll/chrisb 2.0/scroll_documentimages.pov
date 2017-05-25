
// scroll_documentimages.pov
// ----------------------------
// Created by Chris Bartlett August 2008
// This scene file demonstrates the use of the 'scroll' include file. 
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The scale is 1 POV-Ray units = 1 metre

// Purpose
// -------
// This scene file is used to re-generate the images used within the documentation contained in scroll.html. 
//
// To generate all of the standard images use the animation command line options +kfi1 +kff3 which sets ImageNumber to equal 
// the frame_number. 
// To generate a single image switch off animation and it will use ImageNumber = n, where 'n' is the number of the image you 
// specify here:
#if (frame_number=0) #local ImageNumber = 14;  // Set this to the required image number
#else                #local ImageNumber = frame_number;
#end 

// Uncomment the following line to generate the animated version of image 6 using command line options +kfi0 +kff20
//#local ImageNumber = 6;

#include "scroll.inc" 
#include "scroll_typeset.inc" 

// Default camera (may be overridden for specific images below)
camera {location <-0.3,0.3,-0.3> look_at <0.1,0.1,0>}

light_source { <-10,4,-4> color rgb 1}
light_source { <-10,-7,-40> color rgb 1} 
                                                        
//**************************//
//  Plain Scroll            //
//**************************// 
#if (ImageNumber=1)
  camera {location <-0.3,0.3,-0.45> look_at <0.1,0.1,0.2>}
  object {Scroll() pigment {rgb 1}}
#end 

//**************************//
//  Scroll with Writing     //
//**************************// 
#if (ImageNumber=2)
  // Set the length, in POV-Ray units at which the text (at the default size) will wrap.
  #declare Scroll_LineLength    = 12;
  
  // Add text and paragraph throws to the text array
  Scroll_WrapText("How many roads must a man walk down?") 
  Scroll_NewParagraph(1)
  Scroll_WrapText("42!")
  Scroll_NewParagraph(2)
  Scroll_WrapText("Hmmm. Sounds good, but doesn't tie us down to actually meaning anything.")
 
  // Generate a text object, specifying how the text is to be justified (Left, Right, Center or Full) 
  #declare MyTextObject = Scroll_MakeTextObject("Full")
  
  // Scale the text object so that it to fits within a unit square, using the default margins
  #declare MyTextObject = Scroll_FitToUnitSquare(MyTextObject)

  // Create a scroll object and uv_map the text onto the front surface. Use a different texture for the back surface.
  object { 
    Scroll() 
    texture {uv_mapping pigment {object {MyTextObject color rgb <1,1,0.8> color rgb <0.1,0.05,0.03>}}} 
    interior_texture {
      pigment {color rgb <1,1,0.8>}
      normal {agate 0.1 scale 0.01} 
    }
    rotate -30*z
  }
#end 

//**************************//
//  Scroll - Landscape Mode //
//**************************// 
#if (ImageNumber=3)
  camera {location <0.175,0.3,-0.3> look_at <0.175,0,0>}

  #declare Scroll_FontFile    = "VIVALDII.TTF";
  #declare Scroll_LineLength  = 20;

//  #declare Scroll_TopMargin     = 0.05; 
  #declare Scroll_BottomMargin  = 0.35;
//  #declare Scroll_LeftMargin    = 0.25; 
//  #declare Scroll_RightMargin   = 0.25; 
//  #declare Scroll_Length           = 0.9; 
//  #declare Scroll_BottomRollLength = 0.2; 
//  #declare Scroll_TopRadius        = 0.03;
//  #declare Scroll_CentreRadius     = 2.5; 
//  #declare Scroll_BottomRadius     = 0.03;
//  #declare Scroll_Top              = 0.4;
//  #declare Scroll_TextSlant = 1;
  

//  // Add text to the text array
//  Scroll_WrapText("Happy Birthday!") 

  // Add text and paragraph throws to the text array
  Scroll_WrapText("\"The Hitchhiker's Guide to the Galaxy\" is a wholly remarkable book.") 
  Scroll_WrapText(" Perhaps the most remarkable, certainly the most successful book ever to come out of the great publishing corporations of Ursa Minor.") 
  Scroll_WrapText(" More popular than \"The Celestial Home Care Omnibus\", better selling than \"Fifty-Three More Things to do in Zero Gravity\",") 
  Scroll_WrapText("and more controversial than Oolon Colluphid's trilogy of philosophical blockbusters \"Where God Went Wrong\", \"Some More of God's Greatest Mistakes\" and \"Who is this God Person Anyway?\".") 
  Scroll_WrapText(" It has already supplanted the Encyclopedia Galactica as the standard repository of all knowledge and wisdom, for two important reasons.")
  Scroll_WrapText(" First, it is slightly cheaper; and secondly it has the words DON'T PANIC printed in large friendly letters on the front cover.")
  
  // Generate a text object, specifying how the text is to be justified (Left, Right, Center or Full) 
  #declare Scroll_Orientation   = "Landscape";
  #declare MyTextObject = Scroll_MakeTextObject("Left")
  // Scale the text object so that it to fits within a unit square, using the default margins
  #declare MyTextObject = Scroll_FitToUnitSquare(MyTextObject)

  // Create a scroll object and uv_map the text onto the front surface. Use a different texture for the back surface.
  object { 
    Scroll() 
    texture {uv_mapping
      pigment {object {MyTextObject color rgb <1,1,0.8> color rgb <0.1,0.05,0.03>}}
      finish {ambient 0.4}
    } 
    interior_texture {  pigment {color rgb <1,1,0.8>}}
    rotate -90*z
//    rotate -x*60
//    rotate <-90,-90.0>
  }
#end 

//**************************//
//  Roll of Wallpaper       //
//**************************// 
#if (ImageNumber=4)
  camera {location <-0.3,0.3,-0.8> look_at <0.1,0.1,-0.2>}
  #declare Scroll_TopRadius        = 0.05; 
  #declare Scroll_BottomRadius     = 0.07; 
  #declare Scroll_Length           = 15; 
  #declare Scroll_Width            = 0.9; 
  #declare Scroll_TopFactor        = 0.2;
  #declare Scroll_BottomFactor     = 1.5;
  #declare Scroll_BottomRollLength = 0.8;
  object { 
    Scroll() 
    texture {uv_mapping pigment {hexagon rotate -x*90 scale <0.06,0.003,1>}}
    interior_texture {
      pigment {color rgb <1,1,0.8>}
      normal {agate 0.1 scale 0.01} 
    }
    rotate -30*z
  }  
#end 

//***************************************//
//  Roll of Wallpaper with Scroll Motif  //
//***************************************// 
#if (ImageNumber=5)
  camera {location <-0.3,0.3,-0.8> look_at <0.1,0.1,-0.2>}
  background {rgb <0.1,0.2,0.3>}
  #declare Scroll_TopRadius        = 0.05; 
  #declare Scroll_BottomRadius     = 0.07; 
  #declare Scroll_Length           = 15; 
  #declare Scroll_Width            = 0.9; 
  #declare Scroll_TopFactor        = 0.2;
  #declare Scroll_BottomFactor     = 1.5;
  #declare Scroll_BottomRollLength = 0.8;
  object { 
    Scroll() 
    texture {uv_mapping pigment {image_map {jpeg "scroll.jpg"} scale <0.2/Scroll_Width,0.2/Scroll_Length,1>}}
    interior_texture {
      pigment {color rgb <1,1,0.8>}
      normal {agate 0.1 scale 0.01} 
    }
    rotate -30*z
  }  
#end 

//***************************************//
//  Test of animation controls           //
//***************************************// 
// Note. To get the animated version of this image uncomment the line "#local ImageNumber=6;" above.
#if (ImageNumber=6)
  camera {location <-0.2,0.1,-0.25> look_at <0,0,-0.04>}
  background {rgb <0.1,0.2,0.1>}
  #declare Scroll_TopRadius        = 0.04; 
  #declare Scroll_BottomRadius     = 0.045; 
  #declare Scroll_Length           = 1; 
  #declare Scroll_Width            = 0.2; 
  #declare Scroll_TopFactor        = 0.2;
  #declare Scroll_BottomFactor     = 1.5;
  #declare Scroll_BottomRollLength = 1-clock*1.5;
  #declare Scroll_Top              = 0.21;
  #declare Scroll_Bottom           = -0.08;
  object { 
    Scroll() 
    texture {uv_mapping pigment {brick scale 0.01*<1/Scroll_Width,1/Scroll_Length,1>}}
    interior_texture {
      pigment {color rgb <1,1,0.8>}
      normal {agate 0.1 scale 0.01} 
    }
    rotate -70*z
  }  
#end 

//**************************//
//  TypeSetting Macros      //
//**************************// 
#if (ImageNumber=7 | ImageNumber=8 | ImageNumber=9 | ImageNumber=10)
  camera {location <5,-3,-9> look_at <5,-3,0>} 
  
  cylinder {-100*x,100*x,0.02 pigment {rgb <1,1,0>}}
  cylinder {-y,y,0.02 pigment {rgb <1,1,0>} translate x*10}
  cylinder {-100*y,100*y,0.02 pigment {rgb <1,0,1>}}
  cylinder {-100*z,100*z,0.02 pigment {rgb <0,1,1>} finish {ambient 1}}

  #declare Scroll_FontFile    = "VIVALDII.TTF";
  #declare Scroll_LineLength  = 10;

  // Add text and paragraph throws to the text array
  Scroll_WrapText("\"The Hitchhiker's Guide to the Galaxy\" is a wholly remarkable book.") 
  Scroll_WrapText(" Perhaps the most remarkable, certainly the most successful book ever to come out of the great publishing corporations of Ursa Minor.") 
  Scroll_WrapText(" More popular than \"The Celestial Home Care Omnibus\", better selling than \"Fifty-Three More Things to do in Zero Gravity\",") 
  Scroll_WrapText("and more controversial than Oolon Colluphid's trilogy of philosophical blockbusters \"Where God Went Wrong\", \"Some More of God's Greatest Mistakes\" and \"Who is this God Person Anyway?\".") 
  Scroll_WrapText(" It has already supplanted the Encyclopedia Galactica as the standard repository of all knowledge and wisdom, for two important reasons.")
  Scroll_WrapText(" First, it is slightly cheaper; and secondly it has the words DON'T PANIC printed in large friendly letters on the front cover.")
  
  // Generate a text object, specifying how the text is to be justified (Left, Right, Center or Full) 
  #declare Scroll_Orientation   = "Portrait";
  #if (ImageNumber=7)  #declare MyTextObject = Scroll_MakeTextObject("Left")   #end
  #if (ImageNumber=8)  #declare MyTextObject = Scroll_MakeTextObject("Right")  #end
  #if (ImageNumber=9)  #declare MyTextObject = Scroll_MakeTextObject("Centre") #end
  #if (ImageNumber=10) #declare MyTextObject = Scroll_MakeTextObject("Full")   #end

  object {MyTextObject pigment {rgb <0.75,0.75,1>}}
#end 
 



//**************************//
//  TypeSetting Macros      //
//**************************// 
#if (ImageNumber=11)
  camera {location <-0.1,0.92,-1.4> look_at <0.6,0.4,0>} 
  
  cylinder {-100*x,100*x,0.01 pigment {rgb <1,1,0>}}
  cylinder {-100*y,100*y,0.01 pigment {rgb <1,0,1>}}
  cylinder {-100*z,100*z,0.01 pigment {rgb <0,1,1>} finish {ambient 1}}
  box {0,1 pigment {rgbt <2,2,2,0.8>}}

  #declare Scroll_FontFile    = "VIVALDII.TTF";
  #declare Scroll_LineLength  = 18;

  #declare Scroll_TopMargin     = 0.15; 
  #declare Scroll_BottomMargin  = 0.10;
  #declare Scroll_LeftMargin    = 0.10; 
  #declare Scroll_RightMargin   = 0.10; 
  
  // Add text and paragraph throws to the text array
  Scroll_WrapText("\"The Hitchhiker's Guide to the Galaxy\" is a wholly remarkable book.") 
  Scroll_WrapText(" Perhaps the most remarkable, certainly the most successful book ever to come out of the great publishing corporations of Ursa Minor.") 
  Scroll_WrapText(" More popular than \"The Celestial Home Care Omnibus\", better selling than \"Fifty-Three More Things to do in Zero Gravity\",") 
  Scroll_WrapText("and more controversial than Oolon Colluphid's trilogy of philosophical blockbusters \"Where God Went Wrong\", \"Some More of God's Greatest Mistakes\" and \"Who is this God Person Anyway?\".") 
  Scroll_WrapText(" It has already supplanted the Encyclopedia Galactica as the standard repository of all knowledge and wisdom, for two important reasons.")
  Scroll_WrapText(" First, it is slightly cheaper; and secondly it has the words DON'T PANIC printed in large friendly letters on the front cover.")
  
  // Generate a text object, specifying how the text is to be justified (Left, Right, Center or Full) 
  #declare Scroll_Orientation   = "Portrait";
  #declare MyTextObject = Scroll_MakeTextObject("Full")
  // Scale the text object so that it to fits within a unit square, using the default margins
  #declare MyTextObject = Scroll_FitToUnitSquare(MyTextObject)

  object {MyTextObject pigment {rgb <0.5,0.2,0.2>}}
#end  



//**************************//
//  Theory                  //
//**************************// 
#if (ImageNumber=12)
  camera {orthographic location <-0.7,0.5,-2> look_at <-0.7,0.5,0>}

  // Generate a test object to write the centre point into the message stream.
  // (Remember to set Scroll_Verbose to '1' inside the Scroll macro)  
  #declare Scroll_Top          = 1;
  #declare Scroll_TopRadius    = 0.2;
  #declare Scroll_BottomRadius = 0.3;
  #declare Scroll_CentreRadius = 1.2;

  #local TestObject = Scroll() 
  
  #local CentrePoint = <-1.35424333,0.645,0>;
  
  // Draw x, y and z axes, adding lines end-on through the centre point and the centre of the top spiral 
  cylinder {-100*x,100*x,0.005 pigment {rgb <1,1,0>}}
  cylinder {-100*y,100*y,0.005 pigment {rgb <1,0,1>}}
  cylinder {-1  *z,100*z,0.005 pigment {rgb <0,1,1>} finish {ambient 1}}
  cylinder {-1  *z,100*z,0.005 pigment {rgb <0,1,1>} finish {ambient 1} translate y}
  cylinder {-1  *z,100*z,0.005 pigment {rgb <0,1,1>} finish {ambient 1} translate CentrePoint}

  // Add circles representing the top and bottom spirals and a central arc 
  torus {Scroll_TopRadius   ,0.005 pigment {rgb <2,1,1>} rotate x*90 translate y*Scroll_Top}
  torus {Scroll_BottomRadius,0.005 pigment {rgb <2,1,1>} rotate x*90}
  difference {
    torus {Scroll_CentreRadius,0.005 pigment {rgb <2,1,1>} rotate x*90 translate CentrePoint}
    plane {y,0 Reorient_Trans(-x,CentrePoint)}
    plane {-y,0 Reorient_Trans(-x,CentrePoint-Scroll_Top*y) translate y*Scroll_Top}
  }
  // Add a construction line through the central arc
  torus {Scroll_CentreRadius,0.002 pigment {rgbt <1,1,1,0.8>} rotate x*90 translate CentrePoint}

  // Draw radial lines joining the centres of the spirals to the centre point of the central arc
  cylinder {0                     ,CentrePoint ,0.003 pigment {rgb <2,1,1>}}
  cylinder {Scroll_Top*y          ,CentrePoint ,0.003 pigment {rgb <2,1,1>}} 

  // Add more construction lines and measurement lines
  cylinder {CentrePoint.y*y+0.1*x ,CentrePoint ,0.002 pigment {rgbt <1,1,1,0.8>}} 
  cylinder {CentrePoint.y*y+0.05*x,0.05*x      ,0.002 pigment {rgbt <1,1,1,0.8>}} 
  cylinder {Scroll_Top*y+0.3*x    ,Scroll_Top*y,0.002 pigment {rgbt <1,1,1,0.8>}} 
  cylinder {Scroll_Top*y+0.25*x   ,0.25*x      ,0.002 pigment {rgbt <1,1,1,0.8>}} 
  
  // Annotate stuff
  text {ttf "timrom.ttf" "r0",0.01,0 pigment {rgb <2,0,0>} scale 0.1 translate <-0.7,0.875,0>}
  text {ttf "timrom.ttf" "r0",0.01,0 pigment {rgb <2,0,0>} scale 0.1 translate <-0.7,0.175,0>}
  text {ttf "timrom.ttf" "r1",0.01,0 pigment {rgb <2,0,0>} scale 0.1 translate <-0.15,0.1,0>}
  text {ttf "timrom.ttf" "r2",0.01,0 pigment {rgb <2,0,0>} scale 0.1 translate <-0.15,1,0>}
  text {ttf "timrom.ttf" "<x1,y1>",0.01,0 pigment {rgb <2,0,0>} scale 0.1 translate <-1.53,0.725,0>}
  text {ttf "timrom.ttf" "x1",0.01,0 pigment {rgb <0,2,0>} scale 0.1 translate <-0.6,0.55,0>}
  text {ttf "timrom.ttf" "y1",0.01,0 pigment {rgb <0,2,0>} scale 0.1 translate <0.075,0.35,0>}
  text {ttf "timrom.ttf" "y2",0.01,0 pigment {rgb <2,0,0>} scale 0.1 translate <0.275,0.5,0>}

#end  

//**************************//
//  Tin Foil                //
//**************************// 
#if (ImageNumber=13) 
  global_settings { max_trace_level 50 }
  // Add something to get reflected in the foil
  plane {x,-100 pigment {image_map {jpeg "scroll_publicdomain.jpg"} rotate y*90 scale <1,20,100> translate z*70}}
  sphere {0,1000 pigment {image_map {jpeg "scroll_publicdomain.jpg" map_type 1}} rotate <0,260,-70> no_image}
  object {Scroll() texture {
      pigment {rgb 0}
      normal {bumps 0.02 scale 0.1}
      finish {reflection 0.97 phong 1}
    }
    rotate -z*30
  }
#end  


//**************************//
//  Kitchen & Bog Roll      //
//**************************// 
#if (ImageNumber=14) 
  #declare Scroll_Top              = 0.2;
  #declare Scroll_TopRadius        = 0.04;
  #declare Scroll_BottomRadius     = 0.04;
  #declare Scroll_CentreRadius     = 0.5;
  #declare Scroll_Width            = 0.1;
  #declare Scroll_Length           = 3.5;
  #declare Scroll_BottomRollLength = -0.1;
  #declare Scroll_TopFactor        = 0.3; 

  // Bog Roll with central cardboard tube
  union {
    object {Scroll()
      texture {uv_mapping
        pigment {gradient y 
          color_map {
            [0     color rgb <1,0.8,0.7>]
            [0.993 color rgb <1,0.8,0.7>]
            [0.993 color rgb 0.8*<1,0.8,0.7>]
            [1     color rgb 0.8*<1,0.8,0.7>]
          }
          scale 0.03 
        }
        normal {bumps 0.01 scale 0.01*<1/Scroll_Width,1/Scroll_Length,1>}
      }
    }
    difference {
      cylinder {Scroll_Top*y-z*Scroll_Width/1.98,Scroll_Top*y+z*Scroll_Width/1.98,Scroll_TopRadius/3}
      cylinder {Scroll_Top*y-z*Scroll_Width/1.95,Scroll_Top*y+z*Scroll_Width/1.95,Scroll_TopRadius/3.2}
      pigment {rgb 0.7*<1,0.85,0.7>}
      normal {bumps 0.4 scale 0.001}
      finish {ambient 0}
    }
    rotate -y*90
    translate y*0.075
  } 
  
  Scroll_Undef()

  #declare Scroll_Top              = 0.3;
  #declare Scroll_TopRadius        = 0.04;
  #declare Scroll_BottomRadius     = 0.04;
  #declare Scroll_CentreRadius     = 1;
  #declare Scroll_Width            = 0.20;
  #declare Scroll_Length           = 3.6;
  #declare Scroll_BottomRollLength = -0.1;
  #declare Scroll_TopFactor        = 0.3; 

  union {
    object {Scroll()
      texture { uv_mapping
        pigment {gradient y 
          color_map {
            [0     color rgb 1]
            [0.995 color rgb 1]
            [0.995 color rgb 0.8]
            [1     color rgb 0.8]
          }
          scale 0.065 
        }
        normal {checker 0.08 turbulence 0.2
          scale 0.008
        }
      }
    }
    difference {
      cylinder {Scroll_Top*y-z*Scroll_Width/1.98,Scroll_Top*y+z*Scroll_Width/1.98,Scroll_TopRadius/3}
      cylinder {Scroll_Top*y-z*Scroll_Width/1.94,Scroll_Top*y+z*Scroll_Width/1.94,Scroll_TopRadius/3.2}
      pigment {rgb 0.9*<1,0.85,0.7>}
      normal {bumps 0.4 scale 0.001}
      finish {ambient 0}
    }
    translate -y*0.175
  } 
  
#end