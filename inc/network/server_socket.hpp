#ifndef SERVER_SOCKET_HPP
#define SERVER_SOCKET_HPP

#include "address_class.hpp"
#include "client_socket.hpp"

namespace net
{

class TCPServerSocket
{
public:
	TCPServerSocket(Address const& a_address);

	TCPServerSocket(TCPServerSocket&& a_other); //move ctor

	TCPServerSocket& operator=(TCPServerSocket&& a_other); //move op=

	~TCPServerSocket();

	void bind(struct sockaddr_in a_sin);
	void listen();
	TCPClientSocket* accept();

	int get_server_socket() const;

private:
	int SetToNoBlocksMode(int _socket);

	TCPServerSocket(TCPServerSocket const& a_other) = delete; 
	void operator=(TCPServerSocket const& a_other) = delete; 

private:
	int m_socket;
	struct sockaddr_in m_sin;

};


}//namespace net






#endif// SERVER_SOCKET_HPP