#include "dropip.hpp"
#include "stack_template.hpp"
#include "controller.hpp"

namespace act
{

const std::string DropIP::NAME = "DROPIP";

DropIP::DropIP()
{
}

DropIP::~DropIP()
{
}

int DropIP::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.pointers_stack();

	s->pop();

	++*(a_bus.controller());

	return 1;
}

Instruction* create_dropip()
{
	return new DropIP();
}

}//namespace act
