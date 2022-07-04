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
	uint8_t newGuess;

	switch(a_buffer[0])
	{
		case '<':
			newGuess = rand() % 256 + static_cast<int>(m_lastGuess[0]);
			break; 

		case '>':
			newGuess = rand() % m_lastGuess[0] - 1;
			break;
	}

	m_lastGuess[0] = newGuess;

	return m_lastGuess;
}

}//namespace net