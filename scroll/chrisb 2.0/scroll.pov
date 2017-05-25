// Scroll.pov
// -----------

// Scene file that generates a mesh2 object in the form of a paper scroll.
// Created by Chris Bartlett 07.02.2005
// Updated by Chris Bartlett 11.08.2008
//    Split out macro into an include file
//    Fixed problem with normals alternating between consecutive triangles
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
// Typical render time 1 minute with text, 1 second without (at 640x480 NoAA).
// Size is about 0.5 POV-Ray units high.
// Position is close to the origin.      
// For animation try command line options +kfi0 +kff10

camera {location <-0.3,0.3,-0.4> look_at <0.1,0.1,0>}
//camera {location <-0.32,0.3,0> look_at <0.1,0.14,0>}

light_source { <-10,4,-4> color rgb 1}
light_source { <-10,-7,-40> color rgb 1} 

// Include the files to generate a scroll object and to format the text
#include "scroll.inc" 
#include "scroll_typeset.inc" 
 
// Set the length, in POV-Ray units at which the text (at the default size) will wrap.
#declare Scroll_LineLength    = 25;

// Add text and paragraph throws to the text array
Scroll_WrapText("\"The Hitchhiker's Guide to the Galaxy\" is a wholly remarkable book.") 
//Scroll_WrapText(" Perhaps the most remarkable, certainly the most successful book ever to come out of the great publishing corporations of Ursa Minor.") 
//Scroll_WrapText(" More popular than \"The Celestial Home Care Omnibus\", better selling than \"Fifty-Three More Things to do in Zero Gravity\",") 
//Scroll_WrapText("and more controversial than Oolon Colluphid's trilogy of philosophical blockbusters \"Where God Went Wrong\", \"Some More of God's Greatest Mistakes\" and \"Who is this God Person Anyway?\".") 
//Scroll_WrapText(" It has already supplanted the Encyclopedia Galactica as the standard repository of all knowledge and wisdom, for two important reasons.")
//Scroll_WrapText(" First, it is slightly cheaper; and secondly it has the words DON'T PANIC printed in large friendly letters on the front cover.")
//Scroll_NewParagraph(2)
//Scroll_WrapText("The introduction begins like this:")
//Scroll_NewParagraph(1)
//Scroll_WrapText("'Space', it says, \"is big. Really big. You just won't believe how vastly hugely mind-bogglingly big it is.")
//Scroll_WrapText(" I mean, you may think it's a long way down the road to the supermarket, but that's Just peanuts to space. Listen...\" and so on.")
//Scroll_NewParagraph(2)
//Scroll_WrapText("After a while the style settles down a bit and it begins to tell you things you actually need to know,")
//Scroll_WrapText("like the fact that the fabulously beautiful planet Bethselamin is now so worried about the cumulative erosion casued by ten billion visiting tourists a year that any net imbalance between")
//Scroll_WrapText("the amount you eat and the amount you excrete while on the planet is surgically removed from your body weight when you leave:")
//Scroll_WrapText("so every time you go to the lavatory there, it is vitally important to get a receipt.")

#declare Scroll_TextSlant = -1;

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

//object {MyTextObject pigment {rgb <1,1,0>}}  
//box {-0.5*z,<1,1,0.5> pigment {rgbt 0.9}}
//cylinder {z,-z,0.2 translate 0.35 *y pigment {rgbt 0.9}}
