#include "binary_jmp_instruction.hpp"
#include "stack_template.hpp"
#include "controller.hpp"

namespace act
{


int BinaryJmpInstruction::execute(Bus& a_bus)
{
	container::Stack<unsigned long>* s = a_bus.numbers_stack();

	unsigned long first = s->pop();
	unsigned long second = s->pop();

	if(compare_func(first, second))
	{
		++*(a_bus.controller());
	}
	else
	{
		++*(a_bus.controller());
		++*(a_bus.controller());
	}

	return 1;
}

}//namespace act