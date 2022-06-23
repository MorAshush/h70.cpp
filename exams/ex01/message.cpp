#include <iostream>
#include <cassert>
#include <sys/socket.h>

//#include "client_socket.hpp"


struct message
{
	int m_id;
	double m_speed;
	double m_altitude;
};

void send_a_message(struct message const& a_msg/*, TCPClientSocket a_client*/)
	{
		char* packet = new char[sizeof(struct message) + 3];
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

		std::cout << packet << '\n';

		/*return a_client.send(packet);*/
	}


int main()
{

	struct message a_msg = {56, 36.33, 50.11};

	
	send_a_message(a_msg);
	return 0;
}

