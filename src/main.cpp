#include <iostream>

#include "paintit.hpp"

int main(int argc, char* argv[])
{
	system("chcp 65001 >nul");
	setlocale(LC_ALL, "pt_BR_utf8");

	for(int i = 1; i < argc; ++i)
	{
		std::cout << "\"" << argv[i] << "\" ";
	}

	paintit::paintit_main paintit;

	paintit.init();
	paintit.execute();

	return 0;
}

