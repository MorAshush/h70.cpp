#include "jnz.hpp"



namespace act
{

const std::string Jnz::NAME = "JNZ";

Jnz::Jnz()
{
}

Jnz::~Jnz()
{
}

int Jnz::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();

	unsigned long a = s->pop();
	unsigned long address = s->pop();

	if(a)
	{
		a_bus.controller()->jump_to(address);
	}
		
	return 1;
}

Instruction* create_jnz()
{
	return new Jnz();
}

}//namespace act