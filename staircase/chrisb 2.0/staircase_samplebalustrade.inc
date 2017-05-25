//
// Source http://lib.povray.org/
// This file is licensed under the terms of the CC-LGPL. 
// 

/**********************************************************************************/
/* staircase_samplebalustrade.inc  -  Created by Chris Bartlett March 2007        */
/*                                                                                */
/* You may re-use this file in original or modified form with or without credit   */
/* being given to the original author. You may redistribute on any form of media. */
/*                                                                                */
/* Description: This include file defines the components of a balustrade.         */
/* Version:     Written using POV-Ray 3.6                                         */
/*                                                                                */
/**********************************************************************************/

#local StairCase_LathePointCount = 64;
#local StairCase_LatheArray =array [StairCase_LathePointCount] {
    /*   0*/ <324.467640, 846.034903>, <324.467640, 846.034903>, <230.467640,845.993593>, <230.467640,845.993593>,
    /*   1*/ <230.467640, 845.993593>, <230.467640, 845.993593>, <232.467640,663.952283>, <232.467640,663.952283>,
    /*   2*/ <232.467640, 663.952283>, <240.467640, 663.952283>, <260.282980,665.541913>, <261.782980,647.273013>,
    /*   3*/ <261.782980, 647.273013>, <261.782980, 636.504113>, <262.214170,649.030023>, <262.214170,635.280023>,
    /*   4*/ <262.214170, 635.280023>, <270.964170, 635.280023>, <288.188920,627.459293>, <289.188920,613.690393>,
    /*   5*/ <289.188920, 613.690393>, <289.188920, 598.421493>, <264.891890,597.607763>, <265.598330,591.633683>,
    /*   6*/ <265.598330, 591.633683>, <265.804770, 580.159603>, <295.757740,593.918753>, <295.761200,552.355033>,
    /*   7*/ <295.761200, 552.355033>, <295.764670, 494.791313>, <234.409240,501.074233>, <232.130520,442.196803>,
    /*   8*/ <232.130520, 442.196803>, <231.101790, 395.819363>, <288.870100,402.031563>, <289.554770,369.557473>,
    /*   9*/ <289.554770, 369.557473>, <289.739420, 353.833393>, <272.105260,357.446503>, <272.105260,352.571503>,
    /*  10*/ <272.105260, 352.571503>, <272.355260, 346.946503>, <290.455020,353.382793>, <290.480260,331.703513>,
    /*  11*/ <290.480260, 331.703513>, <290.130520, 308.149253>, <243.539920,303.844983>, <235.289920,303.844983>,
    /*  12*/ <235.289920, 303.844983>, <235.914920, 287.219983>, <234.877050,297.861443>, <235.221110,288.521813>,
    /*  13*/ <235.221110, 288.521813>, <234.940180, 271.807183>, <206.905770,272.297723>, <206.905770,272.297723>,
    /*  14*/ <206.905770, 272.297723>, <206.905770, 272.297723>, <205.905770,102.965103>, <205.905770,102.965103>,
    /*  15*/ <205.905770, 102.965103>, <205.905770, 102.965103>, <325.138410,102.554733>, <325.138410,102.554733>
}
#local I = 0;
#while (I<StairCase_LathePointCount) 
  // Scale it so that it's half a metre high and centred at the origin with it's base at y=0
  #local StairCase_LatheArray[I] = <-0.8,1>*0.5*(StairCase_LatheArray[I] -<326.750,100>)/449.070;
  #local I = I + 1;
#end

#declare StairCase_Baluster = lathe {
  bezier_spline
  StairCase_LathePointCount,
  #local I = 0;
  #while (I<StairCase_LathePointCount)  
    #if (I<(StairCase_LathePointCount-1)) StairCase_LatheArray[I], 
    #else                       StairCase_LatheArray[I]
    #end
    #local I = I + 1;
  #end
}

