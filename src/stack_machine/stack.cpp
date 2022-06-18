#include <exception>
#include <iostream>

#include "stack.hpp"
#include "stack_overflow.hpp"
#include "stack_underflow.hpp"

namespace container
{


Stack::Stack(size_t a_size)
: m_capacity(a_size)
, m_size(0)
{
}

void Stack::push(unsigned long a_num)
{
	if(! (m_size < m_capacity))
	{
		throw expt::OverFlowErr("Stack::push", "overflow error: stack is overflowed");
	}

	m_stack.push_back(a_num);
	++m_size;
}

unsigned long Stack::pop()
{
	if(m_size == 0)
	{
		throw expt::UnderFlowErr("Stack::pop", "underflow error: stack is empty");
	}

	unsigned long removedTop = m_stack.back();

	m_stack.pop_back();
	--m_size;

	return removedTop;
}

void Stack::print() const
{
	for(size_t i = 0; i < m_size; ++i)
	{
		std::cout << m_stack[i] << "  ";
	}
	std::cout << '\n';
}


}//namespace container