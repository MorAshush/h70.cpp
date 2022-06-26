#include "functions.hpp"

namespace firmware
{
	void push(container::Stack& a_stack, mng::Memory& a_memory, mng::Controller& a_controller)
	{
	    size_t currentIp = a_controller.ip();
	    unsigned long arg = a_memory[++currentIp];
	    a_stack.push(arg); 
	    ++a_controller;
	    ++a_controller;
	}

	void add(container::Stack& a_stack)
	{
		a_stack.push(a_stack.pop() + a_stack.pop());
	}

	void sub(container::Stack& a_stack)
	{
		a_stack.push(a_stack.pop() - a_stack.pop());
	}

	void dup(container::Stack& a_stack)
	{
		unsigned long top = a_stack.pop();
		a_stack.push(top);
		a_stack.push(top);
	}

}