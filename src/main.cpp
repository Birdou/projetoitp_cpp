#include <iostream>

#include "paintit.hpp"

#include "color.hpp"

int main(int argc, char* argv[])
{
	system("chcp 65001 >nul");
	setlocale(LC_ALL, "pt_BR_utf8");

	DebugLogS("this is a log message");
	DebugWarningS("this is a warning message");
	DebugErrorS("this is a error message");
	DebugCriticalS("this is a critical error message");

	paintit::paintit_main paintit;

	paintit.init();
	if(argc > 1)
	{
		std::string file(argv[1]);
		std::cout << "$ " << colorstream("open " << file, fLIGHT_BLUE) << std::endl;
		std::cout << paintit.current_image->open(argv[1]) << std::endl;
		if(paintit.current_image->getWidth() != 0 && paintit.current_image->getHeight() != 0)
		{
			paintit.current_image->savePng("editview.png");
			paintit.updateImage();
		}
	}

	paintit.execute();

	return 0;
}

