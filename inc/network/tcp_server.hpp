#ifndef TCP_SERVER_HPP
#define TCP_SERVER_HPP

#include <list>
#include <string>
#include <arpa/inet.h>
#include <vector>
#include <memory>

#include "server_socket.hpp"
#include "address_class.hpp"
#include "handler.hpp"
#include "selector_base.hpp"


namespace net
{

class TCPServer
{
public:
	TCPServer(Address const& a_address, Handler* a_handler);
	~TCPServer();

	std::vector<uint8_t> recieve(int a_socket);
	void send(int a_socket, std::vector<uint8_t>const& a_text);
	
	void server_run(SelectorBase* a_selector);

private:
	friend class SelectSelector;

	void check_new_clients(fd_set& a_master);
	void check_cur_clients(fd_set& a_master ,fd_set& a_temp, int a_activityVal);
	int get_socket() const;


private:
//	struct sockaddr_in m_sin;
	TCPServerSocket m_serverSocket;
	Handler* m_handler;
	std::list<TCPClientSocket*> m_clients;

};

}//namespace net





#endif//TCP_SERVER_HPP