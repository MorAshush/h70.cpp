#include <sys/socket.h> /*AF_INE def*/
#include <arpa/inet.h>  /*htons*/
#include <unistd.h>     /*close*/
#include <stdlib.h>     /*size_t*/
#include <cstring>      /*memset*/
#include <stdio.h>
#include <errno.h>      
#include <fcntl.h>      /*fcntl*/
#include <sys/select.h> /*select*/
#include <iostream>

#include "server_socket.hpp"


namespace net
{

TCPServerSocket::TCPServerSocket(const char* a_address, const char* a_port)
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);

	if(sock < 0)
	{
		std::cout << "server socket ctor failed\n";
	}

	m_socket = sock;

	int status = SetToNoBlocksMode(m_socket);
	if(status < 0)
	{
		std::cout << "noblock failed\n";
	}

	memset(&m_sin, 0, sizeof(m_sin));

	m_sin.sin_family = AF_INET;
    m_sin.sin_addr.s_addr = inet_addr(a_address); 
    m_sin.sin_port = htons(atoi(a_port));

    bind(m_sin);
    listen();
}

TCPServerSocket::TCPServerSocket(TCPServerSocket&& a_other)
: m_socket(a_other.get_server_socket())
{
	a_other.m_socket = -1; //??
}

void TCPServerSocket::operator=(TCPServerSocket&& a_other)
{
	m_socket = a_other.get_server_socket();
	a_other.m_socket = -1; //??
}

TCPServerSocket::~TCPServerSocket()
{
	close(m_socket);
}

void TCPServerSocket::bind(struct sockaddr_in a_sin)
{
	int optVal = 1;

	if(setsockopt(m_socket, SOL_SOCKET, SO_REUSEADDR, &optVal, sizeof(optVal)) < 0)
	{
		std::cout << "reuse of socket failed\n";
	}

	if(::bind(m_socket, (struct sockaddr*)&a_sin, sizeof(a_sin)) < 0)
	{
		std::cout << "server bind failed\n";
	}
	perror("bind");
}

void TCPServerSocket::listen()
{
	if(::listen(m_socket, 15) < 0)
	{
		std::cout << "listening failed\n";
	}
}

TCPClientSocket* TCPServerSocket::accept()
{
	struct sockaddr_in clientSin;
	unsigned int addr_len = sizeof(clientSin);

	int clientSocket = ::accept(m_socket, (struct sockaddr*)&clientSin, &addr_len);

	if(clientSocket < 0)
	{
		std::cout << "client accept failed\n";
	}

	TCPClientSocket* newClient = new TCPClientSocket(clientSocket);

	return newClient;
}

int TCPServerSocket::get_server_socket() const
{
	return m_socket;
}

int TCPServerSocket::SetToNoBlocksMode(int a_socket)
{
	int flags = 0;

	if (-1 == (flags = fcntl(m_socket, F_GETFL)))
	{
		std::cout << "noblock failed\n";
	}

	if(-1 == fcntl(m_socket, F_SETFL, flags | O_NONBLOCK))
	{
		std::cout << "noblock failed\n";
	}

	return 0;
}

}//namespace net