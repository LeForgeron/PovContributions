
POVStairsHome = "http://lib.povray.org/collection/staircase/chrisb 2.0/staircase.html";


function toggleDisplay (objectid,imageref) {
  
  if (objectid.style.display == "block") {
    objectid.style.display = "none";
    imageref.src = "staircase_expandicon.png";
  } 	
  else {
    objectid.style.display = "block";
    imageref.src = "staircase_collapseicon.png";
  }
}

function setSectionNumbers() {
  for (M=0;M<subSectionCount[thisSection];M++) {
    ss = M+1;
    eval(subSectionName[thisSection][M]+'.innerHTML=thisSection+"."+ss+"&nbsp;&nbsp;"');
  }
}

function headerSection() {
  document.write ("<html>");
  document.write ("<head><title>Section "+thisSection+" - "+sectionHeading[thisSection]+"</title></head>");
  document.write ('<body onload="setSectionNumbers()">');
  document.write ("<div class=titlepage>");
  document.write ("<div class=printspace></div>");
  document.write ("<hr>");
  document.write ("<h1 style='color:#0C2C52'>Users Guide for the StairCase Macro V2.0</h1>");
  document.write ("<h5>Document Version 2.0 - Published 12th March 2008</h5>");
  if (thisSection == 0) document.write ('<h1 style="color:#0C2C52">'+sectionHeading[thisSection]+'</h1>');
  else document.write ('<h1 style="color:#0C2C52">Section '+thisSection+'  - '+sectionHeading[thisSection]+'</h1>');
  document.write ("<hr>");
  document.write ("</div>");
}

function endSection() {
  document.write ("<p>");
  document.write ("<div class=displayonly align=center>");
  document.write ("<a href='staircase.html'>Main Table of Contents</a> &nbsp; ");
  document.write ("<a href=#Top>Section Contents</a>");
  document.write ("</div>");
  document.write ("<p>");
  document.write ("<hr>");
  document.write ("<p>");
}

function footer() {
  document.write ("<hr style='width:100%'>");    
  document.write ("<center>&copy;Copyright Chris Bartlett 2006-2008. Licensed under the CC-LGPL</center>");
  document.write ("Furthermore; You are authorised to re-use the StairCase macro and definitions and any parts ");  
  document.write ("of this document in original or modified form for ");  
  document.write ("commercial and non-commercial purposes, with or without credit being ");  
  document.write ("given to the author, provided that such re-use does not in any way prevent "); 
  document.write ("anybody else from doing the same.");    
  document.write ("<hr style='width:100%'>");    
  document.write ("<p>");
  document.write ("</body>");
  document.write ("</html>");
}

function toc() {
  for (i=1;i<sectionCount;i++){
    document.write ('<h4>');
    document.write ('<img src="staircase_expandicon.png" width=16 onclick="toggleDisplay(classid'+i+',this)"> ');
    document.write ('<a href="'+sectionFile[i]+'"> '+i+' &nbsp; '+sectionHeading[i]+'</a><br>');
    document.write ('</h4>')
    document.write ('<div id="classid'+i+'" style="display:none">');
    for (j=0;j<subSectionCount[i];j++){
      document.write ('&nbsp; &nbsp; <a href="'+sectionFile[i]+'#'+subSectionName[i][j]+'"  >'+i+'.'+(j+1)+' &nbsp; '+subSectionHeading[i][j]+'</a> <br>');
    }
    document.write ('</div>');
  }
//  alert(classid1.outerHTML);
}

function sectionToc() {
  i=thisSection;
  for (j=0;j<subSectionCount[i];j++){
    document.write ('<a href="#'+subSectionName[i][j]+'"  >'+i+'.'+(j+1)+' &nbsp; '+subSectionHeading[i][j]+'</a> <br>');
  }
}

function tocFooter() {
  document.write ("<hr class=displayonly>");
  document.write ("<div class=displayonly align=center>");
  document.write ('  <a href="'+sectionFile[0]+'">Users Guide '+sectionHeading[0]+'</a> &nbsp; &nbsp;');
  if (thisSection >= 2) document.write ('  <a href="'+sectionFile[thisSection-1]+'"   >Previous Section - '+sectionHeading[thisSection-1]+'</a>');
  if (thisSection <= sectionCount-2)document.write ('  &nbsp; &nbsp; <a href="'+sectionFile[thisSection+1]+'"   >Next Section - '+sectionHeading[thisSection+1]+'</a><br>');
  document.write (' &nbsp; &nbsp;<a href="'+sectionFile[0]+'#printing">Saving and Printing this documentation</a>');
  document.write ("</div>");
  document.write ("<hr class=displayonly>");
}

function PSHomeLink() {
  document.write ('<a href="'+POVStairsHome+'">StairCase Macros</a>');
}

