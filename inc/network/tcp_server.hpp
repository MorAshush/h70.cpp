#ifndef TCP_SERVER_HPP
#define TCP_SERVER_HPP

#include <list>
#include <string>
#include <arpa/inet.h>

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
	TCPServer(char* a_address, char* a_port);
	~TCPServer();

	std::string server_recieve(int a_socket);
	std::string server_send();
	void server_run();

private:
	void CheckNewClients(fd_set& a_master);
	void CheckCurClients(fd_set& a_master ,fd_set& a_temp, int a_activityVal);


private:
	struct sockaddr_in m_sin;
	TCPServerSocket m_serverSocket;
//	Handler m_handler;
//	Protocol m_protocol;
	std::list<TCPClientSocket> m_clients;

};

}//namespace net





#endif//TCP_SERVER_HPP