#include "nop.hpp"


namespace act
{

const std::string Nop::NAME = "NOP";

Nop::Nop(mng::Controller* a_controller)
: m_controller(a_controller)
{
}

Nop::~Nop()
{
}

void Nop::execute()
{
	++m_controller;
	return;
}

Instruction* create_nop(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory)
{
	return new Nop(a_controller);
}

}//namespace act