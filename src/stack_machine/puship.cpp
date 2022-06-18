#include "puship.hpp"


namespace act
{

const std::string PushIP::NAME = "PUSHIP";

PushIP::PushIP()
{
}

PushIP::~PushIP()
{
}

int PushIP::execute(Bus& a_bus)
{
	container::Stack<act::Instructor*>* s = a_bus.pointers_stack();

	mng::Controller* c = a_bus.controller();

	size_t currentIP = c->ip();
	mng::Memory* m = a_bus.memory();

	act::Instruction* nextInstruction = m->instruction_ptr(currentIP + 1);

	s->push(nextInstruction);

	++*(a_bus.controller());
	++*(a_bus.controller());

	return 1;
}

Instruction* create_puship()
{
	return new PushIP();
}

}//namespace act
