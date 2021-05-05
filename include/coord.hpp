
#ifndef PAINTIT_COORD_HPP
#define PAINTIT_COORD_HPP

#include <string>
#include <cstddef>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include <exception>

namespace paintit
{
	class coord
	{
	public:
		coord();
		coord(const paintit::coord&);
		coord(ssize_t x, ssize_t y);
		~coord();

		coord& operator=(const paintit::coord& _coord);
		
		ssize_t x = 0;
		ssize_t y = 0;
	};
}

#endif