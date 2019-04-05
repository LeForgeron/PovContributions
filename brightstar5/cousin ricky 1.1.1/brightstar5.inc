/* brightstar5.inc version 1.1.1
 * Persistence of Vision Ray Tracer include file
 * POV-Ray Object Collection
 *
 * Processing of data extracted from the Yale Bright Star Catalogue, 5th ed.
 *
 * Copyright 2017 - 2019 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See https://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers.  Date         Comments
 * -----  ----         --------
 *        2015-Nov-10  Conversion is begun from an unpublished include file that
 *                     processes the BSC4.
 *        2015-Nov-18  Tools are added for processing star color and brightness.
 *        2015-Nov-19  Macros for numeric decoding and encoding of BSC string
 *                     data, left over from the BSC4 version of this file, are
 *                     deleted.
 *        2015-Nov-28  Conversion is complete, except for debugging.
 *        2015-Dec-03  Deleted records from the BSC5 are cleaned up.
 *        2016-Nov-14  The color tables are updated with colors from a new
 *                     source.
 *        2016-Nov-19  A workaround for the color spline, included due to a bug
 *                     in POV-Ray 3.7.1.alpha, is deleted, because the bug has
 *                     been fixed.
 * 1.0    2017-Feb-04  Debugged and uploaded.
 * 1.1    2017-Dec-07  The data files are indexed and binary searches are used.
 *        2018-Oct-12  The error check for the index file is corrected.
 *        2019-Mar-25  View_POV_Include_Stack is utilized.
 * 1.1.1  2019-Mar-25  A POV version check is made for the charset statement.
 */
#ifndef (BrightStar5_Inc_Temp)
#declare BrightStar5_Inc_Temp = version;
#version 3.5;
#declare BRIGHTSTAR5_VERSION = 1.11;
#ifdef (View_POV_Include_Stack)
  #debug "#include \"brightstar5.inc\" //version 1.1.1\n"
#end

#include "brightstar5_data.inc"
#if (BRIGHTSTAR5__DATA_VERSION != BRIGHTSTAR5_VERSION)
  #error "Version mismatch between brightstar5.inc and brightstar5_data.inc!"
#end
#include "brightstar5_index.inc"
#if (BRIGHTSTAR5__INDEX_VERSION != BRIGHTSTAR5_VERSION)
  #error "Version mismatch between brightstar5.inc and brightstar5_index.inc!"
#end

#include "math.inc"

#ifndef (BSC5_Gamma) #declare BSC5_Gamma = 1.0; #end

#declare BSC5_NOT_FOUND = -9998;

global_settings
{ // For POV-Ray < v3.8, charset utf8 is required for Greek letters.
  #if (BrightStar5_Inc_Temp < 3.8) charset utf8 #end
}

//============== INTERNAL (PRIVATE) DATA STRUCTURES AND MACROS =================
// These features are not intended for direct use by the end user.

//--------------- Greek letters ------------------

#declare BSC5__NGR = 24;
#declare bsc5__s_Greeks = array[BSC5__NGR]
{ "alpha", "beta", "gamma", "delta", "epsilon", "zeta", "eta", "theta",
  "iota", "kappa", "lambda", "mu", "nu", "xi", "omicron", "pi",
  "rho", "sigma", "tau", "upsilon", "phi", "chi", "psi", "omega"
}

// The Greek letters must be encoded as escaped character codes, because the
// Object Collection uploader permits only ASCII.
#declare bsc5__s_Gr_chars = "\u03B1\u03B2\u03B3\u03B4\u03B5\u03B6\u03B7\u03B8\u03B9\u03BA\u03BB\u03BC\u03BD\u03BE\u03BF\u03C0\u03C1\u03C3\u03C4\u03C5\u03C6\u03C7\u03C8\u03C9"

/*----- Match multiple star component IDs --------
 * Arguments:
 *   s_Search - the component ID(s)
 *     Note: the user manual does not address requests for multiple components;
 *     the attempt by this macro to fulfill such requests should not be
 *     considered canonical.  (Note that there are circumstances that cause
 *     a binary search on multiple components to fail.)
 *   StarIx   - the star index
 * Returns: Boolean: any character of s_Search matches any star component
 */
