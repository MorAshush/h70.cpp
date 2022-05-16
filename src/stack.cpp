#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <algorithm>

#include "stack.hpp"


namespace adt
{
	Stack::Stack(size_t a_size)
	:m_capacity(a_size)
	,m_size(0)
	,m_array(static_cast<int*>(::malloc(sizeof(int) * m_capacity)))
	{
/*		assert(m_capacity > 0 && "stack size can't be zero");*/
		assert(m_array && "array allocation failed");
	}


	Stack::Stack()
	:m_capacity(m_DEFAULT_SIZE)
	,m_size(0)
	,m_array(static_cast<int*>(::malloc(sizeof(int) * m_capacity)))
	{
/*		assert(m_capacity > 0 && "stack size can't be zero");*/
		assert(m_array && "array allocation failed");
	}


	Stack::Stack(const Stack& a_stack) 
	:m_capacity(a_stack.m_capacity)
	,m_size(a_stack.m_size)
	,m_array(static_cast<int*>(::malloc(sizeof(int) * m_capacity)))
	{
		assert(m_array && "array allocation failed");

		for(size_t i = 0; i < m_size; ++i)
		{
			m_array[i] = a_stack.m_array[i];
		}
	}


	Stack& Stack::operator=(const Stack& a_stack)
	{
		::free(m_array);

		m_capacity = a_stack.m_capacity;
		m_size = a_stack.m_size;
		m_array = static_cast<int*>(::malloc(sizeof(int) * m_capacity));
		assert(m_array && "array allocation failed");

		for(size_t i = 0; i < m_size; ++i)
		{
			m_array[i] = a_stack.m_array[i];
		}

		return *this;
	}


	Stack::~Stack()
	{
		::free(m_array);
	}


	void Stack::print() const
	{
		printf("[");

		if(m_size)
		{
			for(size_t i = 0; i < m_capacity ; ++i)
			{
				printf("%d", m_array[i]);

				if(i == m_capacity - 1)
				{
					break;
				}

				printf(",");
			}
		}

		printf("]\n");
	}


void Stack::push(int a_num)
{
	assert(m_size < m_capacity && "stack array is full");
	
	m_array[m_size] = a_num;
	++m_size;
}


void Stack::clear()
{
	m_size = 0;
}


int Stack::pop()
{
	int t = top();
	--m_size;

	return t;
}


int& Stack::top() const
{
	assert(m_size > 0 && "stack is empty");

	return m_array[m_size - 1];
}


size_t Stack::capacity() const
{
	return m_capacity;
}


size_t Stack::size() const
{
	return m_size;
}

int* Stack::stack_array() const
{
	return m_array;
}

void Stack::operator+=(Stack a_stack)
{
	*this << a_stack;
}


Stack& Stack::operator<<(Stack& a_stack)
{
	size_t needToDrain = a_stack.size();
	size_t canTake = this->capacity() - this->size();
	size_t take = std::min(needToDrain, canTake);
	
	while (take-- > 0)
	{
		this->push(a_stack.pop());
	}

	return *this;
}


Stack& Stack::operator>>(Stack& a_stack)
{
	a_stack << *this;

	return *this;
}

}//namespace adt

