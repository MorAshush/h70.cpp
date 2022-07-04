#include <iostream>
#include <string>

#include "server_socket.hpp"
#include "tcp_server.hpp"
#include "client_socket.hpp"
#include "handler.hpp"
#include "random_guess.hpp"
#include "selector_base.hpp"
#include "select_selector.hpp"


int main()
{
	net::Address ad("127.0.0.1", "4445");

	net::RandomGuess rg;

	net::TCPServer server(ad, &rg);

	net::SelectSelector selector(&server);

	server.server_run(&selector);

	return 0;
}