#include <exception>
#include <iostream>

#include "ip_stack.hpp"
#include "stack_overflow.hpp"
#include "stack_underflow.hpp"

namespace container
{


IPStack::IPStack(size_t a_size)
: m_capacity(a_size)
, m_size(0)
{
}

void IPStack::push(unsigned long a_address)
{
	if(! (m_size < m_capacity))
	{
		throw expt::OverFlowErr("IPStack::push", "overflow error: stack is overflowed");
	}

	m_stack.push_back(a_address);
	++m_size;
}

unsigned long IPStack::pop()
{
	if(m_size == 0)
	{
		throw expt::UnderFlowErr("IPStack::pop", "underflow error: stack is empty");
	}

	unsigned long removedTop = m_stack.back();

	m_stack.pop_back();
	--m_size;

	return removedTop;
}

void IPStack::print() const
{
	for(size_t i = 0; i < m_size; ++i)
	{
		std::cout << m_stack[i] << "  ";
	}
	std::cout << '\n';
}


}//namespace container