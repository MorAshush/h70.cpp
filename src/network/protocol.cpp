#include <iostream>

#include "protocol.hpp"



Protocol::Protocol(CommandsLibary const& a_supportedCmds, parseFunc a_parser)
: m_cmdMap(a_supportedCmds)
, m_parser(a_parser)
{

}

cmdFunc Protocol::unpack(Buffer& a_buff, Buffer& a_data)
{
	std::string commandName;
	commandName = m_parser(a_buff, a_data);

	try
	{
		return m_cmdMap.get_function_by_command(commandName);
	}
	catch(...)
	{
		std::cout << "command is not supported\n"; 
		throw;
	}
}