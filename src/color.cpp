
#include "color.hpp"

paintit::rgb::rgb()
{}

paintit::rgb::rgb(short r, short g, short b):
r(r), g(g), b(b)
{}

paintit::rgb::~rgb()
{}

paintit::rgb paintit::rgb::mix(const paintit::rgb& color)
{
	return (*this + color) / 2;
}

paintit::rgb paintit::rgb::operator+(double num)
{
	return paintit::rgb(this->r + num, this->g + num, this->b + num);
}
paintit::rgb paintit::rgb::operator-(double num)
{
	return paintit::rgb(this->r - num, this->g - num, this->b - num);
}
paintit::rgb paintit::rgb::operator*(double num)
{
	return paintit::rgb(this->r * num, this->g * num, this->b * num);
}
paintit::rgb paintit::rgb::operator/(double num)
{
	return paintit::rgb(this->r / num, this->g / num, this->b / num);
}

paintit::rgb paintit::rgb::operator+(const paintit::rgb& color)
{
	return paintit::rgb(this->r + color.r, this->g + color.g, this->b + color.b);
}
paintit::rgb paintit::rgb::operator-(const paintit::rgb& color)
{
	return paintit::rgb(this->r - color.r, this->g - color.g, this->b - color.b);
}
paintit::rgb paintit::rgb::operator*(const paintit::rgb& color)
{
	return paintit::rgb(this->r * color.r, this->g * color.g, this->b * color.b);
}
paintit::rgb paintit::rgb::operator/(const paintit::rgb& color)
{
	return paintit::rgb(this->r / color.r, this->g / color.g, this->b / color.b);
}
paintit::rgb& paintit::rgb::operator=(const rgb& color)
{
	this->r = color.r;
	this->g = color.g;
	this->b = color.b;

	return *this;
}
bool paintit::rgb::operator==(const paintit::rgb& color)
{
	if (this->r == color.r && this->g == color.g && this->b == color.b)
	{
		return true;
	}
	return false;
}

bool paintit::rgb::operator!=(const paintit::rgb& color)
{
	if (this->r != color.r || this->g != color.g || this->b != color.b)
	{
		return true;
	}
	return false;
}

short paintit::rgb::getR() const
{
	return this->r;
}
void paintit::rgb::setR(short value)
{
	if(value < 0 || value > 255)
		this->r = 0;
	this->r = value;
}

short paintit::rgb::getG() const
{
	return this->g;
}
void paintit::rgb::setG(short value)
{
	if(value < 0 || value > 255)
		this->g = 0;
	this->g = value;
}

short paintit::rgb::getB() const
{
	return this->b;
}
void paintit::rgb::setB(short value)
{
	if(value < 0 || value > 255)
		this->b = 0;
	this->b = value;
}

paintit::rgb paintit::rgb::bw()
{
	paintit::rgb grayscale;
	grayscale.r = (0.3 * this->r) + (0.59 * this->g) + (0.11 * this->b);
	grayscale.g = (0.3 * this->r) + (0.59 * this->g) + (0.11 * this->b);
	grayscale.b = (0.3 * this->r) + (0.59 * this->g) + (0.11 * this->b);
	return grayscale;
}

