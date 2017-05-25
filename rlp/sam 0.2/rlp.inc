/*
 
 This file is licensed under the terms of the CC-LGPL
 
 rlp.inc
 Rounded L-Prism v0.2
 2010 Samuel T. Benge
 
 see readme for details
 
 Contents:
  
  Object Macros
   rlp(pts, z1, z2, d_rad, offs)
   rlp_chamfered(pts, z1, z2, d_rad, bev)
  
  Pointset and Subset Transforms
   rlp_scale(pts, scl)
   rlp_scale_all(pts, scl)
   rlp_rotate(pts, rot)
   rlp_rotate_all(pts, rot)
   rlp_translate(pts, trans)
   rlp_translate_all(pts, trans)
   rlp_set_radii(pts, rad)
   rlp_flatten_all(pts)
   rlp_reverse(pts)
   rlp_shift(pts, offs)
   rlp_shift_all(pts, offs)
  
  Subset Shapes
   rlp_square(sz)
   rlp_rectangle(sz)
   rlp_n_gon(radius, n_pts, rounding)
   rlp_star(rad, inset, npts, r1, r2)
  
  Declarables
   rlp_bevels
   rlp_types
   rlp_enforce_roundness
*/

// hoping to speed up the parse time by not including files...
#declare rlp_sgn = function (x) {select(x,-1, 0, 1)}
#declare rlp_clamp = function (x, y, z) {mod(x - y, z - y) + select(mod(x - y, z - y), z, y)}
#macro rlp_VAngleD(V1, V2) degrees(acos(min(1,vdot(vnormalize(V1), vnormalize(V2))))) #end
#macro rlp_VPerp_Adjust(V, Axis) vnormalize(vcross(vcross(Axis, V), Axis)) #end
#macro rlp_VEq2D(v1, v2) (v1.x=v2.x & v1.y=v2.y) #end
#macro rlp_Shear_Trans(A, B, C)
 transform{matrix< A.x, A.y, A.z, B.x, B.y, B.z, C.x, C.y, C.z, 0, 0, 0>}
#end
#macro rlp_Point_At_Trans(YAxis)
 #local Y = vnormalize(YAxis);
 #local X = rlp_VPerp_To_Vector(Y);
 #local Z = vcross(X, Y);
 rlp_Shear_Trans(X, Y, Z)
#end
#macro rlp_Wedge(Angle)
 #local A = rlp_clamp(Angle, 0, 360);
  #if(A < 180)
   difference{plane{-x, 0} plane {-x, 0 rotate y*A}}
  #else
  #if(A = 180)
    plane {-x, 0}
  #else
   intersection{plane {x, 0} plane {-x, 0 rotate y*A} inverse}
  #end
 #end
#end
#macro rlp_VPerp_To_Vector(v0)
 #if (vlength(v0) = 0) #local vN = <0, 0, 0>;
 #else #local Dm = min(abs(v0.x), abs(v0.y), abs(v0.z));
  #if (abs(v0.z) = Dm)
   #local vN = vnormalize(vcross(v0, z));
  #else
   #if (abs(v0.y) = Dm)
    #local vN = vnormalize(vcross(v0, y));
   #else
    #local vN = vnormalize(vcross(v0, x));
   #end
  #end
 #end
 vN
#end

// wrap a value
#macro rlp_WrapV(V, Repeat) mod(V+Repeat, Repeat) #end

// intersect a 2D line with a plane
// lst, ldir: starting point & direction for line
// pst, pdir: starting point & direction for plane
#macro rlp_line_intersect(lst, ldir, pst, pdir)
 #local bisecting_plane = rlp_VPerp_To_Vector(pdir);
 #local obj = plane{bisecting_plane, 0 translate pst}
 trace(obj,lst,ldir)
#end

#macro rlp_cull_z(vec) <vec.x,vec.y,0> #end
#macro rlp_make2D(vec) <vec.x,vec.y> #end

#declare rlp_enforce_roundness = false;

