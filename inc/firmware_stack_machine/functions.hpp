#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "controller.hpp"
#include "stack.hpp"


namespace firmware
{

	void push(container::Stack& a_stack, mng::Memory& a_memory, mng::Controller& a_controller);
	void add(container::Stack& a_stack);
	void sub(container::Stack& a_stack);
	void dup(container::Stack& a_stack);


}//namespace firmware



#endif// FUNCTIONS_HPP