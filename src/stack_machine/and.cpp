#include "and.hpp"
#include "bus.hpp"


namespace act
{

const std::string And::NAME = "AND";

And::And()
{
}

And::~And()
{
}

int And::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();
	unsigned long first = s->pop();
	unsigned long second = s->pop();

	s->push(first & second);

	++*(a_bus.controller());
	
	return 1;
}

Instruction* create_and()
{
	return new And;
}

}//namespace act