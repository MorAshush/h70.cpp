#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <vector>
#include <cstddef>
#include <cstdint>

namespace net
{

class Handler
{

public:
	virtual ~Handler();

	virtual std::vector<uint8_t>const& handle(std::vector<uint8_t>const& a_buffer) = 0;
};

}//namespace net







#endif //HANDLER_HPP