#macro Bsc5__Match_comp (s_Search, StarIx)
( #if (strlen (s_Search) = 0)
    true // Automatic match if no component is requested.
  #else
    #if (strlen (s_Search) > 1)
      #warning "Searches on more than one component are not guaranteed to work."
    #end
    #local bsc5_s_Test = BSC5_s_Data [StarIx][BSC5_COMP]
    #local bsc5_Found = no;
   // Loop through each character of the star being examined:
    #local bsc5_C2 = 1;
    #while (bsc5_C2 <= strlen (bsc5_s_Test))
      #local bsc5_Comp = substr (bsc5_s_Test, bsc5_C2, 1)
     // Loop through each character of the search string:
      #local bsc5_C1 = 1;
      #while (bsc5_C1 <= strlen (s_Search))
        #if (!strcmp (substr (s_Search, bsc5_C1, 1), bsc5_Comp))
          #local bsc5_Found = yes;
        #end
        #local bsc5_C1 = bsc5_C1 + 1;
      #end
      #local bsc5_C2 = bsc5_C2 + 1;
    #end
    bsc5_Found
  #end
)
#end

/*----- Converts a number to a string ------------
 * If the value is that of a flag constant, then
 * the name of the constant is returned instead.
 */
#macro Bsc5__Number_s (Number)
  #switch (Number)
    #case (BSC5_NO_DATA) "BSC5_NO_DATA" #break
    #case (BSC5_NOT_FOUND) "BSC5_NOT_FOUND" #break
    #else str (Number, 0, -1)
  #end
#end

/*----- Compares Bayer designations --------------
 * Sort order: constellation, Bayer letter, superscript, component
 * Bayer letter is assumed to be initial cap.
 */
#macro Bsc5__Compare_Bayer (s_Letter, Super, s_Const, s_Comp, Index)
  #local bsc5_Cmp = strcmp (s_Const, BSC5_s_Data [Index] [BSC5_CONST]);
  #if (!bsc5_Cmp)
    #local bsc5_Cmp = strcmp (s_Letter, BSC5_s_Data [Index] [BSC5_BAYER]);
    #if (!bsc5_Cmp)
      #local bsc5_Cmp = Super - BSC5_Data [Index] [BSC5_SUPER];
      #if (!bsc5_Cmp & !Bsc5__Match_comp (s_Comp, Index))
        #local bsc5_Cmp = strcmp (s_Comp, BSC5_s_Data [Index] [BSC5_COMP]);
      #end
    #end
  #end
  bsc5_Cmp
#end

/*----- Compares Flamsteed designations ----------
 * Sort order: constellation, Flamsteed number, component
 */
#macro Bsc5__Compare_Flamsteed (Number, s_Const, s_Comp, Index)
  #local bsc5_Cmp = strcmp (s_Const, BSC5_s_Data [Index] [BSC5_CONST]);
  #if (!bsc5_Cmp)
    #local bsc5_Cmp = Number - BSC5_Data [Index] [BSC5_FLAMSTEED];
    #if (!bsc5_Cmp & !Bsc5__Match_comp (s_Comp, Index))
      #local bsc5_Cmp = strcmp (s_Comp, BSC5_s_Data [Index] [BSC5_COMP]);
    #end
  #end
  bsc5_Cmp
#end

/*----- Compares SAO keys ------------------------
 * Sort order: SAO number, component
 */
#macro Bsc5__Compare_SAO (Number, s_Comp, Index)
  #local bsc5_Cmp = Number - BSC5_Data [Index] [BSC5_SAO];
  #if (!bsc5_Cmp & !Bsc5__Match_comp (s_Comp, Index))
    #local bsc5_Cmp = strcmp (s_Comp, BSC5_s_Data [Index] [BSC5_COMP]);
  #end
  bsc5_Cmp
#end

//------------------- Colors ---------------------

