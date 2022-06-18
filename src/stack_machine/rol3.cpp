#include "rol3.hpp"


namespace act
{

const std::string RolThree::NAME = "ROL3";

RolThree::RolThree()
{
}

RolThree::~RolThree()
{
}

int RolThree::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();

	unsigned long first = s->pop();
	unsigned long second = s->pop();
	unsigned long third = s->pop();

	s->push(second);
	s->push(third);
	s->push(first);

	++*(a_bus.controller());

	return 1;
}

Instruction* create_rolThree()
{
	return new RolThree;
}

}//namespace act
