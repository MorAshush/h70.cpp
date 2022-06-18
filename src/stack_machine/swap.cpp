#include "swap.hpp"


namespace act
{

const std::string Swap::NAME = "SWAP";

Swap::Swap()
{
}

Swap::~Swap()
{
}

int Swap::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();
	
	unsigned long first = s->pop();
	unsigned long second = s->pop();


	s->push(first);
	s->push(second);

	++*(a_bus.controller());

	return 1;
}

Instruction* create_swap()
{
	return new Swap;
}

}//namespace act
