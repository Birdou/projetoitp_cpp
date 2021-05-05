
#ifndef COMPRESS_HPP
#define COMPRESS_HPP

#include <string>
#include <sstream>

#include "ppm.hpp"

std::string comp (const std::string& fin, const std::string& fout)
{
	paintit::ppm imagem(0, 0, nullptr);
	bool isc = false;
	int magic, magicc, c, color;
	size_t h, w;
	char P;
	
	std::fstream in, out;
	in.open (fin, std::ios_base::in);
	out.open(fout, std::ios_base::out);

	if (!in.is_open())
		return inexistent_file_exception;

	in >> P >> magic;
	in >> w >> h;

	
	std::string line;
	getline(in, line);
	std::stringstream ss(line);
	ss >> color;

	if(in.failbit)
	{
		in.close();
		out.close();
		return invalid_format_exception;
	}

	ss >> magicc;
	if(ss.failbit)
	{
		isc = false;
	}
	else
	{
		isc = true;
	}

	if (!isc && (magic == 3 || magic == 6))
	{
		in.close();

		out << "P6\r";
		out << imagem.getWidth() << " " << imagem.getHeight() << "\r";
		out << "255 " << magic << "\r";

		imagem.open(fin);

		int tmp, rgb;

		c = 0;
		tmp = imagem[0][0].getR();
		for (size_t i = 0; i < imagem.getHeight(); i++)
		{
			for (size_t j = 0; j < imagem.getWidth(); j++)
			{
				rgb = imagem[i][j].getR();
				if (tmp == rgb && c < 255 && (i != imagem.getHeight() - 1 || j != imagem.getWidth() - 1))
				{
					c++;
				}
				else
				{
					out << static_cast<unsigned char>(c) << static_cast<unsigned char>(tmp);
					c = 1;
				}
				tmp = rgb;
			}
		}

		c = 0;
		tmp = imagem[0][0].getG();
		for (size_t i = 0; i < imagem.getHeight(); i++)
		{
			for (size_t j = 0; j < imagem.getWidth(); j++)
			{
				rgb = imagem[i][j].getG();
				if (tmp == rgb && c < 255 && (i != imagem.getHeight() - 1 || j != imagem.getWidth() - 1))
				{
					c++;
				}
				else
				{
					out << static_cast<unsigned char>(c) << static_cast<unsigned char>(tmp);
					c = 1;
				}
				tmp = rgb;
			}
		}

		c = 0;
		tmp = imagem[0][0].getB();
		for (size_t i = 0; i < imagem.getHeight(); i++)
		{
			for (size_t j = 0; j < imagem.getWidth(); j++)
			{
				rgb = imagem[i][j].getB();
				if (tmp == rgb && c < 255 && (i != imagem.getHeight() - 1 || j != imagem.getWidth() - 1))
				{
					c++;
				}
				else
				{
					out << static_cast<unsigned char>(c) << static_cast<unsigned char>(tmp);
					c = 1;
				}
				tmp = rgb;
			}
		}

		out.close();
	}
	else if (isc && (magicc == 3 || magicc == 6))
	{
		out.close();

		return_iferror(imagem.image(imagem.getWidth(), imagem.getHeight()));

		unsigned char cq, crgb;

		cq = '\0'; c = 0;
		for (size_t i = 0; i < imagem.getHeight(); i++)
		{
			for (size_t j = 0; j < imagem.getWidth(); j++)
			{
				if(c >= cq && (i != imagem.getHeight() - 1 || j != imagem.getWidth() - 1))
				{
					in >> cq >> crgb;
					c = 0;
				}
				imagem[i][j].setR(crgb);
				c++;
			}
		}

		cq = '\0'; c = 0;
		for (size_t i = 0; i < imagem.getHeight(); i++)
		{
			for (size_t j = 0; j < imagem.getWidth(); j++)
			{
				if(c >= cq && (i != imagem.getHeight() - 1 || j != imagem.getWidth() - 1))
				{
					in >> cq >> crgb;
					c = 0;
				}
				imagem[i][j].setG(crgb);
				c++;
			}
		}

		cq = '\0'; c = 0;
		for (size_t i = 0; i < imagem.getHeight(); i++)
		{
			for (size_t j = 0; j < imagem.getWidth(); j++)
			{
				if(c >= cq && (i != imagem.getHeight() - 1 || j != imagem.getWidth() - 1))
				{
					in >> cq >> crgb;
					c = 0;
				}
				imagem[i][j].setB(crgb);
				c++;
			}
		}
		in.close();

		return_iferror(imagem.save(magicc, fout));
	}
	else
	{
		in.close();
		out.close();
		return invalid_format_exception;
	}
	return noerror;
}

#endif