/*##############################################
### PRISM:  StairCase_HandRail
##############################################*/
#declare StairCase_HandRail = prism {
  linear_sweep
  bezier_spline
  1.0, //top
  0.0, //bottom
  52, //nr points
  /*   0*/ <223.000000, 771.987183>, <214.000000, 769.987183>, <215.000000,746.987183>, <216.000000,733.987183>,
  /*   1*/ <216.000000, 733.987183>, <217.000000, 720.987183>, <210.000000,716.987183>, <206.000000,712.987183>,
  /*   2*/ <206.000000, 712.987183>, <202.000000, 708.987183>, <203.000000,700.987183>, <205.000000,695.987183>,
  /*   3*/ <205.000000, 695.987183>, <207.000000, 686.987183>, <226.000000,691.987183>, <226.000000,691.987183>,
  /*   4*/ <226.000000, 691.987183>, <226.000000, 691.987183>, <226.500000,701.487183>, <226.500000,701.487183>,
  /*   5*/ <226.500000, 701.487183>, <226.500000, 701.487183>, <426.187500,700.987183>, <426.187500,700.987183>,
  /*   6*/ <426.187500, 700.987183>, <426.187500, 700.987183>, <426.687500,691.487183>, <426.687500,691.487183>,
  /*   7*/ <426.687500, 691.487183>, <426.687500, 691.487173>, <445.687500,686.487183>, <447.687500,695.487183>,
  /*   8*/ <447.687500, 695.487183>, <449.687500, 700.487173>, <450.687500,708.487183>, <446.687500,712.487183>,
  /*   9*/ <446.687500, 712.487183>, <442.687500, 716.487173>, <435.687500,720.487183>, <436.687500,733.487183>,
  /*  10*/ <436.687500, 733.487183>, <437.687500, 746.487173>, <438.687500,769.487183>, <429.687500,771.487183>,
  /*  11*/ <429.687500, 771.487183>, <421.692480, 774.485303>, <327.241470,781.478393>, <325.000000,781.862183>,
  /*  12*/ <325.000000, 781.862183>, <322.750000, 781.487183>, <231.000000,774.987183>, <223.000000,771.987183>
  translate -<326.750,0,760>
  scale <0.4/449.070,1,0.5/449.070> 
  rotate <-90,180,0>
}

/*##############################################
### PRISM:  StairCase_ToeRail
##############################################*/
#declare StairCase_Stringer = prism {
    linear_sweep
    bezier_spline
    1.0, //top
    0.0, //bottom
    64, //nr points
    /*   0*/ <192.062500, 246.268433>, <192.062500, 246.268433>, <191.562500,233.705933>, <191.562500,233.705933>,
    /*   1*/ <191.562500, 233.705933>, <191.562510, 233.705933>, <178.325520,232.970813>, <179.343750,214.518433>,
    /*   2*/ <179.343750, 214.518433>, <180.361970, 196.066063>, <179.850270,195.333903>, <174.250000,191.643433>,
    /*   3*/ <174.250000, 191.643433>, <168.649720, 187.952933>, <168.656250,188.705933>, <168.656250,188.705933>,
    /*   4*/ <168.656250, 188.705933>, <168.656250, 188.705933>, <169.156250,172.455933>, <169.156250,172.455933>,
    /*   5*/ <169.156250, 172.455933>, <169.156250, 172.455933>, <206.960940,172.448123>, <206.960940,172.448123>,
    /*   6*/ <206.960940, 172.448123>, <206.960940, 172.448123>, <206.363280,34.444183>, <206.363280,34.444183>,
    /*   7*/ <206.363280, 34.444183>, <206.363280, 34.444183>, <446.167970,33.436383>, <446.167970,33.436383>,
    /*   8*/ <446.167970, 33.436383>, <446.167970, 33.436383>, <446.570310,172.432493>, <446.570310,172.432493>,
    /*   9*/ <446.570310, 172.432493>, <446.570310, 172.432493>, <484.375000,172.424683>, <484.375000,172.424683>,
    /*  10*/ <484.375000, 172.424683>, <484.375000, 172.424683>, <484.875000,188.674683>, <484.875000,188.674683>,
    /*  11*/ <484.875000, 188.674683>, <484.875000, 188.674683>, <484.881540,187.921683>, <479.281250,191.612183>,
    /*  12*/ <479.281250, 191.612183>, <473.680980, 195.302653>, <473.169280,196.034813>, <474.187500,214.487183>,
    /*  13*/ <474.187500, 214.487183>, <475.205730, 232.939563>, <461.968760,233.705933>, <461.968750,233.705933>,
    /*  14*/ <461.968750, 233.705933>, <461.968750, 233.705933>, <461.468750,246.237183>, <461.468750,246.237183>,
    /*  15*/ <461.468750, 246.237183>, <461.468750, 246.237183>, <192.062500,246.268433>, <192.062500,246.268433>
  translate -<326.750,0,120>
  scale <0.4/449.070,1,0.5/449.070> 
  rotate <-90,180,0>
}

