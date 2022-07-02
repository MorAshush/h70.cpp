#ifndef SERVER_SOCKET_HPP
#define SERVER_SOCKET_HPP

#include "client_socket.hpp"

namespace net
{

class TCPServerSocket
{
public:
	TCPServerSocket();

	TCPServerSocket(TCPServerSocket const& a_other); //copy ctor---declared cut not defined
	TCPServerSocket(TCPServerSocket&& a_other); //move ctor

	void operator=(TCPServerSocket const& a_other); //copy op=---declared cut not defined
	void operator=(TCPServerSocket&& a_other); //move op=

	~TCPServerSocket();

	void ss_bind(struct sockaddr_in a_sin);
	void ss_listen();
	TCPClientSocket ss_accept();

	int get_server_socket() const;

private:
	int SetToNoBlocksMode(int _socket);

private:
	int m_socket;

};


}//namespace net






#endif// SERVER_SOCKET_HPP