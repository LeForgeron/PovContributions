// Title: Cube Fonts macro v1.0
// Author: Michael Horvath
// Homepage: http://isometricland.com
// Created: 2009-10-29
// Last Updated: 2009-10-29
// This file is licensed under the terms of the CC-LGPL.

DESCRIPTION

This include file contains a macro to create text characters 
that intersect and form 3D blocks that show different letters 
depending on the face of the cube you're looking at.


USAGE

The syntax is:

  CBF_String_Macro(Strings,Font,Direction,Distance,Scale)

You must nest the macro within an object wrapper. For example:

  object
  {
      CBF_String_Macro(...)
  }

The parameters are:

  Strings: An array containing the three text strings to render 
  (one for each axis). All strings must be of equal length. If 
  you don't want any characters to appear on an axis, pad the 
  string with spaces instead.

  Font: The file name of the installed font. A font I recommend 
  to use is the "visitor1.ttf" font.

  Direction: The direction in which the text should extend to. 
  This is an integer value ranging from 0 to 7 for the cardinal 
  directions, and from 8 to 9 for the up and down directions.

  Distance: The amount of spacing between each character along 
  the given direction. A distance of zero means the characters 
  all occupy the same space. A distance of one means the 
  characters will be placed so that they are touching each other
  (or nearly so) along their sides.

  Scale: The amount to scale each character by. Each character 
  is normalized so that it fits *exactly* within a 1x1x1 cube. 
  The scaling amount is then applied afterward. This parameter 
  is in the form of a vector consisting of three float values, 
  and allows each axis to be scaled independently.


GENERAL TIPS

You must use a monospace and/or bitmap font with flat sides. 
Otherwise, you can't count on the output being correct. Also, 
specifying three strings in the Strings array is not guaranteed 
to produce working results, as some combinations of characters 
(such as "I", "S" and "O") can't be used together. The exact 
combination of characters that do or do not work together varies
with each font.

I recommend looking up the "Eat my dust Godel, Escher, Bach" 
thread (12 Nov 2008) in povray.binaries.images for some neat 
tricks you can perform with these characters. It's where I 
originally got the idea for this collection. There's also a nice
example of a curved font being used in one of the replies to the
thread -- though I was never able to locate the font itself in 
order to install or test it.

KEYWORDS

character
font
letter
block
monospace
3D
three
dimensional
intersection
cube
