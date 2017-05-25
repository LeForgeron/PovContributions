Title: Lego Road Macro v2.0
Author: Michael Horvath
Created: 2005-02-05
Updated: 2008-06-25
Homepage: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
This file is licensed under the terms of the CC-LGPL.


DESCRIPTION
***********

This include file contains macros that generate Lego/LDraw-
style roads that can be formed into various shapes. There are 
macros for
- creating straight roads
- creating elliptical roads
- creating spiral roads
- creating spline-shaped roads
- creating straight roads that intersect at any angle

Also supported is super-elevation (banking) of the roads. This 
can be enabled/disabled when calling the macro.


NOTES
*****

- If super-elevation is disabled, then tilt angles are 
  interpolated linearly from beginning to end.
- If you enable superelevation, don't make the curve turn too 
  sharply at the beginning, as the change in banking angle will 
  be too abrupt.
- Note that the banking angle at each step is printed to the 
  "Messages" window when you select one of the higher debug 
  levels. You can use this information to determine whether 
  you've set the speed limit too high or too low.
- Banking angles should never be more than 7 degrees on normal 
  roads (5 degrees in icy areas).
- When using the intersection macro, roads will always be flat. 
  Tilting and banking intersections is not supported.


FORMULAS
********

Superelevation Formula #1:
	e + f = V^2 / 15 * r
	      = v^2 / g * r
Variables:
	e = rate of superelevation (ft/ft)
	    values range from 0.00 to 0.12 ft/ft. (0.08 in areas w/snow and ice, such as Virginia)
	f = side friction factor
	    values range from 0.17 to 0.09
	V = velocity (mph) (5280 ft/mi)
	r = radius of curve (ft)
	v = velocity (ft/sec)
	g = acceleration of gravity (32.2 ft/sec^2)

Superelevation Formula #2:
	tan(theta) = v^2 / rg
Variables:
	theta = banking angle
	v = car speed (ft/sec) (mph * 5280/3600 = ft/sec)
	r = radius of curvature (ft)
	g = acceleration due to gravity (32.2 ft/sec^2)


THINGS TO DO
************

- Store the tangent vectors at the beginning and end of each 
  curve, so that roads in succession can line up flush with one 
  another.
- The center stripes aren't evenly spaced.
- Provide a way of reversing the spiral's direction.
- The tilt angle is currently only valid if the spline turns in 
  a counter-clockwise direction. Otherwise, the road is banked 
  in the wrong direction (e.g. up-side-down).
- There is an odd twisting of the road surface when a spline 
  turns at an angle greater than 90 degrees.
- The spline should accept an initial and final tilt value, as 
  well. (Maybe.)
- Need to be able to pass information (e.g. start and ending 
  coords, tilt angles and vectors) between splines, so that 
  they can be smoothed together.
- I would like to base spline tension upon speed-limit.
- I would also like to have the macro automatically generate 
  the proper speed-limit signs at the beginning and end of each 
  curve, using the appropriate LDraw part.
- Automatic generation of structural supports, guard rails and 
  street lamps would be splendid, as well.
- Make it so that the intersection does nt have to be perfectly 
  flat.
- Auto-generate things like stoplights and signposts.


KEYWORDS
********

road
street
spline
ellipse
straight
spiral
lego
ldraw
bank
banking
auto
super-elevation
