
#ifndef PAINTIT_PENCIL_HPP
#define PAINTIT_PENCIL_HPP

#include <string>

#include "color.hpp"
#include "lib.hpp"

namespace paintit
{
	class penc
	{
	private:
		paintit::rgb color;
		double size;

	public:
		penc();
		penc(paintit::rgb color, double size);
		~penc();

		paintit::rgb getColor() const;
		void setColor(paintit::rgb color);

		double getSize() const;
		void setSize(double size);

		void scolor(const std::string& colorname);
	};
}

#endif
