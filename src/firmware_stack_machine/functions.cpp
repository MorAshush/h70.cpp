#include "functions.hpp"
#include "stack.hpp"
#include "controller.hpp"
#include "memory.hpp"

namespace firmware
{
	void push(Bus& a_bus)
	{
		container::Stack* stack = a_bus.numbers_stack();	    
	    mng::Controller* controller = a_bus.controller();
	    mng::Memory* memory = a_bus.memory();

	    size_t currentIp = controller->ip();
	    
	    unsigned long arg = memory->operator[](++currentIp);
	    stack->push(arg);

	    ++controller;
	    ++controller;
	}

	void add(Bus& a_bus)
	{
		container::Stack* stack = a_bus.numbers_stack();
		stack->push(stack->pop() + stack->pop());
	}

	void sub(Bus& a_bus)
	{
		container::Stack* stack = a_bus.numbers_stack();		
		stack->push(stack->pop() - stack->pop());
	}

	void dup(Bus& a_bus)
	{
		container::Stack* stack = a_bus.numbers_stack();		
		unsigned long top = stack->pop();
		stack->push(top);
		stack->push(top);
	}

}