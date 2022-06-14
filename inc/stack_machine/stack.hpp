#ifndef STACK_HPP
#define STACK_HPP

#include <stack>

namespace container
{

class Stack
{
public:
	Stack();

	void push(long a_num);
	long pop();

private:
	std::stack<long> m_stack;
};





}//namespace container










#endif //STACK_HPP