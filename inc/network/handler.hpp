#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <vector>
#include <cstddef>
#include <cstdint>
#include <utility>

#include "definitions.hpp"
#include "client_socket.hpp"


namespace net
{

class Handler
{

public:
	virtual ~Handler();

	virtual void handle_request(Buffer const& a_buffer, TCPClientSocket* a_client) = 0;
};

}//namespace net







#endif //HANDLER_HPP