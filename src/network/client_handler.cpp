#include <string>

#include "client_handler.hpp"

namespace net
{

ClientHandler::ClientHandler()
: m_lastGuess(0)
{

}

std::vector<uint8_t>const& ClientHandler::handle(std::vector<uint8_t>const& a_buffer)
{
	if(a_buffer[0] == '=')
	{
		std::string correct("correct");
		std::vector<uint8_t> victory(correct.begin(), correct.end());
		m_lastGuess = std::move(victory);
		return m_lastGuess;
	}
	else
	{
		m_lastGuess = a_buffer;
		return m_lastGuess;
	}
}

}//namespace net