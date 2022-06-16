#include "load.hpp"



namespace act
{

const std::string Load::NAME = "LOAD";

Load::Load(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory)
: m_stack(a_stack)
, m_controller(a_controller)
, m_memory(a_memory)
{
}

Load::~Load()
{
}

void Load::execute()
{
	unsigned long top = m_stack->pop();

	m_stack->push(m_memory->get_data(top));

	++m_controller;
}

Instruction* create_load(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory)
{
	return new Load(a_stack, a_controller, a_memory);
}

}//namespace act