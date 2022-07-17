#ifndef CLIENT_SOCKET_HPP
#define CLIENT_SOCKET_HPP

#include <string>
#include <netinet/in.h>
#include <vector>

#include "address_class.hpp"


namespace net
{

class TCPClientSocket
{
public:
	TCPClientSocket(Address const& a_address);

	TCPClientSocket(TCPClientSocket&& a_other); //move ctor

	void operator=(TCPClientSocket && a_other); //move op=

	~TCPClientSocket();

	void write(std::vector<uint8_t>const& a_text) const;
	std::vector<uint8_t> read() const;

private:
	friend class SelectSelector;
	friend class TCPServer;
	friend class TCPServerSocket;
	friend class Processor;
	
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

void run_guessing(TCPClientSocket& a_clientSocket);

}//namespace net

#endif//CLIENT_SOCKET_HPP