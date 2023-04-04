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
	public:
		const int bits;
		priori::Color*** colors;

		ColorMap(int b = 8);
		ColorMap(const priori::Image &image, int b = 8);
		~ColorMap();

		priori::Color& get(const priori::Color &color);
		priori::Color get(const priori::Color &color) const;
		void recolor(priori::Image &image) const;
	};

	priori::Image getColorMap(int bits = 8);

	priori::Image appendColorMap(const priori::Image &image, int bits = 8);

}

#endif /* COLORMAP_H_ */
