#include "jmp.hpp"



namespace act
{

const std::string Jmp::NAME = "JMP";

Jmp::Jmp()
{
}

Jmp::~Jmp()
{
}

int Jmp::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();
	unsigned long address = s->pop();

	mng::Controller* c = a_bus.controller();
	c->jump_to(address);
		
	return 1;
}

Instruction* create_jmp()
{
	return new Jmp();
}

}//namespace act