// See the acknowledgments in the user manual for the derivation of these
// colors.
#declare bsc5__spl_Colors = spline
{ natural_spline
  -0.374, <0.162364, 0.233949, 0.512479>,
  -0.37, <0.164269, 0.235373, 0.510048>,
  -0.35, <0.168614, 0.238570, 0.504553>,
  -0.30, <0.177892, 0.245149, 0.493066>,
  -0.25, <0.188409, 0.252209, 0.480437>,
  -0.20, <0.201154, 0.260227, 0.465666>,
  -0.15, <0.216844, 0.269340, 0.448234>,
  -0.1, <0.233315, 0.278087, 0.430745>,
  0.0, <0.249688, 0.286029, 0.414106>,
  0.1, <0.266849, 0.293622, 0.397391>,
  0.2, <0.284759, 0.300823, 0.380664>,
  0.3, <0.303375, 0.307593, 0.363985>,
  0.4, <0.322649, 0.313901, 0.347411>,
  0.5, <0.342528, 0.319722, 0.330996>,
  0.6, <0.362959, 0.325035, 0.314789>,
  0.7, <0.383886, 0.329825, 0.298835>,
  0.8, <0.405251, 0.334083, 0.283172>,
  0.9, <0.427000, 0.337804, 0.267837>,
  1.0, <0.449076, 0.340985, 0.252861>,
  1.1, <0.471424, 0.343629, 0.238271>,
  1.2, <0.493993, 0.345742, 0.224090>,
  1.3, <0.516730, 0.347331, 0.210337>,
  1.4, <0.539587, 0.348408, 0.197028>,
  1.5, <0.562516, 0.348985, 0.184175>,
  1.6, <0.585474, 0.349077, 0.171787>,
  1.7, <0.608418, 0.348702, 0.159870>,
  1.8, <0.631308, 0.347876, 0.148428>,
  1.9, <0.654109, 0.346619, 0.137461>,
  2.0, <0.676787, 0.344950, 0.126968>,
  2.1, <0.699310, 0.342891, 0.116945>,
  2.2, <0.721650, 0.340461, 0.107387>,
  2.3, <0.743782, 0.337683, 0.098286>,
  2.4, <0.765682, 0.334577, 0.089633>,
  2.5, <0.787330, 0.331164, 0.081420>,
  2.6, <0.808707, 0.327466, 0.073634>,
  2.7, <0.829799, 0.323504, 0.066263>,
  2.8, <0.850590, 0.319297, 0.059295>,
  2.9, <0.871071, 0.314865, 0.052717>,
  3.0, <0.891231, 0.310227, 0.046514>,
  3.2, <0.930561, 0.300408, 0.035178>,
  3.4, <0.968536, 0.289978, 0.025172>,
  3.6, <1.005138, 0.279064, 0.016382>,
  3.8, <1.040365, 0.267779, 0.008694>,
  4.0, <1.074232, 0.256226, 0.002002>,
  4.2, <1.106765, 0.244493, -0.003798>,
  4.4, <1.137997, 0.232659, -0.008800>,
  4.6, <1.167971, 0.220789, -0.013094>,
  4.8, <1.196731, 0.208941, -0.016759>,
  5.0, <1.224326, 0.197164, -0.019870>,
  5.2, <1.250805, 0.185498, -0.022494>,
  5.4, <1.276217, 0.173976, -0.024689>,
  5.6, <1.300612, 0.162627, -0.026510>,
  5.8, <1.324038, 0.151472, -0.028004>,
  6.0, <1.346540, 0.140528, -0.029214>,
}

//--------------- Debugging tool -----------------

#ifndef (bsc5__Dbg) #declare bsc5__Dbg = off; #end
#macro Bsc5__Debug (S) #if (bsc5__Dbg) #debug S #end #end

//======================== PUBLIC MACROS AND FUNCTION ==========================

//------------------------ SEEK DATA ---------------------------

