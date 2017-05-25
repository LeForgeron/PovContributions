/*
--- MESH APPROXIMATOR AND SURFACE DISPLACEMENT MACROS ---
--- by BILL PRAGNELL, 2008 ---
--- http://www.infradead.org/~wmp/ ---
--- This file is licensed under the terms of the CC-LGPL ---


This include file contains several macros:

  Rounded_Wedge
  ballpoint(vang, ang, rad)
  MeshShape(obj, inobj, centr, res, pig, dep, smoothed, saving, name)
  Weathered_Box
  Weathered_Cylinder
  Weathered_Cone
  Weathered_Super
  Weathered_Spheroid
  Weathered_Wedge

Rounded_Wedge() is a triangular/trapezoidal prism with rounded edges - a useful
brick shape. See the macro's comments for a full description.

The ballpoint() macro is simply a polar coordinate generator (vang = angle
from y-axis, ang = ang around y-axis, rad = distance of point from origin).

MeshShape() does all the hard work of building the mesh. It takes the
following parameters:
  obj = object identifier: object to be converted
  inobj = object identifier: inner object to define vertex perturbation directions (see below)
  centr = vector: centre of object
  res = integer: resolution of mesh
  pig = pigment identifier: for weathering function
  dep = float: depth of weathering
  smoothed = yes/no
  saving = yes/no
  name = string/string identifier: name for saved include file and mesh2 within that file

Weathered_x() builds weathered objects of specific types by first declaring
suitable target objects, then passing them on to the MeshShape macro. In
each case, 'edge' defines the radius of curvature for edges, 'dep'
defines the depth of weathering (using a -ve value makes the weathering
stick up as bumps), 'smoothed' and 'saving' are yes/no values, and 'name'
is a string literal or identifier giving the saved mesh a name/filename. For
detailed descriptions of the required parameters, see the macro definitions at
the end of this file.

If you just want to use the predefined simple block shapes, just call
Weathered_x() with your options and away you go. However, if you want to
weather a different shape, or optimise the inner normal shape for the
predefined shapes, you will need to use MeshShape() directly. The macro
requires a little explanation to use properly.

The macro works by shooting rays from the centre of the target object,
recording vertices where these rays strike the surface of the target
object, then applying the weathering pigment function as a displacement to
the vertices. The resulting mesh is built from these vertices. The rays are
shot in a spherical pattern, so vertices will be closer together at the
poles of the shape and further apart at the equator. Since the rays are
shot outwards, the target shape must be a completely filled shape - use
merges, not unions, or the results can be unpredictable.

The direction for the vertex displacement is not the target shape's local
normal, because in some cases this will mangle the result - think of points
at a distance from a corner that is smaller than the specified
displacement. Nor is the displacement always towards the centre of the
object - for wide and flat or tall and thin objects this will look strange.
Instead, a smaller inner object is specified that approximately matches the
target object in shape, and two rays are fired for every vertex. The first
ray finds a point on the inner object, and the second ray is fired from
this point, along the local normal. This means that for long or flat
target objects, the direction of displacement is always roughly normal to
the surface, and only towards the centre for target objects that are
equally-sized in all directions (e.g. cubes and spheres). For the predefined
Weathered_x() macros, this object is a simple spheroid (look at the code
to see for yourself). However, for some objects a less general approach
may be required, so you can supply a more optimal object directly.

In all cases, an inside_vector is added to the mesh, so they can be used
in CSG. Additionally, they are completely closed volumes and so will also work
as media containers (you will need to add the hollow keyword).
*/

#include "shapes.inc"
#include "transforms.inc"

