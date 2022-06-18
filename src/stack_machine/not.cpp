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

int Not::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();

	unsigned long num = s->pop();

	s->push(!num);

	++*(a_bus.controller());
	
	return 1;
}

Instruction* create_not()
{
	return new Not;
}

}//namespace act