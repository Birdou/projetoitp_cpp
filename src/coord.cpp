
#include "coord.hpp"

paintit::coord::coord()
{
}

paintit::coord::coord(ssize_t x, ssize_t y) : x(x), y(y)
{
}

paintit::coord::coord(const paintit::coord &_coord)
{
	this->x = _coord.x;
	this->y = _coord.y;
}

paintit::coord &paintit::coord::operator=(const paintit::coord &_coord)
{
	this->x = _coord.x;
	this->y = _coord.y;

	return *this;
}

paintit::coord::~coord()
{
}
