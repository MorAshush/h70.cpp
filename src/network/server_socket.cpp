#include "server_socket.hpp"
#include <sys/socket.h> /*AF_INE def*/
#include <arpa/inet.h>  /*htons*/
#include <unistd.h>     /*close*/
#include <stdlib.h>     /*size_t*/
#include <errno.h>      
#include <fcntl.h>      /*fcntl*/
#include <sys/select.h> /*select*/

namespace net
{

TCPServerSocket::TCPServerSocket()
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);

	if(sock < 0)
	{
		//throw socket_initialization failed
	}

	m_socket = sock;
	int status = SetToNoBlocksMode(m_socket);
	if(status < 0)
	{
		//throw no block failed;
	}
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

void TCPServerSocket::ss_bind(struct sockaddr_in a_sin)
{
	int optVal = 1;

	if(setsockopt(m_socket, SOL_SOCKET, SO_REUSEADDR, &optVal, sizeof(optVal)) < 0)
	{
		//throw reuse of socket failed;
	}

	if(bind(m_socket, (struct sockaddr*)&a_sin, sizeof(a_sin)) < 0)
	{
		//throw bind failed;
	}
}

void TCPServerSocket::ss_listen()
{
	if(listen(m_socket, 15) < 0)
	{
		//throw listen failed;
	}
}

TCPClientSocket TCPServerSocket::ss_accept()
{
	struct sockaddr_in clientSin;
	unsigned int addr_len = sizeof(clientSin);

	int clientSocket = accept(m_socket, (struct sockaddr*)&clientSin, &addr_len);

	if(clientSocket < 0)
	{
		//throw client acception failed;
	}

	return TCPClientSocket(clientSocket);
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
		//throw error at fcntl
	}

	if(-1 == fcntl(m_socket, F_SETFL, flags | O_NONBLOCK))
	{
		//throw error at fcntl
	}

	return 0;
}

}//namespace net