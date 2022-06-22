#include "or.hpp"

namespace act
{

const std::string Or::NAME = "OR";

Or::Or()
{
}

Or::~Or()
{
}

unsigned long Or::actual_operation(unsigned long a_first, unsigned long a_second)
{
	return a_first | a_second;
}

Instruction* create_or()
{
	return new Or;
}

}//namespace act