// This file is licensed under the terms of the CC-LGPL

#include "transforms.inc"

//cover surface with an object
//////////////////////////////
#macro surface_cover(fileName/*, outFile*/, obj, orientToSurface, sizeToSurface)
#debug concat("\nStart: cover surface\n")
union{
//setup
	/*#local doSave=yes;
	#if(strcmp(outFile,"")=0)
		#local doSave=no;
	#end
	#if(doSave)
		//#fopen saveFile outFile write
	#end*/
	#declare surface_surfacePoints=array[1]
	#include fileName
	
	#local objScale=<1,1,1>;
	#if(sizeToSurface)
		#local objectStart=min_extent(obj);
		#local objectEnd=max_extent(obj);
		
		#local sWidth=abs(objectEnd.x-objectStart.x);
		#local sHeight=abs(objectEnd.y-objectStart.y);
		#local sLength=abs(objectEnd.z-objectStart.z);
		
		#local objScale=<1/(sWidth/surface_resolution)*1.2,1/(sHeight/surface_resolution)*1.2,1/(sLength/surface_resolution)*1.2>;
	#end
	
//loop through surface points
	#local a=0;
	#local pointCount=dimension_size(surface_surfacePoints,1);
	#while(a<pointCount)
		//write to file
		//#if(doSave)
		//#else
		object{obj
			transform{
				scale objScale
				#if(orientToSurface)
					Reorient_Trans(x, surface_surfacePoints[a][1])
				#end
				translate surface_surfacePoints[a][0]
			}
		}
		//#end
		#local a=a+1;
	#end
	
//close
	#undef surface_surfacePoints
	
	/*&#if(doSave)
		#fclose saveFile
	#end*/
}
#debug concat("\nEnd: cover surface\n")
#end

//cover surface with hair
/////////////////////////
#macro surface_coverHair(fileName, outFile, hairName, hairLength, hairDivisions, Thickness, Variation)
#debug concat("\nStart: cover surface\n")
//setup
	#fopen saveFile outFile write
	#write(saveFile,"#declare ",hairName,"=union{")
	
	#declare surface_surfacePoints=array[1]
	#include fileName
	
//loop through surface points
	#local a=0;
	#local pointCount=dimension_size(surface_surfacePoints,1);
	#while(a<pointCount)
		#local s=seed(a);
		#local Var=<-Variation/2+rand(s)*Variation,-Variation/2+rand(s)*Variation,-Variation/2+rand(s)*Variation>;
		#local hair=surface_makeHair(surface_surfacePoints[a][0],surface_surfacePoints[a][1]+Var,<0,-0.01,0>,hairLength*1,hairDivisions,Thickness,0.05,a)
		#local b=0;
		#local hairArraySize=dimension_size(hair,1);
		#while(b<hairArraySize)
			#write(saveFile,"cone{<"vstr(3,hair[b][0],",",0,-1),">,",str(hair[b][1].x,0,6),",<",vstr(3,hair[b][2],",",0,6),">,",str(hair[b][3].x,0,6),"}")
			//cone{hair[b][0],hair[b][1].x,hair[b][2],hair[b][3].x}
			#local b=b+1;
		#end
		#local a=a+1;
	#end
	
//close
	#undef surface_surfacePoints
	
	#write(saveFile,"}")
	#fclose saveFile
#debug concat("\nEnd: cover surface\n")
#end

#macro surface_makeHair(Position,Direction,Gravity,Length,Divisions,Thickness,Variation,Index)
	#local a=0;
	#local s=seed(Index);//#write(hairFile,"cone{<"vstr(3,Position,",",0,4),">,",str(Thickness,0,4),"}")
	#local hair=array[Divisions][4];
	#local Length=Length-Variation/2+rand(s)*Variation;
	#local Direction=<Direction.x-0.1+rand(s)*0.2,Direction.y-0.1+rand(s)*0.2,Direction.z-0.1+rand(s)*0.2>;
	#while(a<Divisions)
		#local Direction=vnormalize(Direction)*Length;
		#local nPosition=Position+Direction+rand(s)*0.0001;
		//#debug concat(str(Index,0,0),"   ",vstr(3,Position,",",0,3),"    ",vstr(3,Direction,",",0,3),"\n")
		//cone{Position,Thickness*(1-a/Divisions),nPosition,Thickness*(1-a/Divisions)}
		#local hair[a][0]=Position;
		#local hair[a][1]=<Thickness*(1-a/Divisions),0,0>;
		#local hair[a][2]=nPosition;
		#local hair[a][3]=<Thickness*(1-(a+1)/Divisions),0,0>;
		#local Position=nPosition;
		#local Direction=Direction+Gravity;
		#if(VEq(Direction,<0,0,0>))
			#local Direction=Direction+Gravity*0.1;
		#end
		#local a=a+1;
	#end
	hair
#end