#macro BSC5_Seek_Bayer (s_Letter, Super, s_Const, s_Comp)
( #if (strlen (s_Letter) < 2)
    #local bsc5_Ltr = s_Letter
  #else // convert to initial caps
    #local bsc5_Ltr = concat
    ( strupr (substr (s_Letter, 1, 1)),
      strlwr (substr (s_Letter, 2, strlen (s_Letter) - 1))
    )
  #end
  Bsc5__Debug (concat
  ( "BSC5_Seek_Bayer (\"", s_Letter, "\" --> \"", bsc5_Ltr, "\", ",
    str (Super, 0, 0), ", \"", s_Const, "\", \"", s_Comp, "\")\n"
  ))
 // binary search
  #local bsc5_Star = BSC5_NOT_FOUND;
  #local bsc5_Hi = dimension_size (BSC5__Bayer_ix, 1);
  #if
  ( Bsc5__Compare_Bayer
    ( bsc5_Ltr, Super, s_Const, s_Comp, BSC5__Bayer_ix [0]
    ) >= 0 &
    Bsc5__Compare_Bayer
    ( bsc5_Ltr, Super, s_Const, s_Comp, BSC5__Bayer_ix [bsc5_Hi - 1]
    ) <= 0
  )
    #local bsc5_Lo = 0;
    #local bsc5_Done = no;
    #local bsc5_New = -1;
    #while (!bsc5_Done & bsc5_Lo < bsc5_Hi)
      #local bsc5_Old = bsc5_New;
      #local bsc5_New = floor ((bsc5_Lo + bsc5_Hi) / 2);
      #local bsc5_Ix = BSC5__Bayer_ix [bsc5_New];
      Bsc5__Debug (concat
      ( "  Lo = ", str (bsc5_Lo, 0, 0), ", Hi = ", str (bsc5_Hi, 0, 0),
        ", New = ", str (bsc5_New, 0, 0), "\n"
      ))
      Bsc5__Debug (concat
      ( "  Comparing \"", BSC5_s_Data [bsc5_Ix] [BSC5_BAYER],
        "\" ", str (BSC5_Data [bsc5_Ix] [BSC5_SUPER], 0, 0),
        " \"", BSC5_s_Data [bsc5_Ix] [BSC5_CONST],
        "\" \"", BSC5_s_Data [bsc5_Ix] [BSC5_COMP], "\"\n"
      ))
      #local bsc5_Test =
        Bsc5__Compare_Bayer (bsc5_Ltr, Super, s_Const, s_Comp, bsc5_Ix);
      Bsc5__Debug (concat ("  Test = ", str (bsc5_Test, 0, -1), "\n"))
      #if (bsc5_Test < 0)
        #local bsc5_Hi = bsc5_New;
      #else #if (bsc5_Test > 0)
        #local bsc5_Lo = bsc5_New;
      #else
        #local bsc5_Star = BSC5__Bayer_ix [bsc5_New];
        #local bsc5_Done = yes;
      #end
      #end
      #if (bsc5_New = bsc5_Old)
        #local bsc5_Done = yes;
        Bsc5__Debug ("  ***** Bailing out *****\n")
      #end
    #end
  #end
  bsc5_Star
  Bsc5__Debug (concat ("  Final index = ", str (bsc5_Star, 0, 0), "\n"))
)
#end

//------------------

#macro BSC5_Seek_Draper (Number)
( Bsc5__Debug (concat ("BSC5_Seek_Draper (", str (Number, 0, 0), ")\n"))
 // binary search
  #local bsc5_Star = BSC5_NOT_FOUND;
  #local bsc5_Hi = dimension_size (BSC5__Draper_ix, 1);
  #if
  ( Number >= BSC5_Data [BSC5__Draper_ix[0]] [BSC5_HD] &
    Number <= BSC5_Data [BSC5__Draper_ix [bsc5_Hi - 1]] [BSC5_HD]
  )
    #local bsc5_Lo = 0;
    #local bsc5_Done = no;
    #local bsc5_New = -1;
    #while (!bsc5_Done & bsc5_Lo < bsc5_Hi)
      #local bsc5_Old = bsc5_New;
      #local bsc5_New = floor ((bsc5_Lo + bsc5_Hi) / 2);
      #local bsc5_Ix = BSC5__Draper_ix [bsc5_New];
      Bsc5__Debug (concat
      ( "  Lo = ", str (bsc5_Lo, 0, 0), ", Hi = ", str (bsc5_Hi, 0, 0),
        ", New = ", str (bsc5_New, 0, 0), "\n"
      ))
      Bsc5__Debug (concat
      ( "  Comparing ", str (BSC5_Data [bsc5_Ix] [BSC5_HD], 0, 0), "\n"
      ))
      #if (Number < BSC5_Data [bsc5_Ix] [BSC5_HD])
        #local bsc5_Hi = bsc5_New;
      #else #if (Number > BSC5_Data [bsc5_Ix] [BSC5_HD])
        #local bsc5_Lo = bsc5_New;
      #else
        #local bsc5_Star = BSC5__Draper_ix [bsc5_New];
        #local bsc5_Done = yes;
      #end
      #end
      #if (bsc5_New = bsc5_Old)
        #local bsc5_Done = yes;
        Bsc5__Debug ("  ***** Bailing out *****\n")
      #end
    #end
  #end
  bsc5_Star
  Bsc5__Debug (concat ("  Final index = ", str (bsc5_Star, 0, 0), "\n"))
)
#end

