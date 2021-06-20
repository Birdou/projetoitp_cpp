
#ifndef LIB_HPP
#define LIB_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <exception>
#include <cstdlib>

#define insufficient_memory_exception "Memória insuficiente."
#define uninitialized_image_exception "Nenhuma imagem foi inicializada."
#define inexistent_file_exception     "Arquivo inexistente."
#define invalid_format_exception      "Formato de arquivo inválido."
#define non_24bit_exception           "O arquivo não corresponde a uma imagem de 24 bits."
#define invalid_syntax_exception      "Sintaxe do comando incorreta. Consulte \"help\"."
#define invalid_argument_exception    "Argumento inválido."
#define color_not_found_exception     "Cor não encontrada, digite \"listcolor\" para ver a lista de cores."
#define missing_pixels_warning        "Imagem corrompida (há informações faltando)."
#define noerror                       ""
#define return_iferror(x)					\
	if(true)								\
	{										\
		const std::string errorlevel = x;	\
		if(errorlevel != noerror)			\
			return errorlevel;				\
	}

#include "color.hpp"

#ifdef DEBUG
	#ifndef NODEBUG
		#define DebugMessage(x) std::cout << colorstream("[DEBUG] " << typeid(*this).name() << "::" << __func__ << ": " << x, fDARK_GRAY) << std::endl
		#define DebugMessageS(x) std::cout << colorstream("[DEBUG] " << __func__ << ": " << x, fDARK_GRAY) << std::endl
	#else
		#define DebugMessage(x)
		#define DebugMessageS(x)
	#endif
	#ifndef NOLOG
		#define DebugLog(x) std::cout << colorstream("[LOG] " << typeid(*this).name() << "::" << __func__ << ": " << x, fLIGHT_GREEN) << std::endl
		#define DebugLogS(x) std::cout << colorstream("[LOG] " << __func__ << ": " << x, fLIGHT_GREEN) << std::endl
	#else
		#define DebugLog(x)
		#define DebugLogS(x)
	#endif
	#ifndef NOWARNING
		#define DebugWarning(x) std::cout << colorstream("[WARN] " << typeid(*this).name() << "::" << __func__ << ": " << x, fYELLOW) << std::endl
		#define DebugWarningS(x) std::cout << colorstream("[WARN] " << __func__ << ": " << x, fYELLOW) << std::endl
	#else
		#define DebugWarning(x)
		#define DebugWarningS(x)
	#endif
	#ifndef NOERROR
		#define DebugError(x) std::cout << colorstream("[ERROR] " << typeid(*this).name() << "::" << __func__ << ": " << x, fRED) << std::endl
		#define DebugErrorS(x) std::cout << colorstream("[ERROR] " << __func__ << ": " << x, fRED) << std::endl
	#else
		#define DebugError(x)
		#define DebugErrorS(x)
	#endif
	#define DebugCritical(x) std::cout << colorstream("[CRITICAL] " << typeid(*this).name() << "::" << __func__ << ": " << x, bWHITE << fRED) << std::endl
	#define DebugCriticalS(x) std::cout << colorstream("[CRITICAL] " << __func__ << ": " << x, bWHITE << fRED) << std::endl
#else
#define DebugMessage(x)
#define DebugMessageS(x)

#define DebugLog(x)
#define DebugLogS(x)

#define DebugWarning(x)
#define DebugWarningS(x)

#define DebugError(x)
#define DebugErrorS(x)

#define DebugCritical(x)
#define DebugCriticalS(x)
#endif

#define CLS system("cls")

namespace lib
{
	#ifndef PI
	#define PI 3.1415927
	#endif
	
	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  num   The number
	 *
	 * @return     { description_of_the_return_value }
	 */
	long int fat(int num);

	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  n     { parameter_description }
	 * @param[in]  i     { parameter_description }
	 *
	 * @return     { description_of_the_return_value }
	 */
	long int bin(int n, int i);

	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  deg   The degrees
	 *
	 * @return     { description_of_the_return_value }
	 */
	double rad(double deg);

	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  word  The word
	 *
	 * @return     { description_of_the_return_value }
	 */
	std::string stolower(const std::string& word);

	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  string1  The string 1
	 * @param[in]  string2  The string 2
	 *
	 * @return     { description_of_the_return_value }
	 */
	int cstrcmp(const std::string& string1, const std::string& string2);
	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  letter  The letter
	 * @param[in]  vect    The vect
	 *
	 * @return     { description_of_the_return_value }
	 */
	bool isany(const char letter, const std::string& vect);

	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  word  The word
	 * @param[in]  vect  The vect
	 *
	 * @return     { description_of_the_return_value }
	 */
	bool isany(const std::string& word, const std::string& vect);

	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  string  The string
	 *
	 * @return     { description_of_the_return_value }
	 */
	size_t chartcount(const std::string& string);

