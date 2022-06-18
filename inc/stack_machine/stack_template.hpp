#ifndef STACK_HPP
#define STACK_HPP

#include <vector>
#include <cstddef>

#include "stack_overflow.hpp"
#include "stack_underflow.hpp"

namespace container
{

template <typename T>
class Stack
{
public:
	Stack(size_t a_size);

	void push(T a_data);
	T pop();

	void print() const;
private:
	size_t m_capacity;
	size_t m_size;
	std::vector<T> m_stack;
};


template <typename T>
Stack<T>::Stack(size_t a_size)
: m_capacity(a_size)
, m_size(0)
{

}

template <typename T>
void Stack<T>::push(T a_data)
{
	if(! (m_size < m_capacity))
	{
		throw expt::OverFlowErr("Stack::push", "overflow error: stack is overflowed");
	}

	m_stack.push_back(a_data);
	++m_size;
}

template <typename T>
T Stack<T>::pop()
{
	if(m_size == 0)
	{
		throw expt::UnderFlowErr("Stack::pop", "underflow error: stack is empty");
	}

	T removedTop = m_stack.back();

	m_stack.pop_back();
	--m_size;

	return removedTop;
}

template <typename T>
void Stack<T>::print() const
{
	for(size_t i = 0; i < m_size; ++i)
	{
		std::cout << m_stack[i] << "  ";
	}
	std::cout << '\n';
}


}//namespace container



#endif //STACK_HPP