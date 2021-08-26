
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
#define inexistent_file_exception "Arquivo inexistente."
#define invalid_format_exception "Formato de arquivo inválido."
#define non_24bit_exception "O arquivo não corresponde a uma imagem de 24 bits."
#define invalid_syntax_exception "Sintaxe do comando incorreta. Consulte \"help\"."
#define invalid_argument_exception "Argumento inválido."
#define color_not_found_exception "Cor não encontrada, digite \"listcolor\" para ver a lista de cores."
#define missing_pixels_warning "Imagem corrompida (há informações faltando)."
#define noerror ""
#define return_iferror(x)                 \
	if (true)                             \
	{                                     \
		const std::string errorlevel = x; \
		if (errorlevel != noerror)        \
			return errorlevel;            \
	}

#include "color.hpp"

#ifdef DEBUG
#define DebugMessage(x) DebugStream("DEBUG", x, fDARK_GRAY)
#define DebugMessageS(x) DebugStreamS("DEBUG", x, fDARK_GRAY)

#define DebugLog(x) DebugStream("LOG", x, fLIGHT_GREEN)
#define DebugLogS(x) DebugStreamS("LOG", x, fLIGHT_GREEN)

#define DebugWarning(x) DebugStream("WARN", x, fYELLOW)
#define DebugWarningS(x) DebugStreamS("WARN", x, fYELLOW)

#define DebugError(x) DebugStream("ERROR", x, fRED)
#define DebugErrorS(x) DebugStreamS("ERROR", x, fRED)

#define DebugCritical(x) DebugStream("CRITICAL", x, bWHITE << fRED)
#define DebugCriticalS(x) DebugStreamS("CRITICAL", x, bWHITE << fRED)
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

#define DebugStream(errorid, stream, color)                                                                                             \
	std::cout << colorstream("[" << errorid << "] " << typeid(*this).name() << "::" << __func__ << ": " << stream, color) << std::endl; \
	SDL_ClearError();

#define DebugStreamS(errorid, stream, color)                                                            \
	std::cout << colorstream("[" << errorid << "] " << __func__ << ": " << stream, color) << std::endl; \
	SDL_ClearError();

#if defined(_WIN32)
#define CLS system("cls")
#elif defined(unix) | defined(__unix) | defined(__unix__)
#define CLS                                                  \
	if (system("clear") != 0)                                \
	{                                                        \
		std::cout << "Alguma coisa deu errado" << std::endl; \
	}
#else
#define CLS std::cout << "Não há suporte para esta função no sistema operacional atual." << std::endl
#endif

namespace lib
{
#ifndef PI
#define PI 3.1415927
#endif

	long int fat(int num);

	long int bin(int n, int i);

	double rad(double deg);

	std::string stolower(const std::string &word);

	int cstrcmp(const std::string &string1, const std::string &string2);
	bool isany(const char letter, const std::string &vect);

	bool isany(const std::string &word, const std::string &vect);

	size_t chartcount(const std::string &string);

	Uint32 getpixel(SDL_Surface *surface, int x, int y);

	class var
	{
	public:
		ssize_t target, step, value;
		bool finished = false;
		var(ssize_t start, ssize_t end, ssize_t step) : target(end), step(step), value(start)
		{
		}

		void increment()
		{
			if ((value >= target && step > 0) || (value <= target && step < 0))
			{
				finished = true;
				return;
			}
			value += step;
		}
	};

	void replaceAll(std::string &str, const std::string &from, const std::string &to);
	void replaceWhole(std::string &str, const std::string &from, const std::string &to);

	void remove_trailling(std::string &number);

	template <typename type>
	void catchoperator(char operation, std::string &expression)
	{
		std::stringstream stream(expression);
		type stoperand, ndoperand;
		size_t firstg, secondg;
		char _operator;

		while (1)
		{
			if (expression.find(operation) == std::string::npos)
			{
				break;
			}

			firstg = stream.tellg();

			stream >> stoperand;
			if (stream.fail())
				break;
			stream >> _operator;
			if (stream.fail())
				break;

			if (_operator == operation)
			{
				stream >> ndoperand;
				if (stream.fail())
					break;
				secondg = stream.tellg();
				switch (operation)
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
				case '^':
				{
					expression.replace(expression.begin() + firstg, expression.begin() + secondg, std::to_string(pow(stoperand, ndoperand)));
					break;
				}
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

	size_t matchParentesis(const std::string &expression, size_t pos);

	template <typename type>
	std::string ssmath(std::string expression)
	{
		size_t first, last;
		while ((first = expression.find_last_of('(')) != std::string::npos)
		{
			last = expression.find_first_of(')', first);
			expression.replace(expression.begin() + first, expression.begin() + last + 1, ssmath<type>(expression.substr(first + 1, last - first - 1)));
		}

		catchoperator<type>('^', expression);
		catchoperator<type>('*', expression);
		catchoperator<type>('/', expression);
		catchoperator<type>('-', expression);
		catchoperator<type>('+', expression);

		return expression;
	}

	template <typename type>
	std::string smath(std::string expression)
	{
		size_t first, last, func;
		while ((func = expression.find("sin")) != std::string::npos)
		{
			first = expression.find_first_of('(', func);
			last = matchParentesis(expression, first);

			std::string result(smath<type>(expression.substr(first + 1, last - first - 1)));
			std::stringstream stream(result);
			double nResult;
			stream >> nResult;
			nResult = sin(nResult);
			expression.replace(expression.begin() + func, expression.begin() + last + 1, std::to_string(nResult));
		}
		while ((func = expression.find("cos")) != std::string::npos)
		{
			first = expression.find_first_of('(', func);
			last = matchParentesis(expression, first);

			std::string result(smath<type>(expression.substr(first + 1, last - first - 1)));
			std::stringstream stream(result);
			double nResult;
			stream >> nResult;
			nResult = cos(nResult);
			expression.replace(expression.begin() + func, expression.begin() + last + 1, std::to_string(nResult));
		}
		while ((func = expression.find("tan")) != std::string::npos)
		{
			first = expression.find_first_of('(', func);
			last = matchParentesis(expression, first);

			std::string result(smath<type>(expression.substr(first + 1, last - first - 1)));
			std::stringstream stream(result);
			double nResult;
			stream >> nResult;
			nResult = tan(nResult);
			expression.replace(expression.begin() + func, expression.begin() + last + 1, std::to_string(nResult));
		}
		std::string newExpression(ssmath<type>(expression));

		return newExpression;
	}

	double logb(double base, double x);

	bool chkdir(const std::string &s);

	double deg(double x);
}

#endif