// offset points and set preliminary radii
#macro rlp_offset_points(pts, darad, offs)
 #local offs_orig = offs;
 #local pts_temp = pts;
 #local v2=0;
 #while(v2<dimension_size(pts,1))
  
  // per-subset custom beveling
  #ifdef(rlp_bevels)#ifdef(rlp_bevels[v2]) #local offs = -abs(rlp_bevels[v2]); #else #local offs = offs_orig; #end #end
  
  #local v1=0;
  #local npts = dimension_size(pts[v2],1);
  #while(v1<npts)
   #local pp=rlp_cull_z(pts_temp[v2][rlp_WrapV(v1-1,npts)]);
   #local pc=rlp_cull_z(pts_temp[v2][v1]);
   #local pn=rlp_cull_z(pts_temp[v2][rlp_WrapV(v1+1,npts)]);
   #local cna = vnormalize( vnormalize(pn-pc) + vnormalize(pp-pc) );
   #local cn  = rlp_VPerp_To_Vector( (pc + vnormalize(pn-pc)) - (pc + vnormalize(pp-pc)) );
   #local is_outside = rlp_VEq2D(cn, cna);
   
   // find the intersection to offset the point
   #local perp1 = pn+(pn-pc)*10+rlp_VPerp_To_Vector(pc-pn)*offs;
   #local perp2 = perp1-rlp_VPerp_To_Vector(pn+(pn-pc)*10-perp1);
   #if(rlp_sgn(offs)=1) #local dir = perp1-perp2; #else #local dir = perp2-perp1; #end
   
   // prevent degenerate normal and set intersection
   #local degen_flag = 0;
   #if( !(cna.x=0 & cna.y=0 & cna.z=0) )
    // new point x/y
    #local intersect = rlp_line_intersect(perp1, dir, pc, cna);
   #else
    #local degen_flag = 1;
    #local intersect = pc+rlp_VPerp_To_Vector(pc-pn)*offs;
   #end
   
   // set default radius
   #if(pts_temp[v2][v1].z=0 )
    #local new_rada = abs(darad);
   #else
    #local new_rada = abs(pts_temp[v2][v1].z);
   #end
   #local new_rad = new_rada;
   
   // adjustment to radius proportional to offset
   #local erad  = pc+vnormalize(pn-pc)*new_rad;
   #local perp3 = erad+rlp_VPerp_To_Vector(pc-erad)*offs;
   #local perp4 = pn+(pn-pc)*1e9+rlp_VPerp_To_Vector(pc-pn)*offs;
   
   // if new radius is out of bounds, set it to 0
   #if(vlength(perp3-perp4)+.001 > vlength(intersect-perp4) | degen_flag)
    #local new_rad = 0;
    
    // test code for no sharp outside corners
    #if(rlp_enforce_roundness)// & is_outside)
     #local li2 = intersect+rlp_VPerp_To_Vector(pn-pc)*offs;
     #local new_rad = vlength(pc-li2)/100;
    #end
    
   #else
    #if(new_rad!=0)
     // change the radius to equal the distance between intersect and erad3
     #local new_rad=vlength(intersect-perp3)-.000000001;
    #else
     // if it's an inside point, give it a minimum radius
     #if(!is_outside & darad!=0)
      #local new_rad=vlength(intersect-(pc+rlp_VPerp_To_Vector(pc-pn)*offs));
     #end
    #end
   #end
   
   // if there is no beveling...
   #if(offs=0)
    #local new_rad=new_rada;
    #local intersect=pc;
   #end
   
   // set new point data
   #local pts[v2][v1] = <intersect.x,intersect.y,new_rad>;
   
   #local v1=v1+1;
  #end
  #local v2=v2+1;
 #end
 #undef pts_temp
#end

// probably a waste of space
#macro rlp_seek_pts(V2,V1)
 #local ppf = pts_temp[V2][rlp_WrapV(V1-1,npts)]; #local pp = rlp_cull_z(ppf);
 #local pcf = pts_temp[V2][rlp_WrapV(V1,npts)];   #local pc = rlp_cull_z(pcf);
 #local pnf = pts_temp[V2][rlp_WrapV(V1+1,npts)]; #local pn = rlp_cull_z(pnf);
 #local dp = vlength(pc-pp);
 #local dn = vlength(pc-pn);
 min(dp,dn)
#end

