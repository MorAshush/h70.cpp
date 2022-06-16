#include "and.hpp"

namespace act
{

const std::string And::NAME = "AND";

And::And(container::Stack* a_stack, mng::Controller* a_controller)
: m_stack(a_stack)
, m_controller(a_controller)
{
}

And::~And()
{
}

void And::execute()
{
	long first = m_stack->pop();
	long second = m_stack->pop();

	m_stack->push(first & second);

	++m_controller;
}

Instruction* create_and(container::Stack* a_stack, mng::Controller* a_controller, mng::Memory* a_memory)
{
	return new And(a_stack, a_controller);
}

}//namespace act