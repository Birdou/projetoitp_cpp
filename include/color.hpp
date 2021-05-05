
#ifndef PAINTIT_COLOR_HPP
#define PAINTIT_COLOR_HPP

#include <string>

#include "lib.hpp"

namespace paintit
{
	class rgb
	{
	private:
		short r;
		short g;
		short b;

	public:
		rgb();
		rgb(short r, short g, short b);
		~rgb();

		rgb mix(const rgb& color);

		rgb bw(const rgb& color);
		rgb antigue(const rgb& color);

		rgb operator+(double num);
		rgb operator-(double num);
		rgb operator*(double num);
		rgb operator/(double num);

		rgb operator+(const rgb& color);
		rgb operator-(const rgb& color);
		rgb operator*(const rgb& color);
		rgb operator/(const rgb& color);

		rgb& operator=(const rgb& color);
		bool operator==(const rgb& color);
		bool operator!=(const rgb& color);

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