// perform autofitting
#macro rlp_fix_radii(pts, darad)
 #ifdef(rlp_arcs) #undef rlp_arcs #end
 #declare rlp_arcs=array[dimension_size(pts,1)];
 #local pts_temp = pts;
 #local v2=0;
 #while(v2<dimension_size(pts,1))
  #local v1=0;
  #local npts = dimension_size(pts[v2],1);
  #declare rlp_arcs[v2] = array[npts][4];
  #while(v1<npts)
   #local ppf = pts_temp[v2][rlp_WrapV(v1-1,npts)]; #local pp = rlp_cull_z(ppf);
   #local pcf = pts_temp[v2][v1];                   #local pc = rlp_cull_z(pcf);
   #local pnf = pts_temp[v2][rlp_WrapV(v1+1,npts)]; #local pn = rlp_cull_z(pnf);
   
   #local radc = pcf.z;
   #local radp = ppf.z;
   #local radn = pnf.z;
   
   #local dp = vlength(pc-pp);
   #local dn = vlength(pc-pn);
   
   // adjust radius to never exceed shortest neighboring segment
   #local dm = rlp_seek_pts(v2,v1);
   #if(radc>dm) #local radc = dm-.000000001; #end
   // ^ adding that small value is a poor fix
   
   // look ahead and do the same
   #local dm1 = rlp_seek_pts(v2,v1-1);
   #if(radp>dm1) #local radp = dm1; #end
   #local dm2 = rlp_seek_pts(v2,v1+1);
   #if(radn>dm2) #local radn = dm2; #end
   
   // possible overlaps
   #local ol1 = select(dp-(radc+radp),abs(dp-(radc+radp)),0);
   #local ol2 = select(dn-(radc+radn),abs(dn-(radc+radn)),0);
   
   // largest possible overlap
   #local olb = max(ol1,ol2);
   
   // if there is an overlap then fit it
   #if( olb > 0)
    // adjust radius to 1/2 of the most offensive overlap...
    // it guarantees that the overlap will be met or exceeded
    #local radc = radc - olb/2;
   #end
   
   // set new radius to point array
   #local pts[v2][v1] = <pc.x,pc.y,radc>;
   
   #local v1=v1+1;
  #end 
  #local v2=v2+1;
 #end
 #undef pts_temp
#end

