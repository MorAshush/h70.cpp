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

int Add::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();

	unsigned long first = s->pop();
	unsigned long second = s->pop();

	s->push(first + second);

	++*(a_bus.controller());

	return 1;
}

Instruction* create_add()
{
	return new Add;
}

}//namespace act
