#include "add.hpp"


namespace act
{

Add::Add(container::Stack* a_stack/*, Controller* a_controller*/)
: m_stack(a_stack)
//, m_controller(a_controller)
, m_opCode("ADD")
{

}

std::string const& Add::op_code() const
{
	return m_opCode;
}

int Add::execute()
{
	long first = m_stack->pop();
	long second = m_stack->pop();

	m_stack->push(first + second);

	return 1;
}

}//namespace act
