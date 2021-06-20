
#ifndef PAINTIT_COORD_HPP
#define PAINTIT_COORD_HPP

#include <string>
#include <cstddef>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include <exception>

namespace paintit
{
	/**
	 * @brief      This class describes a coordinate.
	 */
	class coord
	{
	public:
		/**
		 * @brief      Constructs a new instance.
		 */
		coord();
		/**
		 * @brief      Constructs a new instance.
		 *
		 * @param[in]  <unnamed>  { parameter_description }
		 */
		coord(const paintit::coord&);
		/**
		 * @brief      Constructs a new instance.
		 *
		 * @param[in]  x     { parameter_description }
		 * @param[in]  y     { parameter_description }
		 */
		coord(ssize_t x, ssize_t y);
		/**
		 * @brief      Destroys the object.
		 */
		~coord();

		/**
		 * @brief      Assignment operator.
		 *
		 * @param[in]  _coord  The coordinate
		 *
		 * @return     The result of the assignment
		 */
		coord& operator=(const paintit::coord& _coord);
		
		ssize_t x = 0;
		ssize_t y = 0;
	};
}

#endif