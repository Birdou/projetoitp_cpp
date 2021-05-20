
#ifndef HELP_H
#define HELP_H

#include <cstdio>
#include <string>

namespace paintit
{
	void listcolor();
	void help();

	std::string commandHelp(const std::string& command);
}

#endif