#macro rlp_rounded_lprism(orig_pts, z1, z2, darad, offs, cham)
 union{
  #local offs_orig = offs;
  #local rlp_cham = cham;
  
  // so the macro doesn't inadvertently modify the original array
  #local pts = orig_pts;
  
  // switch z1 and z2 for negative case
  #if(z1>z2) #local ztemp = z2; #local z2=z1; #local z1=ztemp; #end
  
  // make beveling positive
  #local offs = abs(offs);
  
  // cap beveling to accomodate z-depth
  #if(offs>(z2-z1)/2) #local offs=(z2-z1)/2; #end
  
  // an array for holding arc data
  #local arc_array = pts;
  
  // offset the points and adjust the radii
  rlp_offset_points(pts, darad, -offs)
  rlp_fix_radii(pts, darad)
  
  // poly pts array stuff
  #local poly_pts = array[dimension_size(pts,1)];
  #local poly_V   = array[dimension_size(pts,1)];
  #local poly_pts_tot = 0;
  
  // main loop for placing objects and writing to poly_pts
  #local v2=0;
  #while(v2<dimension_size(pts,1))
   
   #local v1=0;
   #local npts = dimension_size(pts[v2],1);
   
   // give poly_pts a safe size
   #local poly_pts[v2] = array[npts*2];
   #local poly_V[v2] = 0;
   
   // per-subset custom beveling
   #ifdef(rlp_bevels)#ifdef(rlp_bevels[v2]) #local offs = abs(rlp_bevels[v2]); #else #local offs = offs_orig; #end #end
   
   // per-subset custom beveling types
   #ifdef(rlp_types)#ifdef(rlp_types[v2]) #local rlp_cham = rlp_types[v2]; #else #local rlp_cham = cham; #end #end
   
   #while(v1<npts)
    
    // points 3D, 2D, previous, current, next
    #local ppf = pts[v2][rlp_WrapV(v1-1,npts)]; #local pp = rlp_cull_z(ppf);
    #local pcf = pts[v2][v1];                   #local pc = rlp_cull_z(pcf);
    #local pnf = pts[v2][rlp_WrapV(v1+1,npts)]; #local pn = rlp_cull_z(pnf);
    
    // radius offset from current pt
    #local erad = pc+vnormalize(pn-pc)*pcf.z;
    
    // arc calcs
    
    // corner normal
    #local cna = vnormalize( vnormalize(pn-pc) + vnormalize(pp-pc) );
    
    // corner normal for outside evaluation
    #local cn  = rlp_VPerp_To_Vector( (pc + vnormalize(pn-pc)) - (pc + vnormalize(pp-pc)) );
    
    #local is_outside = rlp_VEq2D(cn, cna);
    
    #local intersect =
     rlp_line_intersect(
      erad,
      rlp_VPerp_To_Vector(pn-pc)*(-1+is_outside*2),
      pc,
      cna
     );
    
    // save arc data
    // offset x-y, radius, rlp_Wedge angle
    #declare rlp_arcs[v2][v1][0] = intersect.x;
    #declare rlp_arcs[v2][v1][1] = intersect.y;
    #declare rlp_arcs[v2][v1][2] = vlength(erad-intersect);
    #declare rlp_arcs[v2][v1][3] = rlp_VAngleD(intersect-erad, cna)*2;
    
    // future point stuff
    #local eradn = pn+vnormalize(pc-pn)*pnf.z;
    #local pnf_n=pts[v2][rlp_WrapV(v1+2,npts)]; #local pn_n = rlp_cull_z(pnf_n);
    
    #local cna_n = vnormalize( vnormalize(pn_n-pn) + vnormalize(pc-pn) );
    #local cn_n  = rlp_VPerp_To_Vector( (pn + vnormalize(pn_n-pn)) - (pn + vnormalize(pc-pn)) );
    #local is_outside_n = rlp_VEq2D(cn_n, cna_n);
    
    // offset current for sharp extending & clipping
    #local offs1 = 0;
    #if(pcf.z=0 & offs!=0 & is_outside)
     #local offs1 =
      vlength(
       pc-rlp_VPerp_To_Vector(pc-pn)*offs
       -(rlp_line_intersect(pc+rlp_VPerp_To_Vector(pc-pn)*offs*(1-is_outside*2),pn-pc,pc, cna ))
      );
    #end
    // offset next for sharp extending & clipping
    #local offs2 = 0;
    #if(pnf.z=0 & offs!=0 & is_outside_n)
     #local offs2 =
      vlength(
       pn+rlp_VPerp_To_Vector(pn-pc)*offs
       -(rlp_line_intersect(pn+rlp_VPerp_To_Vector(pn-pc)*offs*(-1+is_outside_n*2),pc-pn,pn, cna_n ))
      );
    #end
    // curved segment
    #if(pcf.z>0)
     #local clip_obj=object{rlp_Wedge(rlp_arcs[v2][v1][3]) rotate -y*rlp_arcs[v2][v1][3]/2}
     
     #if(offs!=0)
      #local arc=
       #if(rlp_cham)
      cone{0,rlp_arcs[v2][v1][2]-offs*(1-is_outside*2),y*offs,rlp_arcs[v2][v1][2] open
       #else
      torus{rlp_arcs[v2][v1][2],offs
       clipped_by{plane{-y,0}}
       clipped_by{cylinder{-y*(offs+.01),y*(offs+.01),rlp_arcs[v2][v1][2] #if(is_outside) inverse #end}}
       #end
       clipped_by{clip_obj}
       
       // inside clip for self-overlapping torus
       #local isect_obj = sphere{x*rlp_arcs[v2][v1][2],offs}
       #local norm      = <0,0,0>;
       #declare isect   = trace(isect_obj,y*offs*2,-y,norm);
       #if(!(norm.x=0 & norm.y=0 & norm.z=0) & !rlp_cham)
        clipped_by{sphere{0,isect.y inverse}}
       #end
       
       rotate -x*90
       rlp_Point_At_Trans(-cna)
       translate <rlp_arcs[v2][v1][0],rlp_arcs[v2][v1][1]>
      }
      object{arc translate z*offs}
      object{arc scale<1,1,-1> translate z*(z2-z1-offs)}
     #end
    
     // point radius curve
     cylinder{
      z*offs,z*(z2-z1-offs),rlp_arcs[v2][v1][2]+offs*(-1+is_outside*2) open
      clipped_by{clip_obj rotate x*270}
      rlp_Point_At_Trans(-cna)
      translate <rlp_arcs[v2][v1][0],rlp_arcs[v2][v1][1]>
     }
    #end
    
    // segment joins
     
    // sharp extension 1
    #if(rlp_VEq2D(erad,pn) & is_outside_n & offs2!=0) // added offs2 cond.
     #local clip_extend1=
      #if(rlp_cham)
     box{<-offs,0,-offs>,<0,offs2,-offs> matrix<1,0,-1,0,1,0,0,0,1,0,0,0>
      #else
     cylinder{0,y*offs2,offs open
      clipped_by{plane{z,0}}
      #end
      
      rlp_Point_At_Trans(pn-pc) translate pn
      clipped_by{
       plane{x*(1-is_outside_n*2),0
        rlp_Point_At_Trans(cna_n)
        translate eradn
       }
      }
     }
     object{clip_extend1 translate z*offs}
     object{clip_extend1 scale<1,1,-1> translate z*(z2-z1-offs)}
     box{<0,0,offs>,<0,offs2,z2-z1-offs>
      translate -x*offs
      rlp_Point_At_Trans(pn-pc)
      translate pn
     }
    #end
    
    // sharp extension 2 
    #local erad_p = pc+vnormalize(pp-pc)*pcf.z;
    #if(rlp_VEq2D(eradn,pc) & is_outside & (0!=offs1))
     #local clip_extend2=
      #if(rlp_cham)
     box{<-offs,0,-offs>,<0,offs1,-offs> matrix<-1,0,-1,0,1,0,0,0,1,0,0,0>
      #else
     cylinder{0,y*offs1,offs open
      clipped_by{plane{z,0}}
      #end
      rlp_Point_At_Trans(pc-pn) translate pc
      clipped_by{
       plane{-x*(1-is_outside*2),0
        rlp_Point_At_Trans(cna)
        translate erad_p
       }
      }
     }
     object{clip_extend2 translate z*offs}
     object{clip_extend2 scale<1,1,-1> translate z*(z2-z1-offs)}
     box{<0,0,offs>,<0,offs1,z2-z1-offs>
      translate x*offs
      rlp_Point_At_Trans(pc-pn)
      translate pc
     }
    #end
     
     
    // straight segment 
    #if(-offs1 != vlength(erad-eradn)+offs2 & !rlp_VEq2D(erad,eradn) )
     #local join=
      #if(rlp_cham)
     box{<-offs,-offs1,-offs>,<0,vlength(erad-eradn)+offs2,-offs> matrix<1,0,-1,0,1,0,0,0,1,0,0,0>
      #else
     cylinder{-y*offs1,y*(vlength(erad-eradn)+offs2),offs open
      clipped_by{ plane{z,0} plane{x,0} }
      #end
      rlp_Point_At_Trans(eradn-erad)
      translate erad
      #if(offs1>0 | pcf.z = 0)
       clipped_by{
        plane{x*(-1+is_outside*2),0
         rlp_Point_At_Trans(cna)
         translate erad
        }
       }
      #end
      #if(offs2>0 | pnf.z = 0)
       clipped_by{
        plane{x*(1-is_outside_n*2),0
         rlp_Point_At_Trans(cna_n)
         translate eradn
        }
       }
      #end
     }
     object{join translate z*offs}
     object{join scale<1,1,-1> translate z*(z2-z1-offs)}
     box{<0,-offs1,offs>,<0,vlength(erad-eradn)+offs2,z2-z1-offs>
      translate -x*offs
      rlp_Point_At_Trans(eradn-erad)
      translate erad
      #if(offs2>0 | pnf.z = 0)
       clipped_by{
        plane{x*(1-is_outside_n*2),0
         rlp_Point_At_Trans(cna_n)
         translate eradn
        }
       }
      #end
      #if(offs1>0 | pcf.z = 0)
       clipped_by{
        plane{x*(-1+is_outside*2),0
         rlp_Point_At_Trans(cna)
         translate erad
        }
       }
      #end
     }
    #end
    
    // add points to poly pt array and update total n pts
    #local erad2 = pc+vnormalize(pp-pc)*pcf.z;
    #if(is_outside)
     #local poly_pts[v2][poly_V[v2]]=rlp_make2D(pc);
     #local poly_V[v2]=poly_V[v2]+1;
     #local poly_pts_tot = poly_pts_tot + 1;
    #else
     #local poly_pts[v2][poly_V[v2]]=rlp_make2D(erad2);
     #local poly_V[v2]=poly_V[v2]+1;
     #local poly_pts[v2][poly_V[v2]]=rlp_make2D(erad);
     #local poly_V[v2]=poly_V[v2]+1;
     #local poly_pts_tot = poly_pts_tot + 2;
    #end
    
    #local v1=v1+1;
   #end 
   
   // add 1 for closing poly pt
   #local poly_pts_tot = poly_pts_tot + 1;
   
   #local v2=v2+1;
  #end
  
  
  // make new poly pts array
  #local poly_pts2 = array[poly_pts_tot];
  
  // fill the array
  #local ct = 0;
  #local v2 = 0;
  #while(v2<dimension_size(poly_pts,1))
   #local npts = poly_V[v2];
   #local v1 = 0;
   #while(v1<npts)
    
    #if(v1>0) // remove doubles by turning back the counter
     #if(rlp_VEq2D(poly_pts[v2][v1],poly_pts[v2][v1-1]))
      #local ct = ct - 1;
     #end
    
    #else // make 1st pt
     #local first_pt = poly_pts[v2][v1];
    #end
    
    // make pts
    #local poly_pts2[ct] = poly_pts[v2][v1];
    #local ct = ct + 1;
    #local v1 = v1 + 1;
    
   #end
    
   // make last pt if previous pt != 1st pt
   #if(!rlp_VEq2D(first_pt,poly_pts[v2][v1-1]))
    #local poly_pts2[ct] = first_pt;
    #local ct = ct + 1;
   #end
    
   #local v2=v2+1;
  #end
  
  // make polygon cap
  #local Poly=
  polygon{
   ct
   
   // set points
   #local V=0;
   #while(V<ct)
    poly_pts2[V]
    #if(V>0) #if( rlp_VEq2D(poly_pts2[V],poly_pts2[V-1]) ) #debug "contact the author, there might be a code error \n" #end #end
    #local V=V+1;
   #end
   
   // clipping
   #local v2=0;
   #while(v2<dimension_size(pts,1))
    #local v1=0;
    #local npts = dimension_size(pts[v2],1);
    #while(v1<npts)
     #local ppf=pts[v2][rlp_WrapV(v1-1,npts)]; #local pp = rlp_cull_z(ppf);
     #local pcf=pts[v2][v1];               #local pc = rlp_cull_z(pcf);
     #local pnf=pts[v2][rlp_WrapV(v1+1,npts)]; #local pn = rlp_cull_z(pnf);
     #local cna = vnormalize( vnormalize(pn-pc) + vnormalize(pp-pc) );
     #local cn  = rlp_VPerp_To_Vector( (pc + vnormalize(pn-pc)) - (pc + vnormalize(pp-pc)) );
     #local is_outside = rlp_VEq2D(cn, cna);
     #if(pcf.z>0) // if this corner's radius is >0 then do clipping
      #if(is_outside) // clipping outside corners
       clipped_by{
        intersection{
         cylinder{
          -z*.01,z*.01,rlp_arcs[v2][v1][2]
          translate <rlp_arcs[v2][v1][0],rlp_arcs[v2][v1][1],0>
          inverse
         }
         prism{-.011,.011, 4,
          rlp_make2D(pc-cn*.001),
          rlp_make2D(pc+vnormalize(pn-pc)*pcf.z),
          rlp_make2D(pc+vnormalize(pp-pc)*pcf.z),
          rlp_make2D(pc-cn*.001)
          rotate x*270
         }
         inverse
        }
       }
      #else // clipping inside corners
       clipped_by{
        intersection{
         cylinder{
          -z*.01,z*.01,rlp_arcs[v2][v1][2]
          translate <rlp_arcs[v2][v1][0],rlp_arcs[v2][v1][1],0>
         }
         prism{-.011,.011, 4,
          rlp_make2D(pc),
          rlp_make2D(pc+vnormalize(pn-pc)*pcf.z),
          rlp_make2D(pc+vnormalize(pp-pc)*pcf.z),
          rlp_make2D(pc)
          rotate x*270
         }
         inverse
        }
       }
      #end
     #end
     #local v1=v1+1;
    #end 
    #local v2=v2+1;
   #end
  }
  
  object{Poly}
  object{Poly scale<1,1,-1> translate z*(z2-z1)}
  
  translate z*z1
 }
 #undef rlp_arcs
 #undef pts
 #undef poly_pts
 #undef poly_pts2
 #ifdef(rlp_bevels) #undef rlp_bevels #end
 #ifdef(rlp_types)  #undef rlp_types  #end
#end

// Objects

#macro rlp(orig_pts, z1, z2, darad, offs)
 rlp_rounded_lprism(orig_pts, z1, z2, darad, offs, 0)
#end

#macro rlp_chamfered(orig_pts, z1, z2, darad, offs)
 rlp_rounded_lprism(orig_pts, z1, z2, darad, offs, 1)
#end

// Shapes

#macro rlp_square(sz)
 array[4]{
  <-sz,-sz, 0>,
  <-sz, sz, 0>,
  < sz, sz, 0>,
  < sz,-sz, 0>
 }
#end

#macro rlp_rectangle(sz)
 array[4]{
  <-sz.x,-sz.y, 0>,
  <-sz.x, sz.y, 0>,
  < sz.x, sz.y, 0>,
  < sz.x,-sz.y, 0>
 }
#end

#macro rlp_n_gon(rad, npts, rounding)
 #if(npts<3) #local npts = 3; #end
 #local pts = array[npts];
 #local V=0;
 #while(V<npts)
  #local pts[V]=<sin(pi*2/npts*V),cos(pi*2/npts*V),rounding>*rad;
  #local V=V+1;
 #end
 pts
#end

#macro rlp_star(rad, inset, npts, r1, r2)
 #if(npts<3) #local npts = 3; #end
 #if(inset=0) // copied from n_gon to prevent 3 points along same line error
  #local pts = array[npts];
  #local V=0;
  #while(V<npts)
   #local pts[V]=<sin(pi*2/npts*V),cos(pi*2/npts*V),max(r1,r2)>*rad;
   #local V=V+1;
  #end
 #else        // actual star
  #if(inset<=-1) // automatic star inset
   #local inset = int(inset);
   #local absin = abs(inset);
   #local eq  = pi*2/npts;
   #local p1  = <sin(eq*0),         cos(eq*0),0>*rad;
   #local n1  = <sin(eq*(1+absin)), cos(eq*(1+absin)),0>*rad-p1;
   #local p2  = <sin(eq*1),         cos(eq*1),0>*rad;
   #local n2  = <sin(eq*-(absin)),  cos(eq*-(absin)),0>*rad-p2;
   #local ins = vlength(rlp_line_intersect(p1, n1, p2, n2));
  #end
  #local inset = abs(inset);
  #local pts = array[npts*2];
  #local V=0;
  #while(V<npts*2)
   #local p1 = <sin(pi/npts*V),cos(pi/npts*V),0>*rad;
   #local p2 = <sin(pi/npts*(V+2)),cos(pi/npts*(V+2)),0>*rad;
   #local pts[V] = <p1.x,p1.y,r1>;
   #ifdef(ins)
    #local pts[V+1] = <sin(pi/npts*(V+1)),cos(pi/npts*(V+1)),0>*ins+<0,0,r2>;
   #else
    #local pts[V+1] = (p1+p2)/2*(1-inset)+<0,0,r2>;
   #end
   #local V=V+2;
  #end
 #end
 pts
#end

// Transforms

#macro rlp_shift_all(pts, offs)
 rlp_offset_points(pts, 0, offs)
#end

#macro rlp_shift(pts, offs)
 #local pts_temp = array[1]{pts}
 rlp_offset_points(pts_temp, 0, offs)
 #local pts = pts_temp[0];
#end

#macro rlp_rotate_all(pts, rot)
 #local v2=0;
  #while(v2<dimension_size(pts,1))
   #local v1=0;
   #while(v1<dimension_size(pts[v2],1))
    #local pt = pts[v2][v1];
    #local pt_rot = vrotate(<pt.x,pt.y,0>,z*rot);
    #local pts[v2][v1] = <pt_rot.x,pt_rot.y,pt.z>;
   #local v1=v1+1;
   #end
  #local v2=v2+1;
 #end
#end

#macro rlp_rotate(pts, rot)
 #local v1=0;
 #while(v1<dimension_size(pts,1))
  #local pt = pts[v1];
  #local pt_rot = vrotate(<pt.x,pt.y,0>,z*rot);
  #local pts[v1] = <pt_rot.x,pt_rot.y,pt.z>;
 #local v1=v1+1;
 #end
#end

#macro rlp_translate_all(pts, trans)
 #local v2=0;
  #while(v2<dimension_size(pts,1))
   #local v1=0;
   #while(v1<dimension_size(pts[v2],1))
    #local pt = pts[v2][v1];
    #local pts[v2][v1] = <pt.x+trans.x,pt.y+trans.y,pt.z>;
   #local v1=v1+1;
   #end
  #local v2=v2+1;
 #end
#end

#macro rlp_translate(pts, trans)
 #local v1=0;
 #while(v1<dimension_size(pts,1))
  #local pt = pts[v1];
  #local pts[v1] = <pt.x+trans.x,pt.y+trans.y,pt.z>;
 #local v1=v1+1;
 #end
#end

#macro rlp_scale_all(pts, scl)
 #local v2=0;
 #while(v2<dimension_size(pts,1))
  #local v1=0;
  #while(v1<dimension_size(pts[v2],1))
   #local pt = pts[v2][v1];
   #local pts[v2][v1] = <pt.x*scl.x,pt.y*scl.y,pt.z*(abs(scl.x)+abs(scl.y))/2>;
   #local v1=v1+1;
  #end
  #if( (rlp_sgn(scl.x)=-1 & rlp_sgn(scl.y)=1) | (rlp_sgn(scl.y)=-1 & rlp_sgn(scl.x)=1) )
   rlp_reverse(pts[v2])
  #end
  #local v2=v2+1;
 #end
#end

#macro rlp_scale(pts, scl)
 #local v1=0;
 #while(v1<dimension_size(pts,1))
  #local pt = pts[v1];
  #local pts[v1] = <pt.x*scl.x,pt.y*scl.y,pt.z*(abs(scl.x)+abs(scl.y))/2>;
 #local v1=v1+1;
 #end
 #if( (rlp_sgn(scl.x)=-1 & rlp_sgn(scl.y)=1) | (rlp_sgn(scl.y)=-1 & rlp_sgn(scl.x)=1) )
  rlp_reverse(pts)
 #end
#end

#macro rlp_set_radii(pts, rad)
 #local v1=0;
 #while(v1<dimension_size(pts,1))
  #local pt = pts[v1];
  #local pts[v1] = <pt.x,pt.y,rad>;
  #local v1=v1+1;
 #end
#end

#macro rlp_flatten_all(pts)
 #local v2=0;
 #while(v2<dimension_size(pts,1))
  #local v1=0;
  #while(v1<dimension_size(pts[v2],1))
   #local pt = pts[v2][v1];
   #local pts[v2][v1] = <pt.x,pt.y,0>;
   #local v1=v1+1;
  #end
  #local v2=v2+1;
 #end
#end

#macro rlp_reverse(pts)
 #local npts = dimension_size(pts,1);
 #local old_pts = pts;
 #local v1=0;
 #while(v1<npts)
  #local pts[v1]=old_pts[npts-1-v1];
  #local v1=v1+1;
 #end
 #undef old_pts
#end