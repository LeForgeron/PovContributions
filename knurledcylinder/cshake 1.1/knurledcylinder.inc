// Object Name:	KnurledCylinder
// Version:	1.1 for POV > 3.1 (revised 4/26/2009)
// Description:	Cylinder with knurled exterior.
// Scale:	User specified
// Positioning:	Cylinder starting at origin, extending in +y
// Keywords:	Knurl
// Author:	Christopher Shake
// Thanks to: Tim Attwood and Stephen S for bugfixes
// This file is licensed under the terms of the CC-LGPL
/*
	Call:
		KnurledCylinder(Radius,CylinderHeight,KnurlDepth,HorizontalSpacing,VerticalSpacing,FlattenPercent,RaisePercent)
	
	Parameters:
		Radius - Mean radius of cylinder, measured to the middle of the knurling.
		CylinderHeight - Height of generated cylinder
		KnurlDepth - Depth of knurl, measured peak to valley.
		HorizontalSpacing - Distance between peaks around circumference.
		VerticalSpacing - Distance between peaks in the axial direction.
		FlattenPercent - Amount to flatten peaks. 0 is no flattening, 1 shaves all the way down to the mean radius.
		RaisePercent - Amount to raise valleys, 0 is no raising, 1 raises up to the mean radius.
	
	Generates:
		A knurled cylinder with no texture extending from the origin in the +y direction.
		Equivalent shape to 'cylinder{<0,0,0>,<0,CylinderHeight,0>,Radius}'
	
	Note: Generates a parse warning that patch objects are not allowed in intersection,
		but works as expected even with the warning.

	Changelog:
	v1.1:
		(1) Implemented CSG fix from Tim
		(2) Fixed peak mismatch at start/end of mesh (the '#local divs=' line)
		(3) Added some comments
  v1.0.1 (Tim Attwood):   Intersection didn't quite work perfect, the cylinder doesn't
		remove the ends properly because of the intersection.
		(1) Replaced CSG with difference version.
*/

#ifndef(KNURLED_CYLINDER_INC_TEMP)
#declare KNURLED_CYLINDER_INC_TEMP = version;
#version 3.1;

#macro KnurledCylinder(Radius,CylinderHeight,KnurlDepth,HorizontalSpacing,VerticalSpacing,FlattenPercent,RaisePercent)
	#local horiz_spacing=HorizontalSpacing;
	#local vert_spacing=VerticalSpacing;
	#local mean_radius=Radius;
	#local knurl_depth=KnurlDepth;
	#local cylinder_length=CylinderHeight;
	#local flatten_percent=FlattenPercent;
	#local raise_percent=RaisePercent;

	#local divs=floor((pi*mean_radius*2/horiz_spacing)/2)*2; // Force an even number of divisions so peaks line up and the start/end
//	#debug concat("\nHorizontal divisions: ",str(divs,0,1),"\n")
	#local vert=int(cylinder_length/vert_spacing)+2; // Add 2 to have half-peaks on top and bottom edges
//	#debug concat("Vertical divisions: ",str(vert,0,1),"\n")
	
	// Make mesh
	#local knurlmesh=
	mesh2{
		vertex_vectors{
			divs*vert+2,
			#local horiziter=0;
			#while (horiziter<divs)
				#local vertiter=0;
				#while (vertiter<vert)
					#if(mod(horiziter+vertiter,2)=0) // positive and negative peak positions
						<(mean_radius-knurl_depth/2)*cos(2*pi*horiziter/divs),vert_spacing*vertiter,(mean_radius-knurl_depth/2)*sin(2*pi*horiziter/divs)>,
					#else
						<(mean_radius+knurl_depth/2)*cos(2*pi*horiziter/divs),vert_spacing*vertiter,(mean_radius+knurl_depth/2)*sin(2*pi*horiziter/divs)>,
					#end
					#local vertiter=vertiter+1;
				#end
				#local horiziter=horiziter+1;
			#end
			<0,0,0>,<0,vert_spacing*(vert-1),0>
		}
		face_indices{
			divs*(vert-1)*2+divs*2,
			#local iter=0;
			#local diag=1;
			#while(iter<(divs*vert))
				// The 4 points are the corners of each 'folded rectangle' segment
				#local pt1=iter;
				#local pt2=iter+1;
				#local pt3=iter+vert;
				#local pt4=iter+vert+1;
				#if(pt3>=divs*vert)
					#local pt3=mod(iter,vert);
					#local pt4=mod(iter,vert)+1;
				#end
				#if(diag=1)
					<pt1,pt3,pt4>,<pt1,pt4,pt2>,
				#else
					<pt1,pt3,pt2>,<pt3,pt4,pt2>,
				#end
				#local diag = -diag; // Flip the direction of the 'fold' each time
				#if(mod(iter,vert)=vert-2) // Reset start point for each new column
					#if(mod(vert,2)=1)
						#local diag=-diag;
					#end
					#local iter=iter+1;
				#end
				#local iter=iter+1;
			#end
			#local iter=0;
			#local bot3=divs*vert;
			#local top3=divs*vert+1;
			#while (iter<divs) // Close the top and bottom surfaces
				#local bot1=iter*vert;
				#local bot2=(iter+1)*vert;
				#local top1=iter*vert+(vert-1);
				#local top2=(iter+1)*vert+(vert-1);
				#if(bot2>=divs*vert)
					#local bot2=0;
					#local top2=vert-1;
				#end
					<bot2,bot1,bot3>,<top1,top2,top3>,
				#local iter=iter+1;
			#end
			
		}
		inside_vector <0,0,1>	
	}

	// Create object with CSG for flattening and raising
	difference{
		union{
			object{knurlmesh}
			cylinder{<0,-1,0>,<0,cylinder_length+1,0>,mean_radius-(1-raise_percent)*knurl_depth/2}
		}
		cylinder{<0,0,0>,<0,cylinder_length,0>,mean_radius+(1-flatten_percent)*knurl_depth/2 inverse}
	}
#end

#version KNURLED_CYLINDER_INC_TEMP;
#end