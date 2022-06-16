#ifndef STACK_HPP
#define STACK_HPP

#include <vector>
#include <cstddef>

namespace container
{

class Stack
{
public:
	Stack(size_t a_size);

	void push(long a_num);
	long pop();

	void print() const;
private:
	size_t m_capacity;
	size_t m_size;
	std::vector<unsigned long> m_stack;
};





}//namespace container










#endif //STACK_HPP