#include <string>

#include "random_guess.hpp"

namespace net
{

RandomGuess::RandomGuess()
: m_num(rand() % 256)
, m_indication(1, 0)
{

}

std::vector<uint8_t>const& RandomGuess::handle(std::vector<uint8_t>const& a_buffer)
{
	uint8_t guess = a_buffer[0];

	if(guess < m_num)
	{
		m_indication[0] = '<';
	}
	else if(guess > m_num)
	{
		m_indication[0] = '>';
	}

	m_indication[0] = '=';

	return m_indication;
}

}//namespace net