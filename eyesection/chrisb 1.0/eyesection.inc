//
// eyesection.inc
// --------------
//
// Model created by Israel Barzel 1997  
// Adapted to go into the POV-Ray Object Collection Oct 2009 by Chris Bartlett
// This include file adds a model of the section of an eye to your scene. It can 
// also add the tools used to perform Phacoemulcification (modern cataract 
// surgery) to the model.
//
// This file is licensed under the terms of the CC-LGPL. 
// Source http://lib.povray.org/
//
// The model is about 50 POV-Ray units in height and, by default, the centre of the 
// eye is centred at the origin.
//
// Adding this model to your scene is likely to add a few seconds to the render time.
//
// See eyesection.html for more details
//

#include "eyesection_materials.inc"

#ifndef (EyeSection_CutLens          ) #declare EyeSection_CutLens           = true;    #end
#ifndef (EyeSection_PhacoProbeDepth  ) #declare EyeSection_PhacoProbeDepth   = 1;       #end
#ifndef (EyeSection_InfusionTubeDepth) #declare EyeSection_InfusionTubeDepth = 1;       #end

#ifndef (EyeSection_SectionLens      ) #declare EyeSection_SectionLens       = 1;       #end
#ifndef (EyeSection_SectionIris      ) #declare EyeSection_SectionIris       = 1;       #end
#ifndef (EyeSection_SectionOra       ) #declare EyeSection_SectionOra        = 1;       #end
#ifndef (EyeSection_SectionCornea    ) #declare EyeSection_SectionCornea     = 1;       #end
#ifndef (EyeSection_SectionChoroid   ) #declare EyeSection_SectionChoroid    = 1;       #end
#ifndef (EyeSection_SectionSclera    ) #declare EyeSection_SectionSclera     = 1;       #end
#ifndef (EyeSection_SectionRetina    ) #declare EyeSection_SectionRetina     = 1;       #end
#ifndef (EyeSection_SectionOpticNerve) #declare EyeSection_SectionOpticNerve = 1;       #end


#declare EyeSection_PhacoTube1 = difference {
  cylinder { // tube1
    <0,0,1>, <0,0,0>, 1 open
    material {
      EyeSection_WhiteMaterial
    }
    no_shadow
    hollow
    photons {
      collect off
      pass_through off
    }
    scale <1.1, 1.1, 40.0>
    rotate -90.0*x
    translate  2.0*y
  }
  cylinder { // Cylndr2
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_TransparentMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.6, 0.6, 3.0>
    rotate -90.0*y
    translate  <1.5, 3.5, 0.0>
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  translate  0.5*y
}
#declare EyeSection_PhacoTube2 = intersection {
  cylinder { // tube2
    <0,0,1>, <0,0,0>, 1 open
    material {
      EyeSection_GoldMaterial
    }
    no_shadow
    hollow
    photons {
      collect off
      pass_through off
    }
    scale <1.0, 1.0, 42.0>
    rotate -90.0*x
  }
  plane { // Plane8
    z,0
    material {
      EyeSection_TransparentMaterial2
    }
    photons {
      collect off
    }
    scale 2.0
    rotate 48.0*x
    translate  <0.0, 0.619542, -0.154885>
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
}
#declare EyeSection_PhacoProbe = union { // Phaco
  object { EyeSection_PhacoTube1 }
  object { EyeSection_PhacoTube2 }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  translate y*20*(1-EyeSection_PhacoProbeDepth)  
  rotate <6.96933, -2.450411, -70.72242>
  translate  <-0.500143, 0.290967, 18.612857>
}


