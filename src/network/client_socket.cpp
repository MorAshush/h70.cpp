#include <stdio.h> /*printf, perror*/
#include <sys/socket.h> /*AF_INE def*/
#include <arpa/inet.h> /*htons*/
#include <unistd.h> /*close*/
#include <stdlib.h> /*atoi*/
#include <string.h> 
#include <iostream>

#include "client_socket.hpp"


namespace net
{

	TCPClientSocket::TCPClientSocket(int a_socket)
	: m_socket(a_socket)
	{

	}

	TCPClientSocket::TCPClientSocket(char* a_address, char* a_port)
	{
		int sock = socket(AF_INET, SOCK_STREAM, 0);

		if(sock < 0)
		{
			//throw socket_initialization failed
		}

		m_socket = sock;

		memset(&m_sin, 0, sizeof(m_sin));

		m_sin.sin_family = AF_INET;
		m_sin.sin_addr.s_addr = inet_addr(a_address);
		m_sin.sin_port = htons(atoi(a_port));
	}

	TCPClientSocket::TCPClientSocket(TCPClientSocket&& a_other)
	: m_socket(a_other.get_client_socket())
	{
		a_other.m_socket = -1; //??
	}

	void TCPClientSocket::operator=(TCPClientSocket&& a_other)
	{
		m_socket = a_other.get_client_socket();
		a_other.m_socket = -1; //??
	}

	TCPClientSocket::~TCPClientSocket()
	{
		close(m_socket);
	}

	void TCPClientSocket::client_connect()
	{
		std::cout << "connecting to server\n";

/*		if(bind(m_socket, (struct sockaddr*)&m_sin, sizeof(m_sin)) < 0)
		{
			std::cout << "client bind failed\n";
		}
*/
		int status = connect(m_socket, (struct sockaddr*)&m_sin, sizeof(m_sin));
		if(status < 0)
		{
			//throw connection failed;
			std::cout << "connect: failed\n";
		}
	}

	void TCPClientSocket::write(std::string const& a_text)
	{
		char* cstr = new char[a_text.length() + 1];

		strcpy(cstr, a_text.c_str());

		int sentBytes = send(m_socket, cstr, strlen(cstr), 0);
		std::cout << "sentBytes: " << sentBytes << " to socket: " << m_socket << '\n';

		delete [] cstr;

		if(sentBytes < 0)
		{
			//throw send failed;
		}
	}

	std::string TCPClientSocket::read()
	{
		char buffer[4096];
		int expectedDataLen = sizeof(buffer);

		std::string data;
		int readBytes = recv(m_socket, buffer, expectedDataLen, 0);

		if(readBytes < 0)
		{
			//throw recieve failed;
		}
		else if(readBytes == 0)
		{
			//throw socket closed error;
		}

		data += '\0';

		return data;
	}

	int TCPClientSocket::get_client_socket() const
	{
		return m_socket;
	}

}