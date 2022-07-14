#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <vector>

#include "server_socket.hpp"
#include "tcp_server.hpp"
#include "client_socket.hpp"
#include "handler.hpp"
#include "app_handler.hpp"
#include "selector_base.hpp"
#include "select_selector.hpp"
#include "../../inc/threads/thread_safe_queue.hpp"

typedef void(*cmdFunc)(std::vector<uint32_t>const&);

cmdFunc cmd_extractor(std::vector<uint8_t> a_buffer, std::map<std::string, cmdFunc> a_supportedCmd)
{
	std::string cmd;

	for(auto c : a_buffer)
	{
		if(c != ':')
		{
			cmd += c;
		}
		else
		{
			break;
		}
	}

	auto it = a_supportedCmd.find(cmd);
	if(it != a_supportedCmd.end())
	{
		return it->second;
	}
	else
	{
		std::cout << "command is not supported\n"; 
		throw "cmd not found";
	}
}

auto add = [](std::vector<uint32_t>const& a_nums)
{
	uint32_t sum = 0;
	for(auto& n : a_nums)
	{
		sum += n;
	}

	return sum;
};

auto mul = [](std::vector<uint32_t>const& a_nums)
{
	uint32_t result = 0;
	for(auto& n : a_nums)
	{
		result *= n;
	}

	return result;
};
/*
std::string const& get(std::string const& a_fileName)
{
	std::ifstream fin;
    fin.open(m_fileName);
    if(!fin)
    {
    	std::cout << "file couldn't open\n";
    }

    std::string fileContent;
    std::string line;
    getline(fin, line);
    while(fin)
    {
    	fileContent += line;
        fileContent += '\n';
    }

    fin.close();
    return fileContent;
}
*/

int main()
{
	net::Address ad("127.0.0.1", "4445");

	SafeQueue<net::Request> sq(1000);

	net::AppHandler ah(sq);

	net::TCPServer server(ad, &ah);

	net::SelectSelector selector(&server);

	server.server_run(&selector);
	std::map<std::string, cmdFunc> cmdMap;

	auto threadHandler = [&sq, &server, &cmdMap]()
	{
		net::Request r;
		sq.dequeue(r);

		auto work = cmd_extractor(r.first, cmdMap);
		//need to seperate data segment from request vector and pass it to work function
		auto result = work(r.first);

		net::TCPClientSocket* cs = r.second;
		//send client the reply
	};

	return 0;
}