#include <cstring>
#include <iostream>
#include <sys/select.h> /*select*/
#include <unistd.h> /*close*/

#include "tcp_server.hpp"



namespace net
{

TCPServer::TCPServer(Address const& a_address, Handler* a_handler)
: m_serverSocket(a_address)
, m_handler(std::move(a_handler))
{
}

TCPServer::~TCPServer()
{
	for(auto client : m_clients)
	{
		delete client;
	}

	delete m_handler;
}

std::vector<uint8_t> TCPServer::recieve(int a_socket)
{
	std::vector<uint8_t> buffer(4096, 0);

	int readBytes = recv(a_socket, buffer.data(), buffer.size(), 0);
	std::cout << "\nreadBytes: " << readBytes << '\n';

	if(readBytes == -1)
	{
		perror("recv");
		std::cout << "server recieve failed\n";
	}
	else if(readBytes == 0)
	{
		perror("recv");
		std::cout << "socket closed\n";
	}

	for(auto c : buffer)
	{
		std::cout << c;
	}
	std::cout << '\n';

	return buffer;
}


void TCPServer::send(int a_socket, std::vector<uint8_t>const& a_text)
{
	int sentBytes = ::send(a_socket, a_text.data(), a_text.size(), 0);
	std::cout << "sent " << sentBytes << " Bytes to client at socket: " << a_socket << '\n';

	if(sentBytes < 0)
	{
		perror("recv");
		std::cout << "server send failed\n";
		//throw "server send failed";
	}
}

void TCPServer::check_new_clients(fd_set& a_master)
{
	m_clients.push_back(std::move(m_serverSocket.accept()));

	auto last = m_clients.rbegin();
	int socket = (*last)->get_client_socket();
	
	std::cout << "\nclient connected at socket: " << socket << '\n';
	FD_SET(socket, &a_master);
}

void TCPServer::check_cur_clients(fd_set& a_master ,fd_set& a_temp, int a_activityVal)
{
	auto it = m_clients.begin();
	auto end = m_clients.end();

	while(it != end)
	{
		int socket = (*it)->get_client_socket();
		if(FD_ISSET(socket, &a_temp))
		{
			try
			{
				std::vector<uint8_t> buffer;
				buffer = recieve(socket);

				auto indication = m_handler->handle(buffer);

				send(socket, indication);
			}
			catch(...) //exception of closed socket or recv failed
			{
				close((*it)->get_client_socket());
				delete (*it);
				m_clients.remove(*it);
				FD_CLR(socket, &a_master);
			}

			--a_activityVal;
		}

		if(a_activityVal == 0)
		{
			break;
		}

		++it;
	}
}

void TCPServer::server_run(SelectorBase* a_selector)
{
	while(true)
	{
		a_selector->select();
	}
}
/*
void TCPServer::server_run()
{
	fd_set masterReadfds;
	fd_set tempReadfds;

	int listeningSocket = m_serverSocket.get_server_socket();

	FD_ZERO(&masterReadfds);
	FD_SET(listeningSocket, &masterReadfds);

	while(true)
	{
		FD_ZERO(&tempReadfds);
		tempReadfds = masterReadfds;

		int maxSockets = 1024;
		int activity = select(maxSockets, &tempReadfds, nullptr, nullptr, nullptr);
		if(activity < 0)
		{
			perror("select");
		}
		std::cout << "activity: " << activity << '\n';

		if(activity > 0)
		{
			if(FD_ISSET(listeningSocket, &tempReadfds))
			{
				check_new_clients(masterReadfds);
			}

			check_cur_clients(masterReadfds, tempReadfds, activity);
		}	
	}
}
*/

int TCPServer::get_socket() const
{
	return m_serverSocket.get_server_socket();
}

}//namespace net