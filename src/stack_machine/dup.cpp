#include "dup.hpp"


namespace act
{

const std::string Dup::NAME = "DUP";

Dup::Dup()
{
}

Dup::~Dup()
{
}

int Dup::execute()
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();
	unsigned long top = s->pop();

	s->push(top);
	s->push(top);

	++*(a_bus.controller());

	return 1;
}

Instruction* create_dup()
{
	return new Dup;
}

}//namespace act
