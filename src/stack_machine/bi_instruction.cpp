#include <iostream>

#include "bi_instruction.hpp"
#include "stack_template.hpp"
#include "controller.hpp"
#include "memory.hpp"

namespace act
{


int BiInstruction::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();

	unsigned long first = s->pop();
	unsigned long second = s->pop();

	unsigned long result = actual_operation(first, second);
	s->push(result);

	++*(a_bus.controller());

	return 1;
}

}//namespace act