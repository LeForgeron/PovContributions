// This file is licensed under the terms of the CC-LGPL

//main macro to find the surface
//////////////////////////////////////////////////
#macro surface_traceSurface(traceObj, resolution, fileName, Variation)
#debug concat("\nStart: trace\n")
//setup
///////
	#local objectStart=min_extent(traceObj);
	#local objectEnd=max_extent(traceObj);
	
	#local sWidth=abs(objectEnd.x-objectStart.x);
	#local sHeight=abs(objectEnd.y-objectStart.y);
	#local sLength=abs(objectEnd.z-objectStart.z);
	
	#local samplesX=floor(sWidth*resolution);
	#local samplesY=floor(sHeight*resolution);
	#local samplesZ=floor(sLength*resolution);
	
	//#debug concat("\nstring:",str(surface_samplesZ,0,2),"\n")
	
	#local resStep=1/resolution;
	#local sSamples=array[samplesX][samplesY][samplesZ];
	
	//#debug concat("\nSamples:",str(samplesX,0,0),",",str(samplesY,0,0),",",str(samplesZ,0,0),"\n")
	
	#fopen saveFile fileName write
	#local arrayOutput="";
	#local pointCount=0;
//find surface
//////////////
	#local a=0;
	//start loop
	#while(a<samplesX)
		#local b=0;
		#while(b<samplesY)
			#local c=0;
			#while(c<samplesZ)
				//sample current point if point has not been sampled
				#ifndef(sSamples[a][b][c])
					#local sSamples[a][b][c]=surface_samplePoint(traceObj,a,b,c,resolution, objectStart);
				#end
				
				//check for surface if point is inside
				#if(sSamples[a][b][c]=1)
					#local s1=a*b*c;
					#local s2=a+b+c;
					#local s3=a+b*c;
					//left
					#if(a>0)
					#ifdef(sSamples[a-1][b][c])
					#if(sSamples[a-1][b][c]=0)
						#local surfacePoint=surface_sampleSurface(traceObj, <a,b,c>, <a-resolution,b,c>, resolution, objectStart, Variation, s1,s2,s3)
						
						#if(vlength(surfacePoint[1])!=0)
							#if(pointCount>0) #local arrayOutput=concat(arrayOutput,",\n"); #end
							#local arrayOutput=concat(arrayOutput,"{<",vstr(3,surfacePoint[0],",",0,-1),">,<",vstr(3,surfacePoint[1],",",0,-1),">}");
							#local pointCount=pointCount+1;
						#end
					#end
					#end
					#else
						#local surfacePoint=surface_sampleSurface(traceObj, <a,b,c>, <a-resolution,b,c>, resolution, objectStart, Variation, s1,s2,s3)
						
						#if(vlength(surfacePoint[1])!=0)
							#if(pointCount>0) #local arrayOutput=concat(arrayOutput,",\n"); #end
							#local arrayOutput=concat(arrayOutput,"{<",vstr(3,surfacePoint[0],",",0,-1),">,<",vstr(3,surfacePoint[1],",",0,-1),">}");
							#local pointCount=pointCount+1;
						#end
					#end
					//right
					#if(a<samplesX-1)
						#local sSamples[a+1][b][c]=surface_samplePoint(traceObj,a+1,b,c,resolution, objectStart);
						#if(sSamples[a+1][b][c]=0)
							#local surfacePoint=surface_sampleSurface(traceObj, <a,b,c>, <a+resolution,b,c>, resolution, objectStart, Variation, s1,s2,s3)
							
							#if(vlength(surfacePoint[1])!=0)
								#if(pointCount>0) #local arrayOutput=concat(arrayOutput,",\n"); #end
								#local arrayOutput=concat(arrayOutput,"{<",vstr(3,surfacePoint[0],",",0,-1),">,<",vstr(3,surfacePoint[1],",",0,-1),">}");
								#local pointCount=pointCount+1;
							#end
						#end
					#else
						#local surfacePoint=surface_sampleSurface(traceObj, <a,b,c>, <a+resolution,b,c>, resolution, objectStart, Variation, s1,s2,s3)
						
						#if(vlength(surfacePoint[1])!=0)
							#if(pointCount>0) #local arrayOutput=concat(arrayOutput,",\n"); #end
							#local arrayOutput=concat(arrayOutput,"{<",vstr(3,surfacePoint[0],",",0,-1),">,<",vstr(3,surfacePoint[1],",",0,-1),">}");
							#local pointCount=pointCount+1;
						#end
					#end
					//top
					#if(b>0)
					#ifdef(sSamples[a][b-1][c])
					#if(sSamples[a][b-1][c]=0)
						#local surfacePoint=surface_sampleSurface(traceObj, <a,b,c>, <a,b-resolution,c>, resolution, objectStart, Variation, s1,s2,s3)
						
						#if(vlength(surfacePoint[1])!=0)
							#if(pointCount>0) #local arrayOutput=concat(arrayOutput,",\n"); #end
							#local arrayOutput=concat(arrayOutput,"{<",vstr(3,surfacePoint[0],",",0,-1),">,<",vstr(3,surfacePoint[1],",",0,-1),">}");
							#local pointCount=pointCount+1;
						#end
					#end
					#end
					#else
						#local surfacePoint=surface_sampleSurface(traceObj, <a,b,c>, <a,b-resolution,c>, resolution, objectStart, Variation, s1,s2,s3)
						
						#if(vlength(surfacePoint[1])!=0)
							#if(pointCount>0) #local arrayOutput=concat(arrayOutput,",\n"); #end
							#local arrayOutput=concat(arrayOutput,"{<",vstr(3,surfacePoint[0],",",0,-1),">,<",vstr(3,surfacePoint[1],",",0,-1),">}");
							#local pointCount=pointCount+1;
						#end
					#end
					//bottom
					#if(b<samplesY-1)
						#local sSamples[a][b+1][c]=surface_samplePoint(traceObj,a,b+1,c,resolution, objectStart);
						#if(sSamples[a][b+1][c]=0)
							#local surfacePoint=surface_sampleSurface(traceObj, <a,b,c>, <a,b+resolution,c>, resolution, objectStart, Variation, s1,s2,s3)
							
							#if(vlength(surfacePoint[1])!=0)
								#if(pointCount>0) #local arrayOutput=concat(arrayOutput,",\n"); #end
								#local arrayOutput=concat(arrayOutput,"{<",vstr(3,surfacePoint[0],",",0,-1),">,<",vstr(3,surfacePoint[1],",",0,-1),">}");
								#local pointCount=pointCount+1;
							#end
						#end
					#else
						#local surfacePoint=surface_sampleSurface(traceObj, <a,b,c>, <a,b+resolution,c>, resolution, objectStart, Variation, s1,s2,s3)
						
						#if(vlength(surfacePoint[1])!=0)
							#if(pointCount>0) #local arrayOutput=concat(arrayOutput,",\n"); #end
							#local arrayOutput=concat(arrayOutput,"{<",vstr(3,surfacePoint[0],",",0,-1),">,<",vstr(3,surfacePoint[1],",",0,-1),">}");
							#local pointCount=pointCount+1;
						#end
					#end
					//front
					#if(c>0)
					#ifdef(sSamples[a][b][c-1])
					#if(sSamples[a][b][c-1]=0)
						#local surfacePoint=surface_sampleSurface(traceObj, <a,b,c>, <a,b,c-resolution>, resolution, objectStart, Variation, s1,s2,s3)
						
						#if(vlength(surfacePoint[1])!=0)
							#if(pointCount>0) #local arrayOutput=concat(arrayOutput,",\n"); #end
							#local arrayOutput=concat(arrayOutput,"{<",vstr(3,surfacePoint[0],",",0,-1),">,<",vstr(3,surfacePoint[1],",",0,-1),">}");
							#local pointCount=pointCount+1;
						#end
					#end
					#end
					#else
						#local surfacePoint=surface_sampleSurface(traceObj, <a,b,c>, <a,b,c-resolution>, resolution, objectStart, Variation, s1,s2,s3)
						
						#if(vlength(surfacePoint[1])!=0)
							#if(pointCount>0) #local arrayOutput=concat(arrayOutput,",\n"); #end
							#local arrayOutput=concat(arrayOutput,"{<",vstr(3,surfacePoint[0],",",0,-1),">,<",vstr(3,surfacePoint[1],",",0,-1),">}");
							#local pointCount=pointCount+1;
						#end
					#end
					//back
					#if(c<samplesZ-1)
						#local sSamples[a][b][c+1]=surface_samplePoint(traceObj,a,b,c+1,resolution, objectStart);
						#if(sSamples[a][b][c+1]=0)
							#local surfacePoint=surface_sampleSurface(traceObj, <a,b,c>, <a,b,c+resolution>, resolution, objectStart, Variation, s1,s2,s3)
							
							#if(vlength(surfacePoint[1])!=0)
								#if(pointCount>0) #local arrayOutput=concat(arrayOutput,",\n"); #end
								#local arrayOutput=concat(arrayOutput,"{<",vstr(3,surfacePoint[0],",",0,-1),">,<",vstr(3,surfacePoint[1],",",0,-1),">}");
								#local pointCount=pointCount+1;
							#end
						#end
					#else
						#local surfacePoint=surface_sampleSurface(traceObj, <a,b,c>, <a,b,c+resolution>, resolution, objectStart, Variation, s1,s2,s3)
						
						#if(vlength(surfacePoint[1])!=0)
							#if(pointCount>0) #local arrayOutput=concat(arrayOutput,",\n"); #end
							#local arrayOutput=concat(arrayOutput,"{<",vstr(3,surfacePoint[0],",",0,-1),">,<",vstr(3,surfacePoint[1],",",0,-1),">}");
							#local pointCount=pointCount+1;
						#end
					#end
					
				#end
				
				#local c=c+1;
			#end
			#local b=b+1;
		#end
		#local a=a+1;
	#end
	
	#local arrayOutput=concat("#declare surface_surfacePoints=array[",str(pointCount,0,0),"][2]{\n",arrayOutput,"\n}");
	#local arrayOutput=concat("#declare surface_resolution=",str(1/resolution,0,-1),";\n",arrayOutput);
	#write(saveFile,arrayOutput)
	#fclose saveFile

