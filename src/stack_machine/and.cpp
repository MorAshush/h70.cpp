#include "and.hpp"

namespace act
{

const std::string And::NAME = "AND";

And::And()
{
}

And::~And()
{
}

unsigned long And::actual_operation(unsigned long a_first, unsigned long a_second)
{
	return a_first & a_second;
}

Instruction* create_and()
{
	return new And;
}

}//namespace act