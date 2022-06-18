#include "compl.hpp"
#include "bus.hpp"

namespace act
{

const std::string Compl::NAME = "COMPL";

Compl::Compl()
{
}

Compl::~Compl()
{
}

int Compl::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();
	unsigned long top = s->pop();

	s->push(~top);

	++*(a_bus.controller());
	
	return 1;
}

Instruction* create_compl()
{
	return new Compl;
}

}//namespace act