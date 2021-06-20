
#ifndef PAINTIT_FUNCTIONS_HPP
#define PAINTIT_FUNCTIONS_HPP

#include <string>
#include <vector>

#include "ppm.hpp"
#include "coord.hpp"

namespace paintit
{
	namespace functions
	{
		/**
		 * @brief      { function_description }
		 *
		 * @param      image   The image
		 * @param[in]  pincel  The pincel
		 * @param[in]  PX      { parameter_description }
		 * @param[in]  PY      { parameter_description }
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string draw		(paintit::ppm& image, const paintit::penc& pincel, ssize_t PX, ssize_t PY) noexcept;
		/**
		 * @brief      { function_description }
		 *
		 * @param      image   The image
		 * @param[in]  pincel  The pincel
		 * @param[in]  P1      The p 1
		 * @param[in]  P2      The p 2
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string linehigh	(paintit::ppm& image, const paintit::penc& pincel, const paintit::coord& P1, const paintit::coord& P2);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image   The image
		 * @param[in]  pincel  The pincel
		 * @param[in]  P1      The p 1
		 * @param[in]  P2      The p 2
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string linelow		(paintit::ppm& image, const paintit::penc& pincel, const paintit::coord& P1, const paintit::coord& P2);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image      The image
		 * @param[in]  pincel     The pincel
		 * @param[in]  <unnamed>  { parameter_description }
		 * @param[in]  <unnamed>  { parameter_description }
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string line		(paintit::ppm& image, const paintit::penc& pincel, const paintit::coord&, const paintit::coord&);

		/**
		 * @brief      { function_description }
		 *
		 * @param      image      The image
		 * @param[in]  pincel     The pincel
		 * @param[in]  <unnamed>  { parameter_description }
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string curve		(paintit::ppm& image, const paintit::penc& pincel, const std::vector<paintit::coord>&);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image      The image
		 * @param[in]  pincel     The pincel
		 * @param[in]  <unnamed>  { parameter_description }
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string polygon		(paintit::ppm& image, const paintit::penc& pincel, const std::vector<paintit::coord>&);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image      The image
		 * @param[in]  pincel     The pincel
		 * @param[in]  <unnamed>  { parameter_description }
		 * @param[in]  <unnamed>  { parameter_description }
		 * @param[in]  <unnamed>  { parameter_description }
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string rect		(paintit::ppm& image, const paintit::penc& pincel, const paintit::coord&, int, int);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image      The image
		 * @param[in]  pincel     The pincel
		 * @param[in]  <unnamed>  { parameter_description }
		 * @param[in]  <unnamed>  { parameter_description }
		 * @param[in]  <unnamed>  { parameter_description }
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string circle		(paintit::ppm& image, const paintit::penc& pincel, const paintit::coord&, int, int);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image   The image
		 * @param[in]  pincel  The pincel
		 * @param[in]  pos     The position
		 * @param[in]  width   The width
		 * @param[in]  height  The height
		 * @param[in]  angle   The angle
		 * @param[in]  p       { parameter_description }
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string elipse		(paintit::ppm& image, const paintit::penc& pincel, const paintit::coord& pos, size_t width, size_t height, double angle, int p);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image      The image
		 * @param[in]  pincel     The pincel
		 * @param[in]  <unnamed>  { parameter_description }
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string fill		(paintit::ppm& image, const paintit::penc& pincel, const paintit::coord&);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image   The image
		 * @param[in]  pincel  The pincel
		 * @param[in]  pos     The position
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string global		(paintit::ppm& image, const paintit::penc& pincel, const paintit::coord& pos);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image  The image
		 * @param[in]  P1     The p 1
		 * @param[in]  P2     The p 2
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string crop		(paintit::ppm& image, const paintit::coord& P1, const paintit::coord& P2);
		/**
		 * @brief      { function_description }
		 *
		 * @param      image      The image
		 * @param[in]  colorname  The colorname
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string sclear		(paintit::ppm& image, const std::string& colorname);
	}
}
#endif
