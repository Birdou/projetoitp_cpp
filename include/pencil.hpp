
#ifndef PAINTIT_PENCIL_HPP
#define PAINTIT_PENCIL_HPP

#include <string>

#include "rgb.hpp"
#include "lib.hpp"

namespace paintit
{
	class penc
	{
	public:
		/**
		 * @brief      Constructs a new instance.
		 */
		penc();
		/**
		 * @brief      Constructs a new instance.
		 *
		 * @param[in]  color  The color
		 * @param[in]  size   The size
		 */
		penc(paintit::rgb color, double size);
		/**
		 * @brief      Destroys the object.
		 */
		~penc();

		/**
		 * @brief      Gets the color.
		 *
		 * @return     The color.
		 */
		paintit::rgb getColor() const;
		/**
		 * @brief      Sets the color.
		 *
		 * @param[in]  color  The color
		 */
		void setColor(paintit::rgb color);

		/**
		 * @brief      Gets the size.
		 *
		 * @return     The size.
		 */
		double getSize() const;
		/**
		 * @brief      Sets the size.
		 *
		 * @param[in]  size  The size
		 */
		void setSize(double size);

		/**
		 * @brief      { function_description }
		 *
		 * @param[in]  colorname  The colorname
		 *
		 * @return     { description_of_the_return_value }
		 */
		std::string scolor(const std::string& colorname);

		/**
		 * @brief      { function_description }
		 *
		 * @param      color  The color
		 */
		void touch(paintit::rgb& color) const;

		/**
		 * @brief      { enum_description }
		 */
		enum Modes
		{
			normal,
			average,
			additive,
			subtractive,
			last_mode
		};
		Modes mode = normal;

	private:
		paintit::rgb color;
		double size;
	};
}

#endif
