#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <vector>
#include <cstddef>
#include <cstdint>
#include <utility>


namespace net
{

class TCPClientSocket;

typedef std::vector<uint8_t> Buffer;
typedef std::pair<Buffer, TCPClientSocket*> Request;

class Handler
{

public:
	virtual ~Handler();

	virtual void handle_request(Buffer const& a_buffer, TCPClientSocket* a_client) = 0;
};

}//namespace net







#endif //HANDLER_HPP