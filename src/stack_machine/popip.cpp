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
	container::Stack<act::Instructor*>* s = a_bus.pointers_stack();

	act::Instruction* toptInstruction = s->pop();

	mng::Memory* m = a_bus.memory();

	size_t address = m->instruction_address(toptInstruction);

	a_bus.controller()->jump_to(address);

	return 1;
}

Instruction* create_popip()
{
	return new PopIP;
}

}//namespace act
