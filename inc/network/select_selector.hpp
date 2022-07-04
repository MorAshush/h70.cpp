#ifndef SELECT_SELECTOR_HPP
#define SELECT_SELECTOR_HPP

#include "selector_base.hpp"
#include "tcp_server.hpp"

namespace net
{

class SelectSelctor: public SelectorBase
{

public:
	SelectSelctor(TCPServer& a_server, std::function<void(fd_set&)> a_onAccept, std::function<void(fd_set&)> a_read_write);

};

}//namespace net













#endif //SELECT_SELECTOR_HPP