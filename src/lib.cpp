
#include "lib.hpp"

#include <sys/types.h>
#include <sys/stat.h>

long int lib::fat(int num)
{
	if (num == 0)
	{
		return 1;
	}
	for (long int i = num - 1; i > 0; i--)
	{
		num *= i;
	}
	return num;
}

long int lib::bin(int n, int i)
{
	return fat(n) / (fat(i) * fat(n - i));
}

double lib::rad(double deg)
{
	return deg * PI / 180;
}

std::string lib::stolower(const std::string &word)
{
	std::stringstream ss;

	for (auto c : word)
	{
		ss << (unsigned char)tolower(c);
	}

	return ss.str();
}

int lib::cstrcmp(const std::string &string1, const std::string &string2)
{
	return strcmp(stolower(string1).c_str(), stolower(string2).c_str());
}

bool isany(const char letter, const std::string &vect)
{
	for (auto l : vect)
	{
		if (letter == l)
		{
			return true;
		}
	}
	return false;
}

bool lib::isany(const std::string &word, const std::string &vect)
{
	for (const auto &wl : word)
	{
		for (const auto &vl : vect)
		{
			if (wl == vl)
			{
				return true;
			}
		}
	}
	return false;
}

size_t lib::chartcount(const std::string &string)
{
	size_t count = string.length();
	for (unsigned char cc : string)
	{
		if (cc == 195 || cc == 194)
		{
			count -= 1;
		}
	}
	return count;
}

Uint32 lib::getpixel(SDL_Surface *surface, int x, int y)
{
	int bpp = surface->format->BytesPerPixel;
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

	switch (bpp)
	{
	case 1:
		return *p;
	case 2:
		return *(Uint16 *)p;
	case 3:
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
		{
			return p[0] << 16 | p[1] << 8 | p[2];
		}
		else
		{
			return p[0] | p[1] << 8 | p[2] << 16;
		}
	case 4:
		return *(Uint32 *)p;
	default:
		return 0;
	}
}

void lib::replaceAll(std::string &str, const std::string &from, const std::string &to)
{
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
}

void lib::replaceWhole(std::string &str, const std::string &from, const std::string &to)
{
	std::istringstream iss(str);
	std::ostringstream oss;

	std::string word;
	while (!iss.eof())
	{
		iss >> word;
		if (word == from)
		{
			oss << to;
		}
		else
		{
			oss << word;
		}
		if (!iss.eof())
		{
			char c;
			while ((c = iss.get()) == ' ')
				oss << " ";
			iss.unget();
		}
	}
	str = oss.str();
}

void lib::remove_trailling(std::string &number)
{
	size_t dot = number.find('.');
	if (dot != std::string::npos)
	{
		number = number.substr(0, number.find_last_not_of('0') + 1);
		if (number.find('.') == number.size() - 1)
		{
			number = number.substr(0, number.size() - 1);
		}
	}
}

bool lib::chkdir(const std::string &path)
{
	struct stat info;

	if (stat(path.c_str(), &info) != 0)
	{
		return false;
	}
	else if (info.st_mode & S_IFDIR)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double lib::logb(double base, double x)
{
	return log(x) / log(base);
}
size_t lib::matchParentesis(const std::string &expression, size_t pos)
{
	char c;
	short other = 0;
	size_t i = pos;
	while (i < expression.length())
	{
		c = expression[i];
		if (c == '(')
		{
			other++;
		}
		else if (c == ')')
		{
			if (other == 1)
				break;
			other--;
		}
		i++;
	}

	return i;
}

double lib::deg(double x)
{
	return x * (180 / 3.14159265359);
}