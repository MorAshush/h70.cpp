#ifndef IP_STACK_HPP
#define IP_STACK_HPP

#include <vector>
#include <cstddef>

#include "instruction_base.hpp"
//#include "stack_base.hpp"

namespace container
{

class IPStack: public StackBase
{
public:
	IPStack(size_t a_size);

	void push(unsigned long a_address);
	unsigned long pop();

	virtual void print() const;
private:
	size_t m_capacity;
	size_t m_size;
	std::vector<unsigned long> m_stack;
};





}//namespace container

#endif//IP_STACK_HPP