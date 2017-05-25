/* rc3metal_demo.pov version 1.2
 * Persistence of Vision Ray Tracer scene description file
 * POV-Ray Object Collection demo
 *
 * Demonstrations of RC3Metal features.
 *
 * Copyright 2013 Richard Callwood III.  Some rights reserved.
 * This file is licensed under the terms of the CC-LGPL.
 * See http://creativecommons.org/licenses/LGPL/2.1/ for more information.
 *
 * Vers  Date         Comments
 * ----  ----         --------
 *       05-mar-2013  Assembled from various demo scenes dating back to
 *                    14-sep-2011.
 * 1.0   09-mar-2013  Uploaded.
 * 1.1   23-apr-2013  Version references are updated.
 *       06-may-2013  Gold HTML file shows pigment name at top.
 * 1.2   06-sep-2013  Version references are updated.
 */
//#version, no less than 3.5, to be specified in .ini file or on command line.

#ifndef (Feature) #declare Feature = 0; #end

//Feature values:
#declare BLURRED_REFLECTION = 1;
#declare COLOR_SAMPLES = 2;
#declare COMPARE_GOLDS = 3;
#declare COMPARE_METALS = 4;
#declare COMPARE_TEXTURES = 5;
#declare GALVANIZED = 6;

//================================= SETTINGS ===================================

#macro Set_radiosity (Examples)
  #switch (floor ((frame_number - 1) / Examples))
    #case (2)
      #declare Use_radiosity = yes;
      #version 3.5;
      #break
    #case (3)
      #declare Use_radiosity = yes;
      global_settings { ambient_light 0 }
      #break
    #case (4)
      #declare Use_radiosity = yes;
      #break
    #else
      #declare Use_radiosity = no;
  #end
#end

#switch (Feature)
  #case (COMPARE_GOLDS)
    #declare NFINISHES = 5;
    Set_radiosity (NFINISHES)
    #break
  #case (COMPARE_METALS)
    #declare NFINISHES = 5;
    Set_radiosity (NFINISHES)
    #break
  #case (COMPARE_TEXTURES)
    #declare NEXAMPLES = 9;
    Set_radiosity (NEXAMPLES)
    #break
  #case (COLOR_SAMPLES)
  #case (GALVANIZED)
    #declare Use_radiosity = yes;
    #break
  #case (BLURRED_REFLECTION)
  #else
    #declare Use_radiosity = no;
#end

#if (Use_radiosity)
  #default { finish { ambient 0 } }
  #declare RC3M_Ambient = 0;
#end

#include "rc3metal.inc"

global_settings
{ assumed_gamma 1
  max_trace_level 5
  #if (Use_radiosity)
    radiosity
    { count 200
      error_bound 0.5
      normal on //for spun brass
      pretrace_end 0.01
      recursion_limit 2
    }
  #end
}

#declare RROOM = 6;
#declare HROOM = 8;
#declare VIEW = 2.5;
#declare V_LIGHT = <1 - RROOM, HROOM - 1, 1 - RROOM>;
#declare V_CAM = <RROOM - 1, 5, 1 - RROOM>;
#declare V_OBJ = <0, 1, RROOM - 2>;
#declare Field = VIEW / vlength (V_OBJ - V_CAM);
camera
{ location V_CAM
  look_at V_OBJ
  right Field * x
  up Field * y
}

