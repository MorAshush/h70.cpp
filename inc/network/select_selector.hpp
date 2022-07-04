#ifndef SELECT_SELECTOR_HPP
#define SELECT_SELECTOR_HPP

#include "selector_base.hpp"
#include "tcp_server.hpp"

namespace net
{

class SelectSelector: public SelectorBase
{

public:
	SelectSelector(TCPServer* a_server);

	virtual void select();

private:
	TCPServer* m_server;

};

}//namespace net













#endif //SELECT_SELECTOR_HPP