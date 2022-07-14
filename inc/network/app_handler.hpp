#ifndef APP_HANDLER_HPP
#define APP_HANDLER_HPP

#include <vector>

#include "handler.hpp"
#include "../threads/thread_safe_queue.hpp"
#include "client_socket.hpp"


namespace net
{

class AppHandler: public Handler
{
public:
	AppHandler(SafeQueue<Request>& a_que);

//	virtual std::vector<uint8_t>const& handle(std::vector<uint8_t>const& a_buffer) = 0;
	void handle_request(Buffer const& a_buffer, TCPClientSocket* a_client);

private:
	SafeQueue<Request> m_requests;
};






}//namespace net







#endif // APP_HANDLER_HPP