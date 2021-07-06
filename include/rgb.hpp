
#ifndef PAINTIT_COLOR_HPP
#define PAINTIT_COLOR_HPP

#include <string>

#include "lib.hpp"

namespace paintit
{
	class rgb
	{
	private:
		short r = 0;
		short g = 0;
		short b = 0;

	public:
		rgb();
		rgb(short r, short g, short b);
		rgb(const rgb&);
		~rgb();

		rgb mix(const rgb& color);

		rgb bw(const rgb& color);
		rgb antigue(const rgb& color);

		rgb operator+(double num) const;
		rgb operator-(double num) const;
		rgb operator*(double num) const;
		rgb operator/(double num) const;

		rgb operator+(const rgb& color) const;
		rgb operator-(const rgb& color) const;
		rgb operator*(const rgb& color) const;
		rgb operator/(const rgb& color) const;

		rgb& operator=(const rgb& color);
		bool operator==(const rgb& color) const;
		bool operator!=(const rgb& color) const;

		short getR() const;
		void setR(short);

		short getG() const;
		void setG(short);

		short getB() const;
		void setB(short);

		void setRGB(short r, short g, short b);

		std::string getrgbval(const std::string&);

		rgb bw();
		rgb antigue();
	};
}

#endif
