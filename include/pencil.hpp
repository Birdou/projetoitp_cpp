
#ifndef PAINTIT_PENCIL_HPP
#define PAINTIT_PENCIL_HPP

#include <string>

#include "rgb.hpp"
#include "lib.hpp"

namespace paintit
{
	class penc
	{
	public:
				penc();
				penc(paintit::rgb color, double size);
				~penc();

				paintit::rgb getColor() const;
				void setColor(paintit::rgb color);

				double getSize() const;
				void setSize(double size);

				std::string scolor(const std::string& colorname);

				void touch(paintit::rgb& color) const;

				enum Modes
		{
			normal,
			average,
			additive,
			subtractive,
			last_mode
		};
		Modes mode = normal;

	private:
		paintit::rgb color;
		double size;
	};
}

#endif