//------------------

#macro BSC5_Seek_Flamsteed (Number, s_Const, s_Comp)
( Bsc5__Debug (concat
  ( "BSC5_Seek_Flamsteed (", str (Number, 0, 0), ", \"", s_Const, "\", \"",
    s_Comp, "\")\n"
  ))
 // binary search
  #local bsc5_Star = BSC5_NOT_FOUND;
  #local bsc5_Hi = dimension_size (BSC5__Flamsteed_ix, 1);
  #if
  ( Bsc5__Compare_Flamsteed
    ( Number, s_Const, s_Comp, BSC5__Flamsteed_ix [0]
    ) >= 0 &
    Bsc5__Compare_Flamsteed
    ( Number, s_Const, s_Comp, BSC5__Flamsteed_ix [bsc5_Hi - 1]
    ) <= 0 &
    Number != BSC5_NO_DATA
  )
    #local bsc5_Lo = 0;
    #local bsc5_Done = no;
    #local bsc5_New = -1;
    #while (!bsc5_Done & bsc5_Lo < bsc5_Hi)
      #local bsc5_Old = bsc5_New;
      #local bsc5_New = floor ((bsc5_Lo + bsc5_Hi) / 2);
      #local bsc5_Ix = BSC5__Flamsteed_ix [bsc5_New];
      Bsc5__Debug (concat
      ( "  Lo = ", str (bsc5_Lo, 0, 0), ", Hi = ", str (bsc5_Hi, 0, 0),
        ", New = ", str (bsc5_New, 0, 0), "\n"
      ))
      Bsc5__Debug (concat
      ( "  Comparing ", str (BSC5_Data [bsc5_Ix] [BSC5_FLAMSTEED], 0, 0),
        " \"", BSC5_s_Data [bsc5_Ix] [BSC5_CONST],
        "\" \"", BSC5_s_Data [bsc5_Ix] [BSC5_COMP], "\"\n"
      ))
      #local bsc5_Test =
        Bsc5__Compare_Flamsteed (Number, s_Const, s_Comp, bsc5_Ix);
      Bsc5__Debug (concat ("  Test = ", str (bsc5_Test, 0, -1), "\n"))
      #if (bsc5_Test < 0)
        #local bsc5_Hi = bsc5_New;
      #else #if (bsc5_Test > 0)
        #local bsc5_Lo = bsc5_New;
      #else
        #local bsc5_Star = BSC5__Flamsteed_ix [bsc5_New];
        #local bsc5_Done = yes;
      #end
      #end
      #if (bsc5_New = bsc5_Old)
        #local bsc5_Done = yes;
        Bsc5__Debug ("  ***** Bailing out *****\n")
      #end
    #end
  #end
  bsc5_Star
  Bsc5__Debug (concat ("  Final index = ", str (bsc5_Star, 0, 0), "\n"))
)
#end

//------------------

#macro BSC5_Seek_HR (Number)
( #if (Number >= 1 & Number <= BSC5_N)
    floor (Number - 1)
  #else
    BSC5_NOT_FOUND
  #end
)
#end

//------------------

