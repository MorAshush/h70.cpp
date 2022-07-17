#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <vector>

#include "server_socket.hpp"
#include "tcp_server.hpp"
#include "client_socket.hpp"
#include "handler.hpp"
#include "request_handler.hpp"
#include "selector_base.hpp"
#include "select_selector.hpp"
#include "../../inc/threads/thread_safe_queue.hpp"
#include "processor.hpp"
#include "protocol.hpp"
#include "definitions.hpp"
#include "supported_cmds.hpp"
#include "all_commands.hpp"

std::string parse_func(std::vector<uint8_t>const& a_buffer, std::vector<uint8_t>& a_dataBuffer)
{
	std::string buffer(a_buffer.begin(), a_buffer.end());
	std::string commandName;

	size_t len = buffer.length();

	size_t i;
	for(i = 0; i < len; ++i)
	{
		if(buffer[i] != ':')
		{
			commandName += buffer[i];
		}
		else
		{
			break;
		}
	}

	a_dataBuffer = std::vector<uint8_t>(buffer.begin() + i + 1, buffer.end());
	return commandName;
}

int main()
{
	net::Address ad("127.0.0.1", "4445");

	SafeQueue<std::pair<Buffer, net::TCPClientSocket*>> sq(1000);

	net::RequestHandler ah(sq);

	net::TCPServer server(ad, &ah);

	net::SelectSelector selector(&server);

	CommandsLibary cmdMap;
	Protocol protocol(cmdMap, parse_func);
	Processor processor(Protocol);

	server.server_run(&selector);


/*	auto threadHandler = [&sq, &server, &cmdMap]()
	{
		std::pair<Buffer, net::TCPClientSocket*> r;
		sq.dequeue(r);

		auto work = cmd_extractor(r.first, cmdMap);
		//need to seperate data segment from request vector and pass it to work function
		auto result = work(r.first);

	//	net::TCPClientSocket* cs = r.second;
		//send client the reply
	};*/

	return 0;
}