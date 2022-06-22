#include "not.hpp"

namespace act
{

const std::string Not::NAME = "NOT";

Not::Not()
{
}

Not::~Not()
{
}

unsigned long Not::actual_operation(unsigned long a_num, Bus& a_bus)
{
	return !a_num;
}

Instruction* create_not()
{
	return new Not;
}

}//namespace act