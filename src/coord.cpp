
#include "coord.hpp"

paintit::coord::coord()
{}

paintit::coord::coord(ssize_t x, ssize_t y):
	x(x), y(y)
{}

paintit::coord::coord(const paintit::coord& _coord)
{
	this->x = _coord.x;
	this->y = _coord.y;
}

paintit::coord& paintit::coord::operator=(const paintit::coord& _coord)
{
	this->x = _coord.x;
	this->y = _coord.y;

	return *this;
}

paintit::coord::~coord()
{}


/*

color 255 0 0
for r from 0 to 1200 by 3 do line 0 r 960 r
color 0 255 0
for r from 1 to 1200 by 3 do line 0 r 960 r
color 0 0 255
for r from 2 to 1200 by 3 do line 0 r 960 r
color 255 0 0
for r from 0 to 960 by 3 do line r 0 r 1200
color 0 255 0
for r from 1 to 960 by 3 do line r 0 r 1200
color 0 0 255
for r from 2 to 960 by 3 do line r 0 r 1200

for x from 0 to 1000 by 1 y from 1000 to 0 by -1 do line x 0 y 1000 line 0 x 1000 y

for r from 0 to 255 by 2 x from 0 to 300 by 1 do for g from 0 to 255 by 2 y from 0 to 300 by 1 do color r g 122 line x y 300 y

*/