#macro BSC5_Seek_SAO (Number, s_Comp)
( Bsc5__Debug (concat
  ( "BSC5_Seek_SAO (", str (Number, 0, 0), ", \"", s_Comp, "\")\n"
  ))
 // binary search
  #local bsc5_Star = BSC5_NOT_FOUND;
  #local bsc5_Hi = dimension_size (BSC5__SAO_ix, 1);
  #if
  ( Bsc5__Compare_SAO
    ( Number, s_Comp, BSC5__SAO_ix [0]
    ) >= 0 &
    Bsc5__Compare_SAO
    ( Number, s_Comp, BSC5__SAO_ix [bsc5_Hi - 1]
    ) <= 0 &
    Number != BSC5_NO_DATA
  )
    #local bsc5_Lo = 0;
    #local bsc5_Done = no;
    #local bsc5_New = -1;
    #while (!bsc5_Done & bsc5_Lo < bsc5_Hi)
      #local bsc5_Old = bsc5_New;
      #local bsc5_New = floor ((bsc5_Lo + bsc5_Hi) / 2);
      #local bsc5_Ix = BSC5__SAO_ix [bsc5_New];
      Bsc5__Debug (concat
      ( "  Lo = ", str (bsc5_Lo, 0, 0), ", Hi = ", str (bsc5_Hi, 0, 0),
        ", New = ", str (bsc5_New, 0, 0), "\n"
      ))
      Bsc5__Debug (concat
      ( "  Comparing ", str (BSC5_Data [bsc5_Ix] [BSC5_SAO], 0, 0),
        " \"", BSC5_s_Data [bsc5_Ix] [BSC5_COMP], "\"\n"
      ))
      #local bsc5_Test =
        Bsc5__Compare_SAO (Number, s_Comp, bsc5_Ix);
      Bsc5__Debug (concat ("  Test = ", str (bsc5_Test, 0, -1), "\n"))
      #if (bsc5_Test < 0)
        #local bsc5_Hi = bsc5_New;
      #else #if (bsc5_Test > 0)
        #local bsc5_Lo = bsc5_New;
      #else
        #local bsc5_Star = BSC5__SAO_ix [bsc5_New];
        #local bsc5_Done = yes;
      #end
      #end
      #if (bsc5_New = bsc5_Old)
        #local bsc5_Done = yes;
        Bsc5__Debug ("  ***** Bailing out *****\n")
      #end
    #end
  #end
  bsc5_Star
  Bsc5__Debug (concat ("  Final index = ", str (bsc5_Star, 0, 0), "\n"))
)
#end

//-------------------------- GREEK -----------------------------

#macro BSC5_Bayer_label (s_Letter, Super, s_Const, s_Comp, s_Font)
  #if (strlen (s_Letter) = 0)
    #error "BSC5_Bayer_label(): A null string was given as s_Letter.")
  #end
  #local bsc5_s_Greek = BSC5_Greek_char (s_Letter)
  #if (strlen (bsc5_s_Greek) = 0)
    #local bsc5_s_Greek = s_Letter
  #end
  #local bsc5_o_Greek = text { ttf s_Font bsc5_s_Greek 1, 0 }
  #if (Super != BSC5_NO_DATA)
    #local bsc5_s_Sup = str (Super, 0, 0)
    #local bsc5_o_Sup = text { ttf s_Font bsc5_s_Sup 1, 0 }
    #local bsc5_o_Greek_plus = text
    { ttf s_Font concat (bsc5_s_Greek, bsc5_s_Sup) 1, 0
    }
    #local bsc5_o_Greek = union
    { object { bsc5_o_Greek } // Greek glyph
      object // superscript
      { bsc5_o_Sup
        scale <0.75, 0.75, 1>
       // The x component calculation in this translation creates a narrow
       // space between the Greek glyph and the superscript:
        translate
        < max_extent (bsc5_o_Greek_plus).x - max_extent (bsc5_o_Sup).x,
          0.35,
          0
        >
      }
    }
  #end
  #local bsc5_s_Post = concat
  ( #if (strlen (s_Const) > 0) " ", s_Const, #end // constellation
    #if (strlen (s_Comp) > 0) " ", s_Comp, #end // multiple star component
    ""
  )
  #if (strlen (bsc5_s_Post) > 0)
    union
    { object { bsc5_o_Greek }
      text
      { ttf s_Font bsc5_s_Post 1, 0
        translate max_extent (bsc5_o_Greek) * x
      }
    }
  #else // Do not union with a null string; it messes up the bounding box.
    object { bsc5_o_Greek }
  #end
#end

//------------------

#macro BSC5_Bayer_label_by_index (Index, Const, Comp, s_Font)
  #local bsc5_This = concat
  ( "BSC5_Bayer_label_by_index(): Star index ", Bsc5__Number_s (Index)
  )
  #if (Index < 0 | Index >= BSC5_N)
    #error concat (bsc5_This, " is not in the catalog.")
  #end
  #if (strlen (BSC5_s_Data [Index][BSC5_BAYER]) = 0)
    #error concat
    ( bsc5_This, " (HR ", str (BSC5_Data [Index][BSC5_HR], 0, 0),
      ") has no Bayer designation."
    )
  #end
  BSC5_Bayer_label
  ( BSC5_s_Data [Index][BSC5_BAYER],
    BSC5_Data [Index][BSC5_SUPER],
    #if (Const) BSC5_s_Data [Index][BSC5_CONST] #else "" #end,
    #if (Comp) BSC5_s_Data [Index][BSC5_COMP] #else "" #end,
    s_Font
  )
