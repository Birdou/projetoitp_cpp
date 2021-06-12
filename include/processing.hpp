
#ifndef PAINTIT_PROCESSING_HPP
#define PAINTIT_PROCESSING_HPP

#include <string>
#include <random>

#include "ppm.hpp"
#include "coord.hpp"

namespace paintit
{
	namespace processing
	{
		static std::random_device rd;
		std::string grayscale	(paintit::ppm& image);
		std::string sepia		(paintit::ppm& image);
		std::string negative	(paintit::ppm& image);
		std::string brighten	(paintit::ppm& image, double scale);
		std::string darken		(paintit::ppm& image, double scale);
		std::string vibrancy	(paintit::ppm& image, double scale);
		std::string guev		(paintit::ppm& image, double scale);
		std::string intensity	(paintit::ppm& image, double red, double green, double blue);
		std::string desaturate	(paintit::ppm& image, double red, double green, double blue);
		std::string redequal	(paintit::ppm& image, double red, double green, double blue);
		std::string greenequal	(paintit::ppm& image, double red, double green, double blue);
		std::string blueequal	(paintit::ppm& image, double red, double green, double blue);
		std::string glitch		(paintit::ppm& image, int scale, double angle);
		std::string rbglitch	(paintit::ppm& image, int scale, double angle);
		std::string pixelize	(paintit::ppm& image, int px);
		std::string makenoise	(paintit::ppm& image);
	}
}

#endif