#include <cstring>
#include <iostream>
#include <sys/select.h> /*select*/
#include <unistd.h> /*close*/

#include "tcp_server.hpp"



namespace net
{

TCPServer::TCPServer(const char* a_address, const char* a_port, Handler* a_handler)
: m_serverSocket(a_address, a_port)
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


void TCPServer::send(int a_socket, std::string const& a_text)
{
	char* cstr = new char[a_text.length() + 1];

		strcpy(cstr, a_text.c_str());

		int sentBytes = ::send(a_socket, cstr, strlen(cstr), 0);
		std::cout << "sentBytes to client at socket: " << a_socket << ", " << sentBytes << '\n';

		delete [] cstr;

		if(sentBytes < 0)
		{
			perror("recv");
			std::cout << "server send failed\n";
			//throw "server send failed";
		}
}

void TCPServer::CheckNewClients(fd_set& a_master)
{
	std::cout << "\nchecking for new clients...\n";
	m_clients.push_back(std::move(m_serverSocket.accept()));

	auto last = m_clients.rbegin();
	int socket = (*last)->get_client_socket();
	
	std::cout << "client connected at socket: " << socket << '\n';
	FD_SET(socket, &a_master);
}

void TCPServer::CheckCurClients(fd_set& a_master ,fd_set& a_temp, int a_activityVal)
{
	std::cout << "\nchecking for new messages...\n";

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

				std::cout << "\nrecieved msg from client in socket: " << socket << '\n';

				send(socket, "this is a msg from server\n");
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
				CheckNewClients(masterReadfds);
			}

			CheckCurClients(masterReadfds, tempReadfds, activity);
		}	
	}
}

}//namespace net