#debug concat("\nEnd: trace\n")
//end surface_trace macro	
#end

//macro to test whether point is inside the object
//////////////////////////////////////////////////
#macro surface_samplePoint(obj, X, Y, Z, resolution, objectStart)
	#local isInside=0;
	#if(inside(obj,<(X)/resolution+objectStart.x,(Y)/resolution+objectStart.y,(Z)/resolution+objectStart.z>))
		#local isInside=1;
	#else
		#local isInside=0;
	#end
	isInside
#end

//macro to trace the surface of the object
//////////////////////////////////////////
#macro surface_sampleSurface(obj, point, outsidePoint, resolution, objectStart, Var, s1, s2, s3)
	#local r1=seed(s1);
	#local r2=seed(s2);
	#local r3=seed(s3);
	#local traceDir=outsidePoint-point-<Var/2,Var/2,Var/2>+<rand(r1)*Var,rand(r2)*Var,rand(r3)*Var>;
	#local Normal=<0,0,0>;
	#local point=<point.x/resolution+objectStart.x, point.y/resolution+objectStart.y, point.z/resolution+objectStart.z>;
	#local outsidePoint=<outsidePoint.x/resolution+objectStart.x, outsidePoint.y/resolution+objectStart.y, outsidePoint.z/resolution+objectStart.z>;
	#local Position=trace(obj, point, traceDir, Normal);
	
	array[2]{Position,Normal}
#end

//include macros for covering surface
/////////////////////////////////////
#include "surface_cover.inc"




/*#if((a>0 & sSamples[a-1][b][c]=0) | a=0)
						#local surfacePoint=surface_sampleSurface(traceObj, <a,b,c>, <a-resolution,b,c>, resolution, objectStart, Variation, s1,s2,s3)
						
						#if(vlength(surfacePoint[1])!=0)
							#if(pointCount>0) #local arrayOutput=concat(arrayOutput,",\n"); #end
							#local arrayOutput=concat(arrayOutput,"{<",vstr(3,surfacePoint[0],",",0,-1),">,<",vstr(3,surfacePoint[1],",",0,-1),">}");
							#local pointCount=pointCount+1;
						#end
					#end*/