#include <cstring>
#include <iostream>
#include <sys/select.h> /*select*/

#include "tcp_server.hpp"



namespace net
{

TCPServer::TCPServer(const char* a_address, const char* a_port)
: m_serverSocket(a_address, a_port)
{
}

TCPServer::~TCPServer()
{

}
/*ORIGIN
std::vector<uint8_t> TCPServer::server_recieve(int a_socket)
{
	std::cout << "in server recieve\n";

	char buffer[4096];
	int expectedDataLen = sizeof(buffer);

	int readBytes = recv(a_socket, buffer, expectedDataLen, 0);
	std::cout << "readBytes: " << readBytes << '\n';

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

	buffer[readBytes] = '\0';

	std::string dataString(buffer);

	return dataString;
}
*/

std::vector<uint8_t> TCPServer::recieve(int a_socket)
{
	std::cout << "in server recieve\n";

	std::vector<uint8_t> buffer(4096, 0);

	int readBytes = recv(a_socket, buffer.data(), buffer.size(), 0);
	std::cout << "readBytes: " << readBytes << '\n';

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
			throw "server send failed";
		}
}

void TCPServer::CheckNewClients(fd_set& a_master)
{
	m_clients.push_back(m_serverSocket.accept());

	auto last = m_clients.rbegin();
	int socket = last->get_client_socket();
	
	std::cout << "client connected at socket: " << socket << '\n';
	FD_SET(socket, &a_master);
}
/* ORIGIN
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
				std::cout << "trying to call server_recieve\n";

				std::string msg = server_recieve(socket);

				std::cout << "msg from client socket: " << socket << '\n' << "pong\n" << '\n';
			}
			catch(...) //exception of closed socket or recv failed
			{
				it = m_clients.erase(it);
				FD_CLR(socket, &a_master);
//				it->~TCPClientSocket();
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
*/

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
				std::cout << "trying to call server_recieve\n";

				std::vector<uint8_t> buffer;
				buffer = recieve(socket);

				std::cout << "msg from client socket: " << socket << '\n' << "pong\n" << '\n';

				send(socket, "this is a msg from server\n");
			}
			catch(...) //exception of closed socket or recv failed
			{
				it = m_clients.erase(it);
				FD_CLR(socket, &a_master);
//				it->~TCPClientSocket();
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

	for(size_t i = 0; i < 5; ++i)
	{
		std::cout << "listening socket: " << listeningSocket << '\n';
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
				std::cout << "checked for new clients.\n";
			}

			CheckCurClients(masterReadfds, tempReadfds, activity);
		}	
	}
}

}//namespace net