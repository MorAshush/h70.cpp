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

int Or::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();

	unsigned long first = s->pop();
	unsigned long second = s->pop();

	s->push(first | second);

	++*(a_bus.controller());
	
	return 1;
}

Instruction* create_or()
{
	return new Or;
}

}//namespace act