#local StairCase_NewelSection = prism {
    linear_sweep
    bezier_spline
    1.0, //top
    0.0, //bottom
    84, //nr points
    /*   0*/ <177.000000, 793.987183>, <177.000000, 793.987183>, <174.250000,787.737183>, <171.500000,784.737183>,
    /*   1*/ <171.500000, 784.737183>, <168.000000, 780.737183>, <164.000000,778.987183>, <161.000000,778.987183>,
    /*   2*/ <161.000000, 778.987183>, <161.000000, 778.987183>, <161.000000,692.987183>, <161.000000,692.987183>,
    /*   3*/ <161.000000, 692.987183>, <161.000000, 692.987183>, <195.000000,692.987183>, <195.000000,692.987183>,
    /*   4*/ <195.000000, 692.987183>, <195.000000, 692.987183>, <195.000000,269.987183>, <195.000000,269.987183>,
    /*   5*/ <195.000000, 269.987183>, <196.500000, 269.737183>, <195.900000,267.037183>, <195.900000,263.037183>,
    /*   6*/ <195.900000, 263.037183>, <195.900000, 258.287183>, <195.250000,257.987183>, <194.250000,257.987183>,
    /*   7*/ <194.250000, 257.987183>, <194.250000, 257.987183>, <161.000000,257.987183>, <161.000000,257.987183>,
    /*   8*/ <161.000000, 257.987183>, <161.000000, 257.987183>, <162.000000,18.987183>, <162.000000,18.987183>,
    /*   9*/ <162.000000, 18.987183>, <162.000000, 18.987183>, <491.500000,19.049683>, <491.500000,19.049683>,
    /*  10*/ <491.500000, 19.049683>, <491.500000, 19.049683>, <492.500000,258.049683>, <492.500000,258.049683>,
    /*  11*/ <492.500000, 258.049683>, <492.500000, 258.049683>, <459.250000,258.049683>, <459.250000,258.049683>,
    /*  12*/ <459.250000, 258.049683>, <458.250000, 258.049683>, <457.600000,258.349683>, <457.600000,263.099683>,
    /*  13*/ <457.600000, 263.099683>, <457.600000, 267.099683>, <457.000000,269.799683>, <458.500000,270.049683>,
    /*  14*/ <458.500000, 270.049683>, <458.500000, 270.049683>, <458.500000,693.049683>, <458.500000,693.049683>,
    /*  15*/ <458.500000, 693.049683>, <458.500000, 693.049683>, <492.500000,693.049683>, <492.500000,693.049683>,
    /*  16*/ <492.500000, 693.049683>, <492.500000, 693.049683>, <492.500000,779.049683>, <492.500000,779.049683>,
    /*  17*/ <492.500000, 779.049683>, <489.500000, 779.049683>, <485.500000,780.799683>, <482.000000,784.799683>,
    /*  18*/ <482.000000, 784.799683>, <479.250000, 787.799683>, <476.500000,794.049683>, <476.500000,794.049683>,
    /*  19*/ <476.500000, 794.049683>, <476.500000, 794.049683>, <325.000000,817.987183>, <325.000000,817.987183>,
    /*  20*/ <325.000000, 817.987183>, <325.000000, 817.987183>, <177.000000,793.987183>, <177.000000,793.987183>
  translate -<326.750,0.5,80>
  scale <0.4/449.070,1,0.5/449.070> 
  rotate <-90,0,0>
}

#declare StairCase_NewelPost = intersection {
  object {StairCase_NewelSection}
  object {StairCase_NewelSection rotate y*90}
}

