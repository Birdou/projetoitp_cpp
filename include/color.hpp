
/*
* Essa biblioteca não deve ser usada com fins lucrativos ou
* comerciais.
* Propriedade intelectual de Felipe Sena de Medeiros - IMD/UFRN
* Última atualização: 25/03/2021
*/

#ifndef COLOURPLUS_H
#define COLOURPLUS_H

#include <iostream>
#include <windows.h>
#include <direct.h>
#include <cstdlib>
#include <sstream>

#define NONE         -1
#define BLACK         0  // 0000
#define BLUE          1  // 0001
#define GREEN         2  // 0010
#define CYAN          3  // 0011
#define RED           4  // 0100
#define MAGENTA       5  // 0101
#define YELLOW        6  // 0110
#define LIGHT_GRAY    7  // 0111
#define DARK_GRAY     8  // 1000
#define LIGHT_BLUE    9  // 1001
#define LIGHT_GREEN   10 // 1010
#define LIGHT_CYAN    11 // 1011
#define LIGHT_RED     12 // 1100
#define LIGHT_MAGENTA 13 // 1101
#define LIGHT_YELLOW  14 // 1110
#define WHITE         15 // 1111

#define colorspace(command, bg, fg) 					\
	if(true)											\
	{													\
		HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);	\
		CONSOLE_SCREEN_BUFFER_INFO bufferInfo;			\
														\
		WORD text_color;								\
														\
		GetConsoleScreenBufferInfo(hl, &bufferInfo);	\
		text_color = bufferInfo.wAttributes;			\
														\
		if(bg >= 0 && bg < 16)							\
		{												\
			text::setbg(hl, bg);						\
		}												\
		if(fg >= 0 && fg < 16)							\
		{												\
			text::setfg(hl, fg);						\
		}												\
														\
		command;										\
														\
		SetConsoleTextAttribute(hl, text_color);		\
	}

namespace text
{
	std::string setfg(HANDLE& hl, int color);

	std::string setbg(HANDLE& hl, int color);

	std::string echo(bool on);

	void hidecursor();
	void showcursor();

	using format = std::stringstream;

	class color
	{
	public:
		const format& data;
		int backcolor = NONE, forecolor = NONE;

		color(const format& data, int backcolor = NONE, int forecolor = NONE):
		data(data), backcolor(backcolor), forecolor(forecolor)
		{}

		friend std::ostream& operator<<(std::ostream& o, const color& text)
		{
			HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

			WORD text_color;

			GetConsoleScreenBufferInfo(hl, &bufferInfo);
			text_color = bufferInfo.wAttributes;

			if(text.backcolor >= 0 && text.backcolor < 16)
			{
				setbg(hl, text.backcolor);
			}
			if(text.forecolor >= 0 && text.forecolor < 16)
			{
				setfg(hl, text.forecolor);
			}

			o << text.data.str();

			SetConsoleTextAttribute(hl, text_color);

			return o;
		}
	};

	class fixed
	{
	public:
		static size_t string_size;
		static size_t& get_ssize()
		{
			static size_t string_size;
			return string_size;
		}

		const format& data;

		fixed(const format& data):
		data(data)
		{}

		friend std::ostream& operator<<(std::ostream& o, const fixed& text)
		{
			HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

			COORD position;

			GetConsoleScreenBufferInfo(hl, &bufferInfo);
			position = bufferInfo.dwCursorPosition;

			for(size_t i = 0; i < get_ssize(); ++i)
				putchar(' ');

			SetConsoleCursorPosition(hl, position);

			o << text.data.str();
			get_ssize() = text.data.str().size();

			SetConsoleCursorPosition(hl, position);

			return o;
		}
	};
}

#endif