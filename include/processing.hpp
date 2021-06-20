
#ifndef PAINTIT_PROCESSING_HPP
#define PAINTIT_PROCESSING_HPP

#include <string>
#include <random>

#include "ppm.hpp"
#include "coord.hpp"

namespace paintit
{
	namespace processing
	{
		static std::random_device rd;
		/**
		 * @brief      { function_description }
		 *
		 * @param      image  The image
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string grayscale	(paintit::ppm& image);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image  The image
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string sepia		(paintit::ppm& image);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image  The image
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string negative	(paintit::ppm& image);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image  The image
		 * @param[in]  scale  The scale
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string brighten	(paintit::ppm& image, double scale);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image  The image
		 * @param[in]  scale  The scale
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string darken		(paintit::ppm& image, double scale);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image  The image
		 * @param[in]  scale  The scale
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string vibrancy	(paintit::ppm& image, double scale);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image  The image
		 * @param[in]  scale  The scale
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string guev		(paintit::ppm& image, double scale);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image  The image
		 * @param[in]  red    The red
		 * @param[in]  green  The green
		 * @param[in]  blue   The blue
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string intensity	(paintit::ppm& image, double red, double green, double blue);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image  The image
		 * @param[in]  red    The red
		 * @param[in]  green  The green
		 * @param[in]  blue   The blue
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string desaturate	(paintit::ppm& image, double red, double green, double blue);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image  The image
		 * @param[in]  red    The red
		 * @param[in]  green  The green
		 * @param[in]  blue   The blue
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string redequal	(paintit::ppm& image, double red, double green, double blue);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image  The image
		 * @param[in]  red    The red
		 * @param[in]  green  The green
		 * @param[in]  blue   The blue
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string greenequal	(paintit::ppm& image, double red, double green, double blue);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image  The image
		 * @param[in]  red    The red
		 * @param[in]  green  The green
		 * @param[in]  blue   The blue
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string blueequal	(paintit::ppm& image, double red, double green, double blue);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image  The image
		 * @param[in]  scale  The scale
		 * @param[in]  angle  The angle
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string glitch		(paintit::ppm& image, int scale, double angle);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image  The image
		 * @param[in]  scale  The scale
		 * @param[in]  angle  The angle
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string rbglitch	(paintit::ppm& image, int scale, double angle);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image  The image
		 * @param[in]  px     { parameter_description }
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string pixelize	(paintit::ppm& image, int px);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image  The image
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string makenoise	(paintit::ppm& image);
	}
}

#endif