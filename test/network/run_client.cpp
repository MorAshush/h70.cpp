#include <stdio.h> /*printf, perror*/
#include <sys/socket.h> /*AF_INE def*/
#include <arpa/inet.h> /*htons*/
#include <unistd.h> /*close*/
#include <string.h> 

#include "client_socket.hpp"



int main()
{
	char ip[] = "127.0.0.1";
	char port[] = "4445";

	net::TCPClientSocket cs(ip, port);
	cs.connect();

	cs.write("Ping");
	cs.write("Ping");
	cs.write("Ping");
	cs.write("Ping");

	cs.read();
	cs.read();
	cs.read();

	return 0;
}