
#include "pencil.hpp"

paintit::penc::penc()
{}

paintit::penc::penc(paintit::rgb color, double size):
color(color), size(size)
{}

paintit::penc::~penc()
{}

paintit::rgb paintit::penc::getColor() const
{
	return this->color;
}

void paintit::penc::setColor(paintit::rgb color)
{
	this->color = color;
}

double paintit::penc::getSize() const
{
	return this->size;
}

void paintit::penc::setSize(double size)
{
	this->size = size;
}

void paintit::penc::scolor(const std::string& colorname)
{
	this->color.getrgbval(colorname);
}
