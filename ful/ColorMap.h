/*
 * ColorMap.h
 *
 *  Created on: Apr 3, 2023
 *      Author: Nathan
 */

#ifndef COLORMAP_H_
#define COLORMAP_H_

#include "priori/Graphical.h"

namespace ful{

	class ColorMap{
		const int pixelBits;
		priori::Color*** colors;

		ColorMap(int b = 24);
		ColorMap(const priori::Image &image, int b = 24);
		~ColorMap();

		priori::Color get(const priori::Color &color) const;
		void recolor(priori::Image &image) const;
	};

	priori::Image appendColorMap(const priori::Image &image, int pixelBits = 24);

}

#endif /* COLORMAP_H_ */
