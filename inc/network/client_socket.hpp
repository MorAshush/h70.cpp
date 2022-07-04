#ifndef CLIENT_SOCKET_HPP
#define CLIENT_SOCKET_HPP

#include <string>
#include <netinet/in.h>
#include <vector>

namespace net
{

class TCPClientSocket
{
public:
	TCPClientSocket(const char* a_address, const char* a_port);

	TCPClientSocket(TCPClientSocket&& a_other); //move ctor

	void operator=(TCPClientSocket && a_other); //move op=

	~TCPClientSocket();

	void write(std::string const& a_text);
	std::vector<uint8_t> read();

private:
//	friend class Selector;
	friend class TCPServer;
	friend class TCPServerSocket;

	explicit TCPClientSocket(int a_socket);
	int get_client_socket() const;
	void connect();

private:
	TCPClientSocket(TCPClientSocket const& a_other) = delete;
	void operator=(TCPClientSocket const& a_other) = delete;

private:
	int m_socket;
	struct sockaddr_in m_sin;
};

}//namespace net

#endif//CLIENT_SOCKET_HPP