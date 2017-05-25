Title: Lego Road Macro v2.5.2
Author: Michael Horvath <mikh2161@gmail.com>
Homepage: http://www.geocities.com/Area51/Quadrant/3864/index.htm
Created: 2005-02-05
Updated: 2008-12-22
This file is licensed under the terms of the CC-LGPL.


DESCRIPTION
***********

This include file contains macros that generate Lego (LDraw) style roads 
that can be formed into various shapes. There are macros for
- creating straight roads
- creating elliptical roads
- creating spiral roads
- creating spline-shaped roads
- creating straight roads that intersect at any angle

Also supported is super-elevation (banking) of the roads. This can be 
enabled and disabled when calling the macro.

There is quite a bit you can do to modify or customize the macros, so
they don't necessarily need to just be used for Lego models. See the 
"Dependencies and global variables" section, below, for a full list of 
configuration settings.


NOTES
*****

- All units (width, height, etc.) correspond to those used in LDraw.
- If super-elevation is disabled, then tilt angles are interpolated 
  linearly from beginning to end.
- If you enable superelevation, don't make the curve turn too sharply
  at the beginning, as the change in banking angle will be abrupt.
- Each step's banking angle is printed to the "Messages" window when 
  turn debugging on. You can use this information to determine whether 
  you've set the speed limit too high or too low.
- Banking angles should never be more than 7 degrees on normal roads (5 
  degrees in icy areas).
- When using the intersection macro, roads will always be flat. Tilting 
  and banking intersections is not supported.
- You can use the embankment feature to model a road's thickness. For
  instance, placing the "LRoad_FloorObject" object so that it lies 
  parallel 4 units below the road's surface, and setting the embankment 
  slope to equal 1, results in the proper thickness for Lego (LDraw) 
  roads.


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

- Store the tangent vectors at the beginning and end of curves, so that 
  roads in succession can line up smoothly.
- Make it so the center stripes are always evenly spaced.
- Tilt angles are currently only valid if a spline turns in a counter-
  clockwise direction. Otherwise, the road is banked in the wrong 
  direction (i.e. up-side-down).
- There is an odd twisting when a spline turns at an angle greater than 
  90 degrees.
- Base the curves' tension upon the speed-limit so that the they change 
  shape to accomadate an optimum the speed of travel.
- Automatic placement of signposts, structural supports, guard rails, 
  etc.
- Fill adjacent areas with studs.
- Make it so that intersections can be non-flat.
- Provide a means of animating along a given path.
- Turning lane markers at intersections. (This would make the road 
  highly "unofficial" from a purist's standpoint.)
- Do two passes through each main loop: one to pre-calculate and store 
  values in arrays; another to retrieve the stored values and put them 
  into effect. This is speedier than repeatedly calculating the same 
  values in each loop.
- There are some minor texture clipping issues in flat intersections 
  when only two roads intersect at a very tight angle.
- Fixed the bug where the small arc between intersections was not being 
  calculated properly.


CHANGE LOG
**********

Newer versions of the macros may break scenes created using previous 
versions. Please check the demo file included with the macros for 
examples of proper syntax and usage.

2.5.2
- Fixed the bug where the embankment was incorrect in intersections when 
  only two roads were used and both roads were parallel.
- Fixed the bug where lots of whitespace was being written to the 
  Messages window but the debug level was set to zero.

2.5.1
- Fixed several bugs in the demo scene file.
- Fixed the bug where the name of the height parameter in the shape 
  macro hadn't been updated.
- Fixed the bug where the stripes of road type #0 were ending 
  prematurely in intersections.

2.5.0
- All road objects are now solid and can be used within CSG operations.
- Added optional road embankments. The angle of the embankment is 
  determined by the embankment slope and sky vector.
- Fixed the bug in flat intersections where gaps would appear at corners 
  when roads intersected at angles greater than 180 degrees.
- The curve formed when roads intersect at angles greater than 180 
  degrees now is more logical. The curve is continuous and no longer 
  wastes space.
- Hermite spline roads can now accept any number of end and tangent 
  points. Previously there was a limit of two of each.
- The height of flat intersections can now be specified.
- Spiral and elliptical roads can now have a minimum and maximum height 
  instead of just a maximum.
- The entire texture for each road component (i.e. road surface, 
  road stripe, shoulder stripe, etc.) can now be specified explicitely 
  instead of only the pigment.
- Certain macro parameters have been removed and changed into globally-
  declared variables instead.
- Certain macro parameters have been changed so that indices start at 0 
  instead of 1.
- Debug marker objects have been re-enabled or added if missing, and can 
  be toggled on and off by setting the debug level to greater than 1.
- The texture macros have been modified slightly. They now all check for 
  the road type.
- Many of the local variables have been renamed to be more consistent.
- The placement of the crosswalks in intersections is now more accurate.
- The macros now quit with an error and description of the problem in 
  certain instances.
- Many other internal changes to the macros, including a heavier use of 
  arrays to store pre-calculated information.

2.1.5 and earlier
- Bugfixes.

2.0.0
- Renamed all variables to conform to the requirements of the POV-Ray 
  Object Collection.
- Added the project to the POV-Ray Object Collection.

1.0.0
- Initial version.


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
superelevation
corkscrew
