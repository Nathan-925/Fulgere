/*
 * Test.cpp
 *
 *  Created on: Apr 3, 2023
 *      Author: Nathan
 */
#include <iostream>

#include "priori/Graphical.h"
#include "priori/BMPLibrary.h"

#include "ful/ColorMap.h"

using namespace std;
using namespace priori;
using namespace ful;

int main(){
	ColorMap map(2);
	Image img = readbmp("skeeter.bmp");
	map.recolor(img);
	writebmp("test.bmp", img);

	Image img2 = getColorMap(8);
	writebmp("map.bmp", img2);
}
