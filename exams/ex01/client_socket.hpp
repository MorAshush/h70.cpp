#ifndef CLIENT_SOCKET_HPP
#define CLIENT_SOCKET_HPP

#include <iostream>
#include <cassert>
#include <sys/socket.h> 


class ClientSocket
{
public:    
	ClientSocket();

	int connect(char* a_serverAddr);

	int send(char* a_data);

	int recieve();

	int get_socket();

private:
	int m_socket;
	char* m_buffer; // should define a max size?
};






#endif //CLIENT_SOCKET_HPP