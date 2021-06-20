
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

namespace paintit
{
	/**
	 * @brief      This class describes a ppm.
	 */
	class ppm
	{
	private:
		size_t width = 0;
		size_t height = 0;
		paintit::rgb** color = nullptr;

		bool isReady = true;

		/**
		 * @brief      { struct_description }
		 */
		struct bad_access_exception : std::exception
		{
			const char* what() const noexcept
			{
				return "Tentativa de acesso a um índice fora do intervalo da matriz.";
			}
		};

	public:
		/**
		 * @brief      Constructs a new instance.
		 */
		ppm();
		/**
		 * @brief      Constructs a new instance.
		 *
		 * @param[in]  width   The width
		 * @param[in]  height  The height
		 * @param      color   The color
		 */
		ppm(size_t width, size_t height, paintit::rgb** color);
		/**
		 * @brief      Constructs a new instance.
		 *
		 * @param[in]  width   The width
		 * @param[in]  height  The height
		 */
		ppm(size_t width, size_t height);
		/**
		 * @brief      Constructs a new instance.
		 *
		 * @param[in]  <unnamed>  { parameter_description }
		 */
		ppm(const ppm&);
		/**
		 * @brief      Destroys the object.
		 */
		~ppm();

		/**
		 * @brief      Gets the width.
		 *
		 * @return     The width.
		 */
		size_t getWidth() const;
		/**
		 * @brief      Sets the width.
		 *
		 * @param[in]  width  The width
		 */
		void setWidth(size_t width);

		/**
		 * @brief      Gets the height.
		 *
		 * @return     The height.
		 */
		size_t getHeight() const;
		/**
		 * @brief      Sets the height.
		 *
		 * @param[in]  height  The height
		 */
		void setHeight(size_t height);

		/**
		 * @brief      Determines if initialized.
		 *
		 * @return     True if initialized, False otherwise.
		 */
		bool hasInitialized() const;
		/**
		 * @brief      { function_description }
		 *
		 * @return     { description_of_the_return_value }
		 */
		bool ready() const;

		/**
		 * @brief      Gets the color.
		 *
		 * @param[in]  x     { parameter_description }
		 * @param[in]  y     { parameter_description }
		 *
		 * @return     The color.
		 */
		paintit::rgb* getColor(size_t x, size_t y);

		/**
		 * @brief      Array indexer operator.
		 *
		 * @param[in]  column  The column
		 *
		 * @return     The result of the array indexer
		 */
		paintit::rgb* operator[](size_t column);
		/**
		 * @brief      Function call operator.
		 *
		 * @param[in]  x     { parameter_description }
		 * @param[in]  y     { parameter_description }
		 *
		 * @return     The result of the function call
		 */
		paintit::rgb& operator()(size_t x, size_t y);
		
		/**
		 * @brief      Returns a surface representation of the object.
		 *
		 * @return     Surface representation of the object.
		 */
		SDL_Surface* to_surface();

		/**
		 * @brief      Assignment operator.
		 *
		 * @param[in]  image  The image
		 *
		 * @return     The result of the assignment
		 */
		ppm& operator=(const ppm& image);
		/**
		 * @brief      Equality operator.
		 *
		 * @param[in]  image  The image
		 *
		 * @return     The result of the equality
		 */
		bool operator==(const ppm& image);
		/**
		 * @brief      Inequality operator.
		 *
		 * @param[in]  image  The image
		 *
		 * @return     The result of the inequality
		 */
		bool operator!=(const ppm& image);


		/**
		 * @brief      { function_description }
		 *
		 * @param[in]  width   The width
		 * @param[in]  height  The height
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string image(size_t width, size_t height);
		/**
		 * @brief      { function_description }
		 *
		 * @param[in]  file_path  The file path
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string open(const char* file_path);
		/**
		 * @brief      { function_description }
		 *
		 * @param[in]  file_extension  The file extension
		 * @param[in]  file_path       The file path
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string save(const char* file_extension, const char* file_path);
		/**
		 * @brief      Clears the given color.
		 *
		 * @param[in]  color  The color
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string clear(const paintit::rgb& color);
		/**
		 * @brief      { function_description }
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string rotate();
		/**
		 * @brief      { function_description }
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string invert();
		/**
		 * @brief      { function_description }
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string erase();
		/***********************************************************/

		//Specific input operations.

		/**
		 * @brief      Opens a p 3.
		 *
		 * @param[in]  file_path  The file path
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string openP3(const char* file_path);
		/**
		 * @brief      Opens a p 6.
		 *
		 * @param[in]  file_path  The file path
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string openP6(const char* file_path);
		/**
		 * @brief      Opens an other.
		 *
		 * @param[in]  file_path  The file path
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string openOther(const char* file_path);
		
		//Specific output operations.
		
		/**
		 * @brief      Saves a p 3.
		 *
		 * @param[in]  filename  The filename
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string saveP3(const std::string& filename);
		/**
		 * @brief      Saves a p 6.
		 *
		 * @param[in]  filename  The filename
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string saveP6(const std::string& filename);
		/**
		 * @brief      Saves a jpg.
		 *
		 * @param[in]  filename  The filename
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string saveJpg(const std::string& filename);
		/**
		 * @brief      Saves a png.
		 *
		 * @param[in]  filename  The filename
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string savePng(const std::string& filename);
		/**
		 * @brief      Saves a bitmap.
		 *
		 * @param[in]  filename  The filename
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string saveBmp(const std::string& filename);
	};
}

#endif
