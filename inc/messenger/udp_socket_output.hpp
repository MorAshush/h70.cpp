#ifndef UDP_SOCKET_OUTPUT_HPP
#define UDP_SOCKET_OUTPUT_HPP

#include <string>
#include <arpa/inet.h>

#include "text_output.hpp"


namespace out
{


class OutputUDPsocket: public TextOutput
{
public:
	OutputUDPsocket(char* a_address, char* a_port);
	~OutputUDPsocket();

	virtual void send(std::string const& a_text);

private:
	struct sockaddr_in m_sockaddr;
	int m_socket;

};






}//namespace out


#endif //UDP_SOCKET_OUTPUT_HPP