// envelope_business.inc
// ---------------------
// Created by Chris Bartlett January 2008 as part of the 'Office Supplies' theme assembled by Ben Chambers
// This file is used by the Envelope_ macro when an Envelope_Style of 'business' is specified to define the 
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
  #if (strcmp(Envelope_FlapLocation,"Right")=0)
    box {<Envelope_Width-0.2*Envelope_FlapLength,0,0.1*Envelope_Depth>,<Envelope_Width,Envelope_Thickness/2,0.9*Envelope_Depth>} 
  #else
    box {<0.1*Envelope_Width,-0.001,Envelope_Depth-0.2*Envelope_FlapLength>,<0.9*Envelope_Width,Envelope_Thickness/2,Envelope_Depth>} 
  #end
}

// Add the overlapped sections to the back 
// Bottom fold
difference {
  box {<Envelope_Thickness/2,0,0>,<Envelope_Width-Envelope_Thickness/2,Envelope_Thickness/2,0.125*Envelope_Depth>} 
  box {<0,-0.0001,0><1.5*CutterLength,0.0001+Envelope_Thickness/2,1.5*CutterLength>
    rotate -y*45
    translate x*(Envelope_Thickness/2)
  }
  box {<0,-0.0001,0><1.5*CutterLength,0.0001+Envelope_Thickness/2,1.5*CutterLength>
    rotate -y*45
    translate x*(Envelope_Width-Envelope_Thickness/2)
  }
  rotate x*1
  translate z*Envelope_Thickness/2
}
// Left Fold
difference {
  box {<0,0,Envelope_Thickness/2>,<0.08*Envelope_Width,Envelope_Thickness/2,Envelope_Depth-Envelope_Thickness/2>} 
  box {<0,-0.0001,0><1.5*CutterLength,0.0001+Envelope_Thickness/2,1.5*CutterLength>
    rotate y*50
    translate z*(Envelope_Thickness/2)
  }
  box {<0,-0.0001,0><1.5*CutterLength,0.0001+Envelope_Thickness/2,1.5*CutterLength>
    rotate y*40
    translate z*(Envelope_Depth-Envelope_Thickness/2)
  }
  rotate -z*1.1
  translate x*Envelope_Thickness/2
}
    
// Add the flap
#if (strcmp(Envelope_FlapLocation,"Right")=0) 
  difference { 
    box {<0,0,Envelope_Thickness/2>,<Envelope_FlapLength,Envelope_Thickness/2,Envelope_Depth-Envelope_Thickness/2>}
    box {<0,-0.0001,0><CutterLength,0.0001+Envelope_Thickness/2,CutterLength>
      rotate y*(90-Envelope_FlapChamferAngle)
    }
    box {<0,-0.0001,0><CutterLength,0.0001+Envelope_Thickness/2,CutterLength>
      rotate y*Envelope_FlapChamferAngle
      translate z*Envelope_Depth
    }
    #if (Envelope_FlapAngle<180)
      rotate (Envelope_FlapAngle-180)*z 
      translate <Envelope_Width-Envelope_Thickness/2,Envelope_Thickness/2,0>
    #else 
      translate -y*Envelope_Thickness/2
      rotate (Envelope_FlapAngle-180)*z
      translate <Envelope_Width-Envelope_Thickness/2,Envelope_Thickness,0>
    #end
  }
#else
  difference { 
    box {<Envelope_Thickness/2,0,0>,<Envelope_Width-Envelope_Thickness/2,Envelope_Thickness/2,Envelope_FlapLength>}
    box {<0,-0.0001,0><CutterLength,0.0001+Envelope_Thickness/2,CutterLength>
      rotate y*(Envelope_FlapChamferAngle-90)
    }
    box {<0,-0.0001,0><CutterLength,0.0001+Envelope_Thickness/2,CutterLength>
      rotate -y*Envelope_FlapChamferAngle
      translate x*Envelope_Width
    }
    #if (Envelope_FlapAngle<180)
      rotate -(Envelope_FlapAngle-180)*x
      translate <0,Envelope_Thickness/2,Envelope_Depth-Envelope_Thickness/2>
    #else 
      translate -y*Envelope_Thickness/2
      rotate -(Envelope_FlapAngle-180)*x
      translate <0,Envelope_Thickness,Envelope_Depth-Envelope_Thickness/2>
    #end
  }
#end
