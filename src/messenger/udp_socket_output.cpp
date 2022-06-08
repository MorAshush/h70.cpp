#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cassert>
#include <cstring>
#include <stdlib.h>
#include <iostream>

#include "udp_socket_output.hpp"

namespace out
{
	OutputUDPsocket::OutputUDPsocket(char* a_address, char* a_port)
	: m_sockaddr()
	, m_socket(socket(AF_INET, SOCK_DGRAM, 0))
	{
		assert(m_socket > 0 && "socket function failed");

		memset(&m_sockaddr, 0, sizeof(m_sockaddr));

		m_sockaddr.sin_family = AF_INET;
	    m_sockaddr.sin_addr.s_addr = inet_addr(a_address); 
	    m_sockaddr.sin_port = htons(atoi(a_port)); 
	}

	OutputUDPsocket::~OutputUDPsocket()
	{
		close(m_socket);
	}

	void OutputUDPsocket::send(std::string const& a_text)
	{
		char* cstr = new char[a_text.length() + 1];

		strcpy(cstr, a_text.c_str());

		int sentBytes = sendto(m_socket, cstr, a_text.length(), 0, (struct sockaddr*)(&m_sockaddr), sizeof(m_sockaddr));
		assert(sentBytes >= 0 && "sending failed");

		std::cout << "message sent\n";
	}


}//namespace out