
#ifndef LIB_HPP
#define LIB_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <sstream>
#include <cstring>
#include <exception>
#include <cstdlib>

#define return_iferror(x) if(true) { std::string ferrorlevel = x; if(ferrorlevel != ""){ return ferrorlevel; } }
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
}

#endif
