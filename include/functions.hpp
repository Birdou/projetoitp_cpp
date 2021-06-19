
#ifndef PAINTIT_FUNCTIONS_HPP
#define PAINTIT_FUNCTIONS_HPP

#include <string>
#include <vector>

#include "ppm.hpp"
#include "coord.hpp"

namespace paintit
{
	namespace functions
	{
		std::string draw		(paintit::ppm& image, const paintit::penc& pincel, ssize_t PX, ssize_t PY) noexcept;
		std::string linehigh	(paintit::ppm& image, const paintit::penc& pincel, const paintit::coord& P1, const paintit::coord& P2);
		std::string linelow		(paintit::ppm& image, const paintit::penc& pincel, const paintit::coord& P1, const paintit::coord& P2);
		std::string line		(paintit::ppm& image, const paintit::penc& pincel, const paintit::coord&, const paintit::coord&);

		std::string curve		(paintit::ppm& image, const paintit::penc& pincel, const std::vector<paintit::coord>&);
		std::string polygon		(paintit::ppm& image, const paintit::penc& pincel, const std::vector<paintit::coord>&);
		std::string rect		(paintit::ppm& image, const paintit::penc& pincel, const paintit::coord&, int, int);
		std::string circle		(paintit::ppm& image, const paintit::penc& pincel, const paintit::coord&, int, int);
		std::string elipse		(paintit::ppm& image, const paintit::penc& pincel, const paintit::coord& pos, size_t width, size_t height, double angle, int p);
		std::string fill		(paintit::ppm& image, const paintit::penc& pincel, const paintit::coord&);
		std::string global		(paintit::ppm& image, const paintit::penc& pincel, const paintit::coord& pos);
		std::string crop		(paintit::ppm& image, const paintit::coord& P1, const paintit::coord& P2);
		std::string sclear		(paintit::ppm& image, const std::string& colorname);
	}
}
#endif
