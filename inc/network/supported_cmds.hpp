#ifndef SUPPORTED_CMDS_HPP
#define SUPPORTED_CMDS_HPP

#include <map>
#include <string>

#include "definitions.hpp"


class CommandsLibary
{
public:
	CommandsLibary();

	cmdFunc get_function_by_command(std::string a_cmdName);


private:
	std::map<std::string, cmdFunc> m_supportedCmds;
};



#endif // SUPPORTED_CMDS_HPP