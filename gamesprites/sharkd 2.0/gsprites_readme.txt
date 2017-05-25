// Video game sprites collection for POV-Ray v2.00
// ***********************************************
// Author: Michael Horvath
// Created: 2006-03-01
// Last updated: 2008-07-05
// Website: http://www.geocities.com/Area51/Quadrant/3864/povray.htm
// This file is licensed under the terms of the CC-LGPL.


DESCRIPTION

This is a collection of POV-Ray objects designed to be used as sprites in 2D video games. There are five main collections at present.

- Walls - 16-frame animations that adjust to connect with 
  adjacent tiles. A mix of "personal" and "map" scale sizes.
- Floors - single-frame "personal" scale indoor floor tiles.
- Terrain - single-frame "map" scale outdoor ground tiles.
- Hills - 16-frame animations that adjust to meet adjacent 
  tiles, just like walls.
- Scenery - various props that get layered on top of terrain 
  tiles. Mostly "map" scale sizes.

An additional, sixth collection was not included but is 
available from my website. It consists of special effects, such 
as fire, explosions and bullet tracers. I did not include it 
because I was not able to license it under the GPL, as it is 
heavily adapted from, and uses much code from, objects authored 
by different people. I have therefore made it available as a 
separate archive, though it is meant to be used in conjunction 
with this collection.


INSTRUCTIONS

In order to render any of the objects in the collection you'll first need to include the general "scene settings" include file 
containing the camera and lights. After that you'll need to include the "prototypes" file containing the definition of your object. Finally, in most cases, you'll wrap the macro for the object within an "object" tag.


ADJUSTABLE PARAMETERS

A number of parameters can be declared before the inclusion of these files in order to adjust the rendering.

// The default seed value used for random functions.
#declare GSprites_Seed = seed(8829464);		#end
// The default width of a tile in POV-Ray units.
#declare GSprites_Width = 64;			#end
// The default Height of a tile in POV-Ray units.
#declare GSprites_Height = 64;			#end
// The default size of a scene, measured in tiles. Use this to 
// zoom in/out.
#declare GSprites_Tiles = 1;			#end
// Should objects be stretched to meet the change in the number 
// of tiles?
#declare GSprites_Stretch = off;		#end
// Renders multiple copies of a projectile in a single tile.
#declare GSprites_Burst_Mode = on;		#end
// The default camera y-axis rotation angle. By default the 
// camera points in the -X and -Z directions.
#declare GSprites_Camera_Rotate = 45;		#end
// Use this to render the scene on a basic ground plane.
#declare GSprites_Show_Ground_Plane = off;	#end
// Use this to orient the sprite within a template.
#declare GSprites_Show_Grid_Marker = off;	#end
// Renders a plain, 1-tile floor beneath the scene.
#declare GSprites_Show_Basic_Floor = off;	#end
// Renders crosshairs in the center of the scene.
#declare GSprites_Show_Axis_Marker = off;	#end
// Renders part of a tile *beneath* the normal tile so that you 
// can orient the image in a paint program.
#declare GSprites_Show_Grid_Marker = off;	#end
// The height/width aspect ratio of the sprite. You can make a 
// sprite wider in the INI file, but the tile will always be 
// aligned to the bottom.
#declare GSprites_Sprite_Height = 4;		#end


OUTPUTTED IMAGES

The "demo" scenes included with this archive are meant to be 
rendered at a 2:1 width/height ratio in order to squeeze in all 
the examples. However, you can adjust this ratio, as well 
as the "GSprites_Sprite_Height" option, to meet your needs. By 
design, the bottom of a tile that is centered on the origin is 
always aligned with the bottom edge of the output image. I 
recommend using alpha transparency in the outputted images 
wherever possible. If this is not possible, a blue or black 
background is a common choice for video game sprites.


KEYWORDS
hill
terrain
wall
floor
sprite
video game
2d
