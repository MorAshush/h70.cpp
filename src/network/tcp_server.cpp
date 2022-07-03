#include <cstring>
#include <iostream>
#include <sys/select.h> /*select*/

#include "tcp_server.hpp"



namespace net
{

TCPServer::TCPServer(char* a_address, char* a_port)
{
	memset(&m_sin, 0, sizeof(m_sin));

	m_sin.sin_family = AF_INET;
    m_sin.sin_addr.s_addr = inet_addr(a_address); 
    m_sin.sin_port = htons(atoi(a_port));

    m_serverSocket.ss_bind(m_sin);
    m_serverSocket.ss_listen();
}

TCPServer::~TCPServer()
{

}

std::string TCPServer::server_recieve(int a_socket)
{
	char buffer[4096];
	int expectedDataLen = sizeof(buffer);

	int readBytes = recv(a_socket, buffer, expectedDataLen, 0);
	std::cout << "readBytes: " << readBytes << '\n';

	if(readBytes < 0)
	{
		std::cout << "server recieve failed\n";
	}
	else if(readBytes == 0)
	{
		std::cout << "socket closed\n";
	}

	buffer[readBytes] = '\0';

	std::string dataString(buffer);

	return dataString;
}
/*
std::string TCPServer::server_send()
{

}
*/

void TCPServer::CheckNewClients(fd_set& a_master)
{
	int socket = -1;

	TCPClientSocket newClient = m_serverSocket.ss_accept();

	std::cout << "client connected at socket: " << newClient.get_client_socket() << '\n';

	m_clients.push_back(std::move(newClient));
	
	FD_SET(socket, &a_master);
}

void TCPServer::CheckCurClients(fd_set& a_master ,fd_set& a_temp, int a_activityVal)
{
	std::cout << "checking for new messages...\n";

	auto it = m_clients.begin();
	auto end = m_clients.end();

	while(it != end)
	{
		int socket = it->get_client_socket();
		if(FD_ISSET(socket, &a_temp))
		{
			try
			{
				std::string msg = server_recieve(socket);
				std::cout << "msg from client socket: " << socket << '\n' << msg << '\n';
			}
			catch(...) //exception of closed socket or recv failed
			{
				it = m_clients.erase(it);
				FD_CLR(socket, &a_master);
			}

			--a_activityVal;
		}

		if(a_activityVal == 0)
		{
			break;
		}
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
		std::cout << "listening socket: " << listeningSocket << '\n';
		FD_ZERO(&tempReadfds);
		tempReadfds = masterReadfds;

		int maxSockets = 1024;
		std::cout << "line 155\n";
		int activity = select(maxSockets, &tempReadfds, nullptr, nullptr, nullptr);
		if(activity < 0)
		{
			std::cout << "select error\n";
		}
		std::cout << "activity: " << activity << '\n';

		if(activity > 0)
		{
			if(FD_ISSET(listeningSocket, &tempReadfds))
			{
				CheckNewClients(masterReadfds);
				std::cout << "checked for new clients.\n";
			}

			CheckCurClients(masterReadfds, tempReadfds, activity);
		}	
	}
}

}//namespace net