function contentTOCFooter() {
  document.write ("<hr class=displayonly>");
  document.write ("<div class=displayonly align=center>");
  document.write ('  <a href="'+POVStairsHome+'">StairCase Macro Page - POV-Ray Object Collection</a> &nbsp; &nbsp;');
  if (thisSection <= sectionCount-2)document.write ('  &nbsp; &nbsp; <a href="'+sectionFile[thisSection+1]+'"   >Next Section - '+sectionHeading[thisSection+1]+'</a><br>');
  document.write (' &nbsp; &nbsp;<a href="'+sectionFile[0]+'#printing">Saving and Printing this documentation</a>');
  document.write ("</div>");
  document.write ("<hr class=displayonly>");
}


sectionHeading   = new Array();
sectionFile      = new Array();
subSectionHeading = new Array();
subSectionCount   = new Array();
subSectionName    = new Array();

N = 0;
sectionHeading[N] = "Table of Contents"          ; sectionFile[N] = "staircase.html"  ;

N = N + 1;
sectionHeading[N] = "Quick Start"                ; sectionFile[N] = "staircase_quickstart.html";
subSectionHeading[N] = new Array();
subSectionName[N]    = new Array();
subSectionHeading[N][0] = "Downloading the StairCase Macro"           ; subSectionName[N][0] = "downloading"  ;
subSectionHeading[N][1] = "Adding a staircase to your scene" ; subSectionName[N][1] = "adding"   ;
subSectionHeading[N][2] = "Adding separate flights of stairs"; subSectionName[N][2] = "more"     ;
subSectionHeading[N][3] = ""; subSectionName[N][3] = ""    ;
subSectionHeading[N][4] = ""; subSectionName[N][4] = "";
subSectionHeading[N][5] = ""; subSectionName[N][5] = "";
subSectionHeading[N][6] = ""; subSectionName[N][6] = "";
subSectionHeading[N][7] = ""; subSectionName[N][7] = "";
subSectionCount[N] = 3;

N = N + 1;
sectionHeading[N] = "Control Variable Reference" ; sectionFile[N] = "staircase_variables.html" ;
subSectionHeading[N] = new Array();
subSectionName[N]    = new Array();
subSectionHeading[N][0] = "Main Control Variables"; subSectionName[N][0] = "Main";
subSectionHeading[N][1] = "Control Switches";       subSectionName[N][1] = "Switches";
subSectionHeading[N][2] = "Object Definitions";     subSectionName[N][2] = "Objects";
subSectionHeading[N][3] = "Textures";               subSectionName[N][3] = "Textures";
subSectionCount[N] = 4;

N = N + 1;
sectionHeading[N] = "Macro Reference"             ; sectionFile[N] = "staircase_macros.html"    ;
subSectionHeading[N] = new Array();
subSectionName[N]    = new Array();
subSectionHeading[N][0] = "StairCase Macro"                   ; subSectionName[N][0] = "StairCase";
subSectionHeading[N][1] = "StairCase_Spiral Macro"            ; subSectionName[N][1] = "StairCase_Spiral";
subSectionHeading[N][2] = "StairCase_Undef Macro"             ; subSectionName[N][2] = "StairCase_Undef";
subSectionHeading[N][3] = "StairCase_BanisterGen Macro"       ; subSectionName[N][3] = "StairCase_BannisterGen";
subSectionHeading[N][4] = "StairCase_SpiralBannisterGen Macro"; subSectionName[N][4] = "StairCase_SpiralBannisterGen";
subSectionHeading[N][5] = "StairCase_Compatibility Macro"     ; subSectionName[N][5] = "StairCase_Compatibility";
subSectionHeading[N][6] = "StairCase_NewelShape Macro"        ; subSectionName[N][6] = "StairCase_NewelShape";
subSectionHeading[N][7] = "StairCase_BalusterShape Macro"     ; subSectionName[N][7] = "StairCase_BalusterShape";
subSectionCount[N] = 8;

N = N + 1;
sectionHeading[N] = "Appendices"                 ; sectionFile[N] = "staircase_appendices.html"  ;
subSectionHeading[N] = new Array();
subSectionName[N]    = new Array();
subSectionHeading[N][0] = "StairCase Macro license"        ; subSectionName[N][0] = "license"   ;
subSectionHeading[N][1] = "Contributing files"             ; subSectionName[N][1] = "contribute";
subSectionHeading[N][2] = "How the StairCase Macro works"  ; subSectionName[N][2] = "internals";
subSectionHeading[N][3] = "Documentation Utilities"        ; subSectionName[N][3] = "docutils";
subSectionHeading[N][4] = ""; subSectionName[N][4] = "";
subSectionHeading[N][5] = ""; subSectionName[N][5] = "";
subSectionHeading[N][6] = ""; subSectionName[N][6] = "";
subSectionHeading[N][7] = ""; subSectionName[N][7] = "";
subSectionCount[N] = 4;

N = N + 1;
sectionCount = N;