// Rounded wedge shape generator to supplement shapes.inc
// top face, width and height are centred on origin
//
// basew = float - base width (x)
// topw = float - top width (x) (if larger than base width, the two are swapped)
// hgt = float - height of wedge (y)
// dep = float - depth of wedge (z)
// edge = float - edge radius
#macro Round_Wedge(basew, topw, hgt, dep, edge)
  #if (topw > basew) #local temp = basew; #local basew = topw; #local topw = temp; #end
  #if (topw <= 2*edge) #warning "Wedge warning: top width <= edge radius: results may not be as expected" #end
  #if (basew <= 2*edge) #warning "Wedge warning: base width <= edge radius: results may not be as expected" #end
  merge {
  #local bdiff = basew - topw;
  #local hdiff = hgt - 2*edge;
  #local theta = degrees(atan2(bdiff, hdiff));
  #local hyp = sqrt(bdiff*bdiff + hdiff*hdiff);
  // main bulk
  difference {
    merge {
      box { <-topw/2+edge, -hgt/2+edge, -dep/2>, <topw/2+bdiff-edge, hgt/2-edge, dep/2> }
      box { <-topw/2, -hgt/2+edge, -dep/2+edge>, <topw/2+bdiff, hgt/2-edge, dep/2-edge> }
      box { <-topw/2+edge, -hgt/2, -dep/2+edge>, <topw/2+bdiff-edge, hgt/2, dep/2-edge> } }
    intersection {
      plane { -x, 0 rotate z*theta translate <topw/2-edge, hgt/2-edge, 0> }
      plane { -x, 0 translate <topw/2-edge, 0, 0> } } }
  // wedge bulk
  box { <-edge, -hyp, -dep/2+edge>, <edge, 0, dep/2-edge> rotate z*theta translate <topw/2-edge, hgt/2-edge, 0> }
  // corners
  sphere { <-topw/2+edge, -hgt/2+edge, -dep/2+edge>, edge }
  sphere { <-topw/2+edge, -hgt/2+edge, dep/2-edge>, edge }
  sphere { <-topw/2+edge, hgt/2-edge, -dep/2+edge>, edge }
  sphere { <-topw/2+edge, hgt/2-edge, dep/2-edge>, edge }
  sphere { <topw/2-edge, hgt/2-edge, -dep/2+edge>, edge }
  sphere { <topw/2-edge, hgt/2-edge, dep/2-edge>, edge }
  sphere { <topw/2+(basew-topw)-edge, -hgt/2+edge, -dep/2+edge>, edge }
  sphere { <topw/2+(basew-topw)-edge, -hgt/2+edge, dep/2-edge>, edge }
  // z edges
  cylinder { <-topw/2+edge, hgt/2-edge, -dep/2+edge>, <-topw/2+edge, hgt/2-edge, dep/2-edge>, edge }
  cylinder { <topw/2-edge, hgt/2-edge, -dep/2+edge>, <topw/2-edge, hgt/2-edge, dep/2-edge>, edge }
  cylinder { <-topw/2+edge, -hgt/2+edge, -dep/2+edge>, <-topw/2+edge, -hgt/2+edge, dep/2-edge>, edge }
  cylinder { <topw/2+bdiff-edge, -hgt/2+edge, -dep/2+edge>, <topw/2+bdiff-edge, -hgt/2+edge, dep/2-edge>, edge }
  // x edges
  #if (topw != 2*edge)
    cylinder { <-topw/2+edge, hgt/2-edge, -dep/2+edge>, <topw/2-edge, hgt/2-edge, -dep/2+edge>, edge }
    cylinder { <-topw/2+edge, hgt/2-edge, dep/2-edge>, <topw/2-edge, hgt/2-edge, dep/2-edge>, edge }
  #end
  cylinder { <-topw/2+edge, -hgt/2+edge, -dep/2+edge>, <topw/2+bdiff-edge, -hgt/2+edge, -dep/2+edge>, edge }
  cylinder { <-topw/2+edge, -hgt/2+edge, dep/2-edge>, <topw/2+bdiff-edge, -hgt/2+edge, dep/2-edge>, edge }
  // y edges
  cylinder { <-topw/2+edge, -hgt/2+edge, -dep/2+edge>, <-topw/2+edge, hgt/2-edge, -dep/2+edge>, edge }
  cylinder { <-topw/2+edge, -hgt/2+edge, dep/2-edge>, <-topw/2+edge, hgt/2-edge, dep/2-edge>, edge }
  cylinder { <topw/2+bdiff-edge, -hgt/2+edge, -dep/2+edge>, <topw/2-edge, hgt/2-edge, -dep/2+edge>, edge }
  cylinder { <topw/2+bdiff-edge, -hgt/2+edge, dep/2-edge>, <topw/2-edge, hgt/2-edge, dep/2-edge>, edge }
  bounded_by { box { <-topw/2, -hgt/2, -dep/2>, <topw/2+bdiff, hgt/2, dep/2> } } }
#end

