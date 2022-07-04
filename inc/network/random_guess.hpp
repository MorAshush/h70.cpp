#ifndef RANDOM_GUESS_HPP
#define RANDOM_GUESS_HPP

#include <vector>
#include <cstdint>

#include "handler.hpp"

namespace net
{

class RandomGuess: public Handler
{
public:

	RandomGuess();

	virtual std::vector<uint8_t>const& handle(std::vector<uint8_t>const& a_buffer);

private:
	uint8_t m_num;
	std::vector<uint8_t> m_indication;
};

}//namespace net






#endif //RANDOM_GUESS_HPP