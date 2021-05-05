
#include "processing.hpp"

std::string paintit::processing::grayscale(paintit::ppm& image) 
{
	if(!image.hasInitialized()) 
		return uninitialized_image_exception;

	for(size_t i = 0; i < image.getWidth(); ++i) 
	{
		for(size_t j = 0; j < image.getHeight(); ++j) 
		{
			image[i][j] = image[i][j].bw();
		}
	}
	
	return noerror;
}

std::string paintit::processing::sepia(paintit::ppm& image)
{
	if(!image.hasInitialized()) 
		return uninitialized_image_exception;

	for(size_t i = 0; i < image.getWidth(); ++i) 
	{
		for(size_t j = 0; j < image.getHeight(); ++j) 
		{
			image[i][j] = image[i][j].antigue();
		}
	}
	
	return noerror;
}

std::string paintit::processing::brighten(paintit::ppm& image, double scale) 
{
	if(!image.hasInitialized()) 
		return uninitialized_image_exception;

	int value = 255 *(scale / 100);
	for(size_t i = 0; i < image.getWidth(); ++i) 
	{
		for(size_t j = 0; j < image.getHeight(); ++j) 
		{
			image[i][j] = image[i][j] + value;
		}
	}
	
	return noerror;
}

std::string paintit::processing::darken(paintit::ppm& image, double scale) 
{
	if(!image.hasInitialized()) 
		return uninitialized_image_exception;

	int value = 255 *(scale / 100);
	for(size_t i = 0; i < image.getWidth(); ++i) 
	{
		for(size_t j = 0; j < image.getHeight(); ++j) 
		{
			image[i][j] = image[i][j] - value;
		}
	}
	
	return noerror;
}

std::string paintit::processing::negative(paintit::ppm& image)
{
	if(!image.hasInitialized()) 
		return uninitialized_image_exception;

	for(size_t i = 0; i < image.getWidth(); ++i) 
	{
		for(size_t j = 0; j < image.getHeight(); ++j) 
		{
			image[i][j] = paintit::rgb(255 - image[i][j].getR(), 255 - image[i][j].getG(), 255 - image[i][j].getB());
		}
	}
	
	return noerror;
}

std::string paintit::processing::intensity(paintit::ppm& image, double red, double green, double blue) 
{
	if(!image.hasInitialized()) 
		return uninitialized_image_exception;

	for(size_t i = 0; i < image.getWidth(); ++i) 
	{
		for(size_t j = 0; j < image.getHeight(); ++j) 
		{
			image[i][j] = image[i][j] + paintit::rgb(image[i][j].getR() *(red / 100), image[i][j].getG() *(green / 100), image[i][j].getB() *(blue / 100));
		}
	}
	
	return noerror;
}

std::string paintit::processing::redequal(paintit::ppm& image, double red, double green, double blue) 
{
	if(!image.hasInitialized()) 
		return uninitialized_image_exception;

	for(size_t i = 0; i < image.getWidth(); ++i) 
	{
		for(size_t j = 0; j < image.getHeight(); ++j) 
		{
			image[i][j] = image[i][j] + paintit::rgb(image[i][j].getR() *(red / 100), image[i][j].getR() *(green / 100), image[i][j].getR() *(blue / 100));
		}
	}
	
	return noerror;
}

std::string paintit::processing::greenequal(paintit::ppm& image, double red, double green, double blue) 
{
	if(!image.hasInitialized()) 
		return uninitialized_image_exception;

	for(size_t i = 0; i < image.getWidth(); ++i) 
	{
		for(size_t j = 0; j < image.getHeight(); ++j) 
		{
			image[i][j] = image[i][j] + paintit::rgb(image[i][j].getG() *(red / 100), image[i][j].getG() *(green / 100), image[i][j].getG() *(blue / 100));
		}
	}
	
	return noerror;
}

std::string paintit::processing::blueequal(paintit::ppm& image, double red, double green, double blue) 
{
	if(!image.hasInitialized()) 
		return uninitialized_image_exception;

	for(size_t i = 0; i < image.getWidth(); ++i) 
	{
		for(size_t j = 0; j < image.getHeight(); ++j) 
		{
			image[i][j] = image[i][j], paintit::rgb(image[i][j].getB() *(red / 100), image[i][j].getB() *(green / 100), image[i][j].getB() *(blue / 100));
		}
	}
	
	return noerror;
}