paintit::rgb paintit::rgb::antigue()
{
	paintit::rgb sepia;
	sepia.r = (0.393 * this->r) + (0.769 * this->g) + (0.189 * this->b);
	sepia.g = (0.349 * this->r) + (0.686 * this->g) + (0.168 * this->b);
	sepia.b = (0.272 * this->r) + (0.534 * this->g) + (0.131 * this->b);
	return sepia;
}
void paintit::rgb::setRGB(short r, short g, short b)
{
	setR(r);
	setG(g);
	setB(b);
}
std::string paintit::rgb::getrgbval(const std::string& ref)
{
	if(lib::cstrcmp("Black", ref) == 0) { *this = paintit::rgb(0, 0, 0); }
	else if(lib::cstrcmp("White", ref) == 0) { *this = paintit::rgb(255, 255, 255); }
	else if(lib::cstrcmp("grey11", ref) == 0) { *this = paintit::rgb(28, 28, 28); }
	else if(lib::cstrcmp("grey21", ref) == 0) { *this = paintit::rgb(54, 54, 54); }
	else if(lib::cstrcmp("grey31", ref) == 0) { *this = paintit::rgb(79, 79, 79); }
	else if(lib::cstrcmp("DimGray", ref) == 0) { *this = paintit::rgb(105, 105, 105); }
	else if(lib::cstrcmp("Gray", ref) == 0) { *this = paintit::rgb(128, 128, 128); }
	else if(lib::cstrcmp("DarkGray", ref) == 0) { *this = paintit::rgb(169, 169, 169); }
	else if(lib::cstrcmp("Silver", ref) == 0) { *this = paintit::rgb(192, 192, 192); }
	else if(lib::cstrcmp("LightGrey", ref) == 0) { *this = paintit::rgb(211, 211, 211); }
	else if(lib::cstrcmp("Gainsboro", ref) == 0) { *this = paintit::rgb(220, 220, 220); }
	else if(lib::cstrcmp("SlateBlue", ref) == 0) { *this = paintit::rgb(106, 90, 205); }
	else if(lib::cstrcmp("SlateBlue1", ref) == 0) { *this = paintit::rgb(131, 111, 255); }
	else if(lib::cstrcmp("SlateBlue3", ref) == 0) { *this = paintit::rgb(105, 89, 205); }
	else if(lib::cstrcmp("DarkSlateBlue", ref) == 0) { *this = paintit::rgb(72, 61, 139); }
	else if(lib::cstrcmp("MidnightBlue", ref) == 0) { *this = paintit::rgb(25, 25, 112); }
	else if(lib::cstrcmp("Navy", ref) == 0) { *this = paintit::rgb(0, 0, 128); }
	else if(lib::cstrcmp("DarkBlue", ref) == 0) { *this = paintit::rgb(0, 0, 139); }
	else if(lib::cstrcmp("MediumBlue", ref) == 0) { *this = paintit::rgb(0, 0, 205); }
	else if(lib::cstrcmp("Blue", ref) == 0) { *this = paintit::rgb(0, 0, 255); }
	else if(lib::cstrcmp("refnflowerBlue", ref) == 0) { *this = paintit::rgb(100, 149, 237); }
	else if(lib::cstrcmp("RoyalBlue", ref) == 0) { *this = paintit::rgb(65, 105, 225); }
	else if(lib::cstrcmp("DodgerBlue", ref) == 0) { *this = paintit::rgb(30, 144, 255); }
	else if(lib::cstrcmp("DeepSkyBlue", ref) == 0) { *this = paintit::rgb(0, 191, 255); }
	else if(lib::cstrcmp("LightSkyBlue", ref) == 0) { *this = paintit::rgb(135, 206, 250); }
	else if(lib::cstrcmp("SkyBlue", ref) == 0) { *this = paintit::rgb(135, 206, 235); }
	else if(lib::cstrcmp("LightBlue", ref) == 0) { *this = paintit::rgb(173, 216, 230); }
	else if(lib::cstrcmp("SteelBlue", ref) == 0) { *this = paintit::rgb(70, 130, 180); }
	else if(lib::cstrcmp("LightSteelBlue", ref) == 0) { *this = paintit::rgb(176, 196, 222); }
	else if(lib::cstrcmp("SlateGray", ref) == 0) { *this = paintit::rgb(112, 128, 144); }
	else if(lib::cstrcmp("LightSlateGray", ref) == 0) { *this = paintit::rgb(119, 136, 153); }
	else if(lib::cstrcmp("Aqua", ref) == 0) { *this = paintit::rgb(0, 255, 255); }
	else if(lib::cstrcmp("Cyan", ref) == 0) { *this = paintit::rgb(0, 255, 255); }
	else if(lib::cstrcmp("DarkTurquoise", ref) == 0) { *this = paintit::rgb(0, 206, 209); }
	else if(lib::cstrcmp("Turquoise", ref) == 0) { *this = paintit::rgb(64, 224, 208); }
	else if(lib::cstrcmp("MediumTurquoise", ref) == 0) { *this = paintit::rgb(72, 209, 204); }
	else if(lib::cstrcmp("LightSeaGreen", ref) == 0) { *this = paintit::rgb(32, 178, 170); }
	else if(lib::cstrcmp("DarkCyan", ref) == 0) { *this = paintit::rgb(0, 139, 139); }
	else if(lib::cstrcmp("Teal", ref) == 0) { *this = paintit::rgb(0, 128, 128); }
	else if(lib::cstrcmp("Aquamarine", ref) == 0) { *this = paintit::rgb(127, 255, 212); }
	else if(lib::cstrcmp("MediumAquamarine", ref) == 0) { *this = paintit::rgb(102, 205, 170); }
	else if(lib::cstrcmp("CadetBlue", ref) == 0) { *this = paintit::rgb(95, 158, 160); }
	else if(lib::cstrcmp("DarkSlateGray", ref) == 0) { *this = paintit::rgb(47, 79, 79); }
	else if(lib::cstrcmp("MediumSpringGreen", ref) == 0) { *this = paintit::rgb(0, 250, 154); }
	else if(lib::cstrcmp("SpringGreen", ref) == 0) { *this = paintit::rgb(0, 255, 127); }
	else if(lib::cstrcmp("PaleGreen", ref) == 0) { *this = paintit::rgb(152, 251, 152); }
	else if(lib::cstrcmp("LightGreen", ref) == 0) { *this = paintit::rgb(144, 238, 144); }
	else if(lib::cstrcmp("DarkSeaGreen", ref) == 0) { *this = paintit::rgb(143, 188, 143); }
	else if(lib::cstrcmp("MediumSeaGreen", ref) == 0) { *this = paintit::rgb(60, 179, 113); }
	else if(lib::cstrcmp("SeaGreen", ref) == 0) { *this = paintit::rgb(46, 139, 87); }
	else if(lib::cstrcmp("DarkGreen", ref) == 0) { *this = paintit::rgb(0, 100, 0); }
	else if(lib::cstrcmp("Green", ref) == 0) { *this = paintit::rgb(0, 128, 0); }
	else if(lib::cstrcmp("ForestGreen", ref) == 0) { *this = paintit::rgb(34, 139, 34); }
	else if(lib::cstrcmp("LimeGreen", ref) == 0) { *this = paintit::rgb(50, 205, 50); }
	else if(lib::cstrcmp("Lime", ref) == 0) { *this = paintit::rgb(0, 255, 0); }
	else if(lib::cstrcmp("LawnGreen", ref) == 0) { *this = paintit::rgb(124, 252, 0); }
	else if(lib::cstrcmp("Chartreuse", ref) == 0) { *this = paintit::rgb(127, 255, 0); }
	else if(lib::cstrcmp("GreenYellow", ref) == 0) { *this = paintit::rgb(173, 255, 47); }
	else if(lib::cstrcmp("YellowGreen", ref) == 0) { *this = paintit::rgb(154, 205, 50); }
	else if(lib::cstrcmp("OliveDrab", ref) == 0) { *this = paintit::rgb(107, 142, 35); }
	else if(lib::cstrcmp("DarkOliveGreen", ref) == 0) { *this = paintit::rgb(85, 107, 47); }
	else if(lib::cstrcmp("Olive", ref) == 0) { *this = paintit::rgb(128, 128, 0); }
	else if(lib::cstrcmp("DarkKhaki", ref) == 0) { *this = paintit::rgb(189, 83, 107); }
	else if(lib::cstrcmp("Goldenrod", ref) == 0) { *this = paintit::rgb(218, 165, 32); }
	else if(lib::cstrcmp("DarkGoldenrod", ref) == 0) { *this = paintit::rgb(184, 134, 11); }
	else if(lib::cstrcmp("SaddleBrown", ref) == 0) { *this = paintit::rgb(139, 69, 19); }
	else if(lib::cstrcmp("Sienna", ref) == 0) { *this = paintit::rgb(160, 82, 45); }
	else if(lib::cstrcmp("RosyBrown", ref) == 0) { *this = paintit::rgb(188, 143, 143); }
	else if(lib::cstrcmp("Peru", ref) == 0) { *this = paintit::rgb(205, 133, 63); }
	else if(lib::cstrcmp("Chocolate", ref) == 0) { *this = paintit::rgb(210, 105, 30); }
	else if(lib::cstrcmp("SandyBrown", ref) == 0) { *this = paintit::rgb(244, 164, 96); }
	else if(lib::cstrcmp("NavajoWhite", ref) == 0) { *this = paintit::rgb(255, 222, 173); }
	else if(lib::cstrcmp("Wheat", ref) == 0) { *this = paintit::rgb(245, 222, 179); }
	else if(lib::cstrcmp("BurlyWood", ref) == 0) { *this = paintit::rgb(222, 184, 135); }
	else if(lib::cstrcmp("Tan", ref) == 0) { *this = paintit::rgb(210, 180, 140); }
	else if(lib::cstrcmp("MediumSlateBlue", ref) == 0) { *this = paintit::rgb(123, 104, 238); }
	else if(lib::cstrcmp("MediumPurple", ref) == 0) { *this = paintit::rgb(147, 112, 219); }
	else if(lib::cstrcmp("BlueViolet", ref) == 0) { *this = paintit::rgb(138, 43, 226); }
	else if(lib::cstrcmp("Indigo", ref) == 0) { *this = paintit::rgb(75, 0, 130); }
	else if(lib::cstrcmp("DarkViolet", ref) == 0) { *this = paintit::rgb(148, 0, 211); }
	else if(lib::cstrcmp("DarkOrchid", ref) == 0) { *this = paintit::rgb(153, 50, 204); }
	else if(lib::cstrcmp("MediumOrchid", ref) == 0) { *this = paintit::rgb(186, 85, 211); }
	else if(lib::cstrcmp("Purple", ref) == 0) { *this = paintit::rgb(128, 0, 128); }
	else if(lib::cstrcmp("DarkMagenta", ref) == 0) { *this = paintit::rgb(139, 0, 139); }
	else if(lib::cstrcmp("Fuchsia", ref) == 0) { *this = paintit::rgb(255, 0, 255); }
	else if(lib::cstrcmp("Magenta", ref) == 0) { *this = paintit::rgb(255, 0, 255); }
	else if(lib::cstrcmp("Violet", ref) == 0) { *this = paintit::rgb(238, 130, 238); }
	else if(lib::cstrcmp("Orchid", ref) == 0) { *this = paintit::rgb(218, 112, 214); }
	else if(lib::cstrcmp("Plum", ref) == 0) { *this = paintit::rgb(221, 160, 221); }
	else if(lib::cstrcmp("MediumVioletRed", ref) == 0) { *this = paintit::rgb(199, 21, 133); }
	else if(lib::cstrcmp("DeepPink", ref) == 0) { *this = paintit::rgb(255, 20, 147); }
	else if(lib::cstrcmp("HotPink", ref) == 0) { *this = paintit::rgb(255, 105, 180); }
	else if(lib::cstrcmp("PaleVioletRed", ref) == 0) { *this = paintit::rgb(219, 112, 147); }
	else if(lib::cstrcmp("LightPink", ref) == 0) { *this = paintit::rgb(255, 182, 193); }
	else if(lib::cstrcmp("Pink", ref) == 0) { *this = paintit::rgb(255, 192, 203); }
	else if(lib::cstrcmp("Lightrefal", ref) == 0) { *this = paintit::rgb(240, 128, 128); }
	else if(lib::cstrcmp("IndianRed", ref) == 0) { *this = paintit::rgb(205, 92, 92); }
	else if(lib::cstrcmp("Crimson", ref) == 0) { *this = paintit::rgb(220, 20, 60); }
	else if(lib::cstrcmp("Maroon", ref) == 0) { *this = paintit::rgb(128, 0, 0); }
	else if(lib::cstrcmp("DarkRed", ref) == 0) { *this = paintit::rgb(139, 0, 0); }
	else if(lib::cstrcmp("FireBrick", ref) == 0) { *this = paintit::rgb(178, 34, 34); }
	else if(lib::cstrcmp("Brown", ref) == 0) { *this = paintit::rgb(165, 42, 42); }
	else if(lib::cstrcmp("Salmon", ref) == 0) { *this = paintit::rgb(250, 128, 114); }
	else if(lib::cstrcmp("DarkSalmon", ref) == 0) { *this = paintit::rgb(233, 150, 122); }
	else if(lib::cstrcmp("LightSalmon", ref) == 0) { *this = paintit::rgb(255, 160, 122); }
	else if(lib::cstrcmp("refal", ref) == 0) { *this = paintit::rgb(255, 127, 80); }
	else if(lib::cstrcmp("Tomato", ref) == 0) { *this = paintit::rgb(255, 99, 71); }
	else if(lib::cstrcmp("Red", ref) == 0) { *this = paintit::rgb(255, 0, 0); }
	else if(lib::cstrcmp("OrangeRed", ref) == 0) { *this = paintit::rgb(255, 69, 0); }
	else if(lib::cstrcmp("DarkOrange", ref) == 0) { *this = paintit::rgb(255, 140, 0); }
	else if(lib::cstrcmp("Orange", ref) == 0) { *this = paintit::rgb(255, 165, 0); }
	else if(lib::cstrcmp("Gold", ref) == 0) { *this = paintit::rgb(255, 215, 0); }
	else if(lib::cstrcmp("Yellow", ref) == 0) { *this = paintit::rgb(255, 255, 0); }
	else if(lib::cstrcmp("Khaki", ref) == 0) { *this = paintit::rgb(240, 230, 140); }
	else if(lib::cstrcmp("AliceBlue", ref) == 0) { *this = paintit::rgb(240, 248, 255); }
	else if(lib::cstrcmp("GhostWhite", ref) == 0) { *this = paintit::rgb(248, 248, 255); }
	else if(lib::cstrcmp("Snow", ref) == 0) { *this = paintit::rgb(255, 250, 250); }
	else if(lib::cstrcmp("Seashell", ref) == 0) { *this = paintit::rgb(255, 245, 238); }
	else if(lib::cstrcmp("FloralWhite", ref) == 0) { *this = paintit::rgb(255, 250, 240); }
	else if(lib::cstrcmp("WhiteSmoke", ref) == 0) { *this = paintit::rgb(245, 245, 245); }
	else if(lib::cstrcmp("Beige", ref) == 0) { *this = paintit::rgb(245, 245, 220); }
	else if(lib::cstrcmp("OldLace", ref) == 0) { *this = paintit::rgb(253, 245, 230); }
	else if(lib::cstrcmp("Ivory", ref) == 0) { *this = paintit::rgb(255, 255, 240); }
	else if(lib::cstrcmp("Linen", ref) == 0) { *this = paintit::rgb(250, 240, 230); }
	else if(lib::cstrcmp("refnsilk", ref) == 0) { *this = paintit::rgb(255, 248, 220); }
	else if(lib::cstrcmp("AntiqueWhite", ref) == 0) { *this = paintit::rgb(250, 235, 215); }
	else if(lib::cstrcmp("BlanchedAlmond", ref) == 0) { *this = paintit::rgb(255, 235, 205); }
	else if(lib::cstrcmp("Bisque", ref) == 0) { *this = paintit::rgb(255, 228, 196); }
	else if(lib::cstrcmp("LightYellow", ref) == 0) { *this = paintit::rgb(255, 255, 224); }
	else if(lib::cstrcmp("LemonChiffon", ref) == 0) { *this = paintit::rgb(255, 250, 205); }
	else if(lib::cstrcmp("LightGoldenrodYellow", ref) == 0) { *this = paintit::rgb(250, 250, 210); }
	else if(lib::cstrcmp("PapayaWhip", ref) == 0) { *this = paintit::rgb(255, 239, 213); }
	else if(lib::cstrcmp("PeachPuff", ref) == 0) { *this = paintit::rgb(255, 218, 185); }
	else if(lib::cstrcmp("Moccasin", ref) == 0) { *this = paintit::rgb(255, 228, 181); }
	else if(lib::cstrcmp("PaleGoldenrod", ref) == 0) { *this = paintit::rgb(238, 232, 170); }
	else if(lib::cstrcmp("MistyRose", ref) == 0) { *this = paintit::rgb(255, 228, 225); }
	else if(lib::cstrcmp("LavenderBlush", ref) == 0) { *this = paintit::rgb(255, 240, 245); }
	else if(lib::cstrcmp("Lavender", ref) == 0) { *this = paintit::rgb(230, 230, 250); }
	else if(lib::cstrcmp("Thistle", ref) == 0) { *this = paintit::rgb(216, 191, 216); }
	else if(lib::cstrcmp("Azure", ref) == 0) { *this = paintit::rgb(240, 255, 255); }
	else if(lib::cstrcmp("LightCyan", ref) == 0) { *this = paintit::rgb(224, 255, 255); }
	else if(lib::cstrcmp("PowderBlue", ref) == 0) { *this = paintit::rgb(176, 224, 230); }
	else if(lib::cstrcmp("PaleTurquoise", ref) == 0) { *this = paintit::rgb(175, 238, 238); }
	else if(lib::cstrcmp("Honeydew", ref) == 0) { *this = paintit::rgb(240, 255, 240); }
	else if(lib::cstrcmp("MintCream", ref) == 0) { *this = paintit::rgb(245, 255, 250); }
	else { return color_not_found_exception; }
	
	return noerror;
}