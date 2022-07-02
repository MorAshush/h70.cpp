#ifndef CLIENT_SOCKET_HPP
#define CLIENT_SOCKET_HPP

#include <string>
#include <netinet/in.h>

namespace net
{

class TCPClientSocket
{
public:
	explicit TCPClientSocket(int a_socket);
	TCPClientSocket(char* a_address, char* a_port);

	TCPClientSocket(TCPClientSocket const& a_other); //copy ctor---declared cut not defined
	TCPClientSocket(TCPClientSocket&& a_other); //move ctor

	void operator=(TCPClientSocket const& a_other); //copy op=---declared cut not defined
	void operator=(TCPClientSocket && a_other); //move op=

	~TCPClientSocket();

	void client_connect();
	void write(std::string const& a_text);
	std::string read();

	int get_client_socket() const;

private:
	int m_socket;
	struct sockaddr_in m_sin;
};

}//namespace net

#endif//CLIENT_SOCKET_HPP