/*

3D Clouds include file

Copyright 2002 Sascha Ledinsky

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

global_settings
{
    max_trace_level 200
}
    
#ifndef(clouds_color) #declare clouds_color = color rgb <0.7,0.8,0.9>; #end
#ifndef(clouds_light) #declare clouds_light = 0.3; #end
#ifndef(clouds_transmit) #declare clouds_transmit = -2; #end
#ifndef(clouds_diffuse) #declare clouds_diffuse = 1; #end
#ifndef(clouds_ambient) #declare clouds_ambient = 0; #end
#ifndef(clouds_brilliance) #declare clouds_brilliance = 0.2; #end
#ifndef(clouds_blur) #declare clouds_blur = 0.05; #end
#ifndef(clouds_alt) #declare clouds_alt = 1000; #end
#ifndef(clouds_height) #declare clouds_height = 100; #end
#ifndef(clouds_layers) #declare clouds_layers = 20; #end
#ifndef(clouds_size) #declare clouds_size = 1000; #end
#ifndef(clouds_fill) #declare clouds_fill = 0.5; #end

#declare clouds_layertransmit = pow(pow(10,clouds_transmit),1/clouds_layers);
#macro tx_cloud(fill) 
        pigment
        { 
            granite
            turbulence 0.2
            octaves 6
            lambda 3
            scale clouds_size
            scale <1,2,1>
            color_map
            {
                [0.0 color clouds_color*clouds_light transmit 1]
                [1.0 - fill - clouds_blur color clouds_color*clouds_light transmit 1]
                [1.0 - fill + clouds_blur color clouds_color*clouds_light transmit clouds_layertransmit]
                [1.0 color clouds_color*clouds_light transmit clouds_layertransmit]
            }
        }
        finish
        {
            ambient clouds_ambient
            diffuse clouds_diffuse
            brilliance clouds_brilliance
        }
#end
            
#macro cloud_layer(alt,layer)
    #local cloud = object
    {
        plane
        {
            y,alt
            hollow 
        }    
    }
    object
    {
        cloud                
        texture
        {
            tx_cloud(layer)
        }
        double_illuminate
    }
#end

#local alt = clouds_alt;
#local layer = 0;
#local step = 1/clouds_layers;
#while (layer < 1) 
    cloud_layer(alt,clouds_fill-layer*layer*(1-clouds_fill))
    #local layer = layer + step;
    #local alt = alt + clouds_height/clouds_layers;
#end

        

