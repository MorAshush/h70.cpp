#include <iostream>
#include <functional>

#include "processor.hpp"


Processor::Processor(Protocol const& a_protocol)
: m_protocol(a_protocol)
{

}

void Processor::process(std::pair<Buffer, net::TCPClientSocket*>& a_request)
{
	Buffer msg = a_request.first;

	Buffer data;
	std::function<Buffer(Buffer)> cmdFunc = m_protocol.unpack(msg, data);
	
	Buffer reply = cmdFunc(data);

	net::TCPClientSocket* cs = a_request.second;
	send_reply(reply, cs);
}

void Processor::send_reply(Buffer const& a_reply, net::TCPClientSocket* a_client)
{
	int sentBytes = send(a_client->get_client_socket(), a_reply.data(), a_reply.size(), 0);
	if(sentBytes <= 0)
	{
		std::cout << "processor send failed\n";
		//throw "send failed";
	}
	/*
	try
	{
		a_client->write(a_reply);
	}
	catch(...)
	{
		std::cout << "processor send failed\n";
		throw;
	}
	*/
}