#ifndef CLIENT_HANDLER_HPP
#define CLIENT_HANDLER_HPP

#include <vector>
#include <cstdint>

#include "handler.hpp"

namespace net
{

class ClientHandler: public Handler
{

public:
	ClientHandler();

	virtual std::vector<uint8_t>const& handle(std::vector<uint8_t>const& a_buffer);

private:
	std::vector<uint8_t> m_lastGuess;

};

}//namespace net






#endif //CLIENT_HANDLER_HPP