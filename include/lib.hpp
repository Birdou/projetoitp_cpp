
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

#ifdef DEBUG
#define Debug(x) std::cout << x
#else
#define Debug(x)
#endif

#define CLS system("cls")

namespace lib
{
	#ifndef PI
	#define PI 3.1415927
	#endif
	
	long int fat(int num);

	long int bin(int n, int i);

	double rad(double deg);

	std::string stolower(const std::string& word);

	int cstrcmp(const std::string& string1, const std::string& string2);
	bool isany(const char letter, const std::string& vect);

	bool isany(const std::string& word, const std::string& vect);

	size_t chartcount(const std::string& string);

	Uint32 getpixel(SDL_Surface *surface, int x, int y);
	
	class var
	{
	public:
		ssize_t target, step, value;
		bool finished = false;
		var(ssize_t start, ssize_t end, ssize_t step):
			target(end), step(step), value(start)
		{}
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

	void replaceAll(std::string& str, const std::string& from, const std::string& to);
	void replaceWhole(std::string& str, const std::string& from, const std::string& to);

	void remove_trailling(std::string& number);

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
