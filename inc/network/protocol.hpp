#ifndef PROTOCOL_HPP
#define PROTOCOL_HPP

#include <map>
#include <vector>

#include "client_socket.hpp"
#include "definitions.hpp"
#include "supported_cmds.hpp"

typedef std::string (*parseFunc)(std::vector<uint8_t>const&, std::vector<uint8_t>&);

class Protocol
{
public:
	Protocol(CommandsLibary const& a_supportedCmds, parseFunc a_parser);

	cmdFunc unpack(Buffer& a_buff, Buffer& a_data); //returns a the callable function of the relevant cmd, and puts in data whats left to work on

private:
	CommandsLibary m_cmdMap;
	parseFunc m_parser;

};


#endif //PROTOCOL_HPP