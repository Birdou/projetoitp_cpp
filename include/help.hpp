
#ifndef HELP_H
#define HELP_H

#include <cstdio>
#include <string>

namespace paintit
{
	void listcolor();

	void help(unsigned page = 1);
	std::string command_help(const std::string& command);
	std::string command_sintax(const std::string& command);
}

#endif
