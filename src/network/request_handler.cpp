#include "request_handler.hpp"

namespace net
{

RequestHandler::RequestHandler(SafeQueue<std::pair<Buffer, TCPClientSocket*>>& a_que)
: m_requests(a_que)
{

}

void RequestHandler::handle_request(Buffer const& a_buffer, TCPClientSocket* a_client)
{
	std::pair<Buffer, TCPClientSocket*> newReq;
	newReq = std::make_pair(a_buffer, a_client);

	m_requests.enqueue(std::move(newReq));
}



}//namespace net
