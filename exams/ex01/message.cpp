#include <iostream>
#include <cassert>
#include <sys/socket.h>

#include "client_socket.hpp"


struct message
{
	int m_id;
	double m_speed;
	double m_altitude;
};


int send_a_message(struct message const& a_msg, TCPClientSocket a_client)
{
	char* packet = new char[sizeof(struct message)];
	char* ptr = packet;

	*ptr = sizeof(int);
	++ptr;
	*ptr = a_msg.m_id;
	
	ptr += sizeof(int);

	*ptr = 2 * sizeof(int);
	++ptr;
	*ptr = a_msg.m_speed;
	
	ptr += 2 * sizeof(int);

	*ptr = 2 * sizeof(int);
	++ptr;
	*ptr = a_msg.m_altitude;

	return a_client.send(packet);
}
