
#include "ppm.hpp"

#include <cstdlib>

#include "viewer.hpp"

paintit::ppm::ppm()
{}

paintit::ppm::ppm(size_t width, size_t height, paintit::rgb** color):
width(width), height(height), color(color)
{
}

paintit::ppm::ppm(size_t width, size_t height)
{
	this->image(width, height);
}

paintit::ppm::ppm(const ppm& image)
{
	this->image(image.width, image.height);

	for(size_t i = 0; i < this->width; ++i) 
	{
		for(size_t j = 0; j < this->height; ++j) 
		{
			this->color[i][j] = image.color[i][j];
		}
	}
}

paintit::ppm::~ppm()
{
	DebugMessage("erasing...");
	erase();
}

size_t paintit::ppm::getWidth() const
{
	return this->width;
}

void paintit::ppm::setWidth(size_t width)
{
	this->width = width;
}

size_t paintit::ppm::getHeight() const
{
	return this->height;
}
void paintit::ppm::setHeight(size_t height)
{
	this->height = height;
}

bool paintit::ppm::hasInitialized() const
{
	return this->color != nullptr;
}

bool paintit::ppm::ready() const
{
	return (this->color != nullptr) && isReady;
}

paintit::rgb* paintit::ppm::getColor(size_t x, size_t y)
{
	if(!ready() || !hasInitialized())
		return nullptr;
	return &this->color[x][y];
}

paintit::rgb* paintit::ppm::operator[](size_t line)
{
	return this->color[line];
}

paintit::rgb& paintit::ppm::operator()(size_t x, size_t y)
{
	if(x > width || y > height)
	{
		throw bad_access_exception();
	}
	return this->color[x][y];
}

paintit::ppm& paintit::ppm::operator=(const ppm& image)
{
	this->image(image.width, image.height);

	for(size_t i = 0; i < this->width; ++i) 
	{
		for(size_t j = 0; j < this->height; ++j) 
		{
			this->color[i][j] = image.color[i][j];
		}
	}

	return *this;
}

