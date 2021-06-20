
#ifndef HELP_H
#define HELP_H

#include <cstdio>
#include <string>

namespace paintit
{
	/**
	 * @brief      { function_description }
	 */
	void listcolor();

	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  page  The page
	 */
	void help(unsigned page = 1);
	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  command  The command
	 *
	 * @return     { description_of_the_return_value }
	 */
	std::string command_help(const std::string& command);
	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  command  The command
	 *
	 * @return     { description_of_the_return_value }
	 */
	std::string command_sintax(const std::string& command);
}

#endif
