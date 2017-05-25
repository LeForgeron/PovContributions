// envelope_social.inc
// -------------------
// Created by Chris Bartlett January 2008 as part of the 'Office Supplies' theme assembled by Ben Chambers
// This file is used by the Envelope_ macro when an Envelope_Style of 'social' is specified to define the 
// basic envelope shape. It depends upon variables set within the Envelope_ macro as documented in the
// envelope.html file accompanying this file. Note. This is just the core of the shape and the flap. Rounded
// edges and corners are added along with any window hole required, by the macro rather than in this file.  
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//

// Note. CutterLength is the length of the diagonal cut required to trim the edge off the flap.
// It is calculated by the Envelope_ macro based on the Envelope_FlapLength and Envelope_FlapChamferAngle settings.

// The main envelope shape 
difference {
  box {
    <Envelope_Thickness/2,0,Envelope_Thickness/2>,
    <Envelope_Width-Envelope_Thickness/2, Envelope_Thickness, Envelope_Depth-Envelope_Thickness/2>
  }
  // Cut ridges in the back of the envelope to represent the seams
  difference { 
    box {<0,-0.0001,Envelope_Depth/2><Envelope_Width,Envelope_Thickness/2,Envelope_Depth>}
    box {<0,-0.0001,0><CutterLength,0.0001+Envelope_Thickness/2,CutterLength>
      rotate y*(Envelope_FlapChamferAngle+90) 
      translate z*Envelope_Depth
    }
    box {<0,-0.0001,0><CutterLength,0.0001+Envelope_Thickness/2,CutterLength>
      rotate y*(180-Envelope_FlapChamferAngle) 
      translate <Envelope_Width,0,Envelope_Depth>
    }
  }
} 

// Add the bottom overlapped section to the back 
difference {
  box {<Envelope_Thickness/2,0,0>,<Envelope_Width-Envelope_Thickness/2,Envelope_Thickness/2,0.5*Envelope_Depth>} 
  box {<0,-0.0001,0><1.5*CutterLength,0.0001+Envelope_Thickness/2,1.5*CutterLength>
    rotate -y*45
    translate x*(Envelope_Thickness/2)
  }
  box {<0,-0.0001,0><1.5*CutterLength,0.0001+Envelope_Thickness/2,1.5*CutterLength>
    rotate -y*45
    translate x*(Envelope_Width-Envelope_Thickness/2)
  }
  translate z*Envelope_Thickness/2 
  translate -y*Envelope_Thickness/10
}
   
// Add the flap
difference { 
  box {<Envelope_Thickness/2,0,0>,<Envelope_Width-Envelope_Thickness/2,Envelope_Thickness/2,Envelope_FlapLength>}
  box {<0,-0.0001,0><CutterLength,0.0001+Envelope_Thickness/2,CutterLength>
    rotate y*(Envelope_FlapChamferAngle-90) 
    translate z*0.008
  }
  box {<0,-0.0001,0><CutterLength,0.0001+Envelope_Thickness/2,CutterLength>
    rotate -y*Envelope_FlapChamferAngle   
    translate z*0.008
    translate x*Envelope_Width
  }
  #if (Envelope_FlapAngle<180)
    rotate -(Envelope_FlapAngle-180)*x
    translate <0,(Envelope_Thickness/2)-Envelope_Thickness/10,Envelope_Depth-Envelope_Thickness/2>
  #else 
    translate -y*Envelope_Thickness/2
    rotate -(Envelope_FlapAngle-180)*x
    translate <0,Envelope_Thickness,Envelope_Depth-Envelope_Thickness/2>
  #end
}