bool paintit::ppm::operator==(const ppm& image)
{
	if(this->height != image.height || this->width != image.width)
	{
		return false;
	}

	for(size_t i = 0; i < this->width; ++i)
	{
		for(size_t j = 0; j < this->height; ++j)
		{
			if(this->color[i][j] != image.color[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

bool paintit::ppm::operator!=(const ppm& image)
{
	if(this->height != image.height || this->width != image.width)
	{
		return true;
	}

	for(size_t i = 0; i < this->width; ++i)
	{
		for(size_t j = 0; j < this->height; ++j)
		{
			if(this->color[i][j] != image.color[i][j])
			{
				return true;
			}
		}
	}
	return false;
}

std::string paintit::ppm::image(size_t width, size_t height)
{
	isReady = false;

	this->erase();

	if(height == 0 || width == 0)
	{
		return noerror;
	}

	this->width = width;
	this->height = height;

	this->color = new (std::nothrow) paintit::rgb*[width];
	if(!this->color)
	{
		DebugWarning("couldn't allocate image in memory.");
		return insufficient_memory_exception;
	}
	for(size_t i = 0; i < width; ++i)
	{
		this->color[i] = new (std::nothrow) paintit::rgb[height];
		if(!this->color[i])
		{
			DebugWarning("couldn't allocate image in memory.");
			DebugLog("freeing memory...");
			for(size_t ii = 0; ii < i; ++ii)
			{
				delete[] this->color[ii];
			}
			delete[] this->color;

			this->width = 0;
			this->height = 0;
			this->color = nullptr;

			return insufficient_memory_exception;
		}
	}

	isReady = true;

	return noerror;
}

std::string paintit::ppm::clear(const paintit::rgb& newcolor)
{
	if(this->color == nullptr)
		return uninitialized_image_exception;

	for(size_t i = 0; i < this->width; ++i)
	{
		for(size_t j = 0; j < this->height; ++j)
		{
			this->color[i][j] = newcolor;
		}
	}

	return noerror;
}

std::string paintit::ppm::saveP3(const std::string& arquivo)
{
	std::ofstream save;
	save.open(arquivo);
	save << "P3\r";
	save << this->width << " " << this->height << "\r";
	save << "255\r";

	for(size_t j = 0; j < this->height; ++j) //o laço superior é relacionado à altura devido a ordem de gravação.
	{
		for(size_t i = 0; i < this->width; ++i)
		{
			save <<
				std::setfill('0') << std::setw(3) << this->color[i][j].getR() << " " << 
				std::setfill('0') << std::setw(3) << this->color[i][j].getG() << " " << 
				std::setfill('0') << std::setw(3) << this->color[i][j].getB() << "\r";
		}
	}
	save.close();

	return noerror;
}
std::string paintit::ppm::saveP6(const std::string& arquivo)
{
	std::ofstream save;
	save.open(arquivo, std::ios_base::binary);
	save << "P6\r";
	save << this->width << " " << this->height << "\r";
	save << "255\r";
	for(size_t j = 0; j < this->height; ++j) //o laço superior é relacionado à altura devido a ordem de gravação.
	{
		for(size_t i = 0; i < this->width; ++i)
		{
			save << (unsigned char)this->color[i][j].getR() << (unsigned char)this->color[i][j].getG() << (unsigned char)this->color[i][j].getB();
		}
	}
	save.close();

	return noerror;
}

SDL_Surface* paintit::ppm::to_surface()
{
	SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 64, SDL_PIXELFORMAT_ARGB8888);

	if (surface == NULL)
	{
		std::cout << "SDL_CreateRGBSurfaceWithFormat() failed: " << SDL_GetError() << std::endl;
		return nullptr;
	}	

	SDL_LockSurface(surface);
	Uint8* pixels = (Uint8*)surface->pixels;
	for(size_t i = 0; i < width; ++i)
	{
		for(size_t j = 0; j < height; ++j)
		{
			int target = (j * surface->pitch) + (i * surface->format->BytesPerPixel);
			pixels[target + 2] = this->color[i][j].getR(); //BGRA nesta ordem, ou seja: 2103 <=> RGBA
			pixels[target + 1] = this->color[i][j].getG();
			pixels[target + 0] = this->color[i][j].getB();
			pixels[target + 3] = 255;
		}
	}
	SDL_UnlockSurface(surface);

	return surface;
}

std::string paintit::ppm::saveJpg(const std::string& arquivo)
{
	SDL_Surface* surface = this->to_surface();
	IMG_SaveJPG(surface, arquivo.c_str(), 100);
	SDL_FreeSurface(surface);

	return strcmp(SDL_GetError(), "") != 0 ? SDL_GetError() : noerror; 
}

std::string paintit::ppm::savePng(const std::string& arquivo)
{
	SDL_Surface* surface = this->to_surface();
	IMG_SavePNG(surface, arquivo.c_str());
	SDL_FreeSurface(surface);

	return strcmp(SDL_GetError(), "") != 0 ? SDL_GetError() : noerror; 
}
std::string paintit::ppm::saveBmp(const std::string& arquivo)
{
	SDL_Surface* surface = this->to_surface();
	SDL_SaveBMP(surface, arquivo.c_str());
	SDL_FreeSurface(surface);

	return strcmp(SDL_GetError(), "") != 0 ? SDL_GetError() : noerror; 
}

std::string paintit::ppm::save(const char* format, const char* arquivo)
{
	if(this->color == nullptr)
		return uninitialized_image_exception;

	if(lib::cstrcmp(format, "p3") == 0)
	{
		return saveP3(arquivo);
	}
	else if(lib::cstrcmp(format, "p6") == 0)
	{
		return saveP6(arquivo);
	}
	else if(lib::cstrcmp(format, "jpg") == 0)
	{
		return saveJpg(arquivo);
	}
	else if(lib::cstrcmp(format, "png") == 0)
	{
		return savePng(arquivo);
	}
	else if(lib::cstrcmp(format, "bmp") == 0)
	{
		return saveBmp(arquivo);
	}

	return invalid_format_exception;
}

std::string paintit::ppm::openP3(const char* arquivo)
{
	std::ifstream file;
	file.open(arquivo);

	if(!file.is_open())
	{
		return inexistent_file_exception;
	}
	int colors, magic;
	char P;

	file >> P >> magic;
	file >> this->width >> this->height;
	file >> colors;

	file.ignore();

	if(file.failbit || magic != 3)
	{
		file.close();
		return invalid_format_exception;
	}
	else if(colors != 255)
	{
		file.close();
		return non_24bit_exception;
	}

	this->image(this->width, this->height);

	for(size_t i = 0; i < this->width; ++i)
	{
		for(size_t j = 0; j < this->height; ++j)
		{
			short r = 0, g = 0, b = 0;

			file >> r >> g >> b;
			this->color[i][j] = paintit::rgb(r, g, b);

			if(file.failbit)
			{
				file.close();
				return missing_pixels_warning;
			}
		}
	}
	file.close();

	return noerror;
}

std::string paintit::ppm::openP6(const char* arquivo)
{
	std::fstream file;
	file.open(arquivo, std::ios_base::in);

	if(!file.is_open())
	{
		return inexistent_file_exception;
	}
	int colors, magic;
	char P;

	file >> P >> magic;
	file >> this->width >> this->height;
	file >> colors;

	file.ignore();

	if(file.failbit || magic != 6)
	{
		file.close();
		return invalid_format_exception;
	}
	else if(colors != 255)
	{
		file.close();
		return non_24bit_exception;
	}

	this->image(this->width, this->height);

	for(size_t i = 0; i < this->width; ++i)
	{
		for(size_t j = 0; j < this->height; ++j)
		{
			unsigned char r = 0, g = 0, b = 0;

			file >> r >> g >> b;
			this->color[i][j].setRGB(r, g, b);

			if(file.failbit)
			{
				file.close();
				return missing_pixels_warning;
			}
		}
	}
	file.close();

	return noerror;
}

std::string paintit::ppm::openOther(const char* arquivo)
{
	SDL_Surface* surface = IMG_Load(arquivo);
	if(surface == NULL)
	{
		DebugError("IMG_Load: " << SDL_GetError());
		return inexistent_file_exception;
	}

	this->image(surface->w, surface->h);

	Uint8 r, g, b;
	for(size_t i = 0; i < this->getWidth(); ++i)
	{
		for(size_t j = 0; j < this->getHeight(); ++j)
		{
			SDL_GetRGB(lib::getpixel(surface, i, j), surface->format, &r, &g, &b);
			(*this)[i][j].setRGB(r, g, b);
		}
	}

	SDL_FreeSurface(surface);

	return strcmp(SDL_GetError(), "") != 0 ? SDL_GetError() : noerror;
}

std::string paintit::ppm::open(const char* arquivo)
{
	std::string error;
	isReady = false;
	error = openP3(arquivo);
	if(error != invalid_format_exception)
	{
		return error;
	}
	error = openP6(arquivo);
	if(error != invalid_format_exception)
	{
		return error;
	}
	error = openOther(arquivo);
	if(error != noerror)
	{
		return error;
	}

	isReady = true;
	return noerror;
}

std::string paintit::ppm::erase()
{
	if(this->color == nullptr)
		return noerror;

	for(size_t i = 0; i < this->width; ++i)
	{
		delete[] this->color[i];
	}
	delete[] this->color;
	
	this->height = 0;
	this->width = 0;
	this->color = nullptr;

	return noerror;
}

std::string paintit::ppm::rotate() 
{
	if(this->color == nullptr)
		return uninitialized_image_exception;

	ppm rotationed_bitmap;
	rotationed_bitmap.image(this->height, this->width);
	for(size_t i = 0; i < this->width; ++i) 
	{
		for(size_t j = 0; j < this->height; ++j) 
		{
			rotationed_bitmap.color[this->height - j - 1][i] = this->color[i][j];
		}
	}
	*this = rotationed_bitmap;
	rotationed_bitmap.erase();

	return noerror;
}

std::string paintit::ppm::invert() 
{
	if(this->color == nullptr)
		return uninitialized_image_exception;

	for(size_t i = 0; i < (this->width - 1) / 2; ++i)
	{
		for(size_t j = 0; j <= this->height; ++j)
		{
			paintit::rgb tmp = this->color[i][j];
			this->color[i][j] = this->color[this->width - i - 1][j];
			this->color[this->width - i - 1][j] = tmp;
		}
	}

	return noerror;
}
