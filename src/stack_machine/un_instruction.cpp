#include <iostream>

#include "un_instruction.hpp"
#include "stack_template.hpp"
#include "controller.hpp"

namespace act
{


int UnInstruction::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();

	unsigned long top = s->pop();

	unsigned long result = actual_operation(top, a_bus);
	
	s->push(result);

	mng::Controller* c = a_bus.controller();
	++*c;
		
	return 1;
}

}//namespace act