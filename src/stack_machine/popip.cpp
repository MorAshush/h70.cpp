#include <iostream>

#include "popip.hpp"


namespace act
{

const std::string PopIP::NAME = "POPIP";

PopIP::PopIP()
{
}

PopIP::~PopIP()
{
}

int PopIP::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.pointers_stack();

	unsigned long topAddress = s->pop();

	mng::Controller* c = a_bus.controller();

	c->jump_to(topAddress);

	return 1;
}

Instruction* create_popip()
{
	return new PopIP;
}

}//namespace act
