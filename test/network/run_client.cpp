#include <stdio.h> /*printf, perror*/
#include <sys/socket.h> /*AF_INE def*/
#include <arpa/inet.h> /*htons*/
#include <unistd.h> /*close*/
#include <string.h> 

#include "client_socket.hpp"



int main()
{
	char ip[] = "127.0.0.1";
	char port[] = "8888";

	net::TCPClientSocket cs(ip, port);
	cs.client_connect();

	cs.write("Ping");
	cs.write("Ping");
	cs.write("Ping");
	cs.write("Ping");

	return 0;
}