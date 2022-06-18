#include "load.hpp"



namespace act
{

const std::string Load::NAME = "LOAD";

Load::Load()
{
}

Load::~Load()
{
}

int Load::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();

	unsigned long top = s->pop();
	unsigned long data = s->get_data(top);

	s->push(data);

	++*m_controller;
		
	return 1;
}

Instruction* create_load()
{
	return new Load;
}

}//namespace act