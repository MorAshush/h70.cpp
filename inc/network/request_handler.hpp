#ifndef REQUEST_HANDLER_HPP
#define REQUEST_HANDLER_HPP

#include <vector>

#include "handler.hpp"
#include "../threads/thread_safe_queue.hpp"
#include "client_socket.hpp"


namespace net
{

class RequestHandler: public Handler
{
public:
	RequestHandler(SafeQueue<std::pair<Buffer, TCPClientSocket*>>& a_que);

//	virtual std::vector<uint8_t>const& handle(std::vector<uint8_t>const& a_buffer) = 0;
	void handle_request(Buffer const& a_buffer, TCPClientSocket* a_client);

private:
	SafeQueue<std::pair<Buffer, TCPClientSocket*>> m_requests;
};






}//namespace net


#endif // REQUEST_HANDLER_HPP