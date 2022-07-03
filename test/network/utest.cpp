#include <iostream>
#include <string>

#include "server_socket.hpp"
#include "tcp_server.hpp"
#include "client_socket.hpp"


int main()
{
	char ip[] = "127.0.0.1";
	char port[] = "4445";

	net::TCPServer s(ip, port);
	s.server_run();

	return 0;
}