std::string paintit::processing::vibrancy(paintit::ppm& image, double scale) 
{
	if(!image.hasInitialized()) 
		return uninitialized_image_exception;

	double value = 1 +(scale / 100);
	for(size_t i = 0; i < image.getWidth(); ++i) 
	{
		for(size_t j = 0; j < image.getHeight(); ++j) 
		{
			image[i][j] = image[i][j] * value;
		}
	}

	return noerror;	
}

std::string paintit::processing::glitch(paintit::ppm& image, int scale, double angle) 
{
	if(!image.hasInitialized()) 
		return uninitialized_image_exception;

	ppm prevbitmap(image);

	int xr = - scale * sin(lib::rad(angle)) , yr = scale * cos(lib::rad(angle));
	for(size_t i = 0; i < image.getWidth(); ++i) 
	{
		for(size_t j = 0; j < image.getHeight(); ++j) 
		{
			paintit::coord p(i + xr, j + yr);
			paintit::coord m(i - xr, j - yr);
			if(p.x < static_cast<ssize_t>(image.getWidth()) && p.y < static_cast<ssize_t>(image.getHeight()) && p.x >= 0 && p.y >= 0)
			{
				image[i][j].setR(prevbitmap[p.x][p.y].getR());
			}
			if(m.x < static_cast<ssize_t>(image.getWidth()) && m.y < static_cast<ssize_t>(image.getHeight()) && m.x >= 0 && m.y >= 0) 
			{
				image[i][j].setB(prevbitmap[m.x][m.y].getB());
			}
		}
	}

	return noerror;
}

std::string paintit::processing::rbglitch(paintit::ppm& image, int scale, double angle) 
{
	if(!image.hasInitialized()) 
		return uninitialized_image_exception;

	return_iferror(grayscale(image));
	return_iferror(glitch(image, scale, angle));

	return noerror;
}

std::string paintit::processing::desaturate(paintit::ppm& image, double r, double g, double b) 
{
	if(!image.hasInitialized()) 
		return uninitialized_image_exception;

	int rtol = 255 - (255 * r / 100) , gtol = 255 - (255 * g / 100) , btol = 255 - (255 * b / 100);
	for(size_t i = 0; i < image.getWidth(); ++i) 
	{
		for(size_t j = 0; j < image.getHeight(); ++j) 
		{
			if(image[i][j].getR() > rtol &&(image[i][j].getR() >= image[i][j].getG() && image[i][j].getR() >= image[i][j].getB())) 
				image[i][j] = image[i][j].bw();
			if(image[i][j].getG() > gtol &&(image[i][j].getG() >= image[i][j].getB() && image[i][j].getG() >= image[i][j].getR())) 
				image[i][j] = image[i][j].bw();
			if(image[i][j].getB() > btol &&(image[i][j].getB() >= image[i][j].getR() && image[i][j].getB() >= image[i][j].getG())) 
				image[i][j] = image[i][j].bw();
		}
	}

	return noerror;
}

std::string paintit::processing::pixelize(paintit::ppm& image, int px)
{
	if(!image.hasInitialized()) 
		return uninitialized_image_exception;
	if(px < 1) 
		return invalid_argument_exception;

	ppm resized;
	resized.image(image.getWidth() % px == 0 ? image.getWidth() / px :(image.getWidth() / px) + 1, 
		image.getHeight() % px == 0 ? image.getHeight() / px :(image.getHeight() / px) + 1);

	for(size_t i = 0; i < image.getWidth(); i+=px)
	{
		for(size_t j = 0; j < image.getHeight(); j+=px)
		{
			paintit::rgb color = paintit::rgb(0, 0, 0);
			int pix = 0;
			for(int k = 0; k < px; ++k)
			{
				for(int l = 0; l < px; ++l)
				{
					if(k + i < image.getWidth() && l + j < image.getHeight())
					{
						color = color + image[k + i][l + j];
						pix++;
					}
				}
			}
			color = color / pix;
			resized[i/px][j/px] = color;
		}
	}
	image = resized;

	return noerror;
}

std::string paintit::processing::guev(paintit::ppm& image, double scale)
{
	int lim = 255 *(scale / 100);
	for(size_t i = 0; i < image.getWidth(); ++i)
	{
		for(size_t j = 0; j < image.getHeight(); ++j)
		{
			if((image[i][j].getR() + image[i][j].getG() + image[i][j].getB()) / 3 > lim)
			{
				image[i][j] = paintit::rgb(255, 255, 255);
			}
			else
			{
				image[i][j] = paintit::rgb(0, 0, 0);
			}
		}
	}

	return noerror;
}
