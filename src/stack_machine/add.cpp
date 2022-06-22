#include "add.hpp"


namespace act
{

const std::string Add::NAME = "ADD";

Add::Add()
{
}

Add::~Add()
{
}

unsigned long Add::actual_operation(unsigned long a_first, unsigned long a_second)
{
	return a_first + a_second;
}

Instruction* create_add()
{
	return new Add;
}


}//namespace act
