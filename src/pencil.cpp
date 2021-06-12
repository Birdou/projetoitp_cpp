
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

std::string paintit::penc::scolor(const std::string& colorname)
{
	return this->color.getrgbval(colorname);
}
void paintit::penc::touch(paintit::rgb& surfaceColor) const
{
	switch(this->mode)
	{
		case penc::Modes::normal:
		{
			surfaceColor = this->color;
			break;
		}
		case penc::Modes::average:
		{
			surfaceColor = (surfaceColor + this->color) / 2;
			break;
		}
		case penc::Modes::additive:
		{
			surfaceColor = surfaceColor + this->color;
			break;
		}
		case penc::Modes::subtractive:
		{
			surfaceColor = surfaceColor - this->color;
			break;
		}
		case penc::Modes::last_mode:
		{
			break;
		}
	}
}