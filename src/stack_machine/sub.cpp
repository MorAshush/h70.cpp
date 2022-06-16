#include "sub.hpp"


namespace act
{

const std::string Sub::NAME = "SUB";

Sub::Sub(container::Stack* a_stack, mng::Controller* a_controller)
: m_stack(a_stack)
, m_controller(a_controller)
{
}

Sub::~Sub()
{
}

void Sub::execute()
{
	long first = m_stack->pop();
	long second = m_stack->pop();

	m_stack->push(first - second);

	++m_controller;
}

Instruction* create_sub(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory)
{
	return new Sub(a_stack, a_controller);
}

}//namespace act
