
#ifndef PAINTIT_PPM_H
#define PAINTIT_PPM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <cstddef>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include <exception>

#include "pencil.hpp"
#include "color.hpp"

namespace paintit
{
	class ppm
	{
	private:
		size_t width = 0;
		size_t height = 0;
		paintit::rgb** color = nullptr;

		bool isReady = true;

		struct bad_access_exception : std::exception
		{
			const char* what() const noexcept
			{
				return "Tentativa de acesso a um índice fora do intervalo da matriz.";
			}
		};

	public:
		ppm();
		ppm(size_t width, size_t height, paintit::rgb** color);
		ppm(size_t width, size_t height);
		ppm(const ppm&);
		~ppm();

		size_t getWidth() const;
		void setWidth(size_t width);

		size_t getHeight() const;
		void setHeight(size_t height);

		bool hasInitialized() const;
		bool ready() const;

		paintit::rgb* operator[](size_t column);
		paintit::rgb& operator()(size_t x, size_t y);
		
		SDL_Surface* to_surface();

		ppm& operator=(const ppm& image);
		bool operator==(const ppm& image);
		bool operator!=(const ppm& image);

		/*** IO operations, memory allocation, image management. ***/
		/**
		 * @brief Aloca a memória necessária para uma instância de imagem com as devidas especificações (largura e altura).
		 * 
		 * @param width Largura da imagem.
		 * @param height Altura da imagem.
		 * @return Retorna uma mensagem de erro. Caso seja executada sem erros, retorna uma string vazia.
		 */
		std::string image(size_t width, size_t height);
		std::string open(const std::string& file_path);
		std::string save(const std::string& file_extension, const std::string& file_path);
		std::string clear(const paintit::rgb& color);
		std::string rotate();
		std::string invert();
		std::string erase();
		/***********************************************************/

		//Specific input operations.

		std::string openP3(const std::string& file_path);
		std::string openP6(const std::string& file_path);
		std::string openOther(const std::string& file_path);
		
		//Specific output operations.
		
		std::string saveP3(const std::string& filename);
		std::string saveP6(const std::string& filename);
		std::string saveJpg(const std::string& filename);
		std::string savePng(const std::string& filename);
		std::string saveBmp(const std::string& filename);
	};
}

#endif
