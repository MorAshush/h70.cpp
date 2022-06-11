#include <stdio.h> /*printf, perror*/
#include <sys/socket.h> /*AF_INE def*/
#include <arpa/inet.h> /*htons*/
#include <unistd.h> /*close*/
#include <string.h> 

#include "udp_socket_output.hpp"



int main()
{
	std::string ipString = "127.0.0.1";
	std::string portString = "5555";

	char* ip = new char[ipString.length() + 1];
	char* port = new char[portString.length() + 1];

	strcpy(ip, ipString.c_str());
	strcpy(port, portString.c_str());

	out::OutputUDPsocket c(ip, port);
	c.send("Ping");
	c.send("Pong");
	c.send("Ping");
	c.send("Pong");
	c.send("EOM");

	return 0;
}