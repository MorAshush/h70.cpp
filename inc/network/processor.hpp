#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include <vector>

#include "protocol.hpp"
#include "client_socket.hpp"
#include "definitions.hpp"




class Processor
{
public:
	Processor(Protocol const& a_protocol);

	void process(std::pair<Buffer, net::TCPClientSocket*>& a_request);

private:
	void send_reply(Buffer const& a_reply, net::TCPClientSocket* a_client);

private:
	Protocol m_protocol;

};











#endif //PROCESSOR_HPP