// polar coordinate generator
//
// vangle = angle (degrees) from y-axis
// rangle = angle (degrees) around y-axis
// rad = distance from origin
//
#macro ballpoint(vangle, rangle, rad)
  #local yp = rad*cos(vangle);
  #local locrad = rad*sin(vangle);
  #local xp = locrad*sin(rangle);
  #local zp = locrad*cos(rangle);
  (<xp, yp, zp>)
#end

// surface displacement mesh macro
//
// obj = object identifier - target shape
// innerobj = object identifier - inner shape for displacement normals
// centr = vector - location of object centre
// res = integer - resolution of mesh
// pig = pigment identifier - pigment for surface displacement function
// dep = float - depth of surface displacement (-ve produces raised displacement)
// smoothed = yes/no - smoothed triangles
// sav = yes/no - saving .inc file
// name = string/string identifier - name of resulting mesh / .inc file
//
#macro MeshShape(obj, innerobj, centr, res, pig, dep, smoothed, sav, name)
  // find object extents
  #local objmin = min_extent(obj);
  #local objmax = max_extent(obj);
  #local xs = objmax.x - objmin.x;
  #local ys = objmax.y - objmin.y;
  #local zs = objmax.z - objmin.z;
  #local maxdim = max(xs, max(ys, zs));
  #local xs = xs / maxdim;  #local ys = ys / maxdim;  #local zs = zs / maxdim;
  // make surface weathering function
  #local ptb_fn = function { pigment { pig } }
  // set up
  #local numpoints = 2 + (2*res)*(res-1);
  #local mvertices = array[numpoints];
  #if (smoothed = yes)
    #local mnormals = array[numpoints];
  #end
  #local dang = pi/res;
  #local vang = dang;
  #local ang = 0;
  #local n = 1;
  // --- calculate vertex coordinates ---
  #local dirvec = <0,0,0>;
  #local dummy = trace(innerobj, centr, y, dirvec);
  #local pos = trace(obj, dummy, dirvec);
  #local mvertices[0] = pos - dirvec*dep*ptb_fn(pos.x, pos.y, pos.z).x;
  #while (vang < pi-dang/2)
    #while (ang < 2*pi-dang/2)
      #local dirvec = ballpoint(vang, ang, 1);
      #local dummy = trace(innerobj, centr, <dirvec.x*xs,dirvec.y*ys,dirvec.z*zs>, dirvec);
      #local pos = trace(obj, dummy, dirvec);
      #local mvertices[n] = pos - dirvec*dep*ptb_fn(pos.x, pos.y, pos.z).x;
      #local n = n + 1;
      #local ang = ang + dang;
    #end
    #local ang = 0;
    #local vang = vang + dang;
  #end
  #local dummy = trace(innerobj, centr, -y, dirvec);
  #local pos = trace(obj, dummy, dirvec);
  #local mvertices[n] = pos - dirvec*dep*ptb_fn(pos.x, pos.y, pos.z).x;
  // --- calculate vertex normals ---
  #if (smoothed = yes)
  // top normal
  #local xd = mvertices[1+res] - mvertices[1];
  #local yd = mvertices[1+3*res/2] - mvertices[1+res/2];
  #local mnormals[0] = vnormalize(vcross(xd,yd));
  // top row
  #local xd = mvertices[2] - mvertices[2*res];
  #local yd = mvertices[0] - mvertices[2*res+1];
  #local mnormals[1] = vnormalize(vcross(xd,yd));
  #local n = 2;
  #while (n < 2*res)
    #local xd = mvertices[n+1] - mvertices[n-1];
    #local yd = mvertices[0] - mvertices[n+2*res];
    #local mnormals[n] = vnormalize(vcross(xd,yd));
    #local n = n + 1;
  #end
  #local xd = mvertices[1] - mvertices[2*res-1];
  #local yd = mvertices[0] - mvertices[4*res];
  #local mnormals[2*res] = vnormalize(vcross(xd,yd));
  #local n = n + 1;
  // middle section
  #while (n < numpoints-2*res-2)
    #local xd = mvertices[n+1] - mvertices[n+2*res-1];
    #local yd = mvertices[n-2*res] - mvertices[n+2*res];
    #local mnormals[n] = vnormalize(vcross(xd,yd));
    #local n = n + 1;
    #local rowend = n+2*res-2;
    #while (n < rowend)
      #local xd = mvertices[n+1] - mvertices[n-1];
      #local yd = mvertices[n-2*res] - mvertices[n+2*res];
      #local mnormals[n] = vnormalize(vcross(xd, yd));
      #local n = n + 1;
    #end
    #local xd = mvertices[n-2*res+1] - mvertices[n-1];
    #local yd = mvertices[n-2*res] - mvertices[n+2*res];
    #local mnormals[n] = vnormalize(vcross(xd,yd));
    #local n = n + 1;
  #end
  // last row
  #local xd = mvertices[n+1] - mvertices[n+2*res-1];
  #local yd = mvertices[n-2*res] - mvertices[numpoints-1];
  #local mnormals[n] = vnormalize(vcross(xd,yd));
  #local n = n + 1;
  #while (n < numpoints-2)
    #local xd = mvertices[n+1] - mvertices[n-1];
    #local yd = mvertices[n-2*res] - mvertices[numpoints-1];
    #local mnormals[n] = vnormalize(vcross(xd,yd));
    #local n = n + 1;
  #end
  #local xd = mvertices[n-2*res+1] - mvertices[n-1];
  #local yd = mvertices[n-2*res] - mvertices[numpoints-1];
  #local mnormals[n] = vnormalize(vcross(xd,yd));
  #local n = n + 1;
  // bottom normal
  #local xd = mvertices[n-res] - mvertices[n-2*res];
  #local yd = mvertices[n-res/2] - mvertices[n-3*res/2];
  #local mnormals[numpoints-1] = -vnormalize(vcross(xd,yd));
  #end // (smoothed #if)
  // open output .inc file, if required
  #if (sav = yes)
    #local filename = concat(name,".inc")
    #fopen incfile filename write
    #write (incfile, "#declare ",name," = mesh2 {\n")
    #write (incfile, "vertex_vectors { ",numpoints,",\n")
  #end
  // --- build mesh2 object ---
  mesh2 {
    vertex_vectors { numpoints,
      #local n = 0;
      #while (n < numpoints)
        mvertices[n]
        #if (sav = yes)  #write (incfile, mvertices[n]," \n")  #end
        #local n = n + 1;
      #end }
    #if (smoothed = yes)
    #if (sav = yes)  #write (incfile, "}\nnormal_vectors { ",numpoints,",\n")  #end
    normal_vectors { numpoints,
      #local n = 0;
      #while (n < numpoints)
        mnormals[n]
        #if (sav = yes)  #write (incfile, mnormals[n]," \n")  #end
        #local n = n + 1;
      #end }
    #end // (smoothed #if)
    #if (sav = yes)  #write (incfile, "}\nface_indices { ",4*res*(res-1),",\n")  #end
    face_indices { 4*res*(res-1),
      // top ring of triangles
      #local n = 1;
      #while (n < 2*res)
        <0, n, n+1>,
        #if (sav = yes)  #write (incfile, "<",0,",",n,",",n+1,">,\n")  #end
        #local n = n + 1;
      #end
      <0, n, 1>,
      #if (sav = yes)  #write (incfile, "<",0,",",n,",",1,">,\n")  #end
      // middle triangle doubles
      #local n = 1;
      #local nr = 0;
      #while (nr < res-2)
        #local rowend = n + 2*res - 1;
        #while (n < rowend)
          <n, n+1, n+2*res>,
          <n+1, n+2*res+1, n+2*res>,
          #if (sav = yes)
            #write (incfile, "<",n,",",n+1,",",n+2*res,">,\n")
            #write (incfile, "<",n+1,",",n+2*res+1,",",n+2*res,">,\n")
          #end
          #local n = n + 1;
        #end
        <n, n-(2*res-1), n+2*res>,
        <n-(2*res-1), n+1, n+2*res>,
        #if (sav = yes)
          #write (incfile, "<",n,",",n-(2*res-1),",",n+2*res,">,\n")
          #write (incfile, "<",n-(2*res-1),",",n+1,",",n+2*res,">,\n")
        #end
        #local n = n + 1;
        #local nr = nr + 1;
      #end
      // bottom ring of triangles
      #local n = numpoints-2*res-1;
      #while (n < numpoints-2)
        <numpoints-1, n, n+1>,
        #if (sav = yes)  #write (incfile, "<",numpoints-1,","n,",",n+1,">,\n")  #end
        #local n = n + 1;
      #end
      <numpoints-1, n, n-(2*res-1)>
      #if (sav = yes)  #write (incfile, "<",numpoints-1,",",n,",",n-(2*res-1),"> }\n")  #end
      } inside_vector y }
  #if (sav = yes)  #write (incfile, "inside_vector y }\n")  #fclose incfile  #end
#end

// ROUNDED-EDGE BOX
// p1, p2 = vectors - diagonal corners of box
// edge = float - radius of curvature of edges
// the rest as above
#macro Weathered_Box(p1, p2, edge, res, pig, dep, smoothed, sav, nam)
  #local xs = abs(p2.x-p1.x)/2;
  #local ys = abs(p2.y-p1.y)/2;
  #local zs = abs(p2.z-p1.z)/2;
  #local cpos = p1 + (p2-p1)/2;
  #local inobj = sphere { 0, 1 scale 0.9*<xs, ys, zs> translate cpos }
  #local obj = object { Round_Box_Merge(p1, p2, edge) }
  MeshShape(obj, inobj, cpos, res, pig, dep, smoothed, sav, nam)
#end

// ROUNDED-EDGE CYLINDER
// p1, p2 = vectors - endcaps of cylinder
// rad = float - radius of y-axis cylinder
// edge = float - radius of curvature of edges
// the rest as above
#macro Weathered_Cylinder(p1, p2, rad, edge, res, pig, dep, smoothed, sav, nam)
  #local ys = vlength(p2-p1)/2;
  #local cpos = p1 + (p2-p1)/2;
  #local inobj = sphere { 0, 1 scale 0.9*<rad,ys,rad> Point_At_Trans(p2-p1) translate cpos }
  #local obj = object { Round_Cylinder_Merge(p1, p2, rad, edge) }
  MeshShape(obj, inobj, cpos, res, pig, dep, smoothed, sav, nam)
#end

// SPHEROID
// rad = vector - radius of spheroid in each direction
// the rest as above
#macro Weathered_Spheroid(rad, res, pig, dep, smoothed, sav, nam)
  #local obj = sphere { <0,0,0>, 1 scale rad }
  #local inobj = sphere { <0,0,0>, 1 scale 0.9*rad }
  MeshShape(obj, inobj, <0,0,0>, res, pig, dep, smoothed, sav, nam)
#end

// ROUNDED-EDGE CONE
// p1, p2 = vectors - locations of endcaps
// r1, r2 = floats - radiii of endcaps
// edge = float - radius of curvature of edges
// the rest as above
#macro Weathered_Cone(p1, r1, p2, r2, edge, res, pig, dep, smoothed, sav, nam)
  #local xs = min(r1,r2) + abs(r1-r2)/4;
  #local ys = vlength(p2-p1)/4;
  #local cpos = p1+(p2-p1)/2;
  #local obj = Round_Cone_Merge(p1, r1, p2, r2, edge)
  #local inobj = sphere { 0, 1 scale <xs,ys,xs> Point_At_Trans(p2-p1) translate cpos }
  MeshShape(obj, inobj, cpos, res, pig, dep, smoothed, sav, nam)
#end

// SUPERELLIPSOID
// p1, p2 = floats - superellipsoid parameters
// the rest as above
#macro Weathered_Super(p1, p2, res, pig, dep, smoothed, sav, nam)
  #local obj = superellipsoid { <p1, p2> }
  #local inobj = sphere { 0, 0.9 }
  MeshShape(obj, inobj, <0,0,0>, res, pig, dep, smoothed, sav, nam)
#end

// ROUNDED-EDGE WEDGE
// basewid, topwid = floats - base and top widths
// hgt = float - height of wedge
// thick = float - z-depth of wedge
// edge = float - radius of curvature of edges
// the rest as above
#macro Weathered_Wedge(basewid, topwid, hgt, thick, edge, res, pig, dep, smoothed, sav, nam)
  #local obj = Round_Wedge(basewid, topwid, hgt, thick, edge)
  #local bleft = <-topwid/2, -hgt/2, 0>;
  #local tright = <topwid/2+(basewid-topwid), hgt/2, 0>;
  #local diag = tright - bleft;
  #local p = trace(obj, tright, -diag);
  #local inpos = bleft + (p-bleft)/2;
  #local xysiz = inpos - bleft;
  #local inobj = sphere { 0, 1 scale 0.9*<min(xysiz.x, xysiz.y), min(xysiz.x, xysiz.y), thick/2> translate inpos }
  MeshShape(obj, inobj, inpos, res, pig, dep, smoothed, sav, nam)
#end
