#include "add.hpp"


namespace act
{

const std::string Add::NAME = "ADD";

Add::Add(container::Stack* a_stack, mng::Controller* a_controller)
: m_stack(a_stack)
, m_controller(a_controller)
{
}

Add::~Add()
{
}

void Add::execute()
{
	long first = m_stack->pop();
	long second = m_stack->pop();

	m_stack->push(first + second);

	++m_controller;
}

Instruction* create_add(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory)
{
	return new Add(a_stack, a_controller);
}

}//namespace act