light_source
{ V_LIGHT, rgb 2.5
  fade_power 2 fade_distance vlength (V_LIGHT - V_OBJ) / 2
  looks_like
  { sphere
    { 0, 1/3
      pigment { rgb 1 }
      finish { #if (version < 3.7) ambient #else emission #end 5 }
    }
  }
}

box
{ -1, 1 scale <RROOM, HROOM, RROOM>
  hollow
  pigment { rgb 1 }
}

plane
{ y, 0
  pigment { checker rgb 1 rgb 0.05 }
}

//========================== HTML GENERATION TOOLS =============================

#macro Html_open (s_Title)
  concat
  ( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">\n<html>\n<head>\n",
    "<meta http-equiv=\"Content-Type\" content=\"text/html;charset=utf-8\">\n",
    "<link rel=\"stylesheet\" type=\"text/css\" href=\"rc3metal_demo.css\">\n",
    "<title>RC3Metal 1.2 ", s_Title, " | POV-Ray Object Collection</title>\n",
    "</head>\n<body>\n<h1>RC3Metal 1.2 ", s_Title, "</h1>\n"
  )
#end

#macro Html_close()
  concat
  ( "<address>Copyright &copy; 2013 Richard Callwood III.",
    " Some rights reserved.\n Licensed under the terms of the"
    " <a href=\"http://creativecommons.org/licenses/LGPL/2.1/\">",
    "CC-LGPL</a>.\n</address>\n</body>\n</html>\n"
  )
#end

#macro Html_link()
  "<p>[ <a href=\"rc3metal_demo_index.html\">Index of RC3Metal demos</a> ]\n"
#end

#macro Table_open()
  "<table>\n<tr>\n"
#end

#macro Table_close()
  "</tr>\n</table>\n"
#end

#macro Table_row()
  "</tr><tr>\n"
#end

#macro Table_datum (s_Image, s_Alt, s_Caption)
  concat
  ( " <td><img src=\"rc3metal_demo_", s_Image, ".png\" alt=\"", s_Alt,
    "\"><br>", s_Caption, "</td>\n"
  )
#end

#macro Table_headings (s_File)
  concat
  ( " <th>", s_File, ".inc without Radiosity</th>\n",
    " <th>rc3metal.inc without Radiosity</th>\n <th>", s_File,
    ".inc with POV-Ray 3.5/3.6 Radiosity</th>\n <th>", s_File, ".inc with ",
    #if (version < 3.7)
      "POV-Ray 3.5/3.6 Radiosity and global_settings { ambient_light 0 }",
    #else
      "POV-Ray 3.7 Radiosity",
    #end
    "</th>\n",
    " <th>rc3metal.inc with Radiosity and #declare RC3M_Ambient = 0;</th>\n"
  )
#end

//============================== FEATURE DEMOS =================================

//Returns:
//  True if Column uses textures from standard include file;
//  False if Column uses rc3metal.inc.
//Column is zero-based.
#macro Is_standard (Column)
  (Column = 0 | Column = 2 | Column = 3)
#end

#switch (Feature)

  #case (BLURRED_REFLECTION)//--------------------------------------------------

    #declare N = 12;
    #declare Blurs = array[N]
    { 0.25, 0.25, 0.25, 0.25,
      0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5
    }
    #declare Scales = array[N]
    { 0.001, 0.001, 0.001, 0.001,
      0.001, 0.001, 0.001, 0.001,
      1000, 1000, 1000, 1000
    }
    #declare Samples = array[N]
    { 1, 10, 20, 40,
      1, 10, 20, 40,
      10, 20, 40, 100
    }

   //Render:
    sphere
    { 0, 1
      RC3Metal_Blur_t
      ( RC3Metal_Texture (RC3M_C_BRONZE_NEW, 0.5, 0.7),
        Blurs [frame_number - 1],
        Scales [frame_number - 1],
        Samples [frame_number - 1]
      )
      translate V_OBJ
    }

   //Create HTML file:
    #if (frame_number = 1)
      #fopen Fout "rc3metal_demo_blur.html" write
      #write
      ( Fout, Html_open ("Blurred Reflection Demo"), Html_link(),
        Table_open()
      )
      #declare I = 0;
      #while (I < N)
        #if (mod(I,4) = 0 & I != 0) #write (Fout, Table_row()) #end
        #write
        ( Fout,
          Table_datum
          ( concat ("blur", str (I+1, -2, 0)),
            concat
            ( "Blurriness = ", str (Blurs[I], 0, 2),
              ", Scale = ", str (Scales[I], 0, 3),
              ", Samples = ", str (Samples[I], 0, 0)
            ),
            concat
            ( "<code>Blurriness = ", str (Blurs[I], 0, 2),
              "<br>Scale = ", str (Scales[I], 0, 3),
              "<br>Samples = ", str (Samples[I], 0, 0), "</code>"
            )
          )
        )
        #declare I = I + 1;
      #end
      #write (Fout, Table_close(), Html_link(), Html_close())
      #fclose Fout
    #end
    #break

  #case (COLOR_SAMPLES)//-------------------------------------------------------

    #declare N = 23;
    #declare s_Colors = array[N]
    { RC3M_C_ALUMINUM, RC3M_C_BRASS_COOL, RC3M_C_BRASS_LIGHT,
      RC3M_C_BRASS, RC3M_C_BRASS_WARM, RC3M_C_BRONZE_NEW,
      RC3M_C_BRONZE_COOL, RC3M_C_BRONZE, RC3M_C_BRONZE_WARM,
      RC3M_C_CHROME, RC3M_C_COPPER, RC3M_C_COPPER_LIGHT,
      RC3M_C_GOLD, RC3M_C_GOLD_LIGHT, RC3M_C_NICKEL,
      RC3M_C_PENNY, RC3M_C_SILVER, RC3M_C_SILVER_COIN,
      RC3M_C_STAINLESS, RC3M_C_STAINLESS_WARM, RC3M_C_STEEL,
      RC3M_C_ZINC, RC3M_C_ZINC_COOL,
    }
    #declare s_Names = array[N]
    { "RC3M_C_ALUMINUM", "RC3M_C_BRASS_COOL", "RC3M_C_BRASS_LIGHT",
      "RC3M_C_BRASS", "RC3M_C_BRASS_WARM", "RC3M_C_BRONZE_NEW",
      "RC3M_C_BRONZE_COOL", "RC3M_C_BRONZE", "RC3M_C_BRONZE_WARM",
      "RC3M_C_CHROME", "RC3M_C_COPPER", "RC3M_C_COPPER_LIGHT",
      "RC3M_C_GOLD", "RC3M_C_GOLD_LIGHT", "RC3M_C_NICKEL",
      "RC3M_C_PENNY", "RC3M_C_SILVER", "RC3M_C_SILVER_COIN",
      "RC3M_C_STAINLESS", "RC3M_C_STAINLESS_WARM", "RC3M_C_STEEL",
      "RC3M_C_ZINC", "RC3M_C_ZINC_COOL",
    }

   //Render:
    sphere
    { V_OBJ, 1
      #if (frame_number >= 1 & frame_number <= N)
        RC3Metal (s_Colors [frame_number - 1], 0.5, 0.7)
      #end
    }

   //Create HTML file:
    #if (frame_number = 1)
      #fopen Fout "rc3metal_demo_colors.html" write
      #write (Fout, Html_open ("Sample Colors"), Html_link(), Table_open())
      #declare I = 0;
      #while (I < N)
        #if (mod (I, 5) = 0 & I != 0) #write (Fout, Table_row()) #end
        #write
        ( Fout, Table_datum (concat ("colors", str (I+1, -2, 0)),
          s_Names[I], concat ("<code>", s_Names[I], "</code>"))
        )
        #declare I = I + 1;
      #end
      #write (Fout, Table_close(), Html_link(), Html_close())
      #fclose Fout
    #end
    #break

  #case (COMPARE_GOLDS)//-------------------------------------------------------

    #ifndef (Demo) #declare Demo = 0; #end

    #include "golds.inc"

    #declare NTESTS = 5;
    #declare NCOLORS = 5;
    #declare t_Textures = array [NFINISHES*NCOLORS]
    { T_Gold_1A, T_Gold_1B, T_Gold_1C, T_Gold_1D, T_Gold_1E,
      T_Gold_2A, T_Gold_2B, T_Gold_2C, T_Gold_2D, T_Gold_2E,
      T_Gold_3A, T_Gold_3B, T_Gold_3C, T_Gold_3D, T_Gold_3E,
      T_Gold_4A, T_Gold_4B, T_Gold_4C, T_Gold_4D, T_Gold_4E,
      T_Gold_5A, T_Gold_5B, T_Gold_5C, T_Gold_5D, T_Gold_5E,
    }
    #declare s_Textures = array [NFINISHES*NCOLORS]
    { "T_Gold_1A", "T_Gold_1B", "T_Gold_1C", "T_Gold_1D", "T_Gold_1E",
      "T_Gold_2A", "T_Gold_2B", "T_Gold_2C", "T_Gold_2D", "T_Gold_2E",
      "T_Gold_3A", "T_Gold_3B", "T_Gold_3C", "T_Gold_3D", "T_Gold_3E",
      "T_Gold_4A", "T_Gold_4B", "T_Gold_4C", "T_Gold_4D", "T_Gold_4E",
      "T_Gold_5A", "T_Gold_5B", "T_Gold_5C", "T_Gold_5D", "T_Gold_5E",
    }
    #declare c_Colors = array[NCOLORS]
    { P_Gold1, P_Gold2, P_Gold3, P_Gold4, P_Gold5,
    }
    #declare s_Colors = array[NCOLORS]
    { "P_Gold1", "P_Gold2", "P_Gold3", "P_Gold4", "P_Gold5",
    }
    #declare Specularities = array[NFINISHES]
    { R_GoldA.red, R_GoldB.red, R_GoldC.red, R_GoldD.red, R_GoldE.red
    }
    #declare DIFFUSE = 1;

   //Render:
    #declare Row = mod (frame_number - 1, NFINISHES);
    #declare Column = floor ((frame_number - 1) / NFINISHES);
    sphere
    { V_OBJ, 1
      #if (Is_standard (Column))
        texture { t_Textures [NFINISHES*Demo + Row] }
      #else
        RC3Metal (c_Colors[Demo], Specularities[Row], DIFFUSE)
      #end
    }

   //Create HTML file:
    #if (frame_number = 1)
      #fopen Fout "rc3metal_demo_compg.html" write
      #write
      ( Fout, Html_open ("Comparison with golds.inc"), Html_link(),
        "<p>Using ", s_Colors[Demo], " as an example.\n"
        Table_open(), Table_headings ("golds")
      )
      #declare Row = 0;
      #while (Row < NFINISHES)
        #write (Fout, Table_row())
        #declare s_Texture = s_Textures [NFINISHES*Demo + Row]
        #declare Column = 0;
        #while (Column < NTESTS)
          #declare Frame =
            concat ("compg", str (NFINISHES*Column + Row + 1, -2, 0))
          #write
          ( Fout,
            Table_datum
            ( Frame,
              #if (Is_standard (Column))
                s_Texture, concat ("<code>", s_Texture, "</code>")
              #else
                concat ("RC3Metal alternative to ", s_Texture),
                concat
                ( "<code>RC3Metal (", s_Colors [Demo], ", ",
                  str (Specularities[Row], 0, 2), ", ",
                  str (DIFFUSE, 0, 2), ")</code>"
                )
              #end
            )
          )
          #declare Column = Column + 1;
        #end
        #declare Row = Row + 1;
      #end
      #write (Fout, Table_close(), Html_link(), Html_close())
      #fclose Fout
    #end
    #break

  #case (COMPARE_METALS)//------------------------------------------------------

    #ifndef (Demo) #declare Demo = 8; #end

    #include "metals.inc"

    #declare NTESTS = 5;
    #declare NCOLORS = 20;
    #declare t_Textures = array [NFINISHES*NCOLORS]
    { T_Brass_1A, T_Brass_1B, T_Brass_1C, T_Brass_1D, T_Brass_1E,
      T_Brass_2A, T_Brass_2B, T_Brass_2C, T_Brass_2D, T_Brass_2E,
      T_Brass_3A, T_Brass_3B, T_Brass_3C, T_Brass_3D, T_Brass_3E,
      T_Brass_4A, T_Brass_4B, T_Brass_4C, T_Brass_4D, T_Brass_4E,
      T_Brass_5A, T_Brass_5B, T_Brass_5C, T_Brass_5D, T_Brass_5E,
      T_Copper_1A, T_Copper_1B, T_Copper_1C, T_Copper_1D, T_Copper_1E,
      T_Copper_2A, T_Copper_2B, T_Copper_2C, T_Copper_2D, T_Copper_2E,
      T_Copper_3A, T_Copper_3B, T_Copper_3C, T_Copper_3D, T_Copper_3E,
      T_Copper_4A, T_Copper_4B, T_Copper_4C, T_Copper_4D, T_Copper_4E,
      T_Copper_5A, T_Copper_5B, T_Copper_5C, T_Copper_5D, T_Copper_5E,
      T_Chrome_1A, T_Chrome_1B, T_Chrome_1C, T_Chrome_1D, T_Chrome_1E,
      T_Chrome_2A, T_Chrome_2B, T_Chrome_2C, T_Chrome_2D, T_Chrome_2E,
      T_Chrome_3A, T_Chrome_3B, T_Chrome_3C, T_Chrome_3D, T_Chrome_3E,
      T_Chrome_4A, T_Chrome_4B, T_Chrome_4C, T_Chrome_4D, T_Chrome_4E,
      T_Chrome_5A, T_Chrome_5B, T_Chrome_5C, T_Chrome_5D, T_Chrome_5E,
      T_Silver_1A, T_Silver_1B, T_Silver_1C, T_Silver_1D, T_Silver_1E,
      T_Silver_2A, T_Silver_2B, T_Silver_2C, T_Silver_2D, T_Silver_2E,
      T_Silver_3A, T_Silver_3B, T_Silver_3C, T_Silver_3D, T_Silver_3E,
      T_Silver_4A, T_Silver_4B, T_Silver_4C, T_Silver_4D, T_Silver_4E,
      T_Silver_5A, T_Silver_5B, T_Silver_5C, T_Silver_5D, T_Silver_5E,
    }
    #declare s_Textures = array [NFINISHES*NCOLORS]
    { "T_Brass_1A", "T_Brass_1B", "T_Brass_1C", "T_Brass_1D", "T_Brass_1E",
      "T_Brass_2A", "T_Brass_2B", "T_Brass_2C", "T_Brass_2D", "T_Brass_2E",
      "T_Brass_3A", "T_Brass_3B", "T_Brass_3C", "T_Brass_3D", "T_Brass_3E",
      "T_Brass_4A", "T_Brass_4B", "T_Brass_4C", "T_Brass_4D", "T_Brass_4E",
      "T_Brass_5A", "T_Brass_5B", "T_Brass_5C", "T_Brass_5D", "T_Brass_5E",
      "T_Copper_1A", "T_Copper_1B", "T_Copper_1C", "T_Copper_1D", "T_Copper_1E",
      "T_Copper_2A", "T_Copper_2B", "T_Copper_2C", "T_Copper_2D", "T_Copper_2E",
      "T_Copper_3A", "T_Copper_3B", "T_Copper_3C", "T_Copper_3D", "T_Copper_3E",
      "T_Copper_4A", "T_Copper_4B", "T_Copper_4C", "T_Copper_4D", "T_Copper_4E",
      "T_Copper_5A", "T_Copper_5B", "T_Copper_5C", "T_Copper_5D", "T_Copper_5E",
      "T_Chrome_1A", "T_Chrome_1B", "T_Chrome_1C", "T_Chrome_1D", "T_Chrome_1E",
      "T_Chrome_2A", "T_Chrome_2B", "T_Chrome_2C", "T_Chrome_2D", "T_Chrome_2E",
      "T_Chrome_3A", "T_Chrome_3B", "T_Chrome_3C", "T_Chrome_3D", "T_Chrome_3E",
      "T_Chrome_4A", "T_Chrome_4B", "T_Chrome_4C", "T_Chrome_4D", "T_Chrome_4E",
      "T_Chrome_5A", "T_Chrome_5B", "T_Chrome_5C", "T_Chrome_5D", "T_Chrome_5E",
      "T_Silver_1A", "T_Silver_1B", "T_Silver_1C", "T_Silver_1D", "T_Silver_1E",
      "T_Silver_2A", "T_Silver_2B", "T_Silver_2C", "T_Silver_2D", "T_Silver_2E",
      "T_Silver_3A", "T_Silver_3B", "T_Silver_3C", "T_Silver_3D", "T_Silver_3E",
      "T_Silver_4A", "T_Silver_4B", "T_Silver_4C", "T_Silver_4D", "T_Silver_4E",
      "T_Silver_5A", "T_Silver_5B", "T_Silver_5C", "T_Silver_5D", "T_Silver_5E",
    }
    #declare c_Colors = array[NCOLORS]
    { P_Brass1, P_Brass2, P_Brass3, P_Brass4, P_Brass5,
      P_Copper1, P_Copper2, P_Copper3, P_Copper4, P_Copper5,
      P_Chrome1, P_Chrome2, P_Chrome3, P_Chrome4, P_Chrome5,
      P_Silver1, P_Silver2, P_Silver3, P_Silver4, P_Silver5,
    }
    #declare s_Colors = array[NCOLORS]
    { "P_Brass1", "P_Brass2", "P_Brass3", "P_Brass4", "P_Brass5",
      "P_Copper1", "P_Copper2", "P_Copper3", "P_Copper4", "P_Copper5",
      "P_Chrome1", "P_Chrome2", "P_Chrome3", "P_Chrome4", "P_Chrome5",
      "P_Silver1", "P_Silver2", "P_Silver3", "P_Silver4", "P_Silver5",
    }
    #declare Specularities = array[NFINISHES] { 0.1, 0.25, 0.5, 0.65, 0.8 }
    #declare Diffuses = array[NFINISHES] { 0.80, 0.85, 0.90, 0.95, 1 };

   //Render:
    #declare Row = mod (frame_number - 1, NFINISHES);
    #declare Column = floor ((frame_number - 1) / NFINISHES);
    sphere
    { V_OBJ, 1
      #if (Is_standard (Column))
        texture { t_Textures [NFINISHES*Demo + Row] }
      #else
        RC3Metal (c_Colors[Demo], Specularities[Row], Diffuses[Row])
      #end
    }

   //Create HTML file:
    #if (frame_number = 1)
      #fopen Fout "rc3metal_demo_compm.html" write
      #write
      ( Fout, Html_open ("Comparison with metals.inc"), Html_link(),
        "<p>Using ", s_Colors[Demo], " as an example.\n"
        Table_open(), Table_headings ("metals")
      )
      #declare Row = 0;
      #while (Row < NFINISHES)
        #write (Fout, Table_row())
        #declare s_Texture = s_Textures [NFINISHES*Demo + Row]
        #declare Column = 0;
        #while (Column < NTESTS)
          #declare Frame =
            concat ("compm", str (NFINISHES*Column + Row + 1, -2, 0))
          #write
          ( Fout,
            Table_datum
            ( Frame,
              #if (Is_standard (Column))
                s_Texture, concat ("<code>", s_Texture, "</code>")
              #else
                concat ("RC3Metal alternative to ", s_Texture),
                concat
                ( "<code>RC3Metal (", s_Colors[Demo], ", ",
                  str(Specularities[Row],0,2), ", ",
                  str(Diffuses[Row],0,2), ")</code>"
                )
              #end
            )
          )
          #declare Column = Column + 1;
        #end
        #declare Row = Row + 1;
      #end
      #write (Fout, Table_close(), Html_link(), Html_close())
      #fclose Fout
    #end
    #break

  #case (COMPARE_TEXTURES)//----------------------------------------------------

    #include "textures.inc"

    #declare NTESTS = 5;
    #declare t_Textures = array[NEXAMPLES]
    { Chrome_Metal, Copper_Metal, Polished_Chrome, Polished_Brass,
      New_Brass, Spun_Brass, Silver1, Soft_Silver, Bright_Bronze,
    }
    #declare s_Textures = array[NEXAMPLES]
    { "Chrome_Metal", "Copper_Metal", "Polished_Chrome", "Polished_Brass",
      "New_Brass", "Spun_Brass", "Silver1", "Soft_Silver", "Bright_Bronze",
    }
    #declare Specularities = array[NEXAMPLES]
    { 0.15, 0.25, 0.6, 0.4, 0, 0, 0.45, 0.45, 0.45
    }
    #declare DIFFUSE = 1;

   //Render:
    #declare Row = mod (frame_number - 1, NEXAMPLES);
    #declare Column = floor ((frame_number - 1) / NEXAMPLES);
    sphere
    { V_OBJ, 1
      #if (Is_standard (Column))
        texture { t_Textures[Row] }
      #else
        texture
        { t_Textures[Row]
          RC3Metal_Finish (Specularities[Row], DIFFUSE)
        }
      #end
    }

   //Create HTML file:
    #if (frame_number = 1)
      #fopen Fout "rc3metal_demo_compt.html" write
      #write
      ( Fout, Html_open ("Comparison with textures.inc"), Html_link(),
        Table_open(), Table_headings ("textures")
      )
      #declare Row = 0;
      #while (Row < NEXAMPLES)
        #write (Fout, Table_row())
        #declare Column = 0;
        #while (Column < NTESTS)
          #declare Frame =
            concat ("compt", str (NEXAMPLES*Column + Row + 1, -2, 0))
          #write
          ( Fout,
            Table_datum
            ( Frame,
              #if (Is_standard (Column))
                s_Textures[Row],
                concat ("<code>texture { ", s_Textures[Row], " }</code>")
              #else
                concat ("RC3Metal alternative to ", s_Textures[Row]),
                concat
                ( "<code>texture { ", s_Textures[Row], " RC3Metal_Finish (",
                  str (Specularities[Row], 0, 2), ", ",
                  str (DIFFUSE, 0, 2), ") }</code>"
                )
              #end
            )
          )
          #declare Column = Column + 1;
        #end
        #declare Row = Row + 1;
      #end
      #write (Fout, Table_close(), Html_link(), Html_close())
      #fclose Fout
    #end
    #break

  #case (GALVANIZED)//----------------------------------------------------------

    #include "shapes.inc"

   //Render:
    #declare t_Demo = RC3Metal_Galvanized_t
    ( RC3M_C_ZINC, RC3M_C_STEEL, 0, 0.5, 0.35, 0.7,
      (frame_number - 1) / 5
    )
    object
    { Round_Box (-<1, 1, 0.05>, <1, 1, 0.05>, 0.015, no)
      texture { t_Demo scale 0.15 }
      translate V_OBJ
    }

   //Create HTML file:
    #if (frame_number = 1)
      #fopen Fout "rc3metal_demo_galv.html" write
      #write
      ( Fout, Html_open ("Galvanized Demo"), Html_link(),
        "<p>Demonstration of the <code>Shine</code> argument.\n", Table_open()
      )
      #declare I = 0;
      #while (I < 6)
        #if (I = 3) #write (Fout, Table_row()) #end
        #write
        ( Fout,
          Table_datum
          ( concat ("galv", str (I+1, -1, 0)),
            concat ("Shine = ", str(I/5,0,1)),
            concat ("<code>Shine = ", str(I/5,0,1), "</code>")
          )
        )
        #declare I = I + 1;
      #end
      #write (Fout, Table_close(), Html_link(), Html_close())
      #fclose Fout
    #end
    #break

#end //#switch (Feature)
