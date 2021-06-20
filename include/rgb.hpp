
#ifndef PAINTIT_COLOR_HPP
#define PAINTIT_COLOR_HPP

#include <string>

#include "lib.hpp"

namespace paintit
{
	/**
	 * @brief      This class describes a rgb.
	 */
	class rgb
	{
	private:
		short r = 0;
		short g = 0;
		short b = 0;

	public:
		/**
		 * @brief      Constructs a new instance.
		 */
		rgb();
		/**
		 * @brief      Constructs a new instance.
		 *
		 * @param[in]  r     { parameter_description }
		 * @param[in]  g     { parameter_description }
		 * @param[in]  b     { parameter_description }
		 */
		rgb(short r, short g, short b);
		/**
		 * @brief      Destroys the object.
		 */
		~rgb();

		/**
		 * @brief      { function_description }
		 *
		 * @param[in]  color  The color
		 *
		 * @return     { description_of_the_return_value }
		 */
		rgb mix(const rgb& color);

		/**
		 * @brief      { function_description }
		 *
		 * @param[in]  color  The color
		 *
		 * @return     { description_of_the_return_value }
		 */
		rgb bw(const rgb& color);
		/**
		 * @brief      { function_description }
		 *
		 * @param[in]  color  The color
		 *
		 * @return     { description_of_the_return_value }
		 */
		rgb antigue(const rgb& color);

		/**
		 * @brief      Addition operator.
		 *
		 * @param[in]  num   The number
		 *
		 * @return     The result of the addition
		 */
		rgb operator+(double num) const;
		/**
		 * @brief      Subtraction operator.
		 *
		 * @param[in]  num   The number
		 *
		 * @return     The result of the subtraction
		 */
		rgb operator-(double num) const;
		/**
		 * @brief      Multiplication operator.
		 *
		 * @param[in]  num   The number
		 *
		 * @return     The result of the multiplication
		 */
		rgb operator*(double num) const;
		/**
		 * @brief      Division operator.
		 *
		 * @param[in]  num   The number
		 *
		 * @return     The result of the division
		 */
		rgb operator/(double num) const;

		/**
		 * @brief      Addition operator.
		 *
		 * @param[in]  color  The color
		 *
		 * @return     The result of the addition
		 */
		rgb operator+(const rgb& color) const;
		/**
		 * @brief      Subtraction operator.
		 *
		 * @param[in]  color  The color
		 *
		 * @return     The result of the subtraction
		 */
		rgb operator-(const rgb& color) const;
		/**
		 * @brief      Multiplication operator.
		 *
		 * @param[in]  color  The color
		 *
		 * @return     The result of the multiplication
		 */
		rgb operator*(const rgb& color) const;
		/**
		 * @brief      Division operator.
		 *
		 * @param[in]  color  The color
		 *
		 * @return     The result of the division
		 */
		rgb operator/(const rgb& color) const;

		/**
		 * @brief      Assignment operator.
		 *
		 * @param[in]  color  The color
		 *
		 * @return     The result of the assignment
		 */
		rgb& operator=(const rgb& color);
		/**
		 * @brief      Equality operator.
		 *
		 * @param[in]  color  The color
		 *
		 * @return     The result of the equality
		 */
		bool operator==(const rgb& color) const;
		/**
		 * @brief      Inequality operator.
		 *
		 * @param[in]  color  The color
		 *
		 * @return     The result of the inequality
		 */
		bool operator!=(const rgb& color) const;

		/**
		 * @brief      Gets the r.
		 *
		 * @return     The r.
		 */
		short getR() const;
		/**
		 * @brief      Sets the r.
		 *
		 * @param[in]  <unnamed>  { parameter_description }
		 */
		void setR(short);

		/**
		 * @brief      Gets the g.
		 *
		 * @return     The g.
		 */
		short getG() const;
		/**
		 * @brief      Sets the g.
		 *
		 * @param[in]  <unnamed>  { parameter_description }
		 */
		void setG(short);

		/**
		 * @brief      Gets the b.
		 *
		 * @return     The b.
		 */
		short getB() const;
		/**
		 * @brief      Sets the b.
		 *
		 * @param[in]  <unnamed>  { parameter_description }
		 */
		void setB(short);

		/**
		 * @brief      Sets the rgb.
		 *
		 * @param[in]  r     The new value
		 * @param[in]  g     The new value
		 * @param[in]  b     The new value
		 */
		void setRGB(short r, short g, short b);

		/**
		 * @brief      { function_description }
		 *
		 * @param[in]  <unnamed>  { parameter_description }
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string getrgbval(const std::string&);

		/**
		 * @brief      { function_description }
		 *
		 * @return     { description_of_the_return_value }
		 */
		rgb bw();
		/**
		 * @brief      { function_description }
		 *
		 * @return     { description_of_the_return_value }
		 */
		rgb antigue();
	};
}

#endif
