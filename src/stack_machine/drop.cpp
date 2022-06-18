#include "drop.hpp"


namespace act
{

const std::string Drop::NAME = "DROP";

Drop::Drop()
{
}

Drop::~Drop()
{
}

int Drop::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();
	s->pop();

	++*(a_bus.controller());

	return 1;
}

Instruction* create_drop()
{
	return new Drop;
}

}//namespace act
