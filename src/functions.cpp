
#include "functions.hpp"

std::string paintit::functions::draw(paintit::ppm& image, const penc& pincel, ssize_t PX, ssize_t PY) noexcept
{
	double area = (pincel.getSize() - 1) / 2;
	for(ssize_t i = PX - area; i <= PX + area; ++i)
	{
		for(ssize_t j = PY - area; j <= PY + area; ++j)
		{
			if(i >= 0 && j >= 0)
			{
				if(i < static_cast<ssize_t>(image.getWidth()) && j < static_cast<ssize_t>(image.getHeight()))
				{
					pincel.touch(image[i][j]);
				}
			}
		}
	}
	return noerror;
}

std::string paintit::functions::sclear(paintit::ppm& image, const std::string& colorname) 
{
	if(!image.hasInitialized())
		return uninitialized_image_exception;

	paintit::rgb newcolor;
	newcolor.getrgbval(colorname);

	for(size_t i = 0; i < image.getWidth(); ++i)
	{
		for(size_t j = 0; j < image.getHeight(); ++j) 
		{
			image[i][j] = newcolor;
		}
	}

	return noerror;
}

std::string paintit::functions::curve(paintit::ppm& image, const penc& pincel, const std::vector<coord>& pontos) 
{
	if(!image.hasInitialized())
		return uninitialized_image_exception;

	int n = pontos.size() - 1;
	for(float t = 0; t <= 1; t += 0.0001) 
	{
		float x = 0, y = 0;
		for(int i = 0; i <= n; ++i) 
		{
			x += lib::bin(n, i) * pow(1 - t, n - i) * pow(t, i) * pontos[i].x;
			y += lib::bin(n, i) * pow(1 - t, n - i) * pow(t, i) * pontos[i].y;
		}
		draw(image, pincel, static_cast<int>(x), static_cast<int>(y));
	}

	return noerror;
}

std::string paintit::functions::elipse(paintit::ppm& image, const penc& pincel, const coord& pos, size_t width, size_t height, double angle, int p) 
{
	if(!image.hasInitialized())
		return uninitialized_image_exception;

	if(width < 1 || height < 1)
		return invalid_argument_exception;

	double tol = width >= height ?(width / height) * 0.00999 :(height / width) * 0.00999;
	double quadh = pow(height / 2, 2) , quadw = pow(width / 2, 2);
	for(size_t i = pos.x - width; i <= pos.x + width; ++i) 
	{
		for(size_t j = pos.y - height; j <= pos.y + height; ++j) 
		{
			double posx = pow(i - pos.x, 2);
			double posy = pow(j - pos.y, 2);
			double raz = (posx / quadh) + (posy / quadw);
			int x = i - pos.x, y = j - pos.y;
			int xr =(x * cos(lib::rad(angle) ) ) -(y * sin(lib::rad(angle) ) ), yr =(x * sin(lib::rad(angle) ) ) +(y * cos(lib::rad(angle) ) );
			if(p == 0)
			{
				if(raz >= 1 - tol && raz <= 1 + tol)
				{
					draw(image, pincel, xr + pos.x, yr + pos.y);
				}
			}
			else
			{
				if(raz <= 1)
				{
					draw(image, pincel, xr + pos.x, yr + pos.y);
				}
			}
		}
	}

	return noerror;
}

std::string paintit::functions::global(paintit::ppm& image, const penc& pincel, const coord& pos)
{
	if(!image.hasInitialized())
		return uninitialized_image_exception;

	paintit::rgb cor = image[pos.x][pos.y];
	for(size_t i = 0; i < image.getWidth(); ++i)
	{
		for(size_t j = 0; j < image.getHeight(); ++j)
		{
			if(image[i][j] == cor)
			{
				pincel.touch(image[i][j]);
			}
		}
	}

	return noerror;
}

std::string paintit::functions::linehigh(paintit::ppm& image, const penc& pincel, const coord& P1, const coord& P2)
{
	int dx = P2.x - P1.x, dy = P2.y - P1.y;
	
	int xi = 1;
	
	if(dx < 0)
	{
		xi = -1;
		dx = -dx;
	}

	int D = (2 * dx) - dy;
	int x = P1.x;

	for(ssize_t y = P1.y; y < P2.y; ++y)
	{
		draw(image, pincel, x, y);
		if(D > 0)
		{
			x += xi;
			D += 2 * (dx - dy);
		}
		else
		{
			D += 2 * dx;
		}
	}
	return noerror;
}
std::string paintit::functions::linelow(paintit::ppm& image, const penc& pincel, const coord& P1, const coord& P2)
{
	int dx = P2.x - P1.x, dy = P2.y - P1.y;
	
	int yi = 1;

	if(dy < 0)
	{
		yi = -1;
		dy = -dy;
	}

	int D = (2 * dy) - dx;
	int y = P1.y;

	for(ssize_t x = P1.x; x < P2.x; ++x)
	{
		draw(image, pincel, x, y);
		if(D > 0)
		{
			y += yi;
			D += 2 * (dy - dx);
		}
		else
		{
			D += 2 * dy;
		}
	}
	return noerror;
}
std::string paintit::functions::line(paintit::ppm& image, const penc& pincel, const coord& P1, const coord& P2)
{
	if(!image.hasInitialized())
		return uninitialized_image_exception;

	if(abs(P2.y - P1.y) < abs(P2.x - P1.x))
	{
		if(P1.x > P2.x)
		{
			linelow(image, pincel, P2, P1);
		}
		else
		{
			linelow(image, pincel, P1, P2);
		}
	}
	else
	{
		if(P1.y > P2.y)
		{
			linehigh(image, pincel, P2, P1);
		}
		else
		{
			linehigh(image, pincel, P1, P2);
		}   
	}

	return noerror;
}

