// OSE_envelope_social.inc
// ----------------------
// Created by Chris Bartlett January 2008 as part of the 'Office Supplies' theme assembled by Ben Chambers
// This file is used by the OSE_Envelope macro when an OSE_EnvelopeStyle of 'social' is specified to define the 
// basic envelope shape. It depends upon variables set within the OSE_Envelope macro as documented in the
// OSE_envelope.html file accompanying this file. Note. This is just the core of the shape and the flap. Rounded
// edges and corners are added along with any window hole required, by the macro rather than in this file.  
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//

// Note. CutterLength is the length of the diagonal cut required to trim the edge off the flap.
// It is calculated by the OSE_Envelope macro based on the OSE_EnvelopeFlapLength and OSE_EnvelopeFlapChamferAngle settings.

// The main envelope shape 
difference {
  box {
    <OSE_EnvelopeThickness/2,0,OSE_EnvelopeThickness/2>,
    <OSE_EnvelopeWidth-OSE_EnvelopeThickness/2, OSE_EnvelopeThickness, OSE_EnvelopeDepth-OSE_EnvelopeThickness/2>
  }
  // Cut ridges in the back of the envelope to represent the seams
  difference { 
    box {<0,-0.0001,OSE_EnvelopeDepth/2><OSE_EnvelopeWidth,OSE_EnvelopeThickness/2,OSE_EnvelopeDepth>}
    box {<0,-0.0001,0><CutterLength,0.0001+OSE_EnvelopeThickness/2,CutterLength>
      rotate y*(OSE_EnvelopeFlapChamferAngle+90) 
      translate z*OSE_EnvelopeDepth
    }
    box {<0,-0.0001,0><CutterLength,0.0001+OSE_EnvelopeThickness/2,CutterLength>
      rotate y*(180-OSE_EnvelopeFlapChamferAngle) 
      translate <OSE_EnvelopeWidth,0,OSE_EnvelopeDepth>
    }
  }
} 

// Add the bottom overlapped section to the back 
difference {
  box {<OSE_EnvelopeThickness/2,0,0>,<OSE_EnvelopeWidth-OSE_EnvelopeThickness/2,OSE_EnvelopeThickness/2,0.5*OSE_EnvelopeDepth>} 
  box {<0,-0.0001,0><1.5*CutterLength,0.0001+OSE_EnvelopeThickness/2,1.5*CutterLength>
    rotate -y*45
    translate x*(OSE_EnvelopeThickness/2)
  }
  box {<0,-0.0001,0><1.5*CutterLength,0.0001+OSE_EnvelopeThickness/2,1.5*CutterLength>
    rotate -y*45
    translate x*(OSE_EnvelopeWidth-OSE_EnvelopeThickness/2)
  }
  translate z*OSE_EnvelopeThickness/2 
  translate -y*OSE_EnvelopeThickness/10
}
   
// Add the flap
difference { 
  box {<OSE_EnvelopeThickness/2,0,0>,<OSE_EnvelopeWidth-OSE_EnvelopeThickness/2,OSE_EnvelopeThickness/2,OSE_EnvelopeFlapLength>}
  box {<0,-0.0001,0><CutterLength,0.0001+OSE_EnvelopeThickness/2,CutterLength>
    rotate y*(OSE_EnvelopeFlapChamferAngle-90) 
    translate z*0.008
  }
  box {<0,-0.0001,0><CutterLength,0.0001+OSE_EnvelopeThickness/2,CutterLength>
    rotate -y*OSE_EnvelopeFlapChamferAngle   
    translate z*0.008
    translate x*OSE_EnvelopeWidth
  }
  #if (OSE_EnvelopeFlapAngle<180)
    rotate -(OSE_EnvelopeFlapAngle-180)*x
    translate <0,(OSE_EnvelopeThickness/2)-OSE_EnvelopeThickness/10,OSE_EnvelopeDepth-OSE_EnvelopeThickness/2>
  #else 
    translate -y*OSE_EnvelopeThickness/2
    rotate -(OSE_EnvelopeFlapAngle-180)*x
    translate <0,OSE_EnvelopeThickness,OSE_EnvelopeDepth-OSE_EnvelopeThickness/2>
  #end
}
