#include <string>
#include <iostream>

#include "random_guess.hpp"

namespace net
{

RandomGuess::RandomGuess()
: m_num(static_cast<uint8_t>(rand() % 256))
, m_indication(1, 0)
{
	std::cout << "the chosen number is: " << m_num << "\n\n";
}

std::vector<uint8_t>const& RandomGuess::handle(std::vector<uint8_t>const& a_buffer)
{
	uint8_t guess = a_buffer[0];
	std::cout << "client's guess is: " << guess << "\n\n";

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