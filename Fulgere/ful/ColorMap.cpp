/*
 * ColorMap.cpp
 *
 *  Created on: Apr 3, 2023
 *      Author: Nathan
 */
#include "ColorMap.h"

using namespace std;
using namespace priori;

namespace ful{

	ColorMap::ColorMap(int b) : pixelBits(b){
		int numColors = pow(2, pixelBits/3);
		colors = new Color**[numColors];
		for(int i = 0; i < numColors; i++){
			colors[i] = new Color*[numColors];
			for(int j = 0; j < numColors; j++)
				colors[j] = new Color[numColors];
		}
		for(uint8_t r = 0; r < 256; r++)
			for(uint8_t g = 0; g < 256; g++)
				for(uint8_t b = 0; b < 256; b++)
					colors[r][g][b] = Color(r, g, b);
	}

	ColorMap::ColorMap(const Image &image, int b) : pixelBits(b){

	}

	ColorMap::~ColorMap(){
		int numColors = pow(2, pixelBits/3);
		for(int i = 0; i < numColors; i++){
			for(int j = 0; j < numColors; j++)
				delete[] colors[i][j];
			delete[] colors[i];
		}
		delete[] colors;
	}

	Color ColorMap::get(const Color &color) const{
		return colors[color.r*pixelBits/24][color.g*pixelBits/24][color.b*pixelBits/24];
	}

	void ColorMap::recolor(Image &image) const{
		for(int i = 0; i < image.width; i++)
			for(int j = 0; j < image.height; j++)
				image[i][j] = get(image[i][j]);
	}

	Image appendColorMap(const Image &image, int pixelBits){
		int numColors = pow(2, pixelBits/3);
		int tileWidth = sqrt(numColors);
		for(int r = 0; r < numColors; r++)
			for(int g = 0; g < numColors; g++)
				for(int b = 0; b < numColors; b++)
					colors[r][g][b] = image[r+b%tileWidth]
	}

}
