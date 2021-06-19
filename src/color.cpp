
#include "color.hpp"

std::string text::setfg(HANDLE& hl, int color)
{
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	GetConsoleScreenBufferInfo(hl, &bufferInfo);
	bufferInfo.wAttributes &= 0x00F0;
	SetConsoleTextAttribute(hl, bufferInfo.wAttributes |= color);
	return "";
}

std::string text::setbg(HANDLE& hl, int color)
{
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	GetConsoleScreenBufferInfo(hl, &bufferInfo);
	bufferInfo.wAttributes &= 0x000F;
	SetConsoleTextAttribute(hl, bufferInfo.wAttributes |= (color << 4));
	return "";
}

std::string text::echo(bool on)
{
	DWORD mode;
	HANDLE hl = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hl, &mode);
	mode = on ? (mode | ENABLE_ECHO_INPUT) : (mode & ~(ENABLE_ECHO_INPUT));
	SetConsoleMode(hl, mode);

	return "";
}

void text::hidecursor()
{
	HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(hl, &info);
	info.bVisible = FALSE;
	SetConsoleCursorInfo(hl, &info);
}
void text::showcursor()
{
	HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(hl, &info);
	info.bVisible = TRUE;
	SetConsoleCursorInfo(hl, &info);
}
