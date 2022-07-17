#include <string>
#include <iostream>

#include "supported_cmds.hpp"
#include "all_commands.hpp"



CommandsLibary::CommandsLibary()
{
	m_supportedCmds["add"] = &add;
	m_supportedCmds["mul"] = &mul;
	m_supportedCmds["get"] = &get;
}


cmdFunc CommandsLibary::get_function_by_command(std::string a_cmdName)
{
	auto it = m_supportedCmds.find(a_cmdName);
	if(it == m_supportedCmds.end())
	{
		std::cout << "get_function_by_name: command is not supported\n"; 
		throw;
	}
	return it->second;
}