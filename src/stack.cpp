#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstddef>

#include "stack.hpp"

#define DEFAULT_SIZE 16

namespace adt
{
	Stack::Stack(size_t a_size)
	{
		assert(a_size > 0 && "stack size can't be zero");
		int* array = static_cast<int*>(malloc(sizeof(int) * a_size));

		assert(array && "array allocation failed");

		m_array = array;
		m_size = a_size;
		m_num_of_items = 0;
	}


	Stack::Stack()
	{
		int* array = static_cast<int*>(malloc(sizeof(int) * DEFAULT_SIZE));

		assert(array && "array allocation failed");
		
		m_array = array;
		m_size = DEFAULT_SIZE;
		m_num_of_items = 0;
	}


	void Stack::print() const
	{
		printf("[");

		if(m_num_of_items)
		{
			for(size_t i = 0; i < m_size ; ++i)
			{
				printf("%d", m_array[i]);

				if(i == m_size - 1)
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
	assert(m_num_of_items < m_size && "stack array is full");
	
	m_array[m_num_of_items] = a_num;
	++m_num_of_items;
}


void Stack::clear()
{
	m_num_of_items = 0;
}


int Stack::pop()
{
	assert(m_num_of_items > 0 && "stack is empty");

	int last = m_array[m_num_of_items - 1];
	--m_num_of_items;

	return last;
}


int& Stack::top() const
{
	assert(m_num_of_items > 0 && "stack is empty");

	int& last = m_array[m_num_of_items - 1];

	return last;
}


size_t Stack::get_size() const
{
	return m_size;
}


size_t Stack::get_num_of_items() const
{
	return m_num_of_items;
}

int* Stack::get_stack_array() const
{
	return m_array;
}

void Stack::operator+=(const Stack a_stack)
{
	if(!a_stack.get_size() || !a_stack.get_num_of_items())
	{
		return;
	}

	int* addedArray = a_stack.get_stack_array();
	size_t addedNumOfItems = a_stack.get_num_of_items();

	assert(addedArray && "stack array can't be null");
	assert(((addedNumOfItems + this->m_num_of_items) <= this->m_size) && "stack size is non sufficient");
	
	size_t i = 0;

	while (i < addedNumOfItems)
	{
		this->push(addedArray[i]);
		++i;
	}
}


void Stack::operator<<(Stack& a_stack)
{
	*this += a_stack;
	a_stack.clear();
}


void Stack::operator>>(Stack& a_stack)
{
	a_stack += *this;
	this->clear();
}

}//namespace adt

