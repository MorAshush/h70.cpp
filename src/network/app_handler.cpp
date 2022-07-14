#include "app_handler.hpp"

namespace net
{

AppHandler::AppHandler(SafeQueue<Request>& a_que)
: m_requests(a_que)
{

}

void AppHandler::handle_request(Buffer const& a_buffer, TCPClientSocket* a_client)
{
	Request newReq;
	newReq = std::make_pair(a_buffer, a_client);

	m_requests.enqueue(std::move(newReq));
}



}//namespace net
