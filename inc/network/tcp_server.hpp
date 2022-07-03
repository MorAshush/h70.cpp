#ifndef TCP_SERVER_HPP
#define TCP_SERVER_HPP

#include <list>
#include <string>
#include <arpa/inet.h>
#include <vector>

#include "server_socket.hpp"
//#include "handler.hpp"
//#include "protocol.hpp"

class Handler;
class Protocol;

namespace net
{

class TCPServer
{
public:
	TCPServer(const char* a_address, const char* a_port);
	~TCPServer();

	std::vector<uint8_t> recieve(int a_socket);
	void send(int a_socket, std::string const& a_text);
	void server_run();

private:
	friend class SelectSelctor;
	void CheckNewClients(fd_set& a_master);
	void CheckCurClients(fd_set& a_master ,fd_set& a_temp, int a_activityVal);


private:
//	struct sockaddr_in m_sin;
	TCPServerSocket m_serverSocket;
//	Protocol m_protocol;
	std::list<TCPClientSocket> m_clients;

};

}//namespace net





#endif//TCP_SERVER_HPP