#include <stdio.h> /*printf, perror*/
#include <sys/socket.h> /*AF_INE def*/
#include <arpa/inet.h> /*htons*/
#include <unistd.h> /*close*/
#include <string.h>
#include <vector> 

#include "udp_socket_output.hpp"



int main()
{
	net::Address ad("127.0.0.1", "4445");

	out::OutputUDPsocket c(ad);
	c.send(std::vector<uint8_t> geuss(1, 56));

	return 0;
}