std::string paintit::functions::polygon(paintit::ppm& image, const penc& pincel, const std::vector<coord>& pontos)
{
	if(!image.hasInitialized())
		return uninitialized_image_exception;

	for(size_t i = 1; i < pontos.size(); ++i)
	{
		line(image, pincel, pontos[i - 1], pontos[i]);
	}
	line(image, pincel, pontos[pontos.size() - 1], pontos[0]);

	return noerror;
}

std::string paintit::functions::rect(paintit::ppm& image, const penc& pincel, const coord& pos, int width, int height)
{
	if(!image.hasInitialized())
		return uninitialized_image_exception;

	std::vector<coord> pontos;
	pontos.emplace_back(coord(pos.x - (height / 2), pos.y - (width / 2)));
	pontos.emplace_back(coord(pos.x - (height / 2), pos.y + (width / 2)));
	pontos.emplace_back(coord(pos.x + (height / 2), pos.y + (width / 2)));
	pontos.emplace_back(coord(pos.x + (height / 2), pos.y - (width / 2)));
	
	polygon(image, pincel, pontos);

	return noerror;
}

std::string paintit::functions::circle(paintit::ppm& image, const penc& pincel, const coord& pos, int raio, int p)
{
	if(!image.hasInitialized())
		return uninitialized_image_exception;

	for(int y = -raio; y <= raio; ++y)
	{
		for(int x = -raio; x <= raio; ++x)
		{
			if(p > 1)
			{
				if(round(sqrt(pow(x, 2) + pow(y, 2))) <= raio)
				{
					draw(image, pincel, pos.x+x, pos.y+y);
				}
			}
			else
			{
				if(round(sqrt(pow(x, 2) + pow(y, 2))) == raio)
				{
					draw(image, pincel, pos.x + x, pos.y + y);
				}
			}
		}
	}

	return noerror;
}

std::string paintit::functions::fill(paintit::ppm& image, const penc& pincel, const coord& pos)
{
	if(!image.hasInitialized())
		return uninitialized_image_exception;

	if(pos.x < static_cast<ssize_t>(image.getWidth()) && pos.y < static_cast<ssize_t>(image.getHeight()))
	{
		paintit::rgb cor = image[pos.x][pos.y];
		coord* map = nullptr;
		size_t current_x, current_y, cont = 1;

		map = new coord[image.getHeight() * image.getWidth()];

		if(map == nullptr)
			return insufficient_memory_exception;

		map[0] = pos;
		pincel.touch(image[map[0].x][map[0].y]);
		for(size_t pixel = 0; pixel < cont; ++pixel)
		{
			current_x = map[pixel].x;
			current_y = map[pixel].y;

			if(current_x - 1 < image.getWidth() && current_y < image.getHeight())
			{
				if(image[current_x - 1][current_y] == cor && image[current_x - 1][current_y] != pincel.getColor())
				{
					map[cont] = coord(current_x - 1, current_y);
					pincel.touch(image[current_x - 1][current_y]);
					cont++;
				}
			}
			if(current_x + 1 < image.getWidth() && current_y < image.getHeight())
			{
				if(image[current_x + 1][current_y] == cor && image[current_x + 1][current_y] != pincel.getColor())
				{
					map[cont] = coord(current_x + 1, current_y);
					pincel.touch(image[current_x + 1][current_y]);
					cont++;
				}
			}
			if(current_x < image.getWidth() && current_y - 1 < image.getHeight())
			{
				if(image[current_x][current_y - 1] == cor && image[current_x][current_y - 1] != pincel.getColor())
				{
					map[cont] = coord(current_x, current_y - 1);
					pincel.touch(image[current_x][current_y - 1]);
					cont++;
				}
			}
			if(current_x < image.getWidth() && current_y + 1 < image.getHeight())
			{
				if(image[current_x][current_y + 1] == cor && image[current_x][current_y + 1] != pincel.getColor())
				{
					map[cont] = coord(current_x, current_y + 1);
					pincel.touch(image[current_x][current_y + 1]);
					cont++;
				}
			}
		}
		delete[] map;
	}

	return noerror;
}

std::string paintit::functions::crop(paintit::ppm& image, const paintit::coord& P1, const paintit::coord& P2)
{
	if(!image.hasInitialized())
		return uninitialized_image_exception;

	paintit::ppm cropped_image;
	size_t width = P2.x - P1.x;
	size_t height= P2.y - P1.y;
	cropped_image.image(width, height);
	for(size_t i = 0; i < width; ++i)
	{
		size_t targetX = i + P1.x;
		for(size_t j = 0; j < height; ++j)
		{
			size_t targetY = j + P1.y;
			if(targetX < image.getWidth() || targetY < image.getHeight())
				cropped_image[i][j] = image[i + P1.x][j + P1.y];
		}
	}
	image = cropped_image;

	return noerror;
}