#end

//------------------

#macro BSC5_Greek_char (s_Name)
  #local bsc5_Ltr = strlwr (s_Name)
 // Linear search on the Greek alphabet:
  #local bsc5_Done = no;
  #local bsc5_I = 0;
  #while (bsc5_I < BSC5__NGR & !bsc5_Done)
    #if (!strcmp (bsc5_Ltr, bsc5__s_Greeks [bsc5_I]))
      #local bsc5_Done = yes;
    #else
      #local bsc5_I = bsc5_I + 1;
    #end
  #end
 // Index into string of Greek characters:
  #if (bsc5_I < BSC5__NGR)
    substr (bsc5__s_Gr_chars, bsc5_I + 1, 1)
  #else
    ""
  #end
#end

//------------------------ APPEARANCE --------------------------

#macro BSC5_Color (BminusV)
  #if (BminusV = BSC5_NO_DATA)
    #local bsc5_C = rgb 1;
  #else
    #local bsc5_C = bsc5__spl_Colors (BminusV);
   // Bring into gamut:
    #if (bsc5_C.blue < 0) #local bsc5_C = bsc5_C - bsc5_C.blue; #end
   // Normalize:
    #local bsc5_C = rgb bsc5_C / max (bsc5_C.red, bsc5_C.green, bsc5_C.blue);
   // Adjust gamma:
    #if (BSC5_Gamma != 1)
      #local bsc5_C = rgb VPow (bsc5_C, 1 / BSC5_Gamma);
    #end
  #end
  bsc5_C
#end

//------------------

#macro BSC5_Colour (BminusV)
  BSC5_Color (BminusV)
#end

//------------------

#declare BSC5_fn_Brightness = function (x, y)
{ pow (100, (y - x) * 0.2)
}

//----------------------- DATA CLEANUP -------------------------

#macro BSC5_Update()
 // Gamma Cas variable Delta Sco:
  #declare BSC5_Data [BSC5_Seek_HR (5953)] [BSC5_MAG] = 1.65;
  #declare BSC5_Data [BSC5_Seek_HR (5953)] [BSC5_COLORBV] = -0.124;
 // recurrent nova T CrB, data from BSC5 notes:
  #declare BSC5_Data [BSC5_Seek_HR (5958)] [BSC5_MAG] = 9.88;
  #declare BSC5_Data [BSC5_Seek_HR (5958)] [BSC5_COLORBV] = +1.40;
#end

//----- Clean up deleted records -------

/* The BSC contains 14 novae and non-stellar objects for which most data have
 * not been retained in the 5th edition.  For these objects, the "Name" field
 * in the BSC5 data file does not represent a Bayer or Flamsteed ID, so the
 * data read into the corresponding SDL array fields are essentially garbage.
 * These array fields are erased here.  With most of the other fields having
 * been deleted from the catalog, the object IDs are not of much use for ray
 * tracing anyway.
 *
 * Most of these records retain variable star IDs, which are not extracted in
 * version 1.1 of BrightStar5; and two of them retain radial velocity data,
 * which I have not bothered to erase.
 */
#local bsc5_Deleted = array[14]
{ 92, 95, 182, 1057, 1841, 2472, 2496, 3515, 3671, 6309, 6515, 7189, 7539, 8296,
}
#local bsc5_I = 0;
#while (bsc5_I < 14)
  #local bsc5_Ix = BSC5_Seek_HR (bsc5_Deleted [bsc5_I]);
  #declare BSC5_Data [bsc5_Ix][BSC5_FLAMSTEED] = BSC5_NO_DATA;
  #declare BSC5_Data [bsc5_Ix][BSC5_SUPER] = BSC5_NO_DATA;
  #declare BSC5_s_Data [bsc5_Ix][BSC5_BAYER] = "";
  #declare BSC5_s_Data [bsc5_Ix][BSC5_CONST] = "";
  #local bsc5_I = bsc5_I + 1;
#end

//----------------------------

#version BrightStar5_Inc_Temp;
#end
// end of brightstar5.inc