	/**
	 * @brief      { function_description }
	 *
	 * @param      surface  The surface
	 * @param[in]  x        { parameter_description }
	 * @param[in]  y        { parameter_description }
	 *
	 * @return     { description_of_the_return_value }
	 */
	Uint32 getpixel(SDL_Surface *surface, int x, int y);
	
	/**
	 * @brief      This class describes a variable.
	 */
	class var
	{
	public:
		ssize_t target, step, value;
		bool finished = false;
		/**
		 * @brief      Constructs a new instance.
		 *
		 * @param[in]  start  The start
		 * @param[in]  end    The end
		 * @param[in]  step   The step
		 */
		var(ssize_t start, ssize_t end, ssize_t step):
			target(end), step(step), value(start)
		{}

		/**
		 * @brief      { function_description }
		 */
		void increment()
		{
			if((value >= target && step > 0) || (value <= target && step < 0))
			{
				finished = true;
				return;
			}
			value += step;
		}
	};

	/**
	 * @brief      { function_description }
	 *
	 * @param      str   The string
	 * @param[in]  from  The from
	 * @param[in]  to    { parameter_description }
	 */
	void replaceAll(std::string& str, const std::string& from, const std::string& to);
	/**
	 * @brief      { function_description }
	 *
	 * @param      str   The string
	 * @param[in]  from  The from
	 * @param[in]  to    { parameter_description }
	 */
	void replaceWhole(std::string& str, const std::string& from, const std::string& to);

	/**
	 * @brief      Removes a trailling.
	 *
	 * @param      number  The number
	 */
	void remove_trailling(std::string& number);

	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  operation   The operation
	 * @param      expression  The expression
	 *
	 * @tparam     type        { description }
	 */
	template<typename type>
	void catchoperator(char operation, std::string& expression)
	{
		std::stringstream stream(expression);
		type stoperand, ndoperand;
		size_t firstg, secondg;
		char _operator;

		while(1)
		{
			if(expression.find(operation) == std::string::npos)
			{
				break;
			}

			firstg = stream.tellg();

			stream >> stoperand;
			if(stream.fail()) break;
			stream >> _operator;
			if(stream.fail()) break;

			if(_operator == operation)
			{
				stream >> ndoperand;
				if(stream.fail()) break;
				secondg = stream.tellg();
				switch(operation)
				{
					case '+':
					{
						expression.replace(expression.begin() + firstg, expression.begin() + secondg, std::to_string(stoperand + ndoperand));
						break;
					}
					case '-':
					{
						expression.replace(expression.begin() + firstg, expression.begin() + secondg, std::to_string(stoperand - ndoperand));
						break;
					}
					case '*':
					{
						expression.replace(expression.begin() + firstg, expression.begin() + secondg, std::to_string(stoperand * ndoperand));
						break;
					}
					case '/':
					{
						expression.replace(expression.begin() + firstg, expression.begin() + secondg, std::to_string(stoperand / ndoperand));
						break;
					}
					/*case '%':
					{
						expression.replace(expression.begin() + firstg, expression.begin() + secondg, std::to_string(stoperand % ndoperand));
						break;
					}*/
					default:
					{
						std::cout << "Operador " << _operator << " não foi definido" << std::endl;
					}
				}
				stream.str(expression);
				stream.clear();
				stream.seekg(0);
			}
		}
	}

	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  expression  The expression
	 *
	 * @tparam     type        { description }
	 *
	 * @return     { description_of_the_return_value }
	 */
	template<typename type>
	std::string smath(std::string expression)
	{
		size_t first, last;
		while((first = expression.find_last_of('(')) != std::string::npos)
		{
			last = expression.find_first_of(')', first);
			expression.replace(expression.begin() + first, expression.begin() + last + 1, smath<type>(expression.substr(first + 1, last - first - 1)));
		}

		catchoperator<type>('*', expression);
		catchoperator<type>('/', expression);
		catchoperator<type>('-', expression);
		catchoperator<type>('+', expression);

		return expression;
	}
}

#endif
