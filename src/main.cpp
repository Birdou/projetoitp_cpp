#include <iostream>
#include <sys/stat.h>

#include "paintit.hpp"
#include "color.hpp"

#if defined(_WIN32)
#define TERMINAL_ENCODING system("chcp 65001 >nul");
#else
#define TERMINAL_ENCODING
#endif

int main(int argc, char* argv[])
{
	TERMINAL_ENCODING;
	setlocale(LC_ALL, "pt_BR_utf8");

	DebugLogS("this is a log message");
	DebugWarningS("this is a warning message");
	DebugErrorS("this is a error message");
	DebugCriticalS("this is a critical error message");

	paintit::paintit_main* paintit = new paintit::paintit_main();

	paintit->init();
	if(argc > 1)
	{
		std::string file(argv[1]);
		std::cout << "$ " << colorstream("open " << file, fLIGHT_BLUE) << std::endl;
		std::cout << paintit->current_image->open(argv[1]) << std::endl;
		if(paintit->current_image->getWidth() != 0 && paintit->current_image->getHeight() != 0)
		{
			paintit->current_image->savePng("editview.png");
			//paintit->updateImage();
		}
	}
	else
	{
		struct stat buffer;
  		if(stat("editview.png", &buffer) == 0)
		{
			std::cout << "O programa não foi encerrado corretamente na última vez em que foi usado." << std::endl;
			std::cout << paintit->current_image->open("editview.png") << std::endl;
		}
	}

	paintit->execute();

	delete paintit;

	return 0;
}

/*

color 255 0 0
for r from 0 to 1200 by 3 do line 0 r 960 r
color 0 255 0
for r from 1 to 1200 by 3 do line 0 r 960 r
color 0 0 255
for r from 2 to 1200 by 3 do line 0 r 960 r
color 255 0 0
for r from 0 to 960 by 3 do line r 0 r 1200
color 0 255 0
for r from 1 to 960 by 3 do line r 0 r 1200
color 0 0 255
for r from 2 to 960 by 3 do line r 0 r 1200

for x from 0 to 1000 by 1 y from 1000 to 0 by -1 do line x 0 y 1000 line 0 x 1000 y

for r from 0 to 255 by 2 x from 0 to 300 by 1 do for g from 0 to 255 by 2 y from 0 to 300 by 1 do color r g 122 line x y 300 y

*/