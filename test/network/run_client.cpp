#include <stdio.h> /*printf, perror*/
#include <sys/socket.h> /*AF_INE def*/
#include <arpa/inet.h> /*htons*/
#include <unistd.h> /*close*/
#include <string.h>
#include <vector> 

#include "client_socket.hpp"
#include "client_handler.hpp"


int main()
{
	net::Address ad("127.0.0.1", "4445");

//	net::ClientHandler handler;

	net::TCPClientSocket c(ad);

	run_guessing(c);
	

	return 0;
}