#include <iostream>

#include "paintit.hpp"

#include "color.hpp"

int main(int argc, char* argv[])
{
	system("chcp 65001 >nul");
	setlocale(LC_ALL, "pt_BR_utf8");

	paintit::paintit_main paintit;

	paintit.init();
	if(argc > 1)
	{
		std::string file(argv[1]);
		std::cout << "$ " << text::color(text::format("open " + file), NONE, LIGHT_BLUE) << std::endl;
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