#declare EyeSection_InfusionCoils = merge {
  torus { // Torus7
    1.5, 0.5  rotate -x*90
    material {
      EyeSection_ChromeMetalMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    rotate -90.0*x
    translate  6.0*y
  }
  torus { // Torus6
    1.5, 0.5  rotate -x*90
    material {
      EyeSection_ChromeMetalMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    rotate -90.0*x
    translate  5.0*y
  }
  torus { // Torus5
    1.5, 0.5  rotate -x*90
    material {
      EyeSection_ChromeMetalMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    rotate -90.0*x
    translate  4.0*y
  }
  torus { // Torus3
    1.5, 0.5  rotate -x*90
    material {
      EyeSection_ChromeMetalMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    rotate -90.0*x
    translate  2.0*y
  }
  torus { // Torus4
    1.5, 0.5  rotate -x*90
    material {
      EyeSection_ChromeMetalMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    rotate -90.0*x
    translate  3.0*y
  }
  torus { // Torus2
    1.5, 0.5  rotate -x*90
    material {
      EyeSection_ChromeMetalMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    rotate -90.0*x
    translate  1.0*y
  }
  torus { // Torus8
    1.5, 0.5  rotate -x*90
    material {
      EyeSection_ChromeMetalMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    rotate -90.0*x
  }
  torus { // Torus9
    1.5, 0.5  rotate -x*90
    material {
      EyeSection_ChromeMetalMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    rotate -90.0*x
    translate  7.0*y
  }
  torus { // Torus10
    1.5, 0.5  rotate -x*90
    material {
      EyeSection_ChromeMetalMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    rotate -90.0*x
    translate  8.0*y
  }
  torus { // Torus11
    1.5, 0.5  rotate -x*90
    material {
      EyeSection_ChromeMetalMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    rotate -90.0*x
    translate  9.0*y
  }
  torus { // Torus12
    1.5, 0.5  rotate -x*90
    material {
      EyeSection_ChromeMetalMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    rotate -90.0*x
    translate  10.0*y
  }
  photons {
    collect off
  }
}
#declare EyeSection_InfusionCoilsInverse = difference {
  plane { // Plane9
    z,0
    material {
      EyeSection_TransparentMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 5.0
    rotate <-53.499115, -0.0, 180.0>
    translate  1.0*y
  }
  object { EyeSection_InfusionCoils }
  no_shadow
  photons {
    collect off
    pass_through off
  }
}
#declare EyeSection_InfusionTube = union { // Infusion
  cylinder { // Cylndr002
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ChromeMetalMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <4.0, 4.0, 12.0>
    rotate -90.0*x
    translate  22.0*y
  }
  cylinder { // Cylndr003
    <0,0,1>, <0,0,0>, 1 open
    material {
      EyeSection_GreenMaterial
    }
    no_shadow
    hollow
    photons {
      collect off
      pass_through off
    }
    scale <4.1, 4.1, 30.0>
    rotate -90.0*x
    translate  30.0*y
  }
  cylinder { // Cylndr3
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ChromeMetalMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <3.0, 3.0, 12.0>
    rotate -90.0*x
    translate  10.5*y
  }
  object { EyeSection_InfusionCoilsInverse }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  scale 0.35
  translate y*20*(1-EyeSection_InfusionTubeDepth)  
  rotate <4.034634, 3.086068, 52.646946>
  translate  <-8.0, 6.268226, 20.0>
}


#declare EyeSection_OraSerata = intersection {
  sphere { // Sphere004
    <0,0,0>,1
    material {
      EyeSection_IrisMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 23.9
  }
  plane { // Plane111_h
    z,0
    material {
      EyeSection_TransparentMaterial1
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 20.0
    rotate <-180.0, 0.0, 180.0>
    translate  <0.0, 0.319249, 11.772076>
  }
  #if (EyeSection_SectionOra)
    plane { // Plane111_v
      z,0
      material {
        EyeSection_TransparentMaterial1
      }
      no_shadow
      photons {
        collect off
        pass_through off
      }
      scale 22.0
      rotate <-90.0, 0.0, -180.0>
      translate  <0.0, -6.0, 9.349992>
    }
  #end
  plane { // Plane222_h
    z,0
    material {
      EyeSection_TransparentMaterial1
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 20.0
    translate  19.0*z
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  scale 0.98
}
#declare EyeSection_Cornea = difference {
  sphere { // Sphere5
    <0,0,0>,1
    material {
      EyeSection_CorneaMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 17.0
    translate  20.0*z
  }
  sphere { // Sphere002
    <0,0,0>,1
    material {
      EyeSection_CorneaMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 16.0
    translate  20.0*z
  }
  plane { // Plane001_h
    z,0
    material {
      EyeSection_CornealCrossSectionMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 18.0
    translate  28.6*z
  }
  #if (EyeSection_SectionCornea)
    plane { // Plane002_v
      z,0
      material {
        EyeSection_CornealCrossSectionMaterial
      }
      no_shadow
      photons {
        collect off
        pass_through off
      }
      scale 18.0
      rotate -90.0*x
      translate  <0.0, -5.0, 20.0>
    }                            
  #end
  no_shadow
  photons {
    collect off
    pass_through off
  }
  translate  -9.3*z
}
#declare EyeSection_Choroid = intersection {
  sphere { // Sphere2
    <0,0,0>,1
    material {
      EyeSection_ChoroidMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 23.6
  }
  #if (EyeSection_SectionChoroid)
    plane { // Plane_v2
      z,0
      material {
        EyeSection_TransparentMaterial1
      }
      no_shadow
      photons {
        collect off
        pass_through off
      }
      scale 26.0
      rotate <-90.0, 0.0, -180.0>
      translate  -5.8*y
    }                           
  #end
  plane { // Plane_h2
    z,0
    material {
      EyeSection_TransparentMaterial1
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 26.0
    translate  <-0.45, 0.0, 12.45>
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  scale 0.98
}
#declare EyeSection_Sclera = difference {
  sphere { // Sphere4
    <0,0,0>,1
    material {
      EyeSection_ScleraMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 24.4
  }
  sphere { // Sphere001
    <0,0,0>,1
    material {
      EyeSection_ScleraMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 23.5
  }
  #if (EyeSection_SectionSclera)
    plane { // Plane_v1
      z,0
      material {
        EyeSection_ScleraMaterial
      }
      no_shadow
      photons {
        collect off
        pass_through off
      }
      scale 26.0
      rotate -90.0*x
      translate  -5.0*y
    }
  #end
  plane { // Plane_h1
    z,0
    material {
      EyeSection_ScleraMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 20.0
    rotate -180.0*x
    translate  19.5*z
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
}
#declare EyeSection_SchlemmsCanal = difference {
  torus { // Torus13
    1.0, 0.01  rotate -x*90
    material {
      EyeSection_GrayMaterial
    }
    no_shadow
    hollow
    photons {
      collect off
      pass_through off
    }
    scale <0.994644, 0.993884, 0.994644>
    translate  1.459965*z
  }
  plane { // Plane12
    z,0
    material {
      EyeSection_TransparentMaterial1
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 1.2
    rotate -90.0*x
    translate  <0.0, -0.37, 1.0>
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  scale 14.5
  translate  -2.0*z
}
#declare EyeSection_ZonularFibers = union {
  cylinder { // Cylndr4
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate -90.0*x
    translate  <-0.394567, 7.759823, 0.0>
  }
  cylinder { // Cylndr5
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, -90.0>
    translate  <7.759823, 0.394567, 0.0>
  }
  cylinder { // Cylndr6
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, 90.0>
    translate  <-7.759823, -0.394567, 0.0>
  }
  cylinder { // Cylndr7
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, 80.0>
    translate  <-7.710449, 0.958906, 0.0>
  }
  cylinder { // Cylndr8
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, 70.0>
    translate  <-7.426798, 2.283244, 0.0>
  }
  cylinder { // Cylndr9
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, 60.0>
    translate  <-6.917487, 3.538206, 0.0>
  }
  cylinder { // Cylndr10
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, 50.0>
    translate  <-6.197992, 4.685662, 0.0>
  }
  cylinder { // Cylndr11
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, 40.0>
    translate  <-5.290174, 5.690746, 0.0>
  }
  cylinder { // Cylndr12
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, 30.0>
    translate  <-4.221617, 6.52292, 0.0>
  }
  cylinder { // Cylndr13
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, 20.0>
    translate  <-3.024788, 7.156898, 0.0>
  }
  cylinder { // Cylndr14
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, 10.0>
    translate  <-1.736052, 7.573418, 0.0>
  }
  cylinder { // Cylndr15
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate -90.0*x
    translate  <-0.394567, 7.759823, 0.0>
  }
  cylinder { // Cylndr16
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, -10.0>
    translate  <0.958906, 7.710449, 0.0>
  }
  cylinder { // Cylndr17
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, -20.0>
    translate  <2.283244, 7.426798, 0.0>
  }
  cylinder { // Cylndr18
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, -30.0>
    translate  <3.538206, 6.917487, 0.0>
  }
  cylinder { // Cylndr19
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, -40.0>
    translate  <4.685662, 6.197992, 0.0>
  }
  cylinder { // Cylndr20
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, -50.0>
    translate  <5.690746, 5.290174, 0.0>
  }
  cylinder { // Cylndr21
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, -60.0>
    translate  <6.52292, 4.221617, 0.0>
  }
  cylinder { // Cylndr22
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, -70.0>
    translate  <7.156898, 3.024788, 0.0>
  }
  cylinder { // Cylndr23
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, -80.0>
    translate  <7.573418, 1.736052, 0.0>
  }
  cylinder { // Cylndr24
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, -90.0>
    translate  <7.759823, 0.394567, 0.0>
  }
  cylinder { // Cylndr25
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_ZonularFibersMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.01, 0.01, 5.0>
    rotate <-90.0, 0.0, -110.0>
    translate  <7.426798, -2.283244, 0.0>
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  translate  16.5*z
}
#declare EyeSection_IrisTop = intersection {
  torus { // Torus001
    4.946, 1.539  rotate -x*90
    material {
      EyeSection_IrisMaterial1
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <1.0, 1.0, 0.156417>
  }
  #if (EyeSection_SectionIris)
    plane { // Plane001
      z,0
      material {
        EyeSection_IrisCutAwayMaterial
      }
      no_shadow
      photons {
        collect off
        pass_through off
      }
      scale <11.626823, 4.404391, 3.874956>
      rotate 90.0*x
      translate  <-0.185592, -2.615564, 0.0>
    }
  #end
  no_shadow
  photons {
    collect off
    pass_through off
  }
}
#declare EyeSection_IrisBody1 = intersection {
  #if (EyeSection_SectionIris)
    plane { // Plane002
      z,0
      material {
        EyeSection_IrisCutAwayMaterial
      }
      no_shadow
      photons {
        collect off
        pass_through off
      }
      scale <-8.444781, -3.927712, -7.760377>
      rotate -90.0*x
      translate  <-0.123728, -2.646924, 0.0>
    }
  #end
  torus { // Torus002
    1.842, 0.309  rotate -x*90
    material {
      EyeSection_IrisMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale -3.23242
    translate  <-0.044933, -0.253945, -0.815177>
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
}
#declare EyeSection_IrisBody2 = difference {
  object { EyeSection_IrisBody1 }
  torus { // Torus003
    1.7025, 0.1785  rotate -x*90
    material {
      EyeSection_IrisMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <-3.016034, 3.054235, -4.696887>
    translate  <0.0, -0.052356, -1.007899>
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
}
#declare EyeSection_IrisCore = torus { // Torus14
  1.972, 0.138  rotate -x*90
  material {
    EyeSection_IrisMaterial2
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  scale <3.044407, 2.955662, 3.044407>
  rotate <-180.0, 0.0, -180.0>
  translate  <-0.090557, 0.0, -1.314021>
  no_shadow
  photons {
    collect off
    pass_through off
  }
}
#declare EyeSection_IrisBumps = intersection {
  object { EyeSection_IrisCore }
  #if (EyeSection_SectionIris)
    plane { // Plane003
      z,0
      material {
        EyeSection_IrisCutAwayMaterial
      }
      no_shadow
      photons {
        collect off
        pass_through off
      }
      scale <10.034139, 2.368809, 1.821285>
      rotate 90.0*x
      translate  <-0.123728, -2.708481, 0.0>
    }
  #end
  no_shadow
  photons {
    collect off
    pass_through off
  }
}
#declare EyeSection_IrisBottom = intersection {
  torus { // Torus004
    1.457, 0.112  rotate -x*90
    material {
      EyeSection_IrisMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    translate  <0.0, -0.050007, 1.795439>
  }
  #if (EyeSection_SectionIris)
    plane { // Plane004
      z,0
      material {
        EyeSection_IrisCutAwayMaterial
      }
      no_shadow
      photons {
        collect off
        pass_through off
      }
      scale <2.159937, 0.702034, 1.0>
      rotate 90.0*x
      translate  <-0.042372, -0.554411, 0.0>
    }
  #end
  no_shadow
  photons {
    collect off
    pass_through off
  }
  scale 4.624297
  translate  -9.499758*z
}
#declare EyeSection_Iris = union {
  object { EyeSection_IrisTop }
  object { EyeSection_IrisBody2 }
  object { EyeSection_IrisBumps }
  object { EyeSection_IrisBottom }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  scale 2.03
  translate  19.284508*z
}
#declare EyeSection_Retina = intersection {
  sphere { // Sphere3
    <0,0,0>,1
    material {
      EyeSection_RetinaMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 23.0
  }
  #if (EyeSection_SectionRetina)
    plane { // Plane_v3
      z,0
      material {
        EyeSection_TransparentMaterial1
      }
      no_shadow
      photons {
        collect off
        pass_through off
      }
      scale 26.0
      rotate <-90.0, 0.0, -180.0>
      translate  -5.8*y
    }                          
  #end
  plane { // Plane_h3
    z,0
    material {
      EyeSection_TransparentMaterial1
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 26.0
    translate  <-0.45, 0.0, 12.45>
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  scale 0.97
}
#declare EyeSection_OpticNerveFibres = intersection {
  cylinder { // Cylndr004
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_YellowMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <1.0, 1.0, 5.255086>
  } 
  #if (EyeSection_SectionOpticNerve)
    plane { // Plane006
      z,0
      material {
        EyeSection_YellowMaterial
      }
      no_shadow
      photons {
        collect off
        pass_through off
      }
      scale <1.602713, 3.248618, 2.0>
      rotate -90.0*x
      translate  <0.028378, 0.0, 2.951278>
    }
  #end
  no_shadow
  photons {
    collect off
    pass_through off
  }
  scale <0.75, 0.75, 1.0>
  translate  <-75.0, -30.0, 25.0>
}
#declare EyeSection_OpticNerveShaft = difference {
  cylinder { // Cylndr26
    <0,0,1>, <0,0,0>, 1 open
    material {
      EyeSection_ScleraMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <1.0, 1.0, 6.0>
  }
  cylinder { // Cylndr27
    <0,0,1>, <0,0,0>, 1 open
    material {
      EyeSection_ScleraMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <0.75, 0.75, 6.0>
  }
  #if (EyeSection_SectionOpticNerve)
    plane { // Plane005
      z,0
      material {
        EyeSection_ScleraMaterial
      }
      no_shadow
      photons {
        collect off
        pass_through off
      }
      scale <1.940933, 3.970616, 1.278141>
      rotate 90.0*x
      translate  <0.051888, 0.0, 2.698162>
    }
  #end
  no_shadow
  photons {
    collect off
    pass_through off
  }
  scale <0.930018, 1.0, 0.860035>
  translate  <-75.0, -30.0, 25.0>
}
#declare EyeSection_OpticNerve = union {
  object { EyeSection_OpticNerveFibres }
  object { EyeSection_OpticNerveShaft }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  scale 2.0
  rotate 180.0*x
  translate  <149.957229, -60.041225, 29.36756>
}
#declare EyeSection_LensSac3 = intersection {
  sphere { // Sphere9
    <0,0,0>,1
    material {
      EyeSection_LensMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <10.0, 10.0, 3.0>
    translate  <160.721636, 52.085715, 0.0>
  }
  plane { // Plane10
    z,0
    material {
      EyeSection_TransparentMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 11.0
    rotate -180.0*x
    translate  <161.067014, 51.758148, 0.0>
  }
  plane { // Plane11
    z,0
    material {
      EyeSection_TransparentMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 11.0
    rotate <-90.0, 0.0, -180.0>
    translate  <160.693519, 47.740094, 0.0>
  }
  material {
    EyeSection_TransparentMaterial2
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  translate  <0.002, 0.0, 0.03>
}
#declare EyeSection_LensSac4 = intersection {
  sphere { // Sphere10
    <0,0,0>,1
    material {
      EyeSection_LensMaterial
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 10.3
    translate  <160.721636, 52.085715, 0.0>
  }
  plane { // Plane13
    z,0
    material {
      EyeSection_TransparentMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 11.0
    translate  <161.067014, 51.758148, -2.3>
  }
  plane { // Plane14
    z,0
    material {
      EyeSection_TransparentMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 11.0
    rotate <-90.0, 0.0, -180.0>
    translate  <160.5, 48.0, 0.0>
  }
  material {
    EyeSection_TransparentMaterial2
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  translate  2.3*z
}
#declare EyeSection_LensSac1 = union {
  object { EyeSection_LensSac3 }
  object { EyeSection_LensSac4 }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  translate  <-161.383816, -53.0, 16.0>
}
#declare EyeSection_Capsulorexis = difference {
  object { EyeSection_LensSac1 }
  cylinder { // RHEXIS_CUT
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_TransparentMaterial2
    }
    photons {
      collect off
    }
    scale <7.0, 7.0, 1.0>
    rotate <-0.0, -0.0, 0.0>
    translate  <-0.77, -3.0, 18.33>
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  rotate -0.0*z
  translate  <164.383816, -10.0, -16.0>
}
#declare EyeSection_LensN5 = intersection {
  sphere { // Sphere12
    <0,0,0>,1
    material {
      EyeSection_NucleusMaterial1
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <10.0, 10.0, 3.0>
    translate  <160.721636, 52.085715, 0.0>
  }
  plane { // Plane15
    z,0
    material {
      EyeSection_TransparentMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 11.0
    rotate -180.0*x
    translate  <161.067014, 51.758148, 0.0>
  }
  #if (EyeSection_SectionLens)
    plane { // Plane16
      z,0
      material {
        EyeSection_NucleusMaterial1
      }
      no_shadow
      photons {
        collect off
        pass_through off
      }
      scale 11.0
      rotate <-90.0, 0.0, -180.0>
      translate  <160.858317, 48.338439, 0.0>
    } 
  #end
  material {
    EyeSection_TransparentMaterial2
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  translate  -0.0025*z
}
#declare EyeSection_LensN6 = intersection {
  sphere { // Sphere13
    <0,0,0>,1
    material {
      EyeSection_NucleusMaterial1
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 10.3
    translate  <160.721636, 52.085715, 0.0>
  }
  plane { // Plane17
    z,0
    material {
      EyeSection_TransparentMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale 11.0
    translate  <161.067014, 51.758148, -2.2>
  }
  #if (EyeSection_SectionLens)
    plane { // Plane18
      z,0
      material {
        EyeSection_NucleusMaterial1
      }
      no_shadow
      photons {
        collect off
        pass_through off
      }
      scale 11.0
      rotate <-90.0, 0.0, -180.0>
      translate  <160.525392, 48.3, 0.0>
    }   
  #end
  material {
    EyeSection_TransparentMaterial2
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  scale 0.9999
  translate  2.37*z
}
#declare EyeSection_LensNucleus = merge {
  object { EyeSection_LensN5 }
  object { EyeSection_LensN6 }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  scale 0.99
  rotate <180.0, 0.0, -0.0>
  translate  <-159.383816, 55.195103, 17.085664>
}
#declare EyeSection_LensCuts = merge {
  cylinder { // R6
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_TransparentMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <1.0, 1.0, 5.0>
    rotate <90.0, -0.0, 90.0>
    translate  <-0.0, -7.713689, -14.760429>
  }
  cylinder { // R7
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_NucleusMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <1.0, 1.0, 6.0>
    rotate <90.0, -0.0, 90.0>
    translate  <-0.243278, -2.542305, -13.629715>
  }
  cylinder { // R8
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_TransparentMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <1.0, 1.0, 6.0>
    rotate <90.0, -0.0, 90.0>
    translate  <-0.312786, -3.724483, -14.048947>
  }
  cylinder { // Cylndr28
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_NucleusMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <1.0, 1.0, 6.0>
    rotate <-90.0, -0.0, -90.0>
    translate  <0.363835, 1.490662, -13.083996>
  }
  cylinder { // Cylndr29
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_NucleusMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <1.0, 1.0, 6.0>
    rotate <-90.0, -0.0, -90.0>
    translate  <-1.013046, -5.965709, -14.534289>
  }
  cylinder { // Cylndr30
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_NucleusMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <1.0, 1.0, 6.0>
    rotate <-90.0, -0.0, -90.0>
    translate  <0.782482, 2.815171, -12.698982>
  }
  cylinder { // Cylndr31
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_NucleusMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <1.0, 1.0, 6.0>
    rotate <-90.0, -0.0, -90.0>
    translate  <-0.565946, -6.818031, -14.787573>
  }
  cylinder { // Cylndr32
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_NucleusMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <1.0, 1.0, 6.0>
    rotate <-90.0, -0.0, -90.0>
    translate  <-0.35549, 0.16523, -13.216652>
  }
  cylinder { // Cylndr33
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_NucleusMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <1.0, 1.0, 6.0>
    rotate <-90.0, -0.0, -90.0>
    translate  <-0.597716, -8.631255, -14.69273>
  }
  cylinder { // R9
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_NucleusMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <1.0, 1.0, 6.0>
    rotate <90.0, -0.0, 90.0>
    translate  <-0.0, -1.289165, -13.475871>
  }
  cylinder { // R10
    <0,0,1>, <0,0,0>, 1 
    material {
      EyeSection_NucleusMaterial2
    }
    no_shadow
    photons {
      collect off
      pass_through off
    }
    scale <1.0, 1.0, 6.0>
    rotate <90.0, -0.0, 90.0>
    translate  <-0.444855, -4.847776, -14.101137>
  }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  rotate <-0.0, 0.0, -0.0>
  translate  <-3.673656, 4.521092, 28.0>
  material {
    EyeSection_NucleusMaterial2
    // Transform to parent space
  }
}
#declare EyeSection_WithCuts = difference {
  object { EyeSection_LensNucleus }
  #if (EyeSection_CutLens) object { EyeSection_LensCuts } #end
  no_shadow
  photons {
    collect off
    pass_through off
  }
  rotate <180.0, 0.0, -0.0>
  translate  <164.383816, -7.804897, 17.085664>
}
#declare EyeSection_Lens = union {
  object { EyeSection_Capsulorexis }
  object { EyeSection_WithCuts }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  rotate <0.0, 0.0, -0.0>
  translate  <-164.850002, 10.0, 16.5>
}
union { // EYE_MODEL
  #if (EyeSection_PhacoProbeDepth  )  object { EyeSection_PhacoProbe     } #end
  #if (EyeSection_InfusionTubeDepth)  object { EyeSection_InfusionTube   } #end
  object { EyeSection_OraSerata      }
  object { EyeSection_Cornea         }
  object { EyeSection_Choroid        }
  object { EyeSection_Sclera         }
  object { EyeSection_SchlemmsCanal  }
  object { EyeSection_ZonularFibers  }
  object { EyeSection_Iris           }
  object { EyeSection_Retina         }
  object { EyeSection_OpticNerve     }
  object { EyeSection_Lens           }
  no_shadow
  photons {
    collect off
    pass_through off
  }
  rotate <-90,180,0>
  scale <-1,1,1>
}

