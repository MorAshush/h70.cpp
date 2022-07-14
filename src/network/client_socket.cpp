#include <stdio.h> /*printf, perror*/
#include <sys/socket.h> /*AF_INE def*/
#include <arpa/inet.h> /*htons*/
#include <unistd.h> /*close*/
#include <stdlib.h> /*atoi*/
#include <errno.h>
#include <string.h> 
#include <iostream>

#include "client_socket.hpp"


namespace net
{

TCPClientSocket::TCPClientSocket(int a_socket)
: m_socket(a_socket)
{
	if(a_socket < 0)
	{
		std::cout << "socket initialization failed\n";
		//throw "socket initialization failed";
	}
}

TCPClientSocket::TCPClientSocket(Address const& a_address)
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);

	if(sock < 0)
	{
		std::cout << "socket initialization failed\n";
		//throw "socket initialization failed";
	}

	m_socket = sock;

	memset(&m_sin, 0, sizeof(m_sin));

	m_sin.sin_family = AF_INET;
	m_sin.sin_addr.s_addr = inet_addr(a_address.get_ip());
	m_sin.sin_port = htons(a_address.get_port());

	connect();
}

TCPClientSocket::TCPClientSocket(TCPClientSocket&& a_other)
: m_socket(a_other.get_client_socket())
{
	a_other.m_socket = -1; //??
}

void TCPClientSocket::operator=(TCPClientSocket&& a_other)
{
	if(&a_other != this)
	{
		close(m_socket);
		m_socket = a_other.get_client_socket();
		a_other.m_socket = -1; //??
	}
}

TCPClientSocket::~TCPClientSocket()
{
	close(m_socket);
}

void TCPClientSocket::connect()
{
	std::cout << "connecting to server\n";

/*		if(bind(m_socket, (struct sockaddr*)&m_sin, sizeof(m_sin)) < 0)
	{
		std::cout << "client bind failed\n";
	}
*/
	int status = ::connect(m_socket, (struct sockaddr*)&m_sin, sizeof(m_sin));
	if(status < 0)
	{
		//throw connection failed;
		std::cout << "connect: failed\n";
	}
}

void TCPClientSocket::write(std::vector<uint8_t>const& a_text) const
{
	int sentBytes = send(m_socket, a_text.data(), a_text.size(), 0);
	std::cout << "sentBytes: " << sentBytes << " to socket: " << m_socket << '\n';

	if(sentBytes < 0)
	{
		perror("recv");
		std::cout << "client send failed\n";
		//throw "send failed";
	}
}

std::vector<uint8_t> TCPClientSocket::read() const
{
	std::vector<uint8_t> buffer(4096, 0);

	int readBytes = recv(m_socket, buffer.data(), buffer.size(), 0);

	if(readBytes == -1)
	{
		perror("recv");
		std::cout << "client recieve failed\n";
		//throw "client recieve failed";
	}
	else if(readBytes == 0)
	{
		perror("recv");
		//remove client from list!
		std::cout << "client recieve: socket closed error\n";
		//throw "socket closed error";
	}

	for(auto c : buffer)
	{
		std::cout << c;
	}
	std::cout << '\n';

//	data += '\0';

	return buffer;
}

int TCPClientSocket::get_client_socket() const
{
	return m_socket;
}

void run_guessing(TCPClientSocket& a_clientSocket)
{
	uint8_t randGuess;
	std::cout << "give your first guess\n";
	std::cin >> randGuess;
	
	std::vector<uint8_t> guess(1, randGuess);

	a_clientSocket.write(std::move(guess));

//	std::string correct("correct");
//	std::vector<uint8_t> victory(correct.begin(), correct.end());

	while(true)
	{
		std::vector<uint8_t> buffer = a_clientSocket.read();

//		auto indication = a_handler->handle(buffer);
		if(buffer[0] == '=')
		{
			break;
		}
		else if (buffer[0] == '>')
		{
			std::cout << "too big. try again: \n";
		}
		else if (buffer[0] == '<')
		{
			std::cout << "too small. try again: \n";
		}

		std::cin >> randGuess;

		guess[0] = randGuess;

		a_clientSocket.write(guess);
	}

	std::cout << "you guessed correctly!\n";
}

}