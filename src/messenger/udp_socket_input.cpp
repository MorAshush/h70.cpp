#include <sys/socket.h>
#include <unistd.h>
#include <cassert>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <ctype.h>


#include "udp_socket_input.hpp"

namespace in
{
	InputUDPsocket::InputUDPsocket(char* a_address, char* a_port)
	: m_sockaddr()
	, m_socket(socket(AF_INET, SOCK_DGRAM, 0))
	{
		assert(m_socket > 0 && "socket function failed");

		memset(&m_sockaddr, 0, sizeof(m_sockaddr));

		m_sockaddr.sin_family = AF_INET;
	    m_sockaddr.sin_addr.s_addr = inet_addr(a_address); 
	    m_sockaddr.sin_port = htons(atoi(a_port));

	    int result = bind(m_socket, (struct sockaddr*)(&m_sockaddr), sizeof(m_sockaddr));
	    assert(result > -1 && "socket function failed");
	}

	InputUDPsocket::~InputUDPsocket()
	{
		close(m_socket);
	}

	std::string InputUDPsocket::recieve()
	{
		unsigned int sinLen = sizeof(m_sockaddr);
		int readBytes = 0;
		char buffer[4096];

		std::string data;

		std::cout << "recieving...\n";
		readBytes = recvfrom(m_socket, buffer, sizeof(buffer), 0, (struct sockaddr*)(&m_sockaddr), &sinLen);
		data += buffer;

		if(data == "EOM")
		{
			data = "";
			return data;
		}

		while(true)
		{
			std::cout << "recieving...\n";
			readBytes = recvfrom(m_socket, buffer, sizeof(buffer), 0, (struct sockaddr*)(&m_sockaddr), &sinLen);

			assert(readBytes >= 0 && "recieving failed");

			if(buffer[0] == 'E' && buffer[1] == 'O' && buffer[2] == 'M')
			{
				break;
			}
			
			data += '\n';
			data += buffer;
		}

		data += '\0';

		return data;
	}

InputUDPsocket* create_udpSocket_inputer(std::string a_ipPortString)
{
	std::string ipString;
	std::string portString;
	
	size_t i = a_ipPortString.find(':', 0);
	ipString = a_ipPortString.substr(0, i);
	portString = a_ipPortString.substr(i + 1);

	char* ip = new char[ipString.length() + 1];
	strcpy(ip, ipString.c_str());

	char* port = new char[portString.length() + 1];
	strcpy(port, portString.c_str());

	return new InputUDPsocket(ip, port);
}

}//namespace in
