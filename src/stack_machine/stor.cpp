#include "stor.hpp"



namespace act
{

const std::string Stor::NAME = "STOR";

Stor::Stor()
{
}

Stor::~Stor()
{
}

int Stor::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();

	unsigned long address = s->pop();
	unsigned long data = s->pop();

	mng::Memory* m = a_bus.memory();

	m->set_data(address, data);

	++*(a_bus.controller());
		
	return 1;
}

Instruction* create_stor()
{
	return new Stor;
}

}//namespace act