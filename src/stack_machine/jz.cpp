#include "jz.hpp"



namespace act
{

const std::string Jz::NAME = "JZ";

Jz::Jz()
{
}

Jz::~Jz()
{
}

int Jz::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();
	unsigned long a = s->pop();
	unsigned long address = s->pop();

	if(!a)
	{
		a_bus.controller()->jump_to(address);
	}
		
	return 1;
}

Instruction* create_jz()
{
	return new Jz();
}

}//namespace act