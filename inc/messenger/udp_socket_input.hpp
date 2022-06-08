#ifndef UDP_SOCKET_INPUT_HPP
#define UDP_SOCKET_INPUT_HPP

#include <string>
#include <arpa/inet.h>

#include "text_input.hpp"

namespace in
{


class InputUDPsocket: public TextInput
{
public:
	InputUDPsocket(char* a_address, char* a_port);
	~InputUDPsocket();

	virtual std::string recieve();

private:
	struct sockaddr_in m_sockaddr;
	int m_socket;

};


}//namespace in




#endif//UDP_SOCKET_INPUT_HPP