/*
 * ColorMap.cpp
 *
 *  Created on: Apr 3, 2023
 *      Author: Nathan
 */
#include <iostream>

#include "ColorMap.h"

using namespace std;
using namespace priori;

namespace ful{

	ColorMap::ColorMap(int b) : bits(b){
		int range = pow(2, bits);
		colors = new Color**[range];
		for(int i = 0; i < range; i++){
			colors[i] = new Color*[range];
			for(int j = 0; j < range; j++)
				colors[i][j] = new Color[range];
		}
		for(int r = 0; r < range; r++)
			for(int g = 0; g < range; g++)
				for(int b = 0; b < range; b++)
					colors[r][g][b] = Color(r*255/(range-1), g*255/(range-1), b*255/(range-1));
	}

	ColorMap::ColorMap(const Image &image, int b) : bits(b){
		int range = pow(2, bits);
		colors = new Color**[range];
		for(int i = 0; i < range; i++){
			colors[i] = new Color*[range];
			for(int j = 0; j < range; j++)
				colors[i][j] = new Color[range];
		}

		int root = sqrt(range);
		int imgWidth = range*root;
		for(int x = 0; x < imgWidth; x++)
			for(int y = 0; y < imgWidth; y++){
				int r = x%range;
				int g = y%range;
				int b = (x/range) + (y/range*root);
				colors[r][g][b] = image[x][y];
			}
	}

	ColorMap::~ColorMap(){
		int range = pow(2, bits);
		for(int i = 0; i < range; i++){
			for(int j = 0; j < range; j++)
				delete[] colors[i][j];
			delete[] colors[i];
		}
		delete[] colors;
	}

	Color& ColorMap::get(const Color &color){
		int range = pow(2, bits);
		return colors[color.r*range/256][color.g*range/256][color.b*range/256];
	}

	Color ColorMap::get(const Color &color) const{
		int range = pow(2, bits);
		return colors[color.r*range/256][color.g*range/256][color.b*range/256];;
	}

	void ColorMap::recolor(Image &image) const{
		for(int i = 0; i < image.width; i++)
			for(int j = 0; j < image.height; j++)
				image[i][j] = get(image[i][j]);
	}

	Image getColorMap(int bits){
		int range = pow(2, bits);
		int root = sqrt(range);
		Image out(range*root, range*root);

		for(int r = 0; r < range; r++)
			for(int g = 0; g < range; g++)
				for(int b = 0; b < range; b++)
					out[r+b%root*range][g+b/root*range] = Color(r*255/(range-1), g*255/(range-1), b*255/(range-1));

		return out;
	}

	Image appendColorMap(const Image &image, int bits){
		Image map = getColorMap(bits);
		Image out(max(map.width, image.width), map.height+image.height);

		for(int i = 0; i < map.width; i++)
			for(int j = 0; j < map.height; j++)
				out[i][j] = map[i][j];

		for(int i = 0; i < image.width; i++)
			for(int j = 0; j < image.height; j++)
				out[i][j+map.height] = image[i][j];

		return out;
	}

}
