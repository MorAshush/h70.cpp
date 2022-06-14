#include <exception>

#include "stack.hpp"
//#include "StackUnderFlowExeption.hpp"

namespace container
{


Stack::Stack()
{

}

void Stack::push(long a_num)
{
	m_stack.push(a_num);
}

long Stack::pop()
{
	if(m_stack.size() == 0)
	{
//		throw StackUnderFlowExeption;
	}

	long removedTop = m_stack.top();

	m_stack.pop();

	return removedTop;
}



}//namespace container